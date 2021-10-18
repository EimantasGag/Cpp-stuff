#include <bits/stdc++.h>

using namespace std;

struct LinkedList{
    string phone_number;
    LinkedList* next;

    LinkedList(){
        next = NULL;
    }

    LinkedList(string number){
        phone_number = number;
        next = NULL;
    }
};

int hash_func(string n){
    int index = 0;
    int dup = 1;

    for(int i = n.length()-1;i>4;i--){
        index += dup * (int(n[i]) - '0');
        dup *= 10;
    }

    return index;
}

void addToArr(string number, LinkedList all_numbers[10000]){
    int hash_num = hash_func(number);

    if(all_numbers[hash_num].next == NULL){
        all_numbers[hash_num] = LinkedList(number);
    }
    else{
        LinkedList* cur = &all_numbers[hash_num];
        LinkedList* prev;

        while(true){
            if(cur->next == NULL){
                cur->phone_number = number;
                cur->next = NULL;

                prev->next = cur;

                break;
            }

            prev = cur;
            cur = cur->next;
        }
    }
}

bool inList(string number, LinkedList* cur){
    if(number == cur->phone_number){
        return true;
    }
    else if(!cur->next != NULL){
        return inList(number, cur->next);
    }

    return false;
}

bool inArr(string number, LinkedList all_numbers[10000]){
    int hash_num = hash_func(number);

    if(all_numbers[hash_num].phone_number == number){
        return true;
    }
    else if(all_numbers[hash_num].next != NULL){
        return inList(number, all_numbers[hash_num].next);
    }

    return false;
}

int main(){
    srand (time(NULL));

    LinkedList all_numbers[10000];
    string number = "+370";

    for(int i = 0;i<10000;i++){
        for(int x = 0;x<5;x++){
            int rand_num = rand() % 10;
            number += to_string(rand_num);
        }

        cout << number << endl;

        addToArr(number, all_numbers);

        number = "+370";
    }

    string num;
    cin >> num;
    cout << "Number is in array: " << inArr(num, all_numbers) << endl;
}