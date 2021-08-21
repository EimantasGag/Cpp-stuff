#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isNumber(char chr){
    int n = (int)chr;
    return (n - 48 < 10 && n - 48 >= 0);
}

int toNumber(string str){
    int num = 0;
    int dup = pow(10, str.length() - 1);

    for(int i = 0;i<str.length();i++){
        num += ((int)str[i] - 48) * dup;
        dup /= 10;
    }

    return num;
}

struct Tile{
    private:

    int value = 0;

    public:  

    int tile_id;
    int col_id;
    int row_id;
    bool invincible;

    Tile(int atile_id, int acol_id, int arow_id, bool ainvincible = false){
        tile_id = atile_id; 
        col_id = acol_id;
        row_id = arow_id;
        invincible = ainvincible;
    }

    int getValue(){
        return value;
    }

    void setPrivateValue(int num){
        value = num;
    }
};

struct ColSumTile{
    private:

    int sum;
    int unfilled_children = 0;

    public:

    int id;
    int col;
    int row;
    vector<int> children_id;

    ColSumTile(int asum, int aid, int acol, int arow){
        sum = asum;
        id = aid;
        col = acol;
        row = arow;
    }

    void addChild(Tile tile){
        unfilled_children++;
        children_id.push_back(tile.tile_id);
    }

    int getUnfilledChildren(){
        return unfilled_children;
    }

    int getSum(){
        return sum;
    }

    void increasePrivateSum(int num){
        sum += num;
    }

    void decreasePrivateSum(int num){
        sum -= num;
    }

    void decreasePrivateUnfilledChildren(){
        unfilled_children--;
    }

    void increasePrivateUnfilledChildren(){
        unfilled_children++;
    }
};

struct RowSumTile{
    private:

    int sum;
    int unfilled_children = 0;

    public:

    int id;
    int col;
    int row;
    vector<int> children_id;

    RowSumTile(int asum, int aid, int acol, int arow){
        sum = asum;
        id = aid;
        col = acol;
        row = arow;
    }

    void addChild(Tile tile){
        unfilled_children++;
        children_id.push_back(tile.tile_id);
    }

    int getSum(){
        return sum;
    }

    void increasePrivateSum(int num){
        sum += num;
    }

    void decreasePrivateSum(int num){
        sum -= num;
    }

    int getUnfilledChildren(){
        return unfilled_children;
    }

    void decreasePrivateUnfilledChildren(){
        unfilled_children--;
    }

    void increasePrivateUnfilledChildren(){
        unfilled_children++;
    }
};

struct Grid{
    private:

    void decreaseColSumTileSum(int val, int ind){
        if(ind >= 0){
            colSumTiles[ind].decreasePrivateSum(val);
            if(colSumTiles[ind].getSum() == 0){
                unsolvedCols--;
            }
        }
    }

    void decreaseRowSumTileSum(int val, int ind){
        if(ind >= 0){
            rowSumTiles[ind].decreasePrivateSum(val);
            if(rowSumTiles[ind].getSum() == 0){
                unsolvedRows--;
            }
        }
    }

    public:
    vector<Tile> allTiles = {};
    vector<ColSumTile> colSumTiles = {};
    vector<RowSumTile> rowSumTiles = {}; 
    vector<vector<string>> printItems;

    int unsolvedCols = 0;
    int unsolvedRows = 0;

    void printResults(){
        int ind = 0;

        for(int i = 0;i<printItems.size();i++){
            for(int x = 0;x<printItems[i].size();x++){
                if(printItems[i][x] != "T"){
                    cout << printItems[i][x];
                }
                else{
                    cout << allTiles[ind].getValue();
                    ind++;
                }

                if(x != printItems[i].size() - 1){
                    cout << ",";
                }
            }   
            if(i != printItems.size() - 1){
                cout << endl;
            }
            
        }
    }

    void increaseRowSumTileSum(int val, int ind){
        if(ind >= 0){
            if(rowSumTiles[ind].getSum() == 0){
                unsolvedRows++;
            }
            rowSumTiles[ind].increasePrivateSum(val);
        }
    }

    void increaseColSumTileSum(int val, int ind){
        if(ind >= 0){
            if(colSumTiles[ind].getSum() == 0){
                unsolvedCols++;
            }
            colSumTiles[ind].increasePrivateSum(val);
        }
    }

