#include <iostream>
using namespace std;


int s[200005];

int binarysort(int x,int l,int r){
    int middle = (l+r)/2;
    if(s[middle] == x)return middle;
    else if(s[middle] < x) return binarysort(x,middle+1,r);
    else return binarysort(x,l,middle-1);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    int x;
    while(cin >> x){
        cout <<binarysort(x,0,n) <<"\n";
    }

}