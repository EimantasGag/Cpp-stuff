#include <bits/stdc++.h>

using namespace std;

struct Node{
    int num;
    int best_time = -1;
    int elek_kiekis;
    vector<Node*> keliai;
    bool removable;

    Node(int n, int abest_time = -1, int aelek_kiekis = 0, vector<Node*> akeliai = {}, bool aremovable = false){
        num = n;
        int best_time = abest_time;
        int elek_kiekis = aelek_kiekis;
        vector<Node*> keliai = akeliai;
        removable = aremovable;
    }
};

Node* NULL_NODE = new Node(0);

struct PriorityQueue{
    vector<Node*> heap_arr;
    int heap_size = 0;

    Node* parent(int i){
        if((i-1)/2 >= 0 && (i-1)/2 < heap_size){
            return heap_arr[(i-1)/2];
        }
        else{
            return NULL_NODE;
        }
    }

    Node* left(int i){
        if((i*2)+1 >= 0 && (i*2)+1 < heap_size){
            return heap_arr[(i*2)+1];
        }
        else{
            return NULL_NODE;
        }
    }

    Node* right(int i){
        if((i*2)+2 >= 0 && (i*2)+2 < heap_size){
            return heap_arr[(i*2)+2];
        }
        else{
            return NULL_NODE;
        }
    }

    void swap(int a, int b){
        Node* save = heap_arr[a];
        heap_arr[a] = heap_arr[b];
        heap_arr[b] = save;
    }

    int getParentIndex(int i){
        if((i-1)/2 >= 0 && (i-1)/2 < heap_size){
            return (i-1)/2;
        }
        else{
            return -1;
        }
    }

    int getLeftIndex(int i){
        if((i*2)+1 >= 0 && (i*2)+1 < heap_size){
            return (i*2)+1;
        }
        else{
            return -1;
        }
    }

    int getRightIndex(int i){
        if((i*2)+2 >= 0 && (i*2)+2 < heap_size){
            return (i*2)+2;
        }
        else{
            return -1;
        }
    }

    void heapify(int i){
        if(parent(i) != NULL_NODE && parent(i)->best_time > heap_arr[i]->best_time){
            swap(getParentIndex(i),i);
            return heapify(getParentIndex(i));
        }

        Node* smallest;
        int index;

        if(left(i) == NULL_NODE && right(i) == NULL_NODE){
            return;
        }
        else if(left(i) == NULL_NODE){
            smallest = right(i);
            index = getRightIndex(i);
        }
        else if(right(i) == NULL_NODE){
            smallest = left(i);
            index = getLeftIndex(i);
        }
        else{
            if(right(i)->best_time < left(i)->best_time){
                smallest = right(i);
                index = getRightIndex(i);
            }
            else{
                smallest = left(i);
                index = getLeftIndex(i);
            }
        }

        if(smallest->best_time < heap_arr[i]->best_time){
            heapify(index);
        }
    }

    // void heapify(){
    //     for(int i = heap_size-1;i>=0;i--){
    //         if(parent(i) != NULL_NODE && parent(i)->best_time > heap_arr[i]->best_time){
    //             swap(getParentIndex(i),i);
    //         }
    //     }
    // }

    void push(Node* node){
        if(heap_arr.size() > heap_size){
            heap_arr[heap_size] = node;
        }
        else{
            heap_arr.push_back(node);
        }

        heap_size++;
        heapify(heap_size-1);
    }

    Node* pop(){
        if(heap_size == 0){
            return NULL_NODE;
        }
        else if(heap_size == 1){
            heap_size--;
            return heap_arr[0];
        }

        Node* save = heap_arr[0];
        heap_arr[0] = heap_arr[heap_size-1];
        heap_size--;

        heapify(0);

        return save;
    }

    Node* top(){
        return heap_arr[0];
    }

    bool inQueue(Node* node){
        for(int i = 0;i<heap_size;i++){
            if(node == heap_arr[i]){
                return true;
            }
        }

        return false;
    }

    bool isEmpty(){
        return heap_size <= 0;
    }
};

struct Graph{

    PriorityQueue pq;
    Node* baig_m;
    vector<int> miestu_ikrova;
    int energijos_naud;
    int max_talpa;

    Graph(Node* abaig, const vector<int>& amiestu_ikrova, int aenergijos_naud, int amax_talpa){
        baig_m = abaig;
        miestu_ikrova = amiestu_ikrova;
        energijos_naud = aenergijos_naud;
        max_talpa = amax_talpa;
    }

    struct LinkedList{
        int num = -1;
        LinkedList* next;

        LinkedList(int anum = -1, LinkedList* anext = NULL){
            num = anum;
            next = anext;
        }
    };

