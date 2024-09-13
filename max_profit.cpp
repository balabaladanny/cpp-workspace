#include <iostream>
using namespace std;
int arr[1000005];
long long int sum_arr[100005];
long long int big;
int main()
{
    int n;
    cin >> n;
    while(n--){
        int d;
        cin >> d;
        for(int i = 0 ; i < d ; i++){
            cin >> arr[i];
        }
        big = 0;
        for(int i = 0 ; i < d ; i++){
            if(arr[i+1] > arr[i]){
                big += arr[i+1]-arr[i];
            }
        }
        cout << big << '\n';
        
        
    }
}