    void addTile(Tile tile){
        if(tile.col_id >= 0){
            colSumTiles[tile.col_id].addChild(tile);
        }
        if(tile.row_id >= 0){
            rowSumTiles[tile.row_id].addChild(tile);
        }
        allTiles.push_back(tile);
    }

    void addColSum(ColSumTile csum){
        unsolvedCols++;
        colSumTiles.push_back(csum);
    }

    void addRowSum(RowSumTile rsum){
        unsolvedRows++;
        rowSumTiles.push_back(rsum);
    }

    void increaseColUnfilledChildren(int col_id){
        if(col_id >= 0){
            colSumTiles[col_id].increasePrivateUnfilledChildren();
        }
    }

    void increaseRowUnfilledChildren(int row_id){
        if(row_id >= 0){
            rowSumTiles[row_id].increasePrivateUnfilledChildren();
        }
    }

    int getColId(int tile_col){
        int the_id = -1;

        for(int i = colSumTiles.size()-1;i>=0;i--){
            ColSumTile colSumTile = colSumTiles[i];
            if(colSumTile.col == tile_col){
                for(int x = rowSumTiles.size()-1;x>=0;x--){
                    RowSumTile rowSumTile = rowSumTiles[x];
                    if(rowSumTile.col == tile_col && rowSumTile.row > colSumTile.row){
                        return -1;
                    }
                    else if(rowSumTile.row < colSumTile.row){
                        break;
                    }
                }
                return colSumTile.id;
            }
        }

        return the_id;
    }

    bool solved(){
        if(unsolvedCols == 0 && unsolvedRows == 0){
            printResults();
            // cout << "OMG WE MADE IT" << endl;
            // for(int i = 0;i<allTiles.size();i++){
            //     cout << allTiles[i].getValue() << endl;
            // }
        }
        return (unsolvedCols == 0 && unsolvedRows == 0);
    }

    void setTileValue(int tile_id, int val){
        Tile tile = allTiles[tile_id];

        if(tile.col_id >= 0){
            decreaseColSumTileSum(val, tile.col_id);
            colSumTiles[tile.col_id].decreasePrivateUnfilledChildren();
        }

        if(tile.row_id >= 0){
            decreaseRowSumTileSum(val, tile.row_id);
            rowSumTiles[tile.row_id].decreasePrivateUnfilledChildren();
        }   

        allTiles[tile_id].setPrivateValue(val);
    }

    bool isValuePossible(int col_id, int row_id, int val){
        if(col_id >= 0){
            ColSumTile colSumTile = colSumTiles[col_id];
            if(colSumTile.getSum() - val < colSumTile.getUnfilledChildren() - 1){
                return false;
            }
            else if(colSumTile.getSum() > val && colSumTile.getUnfilledChildren() == 1){
                return false;
            }
            else if(colSumTile.getSum() - val > 9 * (colSumTile.getUnfilledChildren() - 1)
            && colSumTile.getUnfilledChildren() != 0){
                return false;
            }

            for(int i = 0;i<colSumTile.children_id.size();i++){
                int id = colSumTile.children_id[i];
                if(allTiles[id].getValue() == val){
                    return false;
                }
            }
        }
        
        if(row_id >= 0){
            RowSumTile rowSumTile = rowSumTiles[row_id];
            if(rowSumTile.getSum() - val < rowSumTile.getUnfilledChildren() - 1){
                return false;
            }
            else if(rowSumTile.getSum() > val && rowSumTile.getUnfilledChildren() == 1){
                return false;
            }
            else if(rowSumTile.getSum() - val > 9 * (rowSumTile.getUnfilledChildren() - 1)
            && rowSumTile.getUnfilledChildren() != 0){
                return false;
            }

            for(int i = 0;i<rowSumTile.children_id.size();i++){
                int id = rowSumTile.children_id[i];
                if(allTiles[id].getValue() == val){
                    return false;
                }
            }
        }

        return true;
    }
};

string getStringRowSumValue(string line, int x){
    string num = "";
    num += '\\';
    num += line[x+1];

    if(isNumber(line[x+2])){
        num += line[x+2];
    }

    return num;
}

int getRowSumValue(string line, int x){
    string num = "";
    num += line[x+1];

    if(isNumber(line[x+2])){
        num += line[x+2];
        return toNumber(num);
    }

    return toNumber(num);
}

string getStringColSumValue(string line, int x){
    string num = "";

    if(isNumber(line[x-2])){
        num += line[x-2];
        num += line[x-1];
    }
    else{
        num += line[x-1];
    }

    num += '\\';

    return num;
}