    int hash_num = 10000;
    LinkedList aplankyti[10000];

    void addVisited(Node* node){
        if(aplankyti[node->num%hash_num].num == -1){
            LinkedList ll(node->num);
            aplankyti[node->num%hash_num] = ll;
        }
        else{
            LinkedList* cur = &aplankyti[node->num%hash_num];
            while(true){
                if(cur->next == NULL){
                    cur->next = new LinkedList(node->num);
                    break;
                }
                else{
                    cur = cur->next;
                }
            }
        }
    }

    bool IsVisited(int num){
        if(aplankyti[num%hash_num].num == -1){
            return false;
        }
        else{
            LinkedList* cur = &aplankyti[num%hash_num];

            while(true){
                if(cur->num == num){
                    return true;
                }
                else if(cur->next != NULL){
                    cur = cur->next;
                }
                else{
                    return false;
                }
            }
        }

        return false;
    }

    //PADARYTI:
    //PABANDYTI PAOPTIMIZINTI HEAPIFY FUNKCIJA - DONE
    //addToPq degal - NEREIKIA TAISYT
    //isVisited ar tikrai taip turi veikt

    void addToPq(Node* dab_m, Node* node, int laikas, int elek_kiekis){

        //JEIGU NERA PAKROVIMO STOTELES JEI GALI VAZIUOJA I KITA MIESTA

        if(miestu_ikrova[dab_m->num-1] == 0){
            if(elek_kiekis >= energijos_naud){
                Node* miestas = new Node(*node);
                miestas->best_time = laikas+1;
                miestas->elek_kiekis = elek_kiekis-energijos_naud;
                miestas->removable = true;

                pq.push(miestas);
            }

            return;
        }

        if(elek_kiekis >= energijos_naud){
            Node* miestas = new Node(*node);
            miestas->best_time = laikas+1;
            miestas->elek_kiekis = elek_kiekis-energijos_naud;
            miestas->removable = true;

            pq.push(miestas);
        }

        while(true){
            if(elek_kiekis >= max_talpa){
                break;
            }

            laikas++;
            elek_kiekis += miestu_ikrova[dab_m->num-1];

            if(elek_kiekis > max_talpa){
                elek_kiekis = max_talpa;
            }

            if(elek_kiekis >= energijos_naud){
                Node* miestas = new Node(*node);
                miestas->best_time = laikas+1;
                miestas->elek_kiekis = elek_kiekis-energijos_naud;
                miestas->removable = true;

                pq.push(miestas);
            }
        }
    }

    int findBestTime(Node* dab_m, int laikas = 0, int elek_kiekis = 0){

        //cout << "Dabartinis miestas: " << dab_m->num << endl;
        //cout << dab_m << endl;

        if(dab_m->num == baig_m->num){
            return laikas;
        }

        addVisited(dab_m);

        for(int i = 0;i<dab_m->keliai.size();i++){
            Node* kaimynas = dab_m->keliai[i];

            if(!IsVisited(kaimynas->num)){
                addToPq(dab_m, kaimynas, laikas, elek_kiekis);
            }
        }

        if(dab_m->removable){
            //cout << "Allocating memory" << endl;
            delete dab_m;
        }
        //delete dab_m;

        if(pq.isEmpty()){
            return -1;
        }
        else{
            Node* kitas_miestas = pq.pop();
            //cout << "kitas miestas: " << kitas_miestas->num << endl;
            
            return findBestTime(kitas_miestas, kitas_miestas->best_time, kitas_miestas->elek_kiekis);
        }
    }
};



int main(){ 
    int miestu_sk,keliu_sk,talpa,elek_sunaud;

    ifstream read_file("test.txt");

    read_file >> miestu_sk >> keliu_sk >> talpa >> elek_sunaud;

    vector<int> miestu_pakrovimas;
    vector<Node*> visi_miestai;

    for(int i = 0;i<miestu_sk;i++){
        int n;

        read_file >> n;

        miestu_pakrovimas.push_back(n);
        visi_miestai.push_back(new Node(i+1));
        //cout << visi_miestai[i]->num << endl;
    }

    for(int i = 0;i<keliu_sk;i++){
        int a,b;

        read_file >> a >> b;
        visi_miestai[a-1]->keliai.push_back(visi_miestai[b-1]);
        visi_miestai[b-1]->keliai.push_back(visi_miestai[a-1]);
    }

    PriorityQueue pq;
    Graph graph(visi_miestai[miestu_sk-1], miestu_pakrovimas, elek_sunaud, talpa);

    ofstream write_file("ats.txt");

    write_file << graph.findBestTime(visi_miestai[0]);
}