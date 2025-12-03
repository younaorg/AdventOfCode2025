#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std; 
string maxKDigits(const string &digits, int k){
    int n = static_cast<int>(digits.size());
    if(n <= k) return digits;  

    int toRemove = n - k;
    vector<char> st;
    st.reserve(n);

    for(char c : digits){
        while(!st.empty() && toRemove > 0 && st.back() < c){
            st.pop_back();
            --toRemove;
        }
        st.push_back(c);
    }

    while((int)st.size() > k) st.pop_back();
    
    return string(st.begin(), st.end());
}

int main(){
    ifstream infile("aocinput.txt");

    const int K = 12;
    string line;
    unsigned long long totalSum = 0;

    while(getline(infile, line)){
        string digits;
        for(char c : line){
            if(c >= '0' && c <= '9') digits.push_back(c);
        }
        if(digits.empty()) continue;

        string best = maxKDigits(digits, K);

        unsigned long long value = 0;
        for(char c : best) value = value * 10 + (c - '0');
        
        totalSum += value;
    }

    cout << totalSum << '\n';
    return 0;
}
