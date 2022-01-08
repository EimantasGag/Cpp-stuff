#include <bits/stdc++.h>

using namespace std;

struct Node{
    int num;
    int ikrovimas;
    int best_time = -1;
    int degalu_kiekis = 0;
    vector<Node*> kaimynai;
    Node* best_kaimynas;
    Node* prev_node;

    bool inQueue = false;

    void pridetiKaimyna(Node* miestas){
        kaimynai.push_back(miestas);
    }
};

Node* NULL_NODE = new Node();

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

struct Masina{
    int talpa;
    int elek_naudojimas;
    int degalu_kiekis;
};

int countChargeTime(const Masina* masina, const Node* dab_miestas){
    int laikas = 0;

    int degalu_kiekis = masina->degalu_kiekis;
    int talpa = masina->talpa;
    int elek_naudojimas = masina->elek_naudojimas;

    int krovimas = dab_miestas->ikrovimas;

    while(elek_naudojimas > degalu_kiekis){
        laikas++;
        degalu_kiekis += krovimas;

        if(degalu_kiekis > talpa){
            degalu_kiekis = talpa;
        }
    }

    return laikas;
}

int findBestPath(PriorityQueue* pq, Node* cur_node, const Node* end_node, Masina* masina, int cur_time = 0){
    if(cur_node == end_node){
        return cur_time;
    }

    for(int i = 0;i<cur_node->kaimynai.size();i++){
        Node* kaimynas = cur_node->kaimynai[i];

        //NUKELIAVIMO LAIKAS (1H) + KROVIMO LAIKAS

        int charge_time = countChargeTime(masina, cur_node);
        //cout << charge_time << endl;
        int new_time = cur_time + charge_time + 1;
        //cout << new_time << endl;

        if(kaimynas->best_time == -1 || kaimynas->best_time > new_time){
            kaimynas->prev_node = cur_node;
            kaimynas->best_time = new_time;
            kaimynas->degalu_kiekis = cur_node->ikrovimas*charge_time + masina->degalu_kiekis - masina->elek_naudojimas;
        }

        if(!kaimynas->inQueue){
            kaimynas->inQueue = true;
            pq->push(kaimynas);
        }
    }

    if(pq->isEmpty()){
        return -1;
    }

    Node* naujas_miestas = pq->pop();
    
    masina->degalu_kiekis = naujas_miestas->degalu_kiekis;

    return findBestPath(pq, naujas_miestas, end_node, masina, naujas_miestas->best_time);
}

int chargeTill(Masina* masina, double krovimas, int min_deg){
    double pilti_degalu = min_deg - masina->degalu_kiekis;

    if(pilti_degalu <= 0){
        return 0;
    }
    else{
        int krovimo_laikas = ceil(pilti_degalu / krovimas);
        masina->degalu_kiekis += krovimas * krovimo_laikas;

        if(masina->degalu_kiekis > masina->talpa){
            masina->degalu_kiekis = masina->talpa;
        }

        return krovimo_laikas;
    }
}

void initialize(const Node* prad_miestas, Node* pab_miestas){
    if(prad_miestas == pab_miestas){
        return;
    }
    else{
        pab_miestas->prev_node->best_kaimynas = pab_miestas;
        return initialize(prad_miestas, pab_miestas->prev_node);
    }
}

int findBestTime(Node* dab_miestas, const Node* pab_miestas, Masina* masina, int laikas = 0){
    if(dab_miestas == pab_miestas){
        return laikas;
    }

    int max_degalai = masina->talpa;
    int deg_naudojimas = masina->elek_naudojimas;

    Node* miestas = dab_miestas->best_kaimynas;
    max_degalai -= deg_naudojimas;

    int atstumas = 1;

    //IESKO MIESTO KURIAME IKROVIMAS BUTU GREITESNIS
    //KAI JI RANDA, PRIPILDO DEGALU KAD UZTEKTU IKI JO
    //NUVAZIUOTI

    Node* best_miestas = miestas;
    int best_miestas_deg = deg_naudojimas;
    int best_miestas_ats = 1;

    while(max_degalai >= deg_naudojimas){
        if(miestas->ikrovimas > dab_miestas->ikrovimas || miestas == pab_miestas){
            int krovimo_laikas = chargeTill(masina, dab_miestas->ikrovimas, masina->talpa - max_degalai);
            int naujas_laikas = laikas + atstumas + krovimo_laikas; 

            masina->degalu_kiekis -= atstumas * deg_naudojimas;

            return findBestTime(miestas, pab_miestas, masina, naujas_laikas);
        }

        if(best_miestas->ikrovimas < miestas->ikrovimas){
            best_miestas = miestas;
            best_miestas_deg = masina->talpa - max_degalai;
            best_miestas_ats = atstumas;
        }

        max_degalai -= deg_naudojimas;
        miestas = miestas->best_kaimynas;
        atstumas++;
    }

    //JEIGU NERADO GREITESNIO IKROVIMO, VADINASI
    //REIKIA KELIAUTI IKI VISTIEK GREICIAUSIO

    int krovimo_laikas = chargeTill(masina, dab_miestas->ikrovimas, best_miestas_deg);

    masina->degalu_kiekis -= best_miestas_ats * deg_naudojimas;

    return findBestTime(best_miestas, pab_miestas, masina, laikas + best_miestas_ats + krovimo_laikas);
}

int main(){ 
    ifstream read_file("test6.in");
    ofstream write_file("nice.txt");

    int miestu_sk, keliu_sk, talpa, elek_sunaud;

    read_file >> miestu_sk >> keliu_sk >> talpa >> elek_sunaud;

    int ikrovimas;
    vector<Node*> visi_miestai;

    for(int i = 0;i<miestu_sk;i++){
        read_file >> ikrovimas;

        Node* miestas = new Node();
        miestas->ikrovimas = ikrovimas;
        miestas->num = i;

        visi_miestai.push_back(miestas);
    }

    int a,b; //miestas a ir b

    for(int i = 0;i<keliu_sk;i++){
        read_file >> a >> b;

        visi_miestai[a-1]->pridetiKaimyna(visi_miestai[b-1]);
        visi_miestai[b-1]->pridetiKaimyna(visi_miestai[a-1]);
    }

    PriorityQueue* pq = new PriorityQueue();
    Masina* masina = new Masina();

    masina->degalu_kiekis = 0;
    masina->elek_naudojimas = elek_sunaud;
    masina->talpa = talpa;

    int res = findBestPath(pq, visi_miestai[0], visi_miestai[visi_miestai.size()-1], masina);

    if(res != -1){
        masina->degalu_kiekis = 0;
        initialize(visi_miestai[0], visi_miestai[visi_miestai.size()-1]);

        write_file << findBestTime(visi_miestai[0], visi_miestai[visi_miestai.size()-1], masina);
    }
    else{
        write_file << -1;
    }

    
}