int getColSumValue(string line, int x){
    string num = "";

    if(isNumber(line[x-2])){
        num += line[x-2];
        num += line[x-1];
        return toNumber(num);
    }
    else{
        num += line[x-1];
    }

    return toNumber(num);
}

bool solveIt(Grid grid, int tile_index){
    int col_sum = 999;
    int row_sum = 999;
    Tile tile = grid.allTiles[tile_index];
 
    if(tile.invincible){
        if(tile_index+1 != grid.allTiles.size()){
            return solveIt(grid, tile_index+1);
        }
        else{
            return grid.solved();
        }
    }

    if(tile.col_id >= 0){
        ColSumTile colSumTile = grid.colSumTiles[tile.col_id];
        col_sum = colSumTile.getSum();
        if(colSumTile.getUnfilledChildren() == 1){
            if(colSumTile.getSum() < 10 && colSumTile.getSum() > 0 &&
            grid.isValuePossible(tile.col_id, tile.row_id, colSumTile.getSum())){
                grid.setTileValue(tile.tile_id, colSumTile.getSum());

                if(tile_index+1 != grid.allTiles.size()){
                    return solveIt(grid, tile_index+1);
                }
                else{
                    return grid.solved();
                }
            }
            else{
                return false;
            }
        }
    }

    if(tile.row_id >= 0){
        RowSumTile rowSumTile = grid.rowSumTiles[tile.row_id];
        row_sum = rowSumTile.getSum();
        if(rowSumTile.getUnfilledChildren() == 1){
            if(rowSumTile.getSum() < 10 && rowSumTile.getSum() > 0 &&
            grid.isValuePossible(tile.col_id, tile.row_id, rowSumTile.getSum())){
                grid.setTileValue(tile.tile_id, rowSumTile.getSum());

                if(tile_index+1 != grid.allTiles.size()){
                    return solveIt(grid, tile_index+1);
                }
                else{
                    return grid.solved();
                }
            }
            else{
                return false;
            }
        }
    }


    //pries for loopa dar reikia patikrinti gal value jau yra zinoma -DONE
    //ir for loope nenaudoti skaiciu kurie jau buvo panaudoti toje col ar row
    //solved funkcija yra labai stipriai time insuficient (pakeist ja) -DONE

    for(int i = 1;i<10;i++){
        if(!grid.isValuePossible(tile.col_id, tile.row_id, i)){
            continue;
        }
        
        if(i <= col_sum && i <= row_sum){
            grid.setTileValue(tile.tile_id, i);

            if(tile_index+1 != grid.allTiles.size()){
                if(solveIt(grid, tile_index+1)){
                    return true;
                }
            }
            else{ //found the right grid can cout it here
                return grid.solved();
            }

            grid.increaseColSumTileSum(i, tile.col_id);
            grid.increaseRowSumTileSum(i, tile.row_id);
            grid.increaseColUnfilledChildren(tile.col_id);
            grid.increaseRowUnfilledChildren(tile.row_id);
        }
        else{
            break;
        }
    }

    return false;
}

