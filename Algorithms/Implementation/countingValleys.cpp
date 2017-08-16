//@author: Varun Patel
//Counting Valleys
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int map;
    cin >> map;
    char terrain;
    int seaLevel=0;
    int valleyCount=0;
    int isBelowSeaLevel=-1;
    for(int i = 0; i < map; i++){
        cin >> terrain;
        if(terrain == 'U') {
            if (isBelowSeaLevel && seaLevel == -1){
                valleyCount++;
                isBelowSeaLevel = -1;
            }
            seaLevel++;
        } else {
            if(seaLevel == 0){
                isBelowSeaLevel = 1;
            }
            seaLevel--;
        }
    }
    cout << valleyCount ;
    return 0;
}
