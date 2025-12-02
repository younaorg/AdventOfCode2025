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
        string numPart = line.substr(1);
        int dist = stoi(numPart); 
        dist %= 100;

        if(dir == 'L' || dir == 'l') {
            position = position - dist;
            position %= 100;
            if(position < 0) position += 100;
        } else if(dir == 'R' || dir == 'r') {
            position = (position + dist) % 100;
        } else continue;

        if(position == 0) ++zeroCount;
    }
    cout << zeroCount << '\n';

    return 0;
}
