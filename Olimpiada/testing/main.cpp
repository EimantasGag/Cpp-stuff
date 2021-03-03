#include <iostream>
#include <cmath>

using namespace std;

int luno()
{
    string digit;
    cout << "Type in identification code: "; cin >> digit;

    int sum = 0;

    for(int i = 0;i<digit.length();i++){
        if(i % 2 != 0){
            if((int(digit[i])-48)*2 < 10){
                sum += (int(digit[i])-48)*2;
            }
            else{
                sum += 1 + ((int(digit[i])-48)*2)%10;
            }
        }
        else{
            sum += int(digit[i])-48;
        }

    }

    cout << "suma: " << sum << endl;
}

int pointer_func(int *t)
{
    *t += 1;
    *t++; //su pointeriai neveikia t++, iseujus is funkcijos t nepadideja!!!
    cout << t << endl;
    return 0;
}

int char_to_int()
{
    char digit;
    int n = 0;
    int res = 0;

    string all_modes = "ULP";
    int mode_num = 0;
    char mode = 'U';

    string txt = "";

    string punk = "!?,.s;\"\'";

    digit = cin.get();
    n = digit-'0';

    while(true){
        digit = cin.get();

        if(digit == ',' || digit == 10){
            if(mode == 'U' || mode == 'L'){
                res = n%27;
            }
            else{
                res = n%9;
            }

            if(res == 0){
                mode_num++;
                if(mode_num == 3){
                    mode_num = 0;
                }
                mode = all_modes[mode_num];
            }
            else if(mode == 'U' || mode == 'L'){
                if(mode == 'U'){
                    txt += char(64+res);
                }
                else{
                    txt += char(96+res);
                }
            }
            else{
                if(res != 5){
                    txt += punk[res-1];
                }
                else{
                    txt += ' ';
                }
            }

            if(digit == 10){
                break;
            }

            n = 0;
        }
        else{
            n = n * 10 + (digit-'0');
        }

    }
    cout << txt << endl;
}

int printing_shapes()
{
    string line = "########";
    string space = "";

    int l_size = 8;

    int times = 0;

    for(int i = 0;i<4;i++){
        cout << space;

        for(int x = 0;x<l_size;x++){
            cout << "#";
        }

        cout << "\n";

        space += " ";
        l_size -= 2;
    }

    cout << "\n";

    l_size = 2;
    times = 3;

    bool start = true;

    for(int i = 0;i<8;i++){

        for(int x = 0;x<times;x++){
            cout << " ";
        }
        for(int x = 0;x<l_size;x++){
            cout << "#";
        }

        cout << "\n";

        if(start){
           l_size += 2;
            times--;
        }
        else{
            l_size -= 2;
            times ++;
        }

        if(times == -1){
            start = false;
            times = 0;
            l_size -= 2;
        }
    }

    cout << "\n";

    int space_count = 0;
    l_size = 1;
    times = 0;

    start = true;

    for(int i = 0;i<8;i++){
        space_count = (14-l_size*2)-times*2;
        for(int x = 0;x<times;x++){
            cout << " ";
        }
        for(int x = 0;x<l_size;x++){
            cout << "#";
        }
        for(int x = 0;x<space_count;x++){
            cout << " ";
        }
        for(int x = 0;x<l_size;x++){
            cout << "#";
        }

        if(!start){
            l_size--;
            times--;
        }
        if(space_count == 0){
            start = false;
        }
        if(start){
            l_size++;
            times++;
        }


        cout << "\n";
    }

    return 0;
}

string to_binary(int num)
{
    string bin = "";
    while(num != 0){
        if(num%2 == 0){
            bin += "0";
        }
        else{
            bin += "1";
        }
        num = num/2;
    }

    string res = "";

    for(int i = bin.length()-1;i>=0;i--){
        res += bin[i];
    }

    return res;
}

string factorial()
{
    string inp;

    cin >> inp;

    string suma = "";
    int num_mup = 0;
    int remem = 0;

    string num1 = "";
    string num2 = "";

    for(int i = 1;i<inp.length();i++){

        int times = 1;
        int mem_i = i;

        if(i == 1){
            num1 += char(i + '0');
        }

        while(true){
            if(mem_i/10>0){
                times++;
                mem_i = mem_i/10;
            }
            else{
                break;
            }
        }

        for(int x = 0;x<times;x++){
            if(x == mem_i-1){
                if(times == 1){
                    num2 += char(i + '0');
                }
                else{
                    num2 += char(i%10 + '0');
                }
            }
            else{
                num2 += i/pow(10,times);
            }

            times--;
        }


        for(int x = 0;x<num1.length();x++){
            for(int n = 0;n<num2.length();n++){
                num_mup = int(num1[x])*int(num2[n]);
                if(num_mup > 9){
                    if(num_mup/10+remem > 9){
                        suma[n*x-1] = suma[n*x-1]+1;
                        suma += char((num_mup/10+remem/10) + '0');
                        remem = num_mup/10+remem%10;
                    }
                    else{
                        suma += char((num_mup/10+remem) + '0');
                        remem = 0;
                    }

                }
                else{
                    if(num_mup + remem > 9){
                        suma[n*x-1] = suma[n*x-1]+1;
                        suma += char(((num_mup + remem)/10) + '0');
                        remem = num_mup/10+remem%10;
                    }
                    else{
                        suma += char((num_mup + remem) + '0');
                        remem = 0;
                    }
                }
            }
        }
    }

    //inp += char(2 + '0');

    return suma;
}

string int_to_string(int num) //limituotas int ilgis
{
    string res = "";
    int n = num;

    int times = 1;

    while(true){
        if(n/10>0){
            times++;
            n = n/10;
        }
        else{
            break;
        }
    }

    int power = times-1;

    for(int x = 0;x<times;x++){
        if(x == times-1){
            if(times == 1){
                res += char(num + '0');
            }
            else{
                res += char(num%10 + '0');
            }
        }
        else{
            res += char(num/pow(10,power) + '0');
            cout << "res+= " << int(num/pow(10,power)) << endl;
            if(power != 1 && num - pow(10,power) > 0){
                num -= pow(10,power)*int(num/pow(10,power));
            }

        }

        cout << "res: " << res << endl;

        power--;
    }

    return res;
}

int delete_arr()
{
    int* arr = new int[10];

    for(int i = 0;i<10;i++){
        arr[i] = i+1;
    }

    std::fill(std::begin(0), std::end(arr),0);

    for(int i = 0;i<10;i++){
       //cout << arr[i] << endl;
    }

    return 0;
}

int main()
{
    int t = 1254618785;

    string l[] = {"264","1188","132"};

    delete_arr();

    return 0;
}


