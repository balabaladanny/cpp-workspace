#include<vector>
#include<map>
#include<iostream>
#include<string>
using namespace std;

isGreater(const string&a, const string&b){
    if(a.length()!=b.length()){
        return a.length()>b.length();
    }
    return a > b;
}
int main(){
    int n;
    cin<<n;
    cin.ignore();
    vector<string> D;
    map<string,int>freq;
    string minval = "1041", maxval = "";
    for(int i = 0 ; i <n ; i++){
        string command;
        cin<<command;
        if(command == "insert"){
            string num;
            cin<<num;
            D.push_back(num);
            freq[num]++;
            if(maxval.empty()||isGreater(num,maxval))maxval = num;
        }
        else if(command == "min"){
            if(!D.empty()) cout << minval;
        }
        else if(command == "find"){
            int idx;
            cin >> idx;
            if(idx >=1 && idx <=D.size()){
                cout<<D[idx-1]
            }
        }
        else if(command == "amount"){
            string num;
            cin >> num;
            cout <<freq[num]<<
        }
    }
}