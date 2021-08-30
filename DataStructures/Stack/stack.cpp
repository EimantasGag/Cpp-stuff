#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Tag{
    string name;
    map<string, string> attributes;
    vector<Tag> children;
    
    Tag(string aname){
        name = aname;
    }
    
    void addChild(Tag tag){
        children.push_back(tag);
    }
    
    Tag getChild(string name){
        for(int i = 0;i<children.size();i++){
            if(children[i].name == name){
                return children[i];
            }
        }
        
        throw exception();
    }
    
    string getAttribute(string name){
        return attributes[name];
    }
    
    void addAttribute(string name, string value){
        attributes[name] = value;
    }
};

struct Stack{
    vector<Tag*> parents;
    int top = -1;

    bool isEmpty(){ 
        return (top == -1);
    }

    void push(Tag* parent){
        top++;
        if(parents.size() > top){
            parents[top] = parent;
        }
        else{
            parents.push_back(parent);
        }
    }

    Tag* peek(){
        return parents[top];
    }

    void pop(){
        if(!isEmpty()){
            top--;
        }
    }
};

int main(){
    Stack stack = Stack();
    Tag tag1 = Tag("tag1");
    Tag tag2 = Tag("tag2");
    Tag tag3 = Tag("tag3");
    Tag tag4 = Tag("tag4");

    stack.push(&tag1);
    stack.push(&tag2);
    stack.pop();
    stack.push(&tag3);
    stack.pop();
    stack.pop();
    stack.push(&tag4);
}