#include <iostream>
#include <vector>

using namespace std;

struct Node{
        
    struct Path{
        int val;
        Node* node;

        Path(Node* anode, int aval = 1){
            node = anode;
            val = aval;
        }   
    };

    vector<Path> allPaths;

    public:

    int num;
    int shortest_path_val = -1;

    Node(int anum){
        num = anum;
    }

    void addPath(Node *node, int path_val = 1){
        allPaths.push_back(Path(node, path_val));
    }

    int getPathValue(int ind){
        return allPaths[ind].val;
    }

    int countPaths(){
        return allPaths.size();
    }

    Node* getPathNode(int ind){
        return allPaths[ind].node;
    }
};

struct Graph{

    struct PriorityQueue{

        struct LinkedList{
            Node* node;
            LinkedList* next;

            LinkedList(Node* anode){
                node = anode;
            }
        };

        bool empty = true;
        LinkedList* head;

        bool inQueue(Node* node){
            if(empty){
                return false;
            }

            LinkedList* cur = head;

            while(cur != NULL){
                if(cur->node == node){
                    return true;
                }

                cur = cur->next;
            }

            return false;
        }

        void printQueue(){
            LinkedList* cur = head;

            cout << "Current queue status: ";

            if(empty){
                cout << endl;
                return;
            }

            while(cur != NULL){
                cout << cur->node->shortest_path_val << " ";
                cur = cur->next;
            }

            cout << endl;
        }

        void addNode(Node* node){
            if(empty){
                head = new LinkedList(node);
                head->next = NULL;
                empty = false;
            }
            else{
                LinkedList* cur = head;
                LinkedList* prev;
                bool first = true;

                while(true){
                    if(cur->node->shortest_path_val >= node->shortest_path_val){
                        if(first){
                            LinkedList* new_head = new LinkedList(node);
                            new_head->next = head;
                            head = new_head;
                        }
                        else{
                            prev->next = new LinkedList(node);
                            prev->next->next = cur; 
                        }

                        break;
                    }

                    if(cur->next == NULL){
                        cur->next = new LinkedList(node);
                        cur->next->next = NULL;

                        break;
                    }

                    prev = cur;
                    first = false;
                    cur = cur->next;
                }
            }
        }

        bool isEmpty(){
            return empty;
        }

        Node* dequeue(){
            Node* return_node = head->node;
            head = head->next;

            if(head == NULL){
                empty = true;
            }

            return return_node;
        }

        void updateNode(Node* node){
            if(empty){
                return;
            }

            LinkedList* cur = head;
            LinkedList* prev;
            bool first = true;
            bool found = false;

            while(true){
                if(node == cur->node){
                    found = true;

                    if(first){
                        dequeue();
                    }
                    else{
                        prev->next = cur->next; 
                    }

                    break;
                }

                if(cur->next == NULL){
                    break;
                }

                first = false;
                prev = cur;
                cur = cur->next;
            }

            if(found){
                addNode(node);
            }
        }
    };

    vector<Node*> allNodes;

    void addNode(Node* node){
        allNodes.push_back(node);
    }

    void pairNodes(Node* node1, Node* node2, int path_val = 1){
        node1->addPath(node2, path_val);
        node2->addPath(node1, path_val);
    }

    void printNodes(){
        for(int i = 0;i<allNodes.size();i++){
            Node* node = allNodes[i];

            for(int x = 0;x<node->countPaths();x++){
                cout << node->num << " -> " << node->getPathNode(x)->num << endl;
            }
        }
    }

    PriorityQueue priority_queue;
    vector<Node*> visited_nodes;

    bool haveVisited(Node* node){
        for(int i = 0;i<visited_nodes.size();i++){
            if(visited_nodes[i] == node){
                return true;
            }
        }

        return false;
    }

    int findShortestPath(Node* start, Node* end, int range = 0){

        if(start == end){
            return range;
        }

        visited_nodes.push_back(start);

        //APIESKOME KAIMYNINIUS NODES

        for(int i = 0;i<start->countPaths();i++){
            Node* cur_node = start->getPathNode(i);
            
            //JEI KELIAS NUO DABARTINIO NODE IKI KAIMYNINIO GREITESNIS, JI PAKEICIAME

            if(cur_node->shortest_path_val > range + start->getPathValue(i) || cur_node->shortest_path_val == -1){
                cur_node->shortest_path_val = range + start->getPathValue(i);
                priority_queue.updateNode(cur_node);
                //update priority queue
            }

            //JEI NEAPLANKEME SITO KAIMYNINIO NODE PRIDEDAME JI I QUEUE

            if(!haveVisited(cur_node) && !priority_queue.inQueue(cur_node)){
                priority_queue.addNode(cur_node);
            }
        }

        //JEIGU QUEUE YRA TUSCIA SIUO MOMENTU REISKIA NERA KELIO PRIE END NODE

        if(!priority_queue.isEmpty()){
            priority_queue.printQueue();
            Node* next_node = priority_queue.dequeue();
            priority_queue.printQueue();

            return findShortestPath(next_node, end, next_node->shortest_path_val);
        }
        else{
            return -1;
        }
    }
};

int main(){
    Node node1 = Node(1);
    Node node2 = Node(2);
    Node node3 = Node(3);
    Node node4 = Node(4);
    Node node5 = Node(5);

    Graph graph;
    graph.addNode(&node1);
    graph.addNode(&node2);
    graph.addNode(&node3);
    graph.addNode(&node4);
    graph.addNode(&node5);

    graph.pairNodes(&node1, &node2, 9);
    graph.pairNodes(&node1, &node3, 1);

    graph.pairNodes(&node2, &node4, 2);
    graph.pairNodes(&node3, &node4, 5);

    cout << graph.findShortestPath(&node1, &node2);
}