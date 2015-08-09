#include<stdio.h>
#include<stdlib.h>


struct list_edges{
	struct Edge* edge_node;
	struct list_edges* next;
};


struct Vertex{
	int v;
	int flag;
	int pred;
	struct list_edges* adj_list;
};

struct Edge{
	struct Vertex* to;
	struct Vertex* from;
	int cost;
};

void printEdge(struct Edge*);
void print_adj_list(struct list_edges*);
struct Graph{
struct	Vertex** v_list;
	int E,V;
};


struct list_edges* add_edge(struct Edge* e, struct list_edges* ptr){
	if(ptr == NULL){
		ptr = (struct list_edges*)malloc(sizeof(struct list_edges));
		ptr->next = NULL;
		ptr->edge_node = e;
		return ptr;
	}
	struct list_edges* e_node = malloc(sizeof(struct list_edges));
	e_node->next = ptr;
	e_node->edge_node = e;
	return e_node;
}
struct Edge* makeEdge(struct Vertex* from, struct Vertex* to){
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
	printf("\nenter num vertices");
	scanf("%d",&g->V);
	printf("\nnum V:%d",g->V);

	printf("\nEnter num edges");
	scanf("%d",&g->E);
	printf("\nnum E:%d",g->E);
	
	int i =0, to=0, from=0, start=0;
	
	g->v_list = (struct Vertex**)malloc(sizeof(struct Vertex*)*(g->V+1));
	
	for(i = 1;i<=g->V;i++){
		g->v_list[i] = (struct Vertex*) malloc(sizeof(struct Vertex));
		g->v_list[i]->v  = i;
	}
	
	printf("\nenter the edges");
	for( i =1;i<=g->E;i++){
		printf("\nEnter from vertex");
		scanf("%d", &from);
		printf("\nfrom vertex:%d",from);
		
		printf("\nenter to vertex");
		scanf("%d",&to);
		printf("\n to vertex:%d",to);		
		
		struct Edge* e = makeEdge(g->v_list[from],g->v_list[to]);
		struct Edge* e2 = makeEdge(g->v_list[to],g->v_list[from]);
		/* add the edge to the adj_list */
		/* in undirected graph, every vertex has its own edge */
		g->v_list[from]->adj_list = add_edge(e,g->v_list[from]->adj_list);
		//g->v_list[to]->adj_list = add_edge(e2,g->v_list[to]->adj_list);
	}
	return g;
}

void print_adj_list(struct list_edges* list){
	struct list_edges* node = list;
	while(node!= NULL)
	{
		printEdge(node->edge_node);
		node = node->next;
	}
}

void printEdge(struct Edge* e){
	printf("\nfrom %d",e->from->v);
	printf("\tto %d",e->to->v);
}

void printGraph(struct Graph* g){
	int i = 1;
	printf("\nnum edges%d",g->E);
	printf("\nnum vertex%d",g->V);
	printf("\nprintng graph");
	for(;i<=g->V;i++){
		printf("\n%d ->",g->v_list[i]->v);
		print_adj_list(g->v_list[i]->adj_list);
	}
}

void free_list_contents(struct list_edges *ptr){
	struct list_edges *node = ptr;
	while(node!=NULL){
		ptr = ptr->next;
		free(node->edge_node);
		free(node);
		node = ptr;
	}
}
void freeGraph(struct Graph* g){
	int i=1;
	for(;i<=g->V;i++){
		free_list_contents(g->v_list[i]->adj_list);
		free(g->v_list[i]);
	}
	free(g->v_list[0]);
	free(g->v_list);
	free(g);
	
}

void main(){
	struct Graph* g;
	g = makeGraph();
	printGraph(g);
	freeGraph(g);
}
