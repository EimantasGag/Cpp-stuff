#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int spin()
{
    int lucky_wheel[25] = {1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,5,5,5,5,10,10,20};

    int num = rand() % 25;

    return lucky_wheel[num];

}

void interaction()
{
    int money = 0;
    int bet = 0;

    int choosen_num = 0;

    int spin_num = 0;

    char skip;

    cout << "Iveskite pinigu skaiciu, kuri turite: "; cin >> money;
    cout << "Iveskite statoma pinigu kieki: "; cin >> bet;

    cout << "\n\n\n";

    while(true){
        cout << "Jusu balansas: " << money << endl;
        cout << "\n\n";
        cout << "Ar norite praleisti statyma? (T/N): "; cin >> skip;

        if(skip == 'N'){
            cout << "Iveskite skaiciu uz kuri statysite (1,3,5,10,20): "; cin >> choosen_num;
        }

        spin_num = spin();

        cout << "\n\n";
        cout << "Issuktas skaicius: " << spin_num << endl;

        if(skip == 'N'){
            money -= bet;

        if(spin_num == choosen_num){
            if(choosen_num == 1){
                money += bet*2;
            }
            else{
                money += bet*choosen_num;
            }
                cout << "Laimojote, jusu balansas: " << money;
            }
            else{
                cout << "Pralaimejote, jusu balansas: " << money;
            }
        }


        cout << "\n\n\n\n";

    }
}

int dif_count()
{
    int jackpot = 0;

    int arr_dif[100] = {};

    int d = 0;
    int sum = 0;

    int above_50 = 0;
    int above_80 = 0;

    int below_15 = 0;

    int num = 0;

    for(int i = 0;i<1000;i++){
        num = spin();
        if(num == 20){
            arr_dif[i-d] = arr_dif[i-d] + 1;
            if(i-d > 80){
                above_80++;
            }
            else if(i-d > 50){
                above_50++;
            }
            else if(i-d < 15){
                below_15++;
            }

            sum += (i-d);
            jackpot++;
            d = i;
        }
    }

    cout << "\nJackpots: " << jackpot << endl;
    cout << "Difference above 50: " << above_50 << endl;
    cout << "Difference above 80: " << above_80 << endl;
    cout << "Difference below 15: " << below_15 << endl;

    cout << "\n" << endl;

    for(int i = 0;i<100;i++){
        cout << "Diffrence " << i << ", " << arr_dif[i] << " times" << endl;
    }
}

void auto_spinner()
{
    int money = 7000;
    int bet = 70;

    int wait_time = 5;

    int spins = 1000;

    int havent_won_times = 5;


    int dif = 0;
    int num = 0;
    bool betting = false;
    int havent_won = 0;

    bool wait_for_jack = false;

    for(int i = 0;i<spins;i++){
        num = spin();

        cout << "Num: " << num << endl;
        cout << "Betting: " << betting << endl;
        cout << "Money: " << money << endl;
        cout << "Times havent won: " << havent_won << endl;
        cout << "Last 20, " << dif << " spins ago" << endl;

        if(betting){
            if(num == 20){
                money += bet*20;
                betting = false;
                dif = 0;
            }
            else{
                money -= bet;
                havent_won++;
                if(havent_won > havent_won_times){
                    betting = false;
                    wait_for_jack = true;
                    havent_won = 0;
                    dif = 0;
                }
            }
        }

        if(wait_for_jack){
            if(num == 20){
                wait_for_jack = false;
            }
        }
        else{
           if(num != 20){
                dif++;
            }
            else{
                dif = 0;
            }
        }

        if(dif == wait_time){
            betting = true;
        }
    }
}

int main()
{
    srand (time(NULL));

    dif_count();

    return 0;
}
