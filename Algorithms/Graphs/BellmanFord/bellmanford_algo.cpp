#include <bits/stdc++.h>

using namespace std;

int INFINITY_NUM = INT_MIN;

struct Vertic{
    struct Edge{
        Vertic* destination;
        int val;

        Edge(Vertic* d, int v){
            destination = d;
            val = v;
        }
    };

    int shortest_path = INFINITY_NUM;
    vector<Edge> edges;

    void setStartPoint(){
        shortest_path = 0;
    }

    void pair(Vertic* v, int val){
        edges.push_back(Edge(v,val));
    } 
};

int bellmanford(vector<Vertic*>& all_vertices){
    bool changed = true;

    while(changed){
        changed = false;

        for(int i = 0;i<all_vertices.size();i++){
            Vertic* vertic = all_vertices[i];

            if(vertic->shortest_path == INFINITY_NUM){
                continue;
            }
            else{
                for(int x = 0;x<vertic->edges.size();x++){
                    int val = vertic->edges[x].val;
                    Vertic* destination = vertic->edges[x].destination;

                    if(destination->shortest_path == INFINITY_NUM || destination->shortest_path > vertic->shortest_path+val){
                        destination->shortest_path = vertic->shortest_path+val;
                        changed = true;
                    }
                }
            }
        }
    }
}

int main(){
    Vertic vS,vE,vA,vD,vB,vC;

    vS.setStartPoint();

    vS.pair(&vE, 8);
    vS.pair(&vA, 10);
    vE.pair(&vD, 1);
    vA.pair(&vC, 2);
    vD.pair(&vA, -4);
    vD.pair(&vC, -1);
    vB.pair(&vA, 1);
    vC.pair(&vB, -2);

    vector<Vertic*> all_vertices = {&vS,&vE,&vA,&vD,&vB,&vC};

    bellmanford(all_vertices);

    cout << "Shortest paths from S to A cost is: " << all_vertices[2]->shortest_path << endl;
}