/* A simple, TCP based echo server */

#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *selecter();
void *listener(void *);
void *doit4(void*);
void str_echo(int);
pthread_mutex_t lock;
fd_set rdfs;
int spfd = -1;
int fdmax = 1;
int listenfd = -1;
pthread_t tid4;
int fileDescriptors[2];
int connfd = -1;

void* listener(void *arg)
{
	fprintf(stderr, "\ndo it function 2");
	socklen_t clilen2;
	struct sockaddr_in cliaddr2;
	clilen2 = sizeof(cliaddr2);
	int listenfd = *(int*) (arg);
	fprintf(stderr, " value of listen fd :%d", listenfd);
	while ( 1 )
	{
		clilen2 = sizeof(cliaddr2);
		fprintf(stderr, "\nin the for loop accepting connections");
		if ( (connfd = accept(listenfd, (struct sockaddr*) &cliaddr2, &clilen2))< 0)
		{
			fprintf(stderr, "\n: Error in accept%d", connfd);
			exit(0);
		}
		else
		{
			fprintf(stderr,"\nsocket id of the new connection is : %d\n",connfd);
			pthread_mutex_lock(&lock);
			fprintf(stderr, "\nnew connection accepted %d\n", connfd);
			FD_SET(connfd, &rdfs);
			if ( connfd > fdmax )
			fdmax = connfd;
			pthread_mutex_unlock(&lock);
			char buff[5] = "test";
			write(fileDescriptors[1], buff, 4);
		}
	}
}

void *selecter(void *arg)
{
	while ( 1 )
	{
		fprintf(stderr,"\nGoing to select %d\n", fdmax);
		if (select(fdmax + 1, &rdfs, NULL, NULL, NULL) == -1)
		{
			perror("select");
			exit(4);
		}
		fprintf(stderr,"mutex unlocked in selecter");
		int i = 0;
		for (i = 0; i <= fdmax; i++)
		{
			if ( FD_ISSET(i, &rdfs) )
			{
				if ( i == fileDescriptors[0] )
				{
					FD_CLR(fileDescriptors[0], &rdfs);
					fprintf(stderr,"\nclearing pipe :%d",i);
					FD_SET(connfd, &rdfs);
				}
				else if ( i == listenfd )
					continue;
				else
				{
					fprintf(stderr,"\nnew thread for socket :%d\n",i);
					pthread_create(&tid4, NULL, &doit4, (void*)i);
					pthread_mutex_lock(&lock);
					FD_CLR(i,&rdfs);
					pthread_mutex_unlock(&lock);
				}
			}
		}
	}
}

void *doit4(void* i)
{
	fprintf(stderr,"in do it function 4");
	int arg = (int)(i);
	str_echo(arg);
	close((int)arg);
}

void str_echo(int sockfd)
{
	ssize_t n;
	char line[512]= "";

	/* read from socket */
	n = read(sockfd, line, 512);

	printf("\n read line %s\n", line);
	if (n < 0) {
		printf("\nError in read");
		exit(0);
	} else if (n == 0) {
		return;
	}

	/* echo back to the client */
	if (write(sockfd, line, n) < 0) {
		printf("\nError in write");
		exit(0);
	}

	/* note that we are not checking all error cases in the code */
	close(sockfd);
}

int main(int argc, char **argv)
{
	/* variables section */
	pthread_t tid3, tid2, tid4;
	int connfd;
	pid_t childpid;
	socklen_t clilen;
	struct sockaddr_in cliaddr, servaddr;

	/* creating a socket */
	if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("\n%s: Error in socket", argv[0]);
		exit(0);
	}

	/* configuring server address structure */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(9786);

	/* binding our socket to the service port */
	if (bind(listenfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
		printf("\n%s: Error in bind", argv[0]);
		exit(0);
	}
	/* convert our socket to a listening socket */
	if (listen(listenfd, 5) < 0) {
		printf("\n%s: Error in listen", argv[0]);
		exit(0);
	}
	fprintf(stderr, "%d value of listen fd", listenfd);

	pipe(fileDescriptors);
	fdmax = fileDescriptors[0];
	FD_SET(fileDescriptors[0], &rdfs);
	pthread_create(&tid2, NULL, &listener, (void *) &listenfd);
	pthread_create(&tid3, NULL, &selecter, NULL);

	// wait for listen and select threads
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
}
