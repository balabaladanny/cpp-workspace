#include <iostream>
#include <algorithm>
using namespace std;
int n,q;
int a[100000];

int lower_bound(int *arr, int size, int target){
    int l = 0, r = size;
    while(l < r){
        int mid = (l+r)/2;
        if(arr[mid] >= target) r = mid;
        else l = mid+1;
    }
    return r;
}

int upper_bound(int *arr, int size, int target){
    int l = 0 , r = size;
    while(l < r){
        int mid = (l+r)/2;
        if(arr[mid] > target)r = mid;
        else l = mid+1;
    }
    return r;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << upper_bound(a,n,x) - lower_bound(a,n,x) << '\n';
    }
    return 0;
}