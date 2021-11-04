#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int** _initialize(int size1, int size2){
    int** lookup = new int*[size1];
    for(int i = 0;i<size1;i++){
        lookup[i] = new int[size2];
    }

    for(int i = 0;i<size1;i++){
        for(int x = 0;x<size2;x++){
            lookup[i][x] = -1;
        }
    }

    return lookup;
}

int coin_change(int sum, const vector<int>& coins, int coins_size, int** lookup, int start_index = 0){
    if(sum == 0){
        return 1;
    }

    if(lookup[sum][start_index] != -1){
        return lookup[sum][start_index];
    }

    int count = 0;

    for(int i = start_index;i<coins_size;i++){
        int coin = coins[i];

        if(coin <= sum){
            if(lookup[sum-coin][start_index] != -1){
                count += lookup[sum-coin][start_index];
                start_index++;
                continue;
            }

            lookup[sum-coin][start_index] = coin_change(sum-coin,coins,coins_size, lookup, start_index);
            count += lookup[sum-coin][start_index];
        }

        start_index++;
    }

    lookup[sum][start_index] = count;

    return lookup[sum][start_index];
}

int coin_change3( const vector<int>& S, int m, int n )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table
    // is constructed in bottom up
    // manner using the base case 0
    // value case (n = 0)
    int table[n + 1][m];
     
    // Fill the entries for 0
    // value case (n = 0)
    for (i = 0; i < m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table entries
    // in bottom up manner
    for (i = 1; i < n + 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m - 1];
}

int main(){
    int sum = 9991;
    vector<int> coins = {1,2,3};
    int** lookup = _initialize(sum+1,coins.size());

    auto start = high_resolution_clock::now();
    cout << coin_change(sum, coins, coins.size(), lookup) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Duration: " << duration.count() << endl;

    start = high_resolution_clock::now();
    cout << coin_change3(coins, coins.size(), sum) << endl;
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);

    cout << "Duration: " << duration.count() << endl;
}