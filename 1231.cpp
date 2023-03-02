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

int n,k;
int coin[52];
int amount[52];
int dp[52][1005];


ll answer(int pos, int remains){
        if(remains==0){return 1;}
        if(pos>n){return 0;}
        if(dp[pos][remains]!=-1){return dp[pos][remains];}

        int ans=0;
        for(int i=0;i<=amount[pos] &&remains-coin[pos]*i>=0 ;i++){
            ans=(ans+answer(pos+1,remains-coin[pos]*i ) )%mod;
        }
        dp[pos][remains]=ans;
        return dp[pos][remains];
}



void solve(int c){

    cin>>n>>k;
    for(int i=1;i<=n;i++){
            cin>>coin[i];
    }
    for(int i=1;i<=n;i++){
            cin>>amount[i];
    }

    memset(dp,-1,sizeof dp);

    int ans=answer(0,k);

    cout<<"Case "<<c<<": "<<ans<<"\n";
    //cerr<<cnt<<"\n";
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
