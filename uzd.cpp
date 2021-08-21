#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
    vector<int> tags_indexes;
    int top = -1;

    bool isEmpty(){ 
        return (top == -1);
    }

    void push(int tag_index){
        top++;
        if(tags_indexes.size() > top){
            tags_indexes[top] = tag_index;
        }
        else{
            tags_indexes.push_back(tag_index);
        }
        
    }

    int peek(){
        return tags_indexes[top];
    }

    void pop(){
        if(!isEmpty()){
            top--;
        }
    }
};

Tag findTag(vector<Tag> allTags, string name){
    for(int i = 0;i<allTags.size();i++){
        if(allTags[i].name == name){
            return allTags[i];
        }
    }
    throw exception();
}

int main() {
    int code_lines_num, queries_lines_num;
    vector<Tag> allTags;
    Stack parent_stack = Stack();

    cin >> code_lines_num >> queries_lines_num;
    cin.ignore();

    for(int i = 0;i<code_lines_num;i++){
        string line;
        
        getline(cin, line);

        for(int x = 0;x<line.length();x++){
            char chr = line[x];

            if(chr == '<' && line[x+1] != '/'){ //pridedi Tag ir gauni jo varda
                string name = "";
                int ind = x+1;
                
                while(true){
                    if(line[ind] == ' ' || line[ind] == '>'){
                        break;
                    }
                    name += line[ind];
                    
                    ind++;
                }
                
                //cout << "name: " << name << endl;
                Tag tag = Tag(name);
                
                if(line[ind] == ' '){
                    string att_name = "";
                    string att_value = "";
                    bool isValue = false;
                    ind++;
                    
                    while(line[ind] != '>'){
                        if(line[ind] == '>'){
                            tag.addAttribute(att_name, att_value);
                            break;
                        }
                        else if(line[ind] != '=' && line[ind] != ' '){
                            if(!isValue){
                                att_name += line[ind];
                            }
                            else{
                                if(line[ind] == '"'){
                                    if(line[ind+1] == '>' || line[ind+1] == ' '){
                                        tag.addAttribute(att_name, att_value);
                                        att_name = "";
                                        att_value = "";

                                        isValue = false;
                                    }
                                }
                                else{
                                    att_value += line[ind];
                                }
                            }
                        }
                        else if(line[ind] == '='){
                            isValue = true;
                        }  
                        ind++;
                    }

                    if(!parent_stack.isEmpty()){
                        //cout << "Adding child to parent: " << (*parent_stack.peek()).name << endl;
                        //cout << "Childs name: " << tag.name << endl;
                        allTags[parent_stack.peek()].addChild(tag);
                    }

                    allTags.push_back(tag);
                    parent_stack.push(allTags.size()-1);
                    break;
                }
                else{
                    if(!parent_stack.isEmpty()){
                        //cout << "Adding child to parent: " << (*parent_stack.peek()).name << endl;
                        allTags[parent_stack.peek()].addChild(tag);
                    }

                    allTags.push_back(tag);
                    parent_stack.push(allTags.size()-1);
                    break;
                }
            }
            else if(line[x+1] == '/'){
                parent_stack.pop();
            }
        }
    }

    //cout << "vardelis1: " << allTags[0].children[0].name << endl;
    //cout << "vardelis2: " << allTags[0].children[1].name << endl;

    for(int i = 0;i<queries_lines_num;i++){
        string line;
        getline(cin, line);
   
        Tag cur_tag = Tag("");
        string text = "";

        bool firstTime = true;

        for(int x = 0;x<line.length();x++){
            if(line[x] != '.' && line[x] != '~'){
                text += line[x];
            }
            else{
                if(!firstTime){
                    try{
                        cur_tag = cur_tag.getChild(text);
                    }
                    catch(exception e){
                        //cout << "Child with name" << text << " does not exist!" << endl;
                        break;
                    }
                }
                else{
                    firstTime = false;
                    //cout << "Searching for tag with name: " << text << endl;
                    try{
                        cur_tag = findTag(allTags, text);
                    }
                    catch(exception e){
                        //cout << "Tag with name: " << text << " does not exist!" << endl;
                        break;
                    }
                }
                
                text = "";
            }

            if(x == line.length()-1){
                if(cur_tag.getAttribute(text) == ""){
                    cout << "Not Found!" << endl;
                }
                else{
                    cout << cur_tag.getAttribute(text) << endl;
                }
            }
        }
    }
 
    return 0;
}
