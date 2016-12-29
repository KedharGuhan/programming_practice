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
#include <strings.h>
#include <unistd.h>
#include <pthread.h>

static void *doit3();
static void *doit2(void *);
static void *doit4(void*);
void str_echo(int);
pthread_mutex_t lock;
fd_set rdfs;
int spfd;
int i;
int fdmax=1;
char *bufff="test";
int listenfd;
pthread_t tid4;
int main(int argc, char **argv) {

   /* variables section */
   pthread_t tid3,tid2,tid4;
   int                 connfd;
   pid_t              childpid;
   socklen_t          clilen;
   struct sockaddr_in cliaddr, servaddr;

	spfd=socket(AF_INET,SOCK_STREAM,0);
   /* creating a socket */
   if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
     printf("\n%s: Error in socket", argv[0]);
     exit(0);
   }
   
   /* configuring server address structure */
   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family      = AF_INET;
   servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
   servaddr.sin_port        = htons(9786); 

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
fprintf(stderr,"%d value of listen fd",listenfd);

    pthread_create(&tid2,NULL,&doit2,(void *)&listenfd);

    pthread_create(&tid3, NULL, &doit3, NULL); 

	pthread_join(&tid2,NULL);
	pthread_join(&tid3,NULL);

}

 void * doit2(void *arg)
{
fprintf(stderr,"do it function 2");
int connfd;
socklen_t          clilen2;
struct sockaddr_in cliaddr2;
clilen2=sizeof(cliaddr2);
int listenfd=*(int*)(arg);
fprintf(stderr,"%d value of listen fd",listenfd);
for ( ; ; ) {
     clilen2 = sizeof(cliaddr2);
	fprintf(stderr,"accepting connections");
     if ((connfd = accept(listenfd, (struct sockaddr*) &cliaddr2, &clilen2)) < 0) {
      fprintf(stderr,"\n: Error in accept%d",connfd);
	exit(0);}
	else{
	pthread_mutex_lock(&lock);
	fprintf(stderr,"accepting connections");
	FD_SET(connfd,&rdfs);
	write(spfd, (const void*) bufff, strlen(bufff));
	if(connfd>fdmax) fdmax=connfd;

	pthread_mutex_unlock(&lock); 
	}
}
}

void *doit3(void){

for(;;) {
         pthread_mutex_lock(&lock);
        if (select(fdmax+1, &rdfs, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(4);
        }
	for(i = 0; i <= fdmax; i++) {
        if (FD_ISSET(i, &rdfs) && i!=spfd && i!=listenfd)
	{	pthread_create(&tid4,NULL,&doit4,(void*)i );
		pthread_mutex_unlock(&lock);
	}
	}
}
}
 void *doit4(void* i) { 
	str_echo(i);

}
void str_echo (int sockfd) {
  ssize_t n;
  char line[512];
fprintf(stderr,"readd");
  /* read from socket */
  n = read(sockfd, (void *) line, 512);

  if (n < 0) {
    printf("\nError in read"); 
    exit(0);
  } else if (n == 0) {
    return;
  } 

  /* echo back to the client */
  if (write(sockfd, (const void*) line, n) < 0) {
    printf("\nError in write");
    exit(0);
  } 

  /* note that we are not checking all error cases in the code */
  close(sockfd);
}
