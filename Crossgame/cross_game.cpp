#include <iostream>
#include <vector>

using namespace std;

static const int CROSS_SIGN = 1;
static const int CIRCLE_SIGN = 0;
static const int EMPTY_SIGN = -1;
static const int BOARD_SIZE = 9;

struct BoardRes{
    private:

    int row1 = 0;
    int row2 = 0;
    int row3 = 0;
    int col1 = 0;
    int col2 = 0;
    int col3 = 0;
    int crossL = 0;
    int crossR = 0;
    bool endedGame = false;

    public:

    bool getEndedGame(){
        return endedGame;
    }

    void setRow1(int n){
        row1 = n;
        if(n == 3 || n == -3){endedGame = true;}
    }

    void setRow2(int n){
        row2 = n;
        if(n == 3 || n == -3){endedGame = true;}
    }

    void setRow3(int n){
        row3 = n;
        if(n == 3 || n == -3){endedGame = true;}
    }

    void setCol1(int n){
        col1 = n;
        if(n == 3 || n == -3){endedGame = true;}
    }

    void setCol2(int n){
        col2 = n;
        if(n == 3 || n == -3){endedGame = true;}
    }

    void setCol3(int n){
        col3 = n;
        if(n == 3 || n == -3){endedGame = true;}
    }

    void setCrossR(int n){
        crossR = n;
        if(n == 3 || n == -3){endedGame = true;}
    }

    void setCrossL(int n){
        crossL = n;
        if(n == 3 || n == -3){endedGame = true;}
    }

    int getRow1(){return row1;}
    int getRow2(){return row2;}
    int getRow3(){return row3;}
    int getCol1(){return col1;}
    int getCol2(){return col2;}
    int getCol3(){return col3;}
    int getCrossR(){return crossR;}
    int getCrossL(){return crossL;}
};

void copy(int* boardCopy, const int* board){
    for(int i = 0;i<BOARD_SIZE;i++){
        boardCopy[i] = board[i];
    }
}

void fillBoard(int* board){
    for(int i = 0;i<BOARD_SIZE;i++){
        board[i] = EMPTY_SIGN;
    }
}

void printBoard(const int* board){
    int d = 0;

    for(int i = 0;i<BOARD_SIZE;i++){
        d++;

        if(board[i] == CROSS_SIGN){
            cout << 'X';
        }
        else if(board[i] == CIRCLE_SIGN){
            cout << 'O';
        }
        else{
            cout << '-';
        }


        if(d == 3){
            cout << endl;
        }

        d = d % 3;
    }

    cout << endl;
}

void updateBoardRes(BoardRes& boardRes, const bool& crossTurn, const int& ind){
    int val;

    //CROSSES = +1
    //CIRCLES = -1

    if(crossTurn){
        val = 1;
    }
    else{
        val = -1;
    }

    if(ind == 0){
        boardRes.setCol1(boardRes.getCol1() + val);
        boardRes.setRow1(boardRes.getRow1() + val);
        boardRes.setCrossL(boardRes.getCrossL() + val);
    }
    else if(ind == 1){
        boardRes.setCol2(boardRes.getCol2() + val);
        boardRes.setRow1(boardRes.getRow1() + val);
    }
    else if(ind == 2){
        boardRes.setCol3(boardRes.getCol3() + val);
        boardRes.setRow1(boardRes.getRow1() + val);
        boardRes.setCrossR(boardRes.getCrossR() + val);
    }
    else if(ind == 3){
        boardRes.setCol1(boardRes.getCol1() + val);
        boardRes.setRow2(boardRes.getRow2() + val);
    }
    else if(ind == 4){
        boardRes.setCol2(boardRes.getCol2() + val);
        boardRes.setRow2(boardRes.getRow2() + val);
        boardRes.setCrossR(boardRes.getCrossR() + val);
        boardRes.setCrossL(boardRes.getCrossL() + val);
    }
    else if(ind == 5){
        boardRes.setCol3(boardRes.getCol3() + val);
        boardRes.setRow2(boardRes.getRow2() + val);
    }
    else if(ind == 6){
        boardRes.setCol1(boardRes.getCol1() + val);
        boardRes.setRow3(boardRes.getRow3() + val);
        boardRes.setCrossR(boardRes.getCrossR() + val);
    }
    else if(ind == 7){
        boardRes.setCol2(boardRes.getCol2() + val);
        boardRes.setRow3(boardRes.getRow3() + val);
    }
    else{
        boardRes.setCol3(boardRes.getCol3() + val);
        boardRes.setRow3(boardRes.getRow3() + val);
        boardRes.setCrossL(boardRes.getCrossL() + val);
    }
}

void rec(const int board[BOARD_SIZE], BoardRes boardRes, bool cross_turn = true, int empty_cells = 9){
    if(empty_cells == 0 || boardRes.getEndedGame()){
        printBoard(board);
        return;
    }

    int cur_sign;

    if(cross_turn){
        cur_sign = CROSS_SIGN;
    }
    else{
        cur_sign = CIRCLE_SIGN;
    }

    int boardCopy[BOARD_SIZE];
    copy(boardCopy, board);

    int seen_empty_cells = 0;

    for(int i = 0;i<BOARD_SIZE;i++){
        if(boardCopy[i] == EMPTY_SIGN){
            boardCopy[i] = cur_sign;
            seen_empty_cells++;

            //TODO: call updateBoardRes()

            if(seen_empty_cells == empty_cells){
                return rec(boardCopy, boardRes, !cross_turn, empty_cells-1);
            }
            else{
                rec(boardCopy, boardRes, !cross_turn, empty_cells-1);
            }

            //reset the move to place a sign elsewhere 
            boardCopy[i] = EMPTY_SIGN;
        }
    }
}

int main(){
    int board[BOARD_SIZE];
    BoardRes boardRes;
    fillBoard(board);

    rec(board, boardRes);
}