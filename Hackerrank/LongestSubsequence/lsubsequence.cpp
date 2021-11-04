#include <bits/stdc++.h>

using namespace std;

struct HashArr{

    private:

    struct LinkedList{
        char letter = ' ';
        int index = 0;
        LinkedList* next;
    };

    LinkedList arr[57]; //57 skaicius tinka tik jei raides yra nuo A-z

    int hash_func(char c){
        return (int)c - 65;
    }

    int listFind(LinkedList* cur, int min){
        if(cur->index > min){
            return cur->index;
        }
        else{
            if(cur->next != NULL){
                return listFind(cur->next, min);
            }
            else{
                return -1;
            }
        }
    }

    public:

    void add(char c, int index){
        int index = hash_func(c);

        if(arr[index].letter == ' '){
            arr[index].letter = c;
            arr[index].next = NULL;
            arr[index].index = index;
        }
        else{
            LinkedList* cur = &arr[index];

            while(true){
                if(cur->next == NULL){
                    break;
                }

                cur = cur->next;
            }

            LinkedList* ll;
            ll->letter = c;
            ll->index = index;
            ll->next = NULL;

            cur->next = ll;
        }
    }

    int get(char c, int min){
        int index = arr[hash_func(c)].index;

        if(index > min){
            return index;
        }
        else{
            if(arr[hash_func(c)].next != NULL){
                return listFind(arr[hash_func(c)].next, min);
            }
            else{
                return -1;
            }
        }
    }
};

struct CustomStack{
    vector<int> stack_arr;
    int top = -1;

    void push(int n){
        top++;

        if(stack_arr.size() > top){
            stack_arr[top] = n;
        }
        else{
            stack_arr.push_back(n);
        }
    }

    int getTop(){
        if(top >= 0){
            return stack_arr[top];
        }
        else{
            return -1;
        }
    }

    int pop(){
        return stack_arr[top--];
    }

    int size(){
        return top+1;
    }
};

int subsq(string s1, string s2){
    //1 - Hashing s2
    HashArr hashArr;
    for(int i = 0;i<s2.length();i++){
        hashArr.add(s2[i],i);
    }

    CustomStack main_stack;
    CustomStack second_stack;

    int top = -1;
    bool second = false;

    for(int i = 0;i<s1.length();i++){
        char letter = s1[i];
        int letter_index = hashArr.get(letter, top);

        if(letter_index == -1){
            continue;
        }

        if(main_stack.size() == 0){
            main_stack.push(letter_index);
            top = main_stack.getTop();
            continue;
        }
        else{
            top = main_stack.getTop();
        }

        if(letter_index > top){
            main_stack.push(letter_index);
        }
        else{
            int pop_count = 0;
            int popped_index = 0;
            second_stack = main_stack;

            while(second_stack.getTop() == -1 || second_stack.getTop() > letter_index){
                pop_count++;
                popped_index = second_stack.pop();
            }

            if(pop_count == 1){
                second_stack.push(letter_index);
                main_stack = second_stack;
            }
            else{
                //CIA SKAICIAVIMAI AR VERTA TRADINTI 

                if(popped_index - second_stack.getTop() > pop_count && s1.length() - i > pop_count){
                    second = true;
                    second_stack.push(letter_index);
                }
            }
        }
    }

    return main_stack.size();
}

int main(){
    cout << (int)'z' << (int)'A' << endl;
    string x = "";
    string y = "";
}