int main()
{
    // Galimos klaidos:
    // Padariau prielaida kad sumos skaicius (/54) negali but didesnis nei dvizenklis

    // NEPAMIRSTI:
    // FreeTiles gali tureti col_id ir row_id = -1, kas gali sukelti erroru! 

    //Ka prideti:
    //solveIt() funkcijoje patikrinti ar skaicius kuri imamam jau nebuvo toje col ar row
    //cur_row_id metoda ir grid.getColId() nes sakykim gali buti | \23 |  X  |     | - ir tada free tile gauna 23 row id

    //fillAllKnown funkcijos nebutina kviesti kai tikrai zinome kad nera jokiu imanomu -> sekti duomenis kuriant invin tiles
    //ir suzinosim ar tie invin tiles padare kokia row ar col su unfilled_children = 1 (taip ja ir pagreitinti)
    //fillAllKnown funkcijos foor loopas turetu ieskoti tik tas col ir row kuriose buvo invincible tile
    //fillAllKnown funkcija apskritai tik laiko svaistymas turbut
 
    int height;
    int width;
    cin >> height >> width; cin.ignore();

    int row = 0;
    int col = 0;

    int col_id = 0;
    int row_id = 0;

    int tile_id = 0;

    int cur_row_id = -1;

    bool isEmpty = false;

    int invin_tiles = 0;

    Grid grid = Grid();

    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
        //cout << line << endl;

        grid.printItems.push_back({});

        for(int x = 0;x<line.length();x++){
            if(line[x] == '|'){
                if(isEmpty){ //cia pridedam FreeTile
                    grid.addTile(Tile(tile_id, grid.getColId(col), cur_row_id));
                    tile_id++;

                    grid.printItems[row].push_back("T");

                    // cout << "Added a free tile!" << endl;

                    // if(grid.getColId(col) >= 0){
                    //     cout << "Free tile Col sum: " << grid.colSumTiles[grid.getColId(col)].getSum() << endl;
                    // }
                    // else{
                    //     cout << "Free tile Col Sum does not exist!" << endl;
                    // }
                    // if(cur_row_id >= 0){
                    //     cout << "Free tile Row sum: " << grid.rowSumTiles[cur_row_id].getSum() << endl;
                    // }
                    // else{
                    //     cout << "Free tile Row sum does not exist!" << endl;
                    // }
                    
                }
                else{
                    isEmpty = true;
                }

                if(x != 0){
                    col++;
                }
            }
            else if(line[x] == '\\'){
                if(isNumber(line[x+1]) && isNumber(line[x-1])){ //cia row ir col sum numeris
                    ColSumTile colSum = ColSumTile(getColSumValue(line, x), col_id, col, row);
                    grid.addColSum(colSum);

                    RowSumTile rowSum = RowSumTile(getRowSumValue(line, x), row_id, col, row);
                    grid.addRowSum(rowSum);

                    cur_row_id = row_id;

                    string num = "";
                    num += line[x+1];
                    if(isNumber(line[x+2])){
                        num += line[x+2];
                    }

                    grid.printItems[row].push_back(getStringColSumValue(line, x) + num);

                    //cout << "Added a RowSumTile value: " << rowSum.getSum() << " and a ColSumTile value: " << colSum.getSum() << endl;

                    row_id++;
                    col_id++;
                }
                else if(isNumber(line[x+1])){ //cia row sum numeris
                    RowSumTile rowSum = RowSumTile(getRowSumValue(line, x), row_id, col, row);
                    grid.addRowSum(rowSum);

                    cur_row_id = row_id;

                    grid.printItems[row].push_back(getStringRowSumValue(line, x));

                    //cout << "Added a RowSumTile with sum value: " << rowSum.getSum() << endl;

                    row_id++;
                }
                else{ //cia col sum numeris
                    ColSumTile colSum = ColSumTile(getColSumValue(line, x), col_id, col, row);
                    grid.addColSum(colSum);

                    //cout << "Added a ColSumTile with sum value: " << colSum.getSum() << endl;

                    grid.printItems[row].push_back(getStringColSumValue(line, x));

                    cur_row_id = -1;
                    col_id++;
                }
            }
            else if(isNumber(line[x])){ //cia Invincible tile
                if(line[x-1] != '\\' && line[x+1] != '\\' && line[x+2] != '\\' && line[x-2] != '\\'){

                    //TODO: AR NEBUS PADARYTOS DVI INVINCIBLE TILES KAI SKAICIUS DVIZENKLIS!!!!????/
                    //LEL NERA KLAIDOS NES JIS TIESIOG NEGALI BUT DVIZENKLIS NUO 1-9 GALI TEBUT
    
                    string val = "";
                    val += line[x];

                    if(isNumber(line[x+1])){
                        val += line[x+1];
                    }

                    int intval = toNumber(val);

                    grid.addTile(Tile(tile_id, grid.getColId(col), cur_row_id, true));
                    grid.setTileValue(tile_id, intval);

                    tile_id++;

                    grid.printItems[row].push_back("T");

                    //cout << "Addded invincible Tile!" << endl;
                }
            }
            else if(line[x] == 'X'){
                cur_row_id = -1;
                grid.printItems[row].push_back("X");
            }

            if(line[x] != ' ' && line[x] != '|'){
                isEmpty = false;
            }
        }

        isEmpty = false;
        cur_row_id = -1;
        row++;
        col = 0;
    }

    //grid.fillKnown();
    
    // if(grid.solved()){
    //     cout << "Congrats solved a grid before even starting it!" << endl;
    // }
    // else{
    //     cout << "We were not able to solve whole grid" << endl;
    //     solveIt(grid, grid.allTiles[0], 0);
    // }

    solveIt(grid, 0);   
}

