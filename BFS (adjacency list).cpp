#include <iostream>
#include <queue>
#include <list> 
#define MaxVNum 20

using namespace std;

struct ToVertex{
	int v;
	int weight;
};

struct LGraph{
	int Nv;
	int Ne; 
	list<ToVertex> adj[MaxVNum];
};

bool visited[MaxVNum];

struct Edge{
	int v1,v2;
	int weight;
};

LGraph* CreateGraph(int vnum){
	LGraph *g=new LGraph;
	
	g->Nv=vnum;
	g->Ne=0;
	
	return g;
}

void InsertEdge(LGraph *g,Edge *e){
	ToVertex t;
	t.v=e->v2;
	t.weight=e->weight;
	g->adj[e->v1].push_back(t);
	
	t.v=e->v1;
	t.weight=e->weight;
	g->adj[e->v2].push_back(t);
}

LGraph* BuildGraph(){
	LGraph *g;
	
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

void BFS(LGraph *g, int v){
	queue<int> q;
	q.push(v);
	visited[v]=true;
	while(!q.empty()){
		for (list<ToVertex>::iterator it = g->adj[q.front()].begin(); it != g->adj[q.front()].end(); ++it) {
        	if(!visited[it->v]){
				q.push(it->v);
				visited[it->v]=true;
			}
    	}
		cout<<q.front()<<" ";
		q.pop();
	}
}

void ShowGraph(LGraph *g){
	for(int i=0;i<g->Nv;i++){
		for (list<ToVertex>::iterator it = g->adj[i].begin(); it != g->adj[i].end(); ++it) {
        	std::cout << it->v << " ";
		}
		cout<<endl;
    }
}

int main(){
	LGraph *g=BuildGraph();
	ShowGraph(g);
	clearvis(visited);
    BFS(g,0);
	delete g;
	return 0;
}
