#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class graph {
    public:
        int vertex;
        int edge;
        unordered_map<int, list<pair<int, int> > > adj;

        graph(int v, int e){
            this->edge=e;
            this->vertex=v;
        }

        void addEdge(int u, int v, int w){
            pair<int, int> p = make_pair(v,w);
            adj[u].push_back(p);
            pair<int, int> q = make_pair(u,w);
            adj[v].push_back(q);
        }

        void print(){
            for(auto x : adj){
                cout<<x.first<<" : ";
                for(auto y : x.second) {
                    cout<<"["<<y.first<<" "<<y.second<<"],";
                }
                cout<<endl;
            }
        }

        void dij(vector<int> &distance, set<pair<int, int> > &s, int src){
               distance[src]=0;
               s.insert(make_pair(0,src));

               while(!s.empty()){
                    auto it = *(s.begin());
                    int distance_val = it.first;
                    int node = it.second;

                    s.erase(s.begin());
                    for(auto x : adj[node]){
                        if( distance[x.first] > distance_val + x.second) {
                            auto entry = s.find(make_pair(distance[x.first], x.first));
                            if(entry != s.end()) {
                                s.erase(entry);
                            }   

                            distance[x.first] = distance_val + x.second;
                            s.insert(make_pair(distance[x.first], x.first));
                        }
                       
                    }
               }
        }
};

int main() {
    int v, e;
    cout<<"Enter the number of vertices : ";
    cin>>v;
    cout<<"Enter the number of edges : ";
    cin>>e;
    graph g(v,e);
    g.addEdge(0,1,3);
    g.addEdge(0,2,1);
    g.addEdge(1,4,1);
    g.addEdge(1,3,5);
    g.addEdge(3,2,2);
    g.addEdge(1,2,7);
    g.addEdge(2,3,2);

    g.print();

    vector<int> distance(v,INT_MAX);
    set<pair<int,int> > s;
    g.dij(distance, s,0);

    for(auto x : distance) cout<<x<<" ";
    cout<<endl;
    return 0;


}