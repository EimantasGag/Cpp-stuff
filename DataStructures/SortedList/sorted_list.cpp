#include <iostream>

using namespace std;

struct Node{
    char data;
    int freq;

    Node* left_node;
    Node* right_node;

    Node(char adata, int afreq){
        data = adata;
        freq = afreq;
    }
};

struct SortedList{

private:

    struct LinkedList{
        Node node = Node(' ', 0);
        LinkedList* next;

        LinkedList(Node anode){
            node = anode;
        }
    };

    bool empty = true;
    LinkedList* head;
    LinkedList* last;
    string m_word;

public:

    SortedList(string word){
        m_word = word;
    }

    void addNode(Node node){
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
                    if(m_word.find(cur->node.data) > m_word.find(node.data)){
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

    Node getFirst(){
        if(!empty){
            return head->node;
        }
        
    }

    void removeFirst(){
        if(!empty){
            delete head;
            head = head->next;
        }

        if(head == NULL){
            empty = true;
        }
    }

    void printList(){
        if(empty){
            return;
        }

        LinkedList* cur = head;

        while(cur != NULL){
            cout << cur->node.data << " " << cur->node.freq << endl;
            cur = cur->next;
        }
    }
};

int main()
{
    SortedList sortedList = SortedList("bdacefg");
    sortedList.addNode(Node('a',2));
    sortedList.addNode(Node('b',5));
    sortedList.addNode(Node('c',3));
    sortedList.addNode(Node('d',10));
    sortedList.removeFirst();
    sortedList.removeFirst();
    sortedList.removeFirst();
    sortedList.addNode(Node('e',10));
    sortedList.addNode(Node('f',2));
    sortedList.addNode(Node('g',4));
    sortedList.printList();
}