#include <bits/stdc++.h>

using namespace std;

struct Node{
    char* data;
    int freq;

    Node* left_node;
    Node* right_node;

    Node(char* adata, int afreq){
        data = adata;
        freq = afreq;
    }
};

struct SortedList{

private:

    struct LinkedList{
        Node node = Node(new char(' '), 0);
        LinkedList* next;

        LinkedList(Node anode){
            node = anode;
        }
    };

    bool empty = true;
    LinkedList* head;
    LinkedList* last;
    string m_word;
    int size = 0;

public:

    SortedList(string word){
        m_word = word;
    }

    int getSize(){
        return size;
    }

    void addNode(Node node){
        size++;

        if(empty){
            head = new LinkedList(node);
            head->next = NULL;

            last = head;

            empty = false;
        }
        else{
            LinkedList* cur = head;
            LinkedList* prev;

            bool first = true;

            //WHILE LOOPAS PRIDEDA NODE I TEISINGA VIETA RIKIUOTEJE (KAD ISLIKTU SOTTED LISTAS)

            while(true){
                if(cur == NULL || cur->node.freq > node.freq){
                    if(first){ 
                        //JEI ELEMANTAS PIRMOJE VIETOJE SUKURIAME NAUJA NODE IR JI PAVERCIAME HEAD

                        LinkedList* new_node = new LinkedList(node);
                        new_node->next = head;
                        head = new_node;
                    }
                    else{
                        LinkedList* new_node = new LinkedList(node);
                        LinkedList* copy = prev->next;

                        prev->next = new_node;
                        new_node->next = copy;
                    }
                    break;
                }
                else if(cur->node.freq == node.freq){
                    if(node.data == NULL || m_word.find(*cur->node.data) > m_word.find(*node.data)){
                        if(first){
                            LinkedList* new_node = new LinkedList(node);
                            new_node->next = head;
                            head = new_node;
                        }
                        else{
                            LinkedList* new_node = new LinkedList(node);
                            LinkedList* copy = prev->next;

                            prev->next = new_node;
                            new_node->next = copy;
                        }
                        break;
                    }
                }

                first = false;
                prev = cur;
                cur = cur->next;
            }

        }
    }

    bool isEmpty(){
        return empty;
    }

    Node* getFirst(){
        if(!empty){
            return &head->node;
        }
        
    }

    Node removeFirst(){
        if(empty){
            throw 404;
        }

        size--;
        Node first_node = head->node;
        LinkedList* ptr = head;
        
        head = head->next;

        if(head == NULL){
            empty = true;
        }

        return first_node;
    }

    void printList(){
        if(empty){
            return;
        }

        LinkedList* cur = head;

        while(cur != NULL){
            if(cur->node.data != NULL){
                cout << *(cur->node.data) << " " << cur->node.freq << endl;
            }
            else{
                cout << "NULL" << " " << cur->node.freq << endl;
            }
            
            cur = cur->next;
        }
        cout << "\n";
    }
};

struct EncodedWordData{
    string code;
    Node* root;

    EncodedWordData(string acode, Node* aroot){
        code = acode;
        root = aroot;
    }
};

map<char,int> generateMap(const string& word){
    map<char,int> char_map;
    for(int i = 0;i<word.length();i++){
        char_map[word[i]]++;
    }
    return char_map;
}

void getCodes(const Node* cur_node, map<char, string>& all_codes , string code = ""){
    bool left = true;

    if(cur_node->data != NULL){
        all_codes[*cur_node->data] = code;
        return;
    }

    for(int i = 0;i<2;i++){
        if(left){
            getCodes(cur_node->left_node, all_codes, code + '0');
        }
        else{
            getCodes(cur_node->right_node, all_codes, code + '1');
        }

        left = false;
    }

    return;
}

EncodedWordData encode_word(string word){
    map<char,int> char_map = generateMap(word);

    auto iter = char_map.begin();
    SortedList nodes(word);

    for(;iter!=char_map.end();iter++){
        nodes.addNode(Node(new char(iter->first),iter->second));
    }

    //nodes.printList();

    //SUKURI BINARY TREE

    while(nodes.getSize() != 1){
        Node* node1 = nodes.getFirst();
        nodes.removeFirst();
        Node* node2 = nodes.getFirst();
        nodes.removeFirst();

        if(node1->data != NULL){
            node1->left_node = NULL;
            node1->right_node = NULL;
        }
        if(node2->data != NULL){
            node2->right_node = NULL;
            node2->left_node = NULL;
        }

        Node parent = Node(NULL,node1->freq+node2->freq);
        parent.left_node = node1;
        parent.right_node = node2;
        
        nodes.addNode(parent);
    }

    Node* root = nodes.getFirst();

    map<char, string> all_codes;
    getCodes(root, all_codes);

    // auto it = all_codes.begin();
    // for(;it!=all_codes.end();it++){
    //     cout << it->first << " " << it->second << endl;;
    // }

    string final_code = "";

    for(int i = 0;i<word.length();i++){
        final_code += all_codes[word[i]];
    }

    return EncodedWordData(final_code, root);
}

string decode_huff(Node * root, string s) {
    int cur_ind = 0;
    Node* cur_node = root;
    string cur_string = "";
    
    while(cur_ind < s.length()){
        if(s[cur_ind] == '0'){
            cur_node = cur_node->left_node;
        }
        else{
            cur_node = cur_node->right_node;
        }
        
        if(cur_node->data != NULL){
            cur_string += *cur_node->data;
            cur_node = root;
        }
        
        cur_ind++;
    }
    
    return cur_string;
}

int main(){
    EncodedWordData encodedWord = encode_word("LABAS_RYTAS_MOKYTOJA_KAS_BUVO_NAMU_DARBAMS");
    
    cout << "Encoded word: " << encodedWord.code << endl;
    cout << "Decoded word: " << decode_huff(encodedWord.root, encodedWord.code) << endl;
}