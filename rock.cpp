#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        vector<vector<int> > vec(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                cin>>vec[i][j];
                vec[i][j]+=vec[i-1][j]+vec[i][j-1]-vec[i-1][j-1];
            }
        int q;
        cin>>q;
        while(q--)
        {
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<vec[x2][y2]-vec[x1-1][y2]-vec[x2][y1-1]+vec[x1-1][y1-1]<<"\n";
        }
    }
    return 0;
}