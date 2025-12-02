#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool isInvalidId(long long x){
    string s = to_string(x);
    int len = static_cast<int>(s.size());

    for(int blockLen = 1; blockLen <= len / 2; ++blockLen){
        if(len % blockLen != 0) continue; 

        int repeats = len / blockLen;
        if(repeats < 2) continue;

        bool ok = true;
        for(int i = blockLen; i < len && ok; ++i){
            if(s[i] != s[i % blockLen]) ok = false;
        }
        if(ok) return true;
    }
    return false;
}

int main(){
    ifstream infile("aocinput.txt");

    string line;
    string all;
    while(getline(infile, line)){
        if(!all.empty()) all.push_back(','); 
        all += line;
    }

    unsigned long long sum = 0;

    stringstream ss(all);
    string token;

    while(getline(ss, token, ',')){
        if(token.empty()) continue;

        size_t dashPos = token.find('-');
        if(dashPos == string::npos) continue;
        

        long long start = stoll(token.substr(0, dashPos));
        long long end = stoll(token.substr(dashPos + 1));

        for(long long id = start; id <= end; ++id){
            if(isInvalidId(id)) sum += static_cast<unsigned long long>(id);
        }
    }

    cout << sum << '\n';
    return 0;
}
