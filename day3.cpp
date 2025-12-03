#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main(){
    ifstream infile("aocinput.txt");

    string line;
    unsigned long long totalSum = 0;

    while(getline(infile, line)){
        string s;
        for(char c : line){
            if (c >= '0' && c <= '9') s.push_back(c);
        }

        if(s.size() < 2) continue; 

        int bestTwoDigit = 0;

        int maxDigitRight = -1;

        for(int i = static_cast<int>(s.size()) - 1; i >= 0; --i){
            int d = s[i] - '0';

            if(maxDigitRight != -1){
                int candidate = d * 10 + maxDigitRight;
                if(candidate > bestTwoDigit) bestTwoDigit = candidate;
            }

            if(d > maxDigitRight) maxDigitRight = d;
            
        }

        totalSum += static_cast<unsigned long long>(bestTwoDigit);
    }

    cout << totalSum << '\n';
    return 0;
}
