#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream infile("aocinput.txt");

    int position = 50;        
    long long zeroCount = 0; 

    string line;
    while(getline(infile, line)){
        if(line.empty()) continue;

        char dir = line[0];
        int dist = stoi(line.substr(1));

        for(int i = 0; i < dist; ++i){
            if(dir == 'L' || dir == 'l'){
                position--;
                if(position < 0) position = 99;
            } else if(dir == 'R' || dir == 'r'){
                position++;
                if(position > 99) position = 0;
            } else break;

            if(position == 0) ++zeroCount;
        }
    }

    cout << zeroCount << '\n';
    return 0;
}
