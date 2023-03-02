#include<bits/stdc++.h>

using namespace std;

//#define test

#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define inf 1e18
#define mod 100000007
#define limit 100005
#define ceil(a,b) (ll)((a+b-1)/b)

string x,y,z;
int sx,sy,sz;
int dp[50][50][50];



int answer(int i,int j,int k){
    if(i>=sx || j>=sy || k>=sz){return 0;}
    if(dp[i][j][k]!=-1){return dp[i][j][k];}

    if(x[i]==y[j] && y[j]==z[k]){
        dp[i][j][k]=1+answer(i+1,j+1,k+1);
    }
    else{
        dp[i][j][k]=max(answer(i+1,j,k),answer(i,j+1,k));
        dp[i][j][k]=max(dp[i][j][k],answer(i,j,k+1));
    }

    return dp[i][j][k];

}



void solve(int c){
    cin>>x>>y>>z;
    sx=x.size();
    sy=y.size();
    sz=z.size();
    memset(dp,-1,sizeof dp);
    int ans=answer(0,0,0);
    cout<<"Case "<<c<<": "<<ans<<"\n";
}//end of8 solve()



int main(){
Fast;
int t=1;
cin>>t;
for(int i=1;i<=t;i++){
    solve(i);
}

return 0;
}
