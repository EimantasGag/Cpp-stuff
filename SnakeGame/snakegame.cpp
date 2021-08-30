#include <iostream>
#include <Windows.h>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

enum Direction {TOP,RIGHT,LEFT,BOTTOM};

struct Snake{
    struct Body{
        int pos_x;
        int pos_y;
        Direction move_direction;

        Body(int x,int y, Direction dir){
            pos_x = x;
            pos_y = y;
            move_direction = dir;
        }

        void move(){
            if(move_direction == TOP){
                pos_y += 1;
            }
            else if(move_direction == RIGHT){
                pos_x += 3; 
            }
            else if(move_direction == BOTTOM){
                pos_y -= 1;
            }
            else{
                pos_x -= 3; 
            }
        }

        void change_direction(Direction dir){
            move_direction = dir;
        }
    };

    struct Queue{
        vector<Body*> queue;
        int first = 0;
        Direction direction;

        Queue(Direction dir){
            direction = dir;
        }

        void enqueue(Body* body){
            queue.push_back(body);
        }

        Body* dequeue(){
            first++;
            return queue[first-1];
        }

        bool isEmpty(){
            return first >= queue.size();
        }
    };

    int size = 1;
    vector<Body> body_parts = {};
    Direction move_direction = TOP;
    vector<Queue> change_dir_queues;

    Snake(){
        for(int i = 0;i<30;i++){
            Body* body = new Body(104,32-i,TOP);
            body_parts.push_back(*body);
        }
    }

    vector<vector<int>> getCords(){
        vector<vector<int>> cords;

        for(int i = 0;i<body_parts.size();i++){
            cords.push_back({body_parts[i].pos_x,body_parts[i].pos_y});
        }

        return cords;
    }

    void grow(){
        Body last_part = body_parts[body_parts.size()-1];
        int x,y;

        if(last_part.move_direction == TOP){
            y = last_part.pos_y-1;
            x = last_part.pos_x;
        }
        else if(last_part.move_direction == RIGHT){
            y = last_part.pos_y;
            x = last_part.pos_x-1;
        }
        else if(last_part.move_direction == BOTTOM){
            y = last_part.pos_y+1;
            x = last_part.pos_x;
        }
        else{
            y = last_part.pos_y;
            x = last_part.pos_x+1;
        }

        Body body = Body(x,y,last_part.move_direction);

        for(int i = 0;i<change_dir_queues.size();i++){
            change_dir_queues[i].enqueue(&body);
        }

        body_parts.push_back(body);
    }

    void move(){
        for(int i = 0;i<change_dir_queues.size();i++){
            change_dir_queues[i].dequeue()->change_direction(change_dir_queues[i].direction);
        }

        for(int i = 0;i<change_dir_queues.size();i++){//remove empty queues 
            if(change_dir_queues[i].isEmpty()){
                change_dir_queues.erase(change_dir_queues.begin());
            }
        }

        for(int i = 0;i<body_parts.size();i++){
            body_parts[i].move();
        }
    }

    void change_direction(Direction dir){
        move_direction = dir;
        Queue queue = Queue(dir);

        for(int i = 0;i<body_parts.size();i++){
            queue.enqueue(&body_parts[i]);
        }

        change_dir_queues.push_back(queue);
    }
};

struct Map{
    Snake* snake;
    const int SCREEN_MAX_WIDTH = 207;
    const int SCREEN_MAX_HEIGHT = 65;

    struct Apple{
        int x,y;

        Apple(int xx, int yy){
            x = xx;
            y = yy;
        }
    };

    Apple apple = Apple(rand() % SCREEN_MAX_WIDTH, rand() % SCREEN_MAX_HEIGHT);

    Map(Snake* arg){
        snake = arg;
    }

    void generateApple(){
        apple = Apple(rand() % SCREEN_MAX_WIDTH, rand() % SCREEN_MAX_HEIGHT);
    }

    bool appleEaten(vector<vector<int>> cords){
        ofstream myfile;
        myfile.open("gaidytu.txt");
        myfile << "apple cords: " << apple.x << " " << apple.y;
        myfile << "head cords: " << cords[0][0] << " " << cords[0][1];
        myfile << "2 body cords: " << cords[1][0] << " " << cords[1][1];

        if(apple.x == cords[0][0] && apple.y == cords[0][1]){
            return true;
        }
        else if(apple.x < cords[0][0] && apple.x > cords[1][0] && apple.y == cords[0][0]){
            return true;
        }
        else if(apple.x < cords[1][0] && apple.x > cords[0][0] && apple.y == cords[0][0]){
            return true;
        }
        else if(apple.y < cords[0][1] && apple.y > cords[1][1] && apple.x == cords[0][1]){
            return true;
        }
        else if(apple.y < cords[1][1] && apple.y > cords[0][1] && apple.x == cords[0][1]){
            return true;
        }

        return false;
    }

    string draw(){
        vector<vector<int>> cords = snake->getCords();
        bool is_snake = false;
        string output = "";

        if(appleEaten(cords)){
            snake->grow();
            generateApple();
        }

        for(int row = SCREEN_MAX_HEIGHT;row>0;row--){
            for(int col = 0;col<SCREEN_MAX_WIDTH;col++){
                is_snake = false;

                for(int i = 0;i<cords.size();i++){ 
                    if(cords[i][0] == col && cords[i][1] == row){
                        output += '#';
                        is_snake = true;
                        break;
                    }
                }
                if(!is_snake){
                    if(row == apple.y && col == apple.x){
                        output += 'O';
                    }
                    else{
                        output += ' ';
                    }
                }   
            }
        }

        return output;
    }
};

int main(){
    SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
    // HWND console = GetConsoleWindow();
    // RECT r;
    // GetWindowRect(console, &r); 
    // MoveWindow(console, r.left, r.top, 800, 800, TRUE);

    srand (time(NULL));

    auto start = high_resolution_clock::now();

    Snake snake = Snake();
    Map map = Map(&snake);
    Direction cur_dir = TOP;
    bool can_change = true;

    while(1){ //game loopas
        auto cur = high_resolution_clock::now(); 

        if(can_change){
            can_change = false;

            if(GetKeyState('W') & 0x8000){
                if(cur_dir != TOP && cur_dir != BOTTOM){
                    cur_dir = TOP;
                    snake.change_direction(TOP);
                }
            }
            else if(GetKeyState('D') & 0x8000){
                if(cur_dir != RIGHT && cur_dir != LEFT){
                    cur_dir = RIGHT;
                    snake.change_direction(RIGHT);
                }
            }
            else if(GetKeyState('S') & 0x8000){
                if(cur_dir != BOTTOM && cur_dir != TOP){
                    cur_dir = BOTTOM;
                    snake.change_direction(BOTTOM);
                }
            }
            else if(GetKeyState('A') & 0x8000){
                if(cur_dir != LEFT && cur_dir != RIGHT){
                    cur_dir = LEFT;
                    snake.change_direction(LEFT);
                }
            }
        }

        if(duration_cast<microseconds>(cur - start).count() > 100000){
            start = high_resolution_clock::now();

            snake.move();
            can_change = true;

            system("CLS");

            cout << map.draw();
        }
    }
}