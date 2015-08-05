#include<stdio.h>
#include<stdlib.h>

struct Queue{
	Vertex* elements[100];
	int pos;
};

struct Queue q;
struct Vertex{
	int v;
	int flag;
	int pred;
};

struct Edge{
	struct Vertex* to;
	struct Vertex* from;
	int cost;

};

struct Graph{
	struct Edge** edges;
	int E,V;
	struct Vertex* start;
};

struct Edge* makeEdge(struct Vertex* to, struct Vertex* from){
	struct Edge* e = (struct Edge*)malloc(sizeof(struct Edge));
	e->to = to;
	e->from = from;
	e->cost = 6;
	return e;
}


struct Vertex* makeVertex(int v){
	struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
	vertex->v = v;
	vertex->flag = 0;
	vertex->pred = -1;
	return vertex;
}

struct Graph* makeGraph(){
	struct Graph* g = (struct Graph*) malloc(sizeof(struct Graph));
	scanf("%d",&g->V);
	scanf("%d",&g->E);
	int i =0, to=0, from=0, start=0;
	g->edges = (struct Edge**)malloc(sizeof(struct Edge*)*g->E);
	for(;i<g->E;i++){
		scanf("%d%d",&to,&from);
		g->edges[i]=makeEdge(makeVertex(to), makeVertex(from));	
//		g->edges[i]=makeEdge(makeVertex(from), makeVertex(to));
	}
	scanf("%d",&start);
	g->start = makeVertex(start);
	return g;

}

int printVertex(struct Vertex* vertex){
	return vertex->v;
}

void printEdge(struct Edge* e){
	printf("\nfrom %d",printVertex(e->from));
	printf("\tto %d",printVertex(e->to));
}

void printGraph(struct Graph* g){
	int i = 0;
	int j = 0;
	printf("\nnum edges%d",g->E);
	printf("\nnum vertex%d",g->V);
		
	for(;i<g->E;i++)
		printEdge(g->edges[i]);
}

void freeGraph(struct Graph* g){
	int i=0;
	for(;i<g->E;i++){
		free(g->edges[i]->to);
		free(g->edges[i]->from);
		free(g->edges[i]);
	}
	free(g->edges);
	free(g->start);
	free(g);
}
void initQueue(){
	q.pos = -1;
}

void enqueue(Vertex* element){
	q.elements[++q.pos] = element;
}

Vertex* dequeue(){
	return q.elements[q.pos--];
}

int isEmpty(){
	return q.pos;
}
void doBFS(Graph* g){
	int flag[g->V];
	int pred[g->V];
	Vertex* v;
	int i=0;
	enqueue(g->start);
	flag[g->start->v] = 1;
	while(q.pos!=-1){
		v = dequeue();
	}
}
void main(){
	int num_tc;
	int i=0;
	scanf("%d",&num_tc);
	struct Graph* g;
	for(;i<num_tc;i++){
		g = makeGraph();
		printGraph(g);
		freeGraph(g);
	}
}
