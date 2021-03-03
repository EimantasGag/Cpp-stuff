#include <iostream>

using namespace std;

int GridTrav(int px,int py, int times, int ex, int ey)
{

    if(px == ex && py == ey){
        //cout << 1 << endl;
        return 1;
    }

    for(int n = 0;n<2;n++){
        if(n == 0){
            if(px+1 <= ex){
                times += GridTrav(px+1,py,0,ex,ey);
            }
        }
        else{
            if(py+1 <= ey){
                times += GridTrav(px,py+1,0,ex,ey);
            }
        }
    }

    return times;
}

int main()
{
    int px = 1; int py = 1; int times = 0; int ex = 69; int ey = 2;

    cout << GridTrav(px,py,times,ex,ey);

    return 0;
}
