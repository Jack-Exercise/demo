#include <iostream>
#include <queue>
#define MaxVNum 20

using namespace std;

struct MGraph{
	int Nv;
	int Ne;
	int adj[MaxVNum][MaxVNum];
};

bool visited[MaxVNum];

struct Edge{
	int v1,v2;
	int weight;
};

MGraph* CreateGraph(int vnum){
	MGraph *g=new MGraph;
	int v,w;
	
	g->Nv=vnum;
	g->Ne=0;
	
	for(v=0;v<vnum;v++){
		for(w=0;w<vnum;w++){
			g->adj[v][w]=0;
		}
	}
	return g;
}

void InsertEdge(MGraph *g,Edge *e){
	g->adj[e->v1][e->v2]=e->weight;
	g->adj[e->v2][e->v1]=e->weight;
}

MGraph* BuildGraph(){
	MGraph *g;
	
	int Nv;
	
	cout<<"please enter the num of vertex";
	cin>>Nv;
	g=CreateGraph(Nv);
	cout<<"please enter the num of edge";
	cin>>g->Ne;
	
	if(g->Ne!=0){
		Edge e[g->Ne];
		for(int i=0;i<g->Ne;i++){
			cout<<"please enter the vertex and the weight of the edge";
			cin>>e[i].v1>>e[i].v2>>e[i].weight;
			InsertEdge(g,&e[i]);
		} 
	}
	
	return g;
}

void clearvis(bool *visited){
	for(int v=0;v<MaxVNum;v++){
		visited[v]=false;
	}
} 

void BFS(MGraph *g,int v){
	int w;
	queue<int> q;
	q.push(v);
	visited[v]=true;
	while(!q.empty()){
		for(w=0;w<g->Nv;w++){
			if(g->adj[q.front()][w]&&!visited[w]){
				q.push(w);
				visited[w]=true;
			}
		}
		cout<<q.front()<<" ";
		q.pop();
	}
	
	
}

int main(){
	MGraph *g=BuildGraph();
	clearvis(visited);
	BFS(g,0);
	clearvis(visited);
	BFS(g,0);
	delete g;
	return 0;
}
