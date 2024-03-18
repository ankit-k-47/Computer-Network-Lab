#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class graph {
    public:
        int vertex;
        int edge;
        vector<vector<int> > adj;

        graph(int v, int e){
            this->vertex=v;
            this->edge=e;
        }

        void addEdge(int u, int v, int w){
            vector<int> p;
            p.push_back(u);
            p.push_back(v);
            p.push_back(w);
            adj.push_back(p);
        }
        

        void print(){
           for(int i=0; i<adj.size(); i++){
                cout<<adj[i][0]<<" -> "<<adj[i][1]<<" "<<adj[i][2]<<endl;
           }
        }

        int bell(int src, int dest){
            vector<int> distance(vertex, INT_MAX);
            distance[src]=0;
            for(int i=1; i<vertex-1; i++){
                for(int j=0; j<edge; j++){
                    int u=adj[j][0];
                    int v=adj[j][1];
                    int w=adj[j][2];

                    if(distance[u]!=INT_MAX && ((distance[u] + w ) < distance[v])){
                        distance[v]=distance[u] + w;
                    }
                }
            }

            // run one time and see if the values of the distance vector gets updated, if it happens this means there is a negative cycle in the graph
              bool flag = false;
              for(int j=0; j<edge; j++){
                  int u= adj[j][0];
                  int v = adj[j][1];
                  int w = adj[j][2];
                  
                  if(distance[u]!=INT_MAX && distance[u]+ w < distance[v]){
                      distance[v]=distance[u] + w;
                      flag=true;
                  }
             }
             
                if(flag) {
                    cout<<"has a negative cycle"<<endl;
                }
                else {
                    cout<<"No negative cycle"<<endl;
                }

            for(auto x : distance) {
                cout<<x<<" ";
            }
            cout<<endl;

            return distance[dest];
        }
        
};
int main(){
    int v,e;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;
    graph g(v,e);
    // g.addEdge(0,1,2);
    // g.addEdge(1,2,-1);
    // g.addEdge(0,2,2);
    g.addEdge(0,1,3);
    g.addEdge(0,2,1);
    g.addEdge(1,4,1);
    g.addEdge(1,3,5);
    g.addEdge(3,2,2);
    g.addEdge(1,2,7);
    g.addEdge(1,0,3);
    g.addEdge(2,0,1);
    g.addEdge(4,1,1);
    g.addEdge(3,1,5);
    g.addEdge(2,3,2);
    g.addEdge(2,1,7);
    g.print();
    int dest=2, src=0;
    cout<<g.bell(src, dest)<<endl;
    return 0;
}

