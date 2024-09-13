#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    int n;
    set<int> s;
    string op;
    long long sum = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--){
        cin >> op;
        if(op == "insert"){
            int num;
            cin >> num;
            if(s.find(num) == s.end()){
                s.insert(num);
                sum += num;
            }
        }
        else if(op == "print"){
            if(s.empty())continue;
            auto it_begin = s.begin();
            for(auto it=s.begin();it != s.end();++it){
                cout << (it == it_begin? "":" ") << (*it);
            }
            cout << '\n';
        }
        else if(op == "min"){
            if(s.empty()) continue;
            cout << (*s.begin()) << '\n';
        }
        else if (op == "range_erase"){
            int l,r;
            cin >> l >> r;
            auto L = s.lower_bound(l), R = s.upper_bound(r);
            for(auto it = L; it!= R; ++it){
                    sum-=(*it);
            }
            s.erase(L,R);
        }
        else if(op == "sum")
            cout << sum << '\n';
    }
}
