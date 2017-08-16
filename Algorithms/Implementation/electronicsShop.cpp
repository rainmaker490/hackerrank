//@author: Varun Patel
//Electronics Shop
#include <bits/stdc++.h>
#include <set>

using namespace std;

int getMoneySpent(set < int > keyboards, set < int > drives, int s){
    int maxMoneySpent = -1;
    for(set<int>::iterator k_it = keyboards.end(); k_it != keyboards.begin();){
        --k_it;
        for(set<int>::iterator d_it = drives.end(); d_it != drives.begin();){
            --d_it;
            int moneySpent = *d_it + *k_it;
            if(moneySpent > maxMoneySpent && moneySpent <= s){
                maxMoneySpent = moneySpent;
            }
        }
    }
    return maxMoneySpent == 0 ? -1 : maxMoneySpent;
}

int main() {
    int s;
    int n;
    int m;
    cin >> s >> n >> m;
    set <int> keyboards;
    int keyboard;
    for(int keyboards_i = 0; keyboards_i < n; keyboards_i++){
        cin >> keyboard;
        //printf("%d\n",keyboard);
        keyboards.insert(keyboard);
    }
    set <int> drives;
    int drive;
    for(int drives_i = 0; drives_i < m; drives_i++){
        cin >> drive;
        //printf("%d\n",drive);
        drives.insert(drive);
    }
    //  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
    int moneySpent = getMoneySpent(keyboards, drives, s);
    cout << moneySpent << endl;
    return 0;
}
