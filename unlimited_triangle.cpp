#include <iostream>
#include<cstring>

using namespace std;
int T,A,B,C,D;
long long c[100005];
long long sum[50005];
void reset()
{
    memset(c, 0, sizeof(c));
    memset(sum, 0, sizeof(sum));
}
int main()
{
    cin>>T;
    while(T--)
    {
        long long ans=0;
        reset();
        cin>>A>>B>>C>>D;
        for(int x=A;x<=B;x++)
        {
            c[x+B]++;
            c[x+C+1]--;
        }
        for(int i=A+B;i<=(B+C+1);i++)
        {
            c[i]+=c[i-1];
        }
        for(int i=B+C;i>C-1;i--)
        {
            sum[i]=sum[i+1]+c[i];
        }
        for(int i=C;i<=D;i++)
            ans+=sum[i+1];

        cout<<ans<<endl;
    }
    return 0;
}
