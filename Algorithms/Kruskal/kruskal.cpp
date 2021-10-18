#include <bits/stdc++.h>

using namespace std;

struct Vertic;

struct Edge{
    int weight;
    Vertic* start_vertic;
    Vertic* finish_vertic;

    Edge(Vertic* v1, Vertic* v2, int n){
        weight = n;
        start_vertic = v1;
        finish_vertic = v2; 
    }
};

struct Vertic{
    vector<Edge> all_edges;
    int num;

    Vertic(int anum = -1){
        if(anum == -1){
            static int n = 0;
            n++;
            num = n;
        }
        else{
            num = anum;
        }
    }

    Edge pair(Vertic* a, int w){
        Edge edge = Edge(this,a,w);
        all_edges.push_back(edge);

        return edge;
    }

    void printEdges(){
        for(int i = 0;i<all_edges.size();i++){
            cout << all_edges[i].start_vertic->num << " -> " << all_edges[i].finish_vertic->num << endl;
        }
    }
};

struct DisjointSet{
    map<Vertic*, Vertic*> parents;

    void makeSet(const vector<Vertic*>& arr){
        for(int i = 0;i<arr.size();i++){
            parents[arr[i]] = arr[i];
        }
    }

    Vertic* Find(Vertic* a){
        if(parents[a] == a){
            return parents[a];
        }

        return Find(parents[a]);
    }

    void Union(Vertic* a, Vertic* b){
        Vertic* root1 = Find(a);
        Vertic* root2 = Find(b);

        parents[root1] = root2;
    }
};

Vertic* getVertic(int num, const vector<Vertic*>& all_vertices){
    for(int i = 0;i<all_vertices.size();i++){
        if(all_vertices[i]->num == num){
            return all_vertices[i];
        }
    }

    throw(404);
}

vector<Vertic*> kruskal(vector<Edge>& all_edges, DisjointSet disjointSet){
    sort(all_edges.begin(),all_edges.end(),[](Edge a, Edge b){ return a.weight < b.weight; });

    int index = 0;
    vector<Vertic*> new_vertices;

    while(index < all_edges.size()){
        Edge edge = all_edges[index];

        if(disjointSet.Find(edge.start_vertic) != disjointSet.Find(edge.finish_vertic)){
            Vertic* v1;
            Vertic* v2;
    
            bool new_v1 = disjointSet.Find(edge.start_vertic) == edge.start_vertic;
            bool new_v2 = disjointSet.Find(edge.finish_vertic) == edge.finish_vertic;

            if(!new_v1){
                v1 = getVertic(edge.start_vertic->num, new_vertices);
            }
            else{
                v1 = new Vertic(edge.start_vertic->num);
            }

            if(!new_v2){
                v2 = getVertic(edge.finish_vertic->num, new_vertices);
            }
            else{
                v2 = new Vertic(edge.finish_vertic->num);
            }

            v1->pair(v2, edge.weight);
            v2->pair(v1, edge.weight);

            if(new_v1){
                new_vertices.push_back(v1);
            }
            if(new_v2){
                new_vertices.push_back(v2);
            }

            disjointSet.Union(edge.start_vertic, edge.finish_vertic);
        }

        index++;
    }

    return new_vertices;
}

int main(){
    ifstream read_file("data.txt");

    int vertices_num, pairing_num;

    read_file >> vertices_num >> pairing_num;

    vector<Vertic*> all_vertices;
    vector<Edge> all_edges;

    for(int i = 0;i<vertices_num;i++){
        all_vertices.push_back(new Vertic(i));
    }

    for(int i = 0;i<pairing_num;i++){
        int p1, p2, w;

        read_file >> p1 >> p2 >> w; 

        Edge edge = all_vertices[p1]->pair(all_vertices[p2], w);
        all_vertices[p2]->pair(all_vertices[p1], w);

        all_edges.push_back(edge);
    }

    DisjointSet disjointSet;
    disjointSet.makeSet(all_vertices);

    vector<Vertic*> new_vertices = kruskal(all_edges, disjointSet);
    
    for(int i = 0;i<new_vertices.size();i++){
        new_vertices[i]->printEdges();
    }
}