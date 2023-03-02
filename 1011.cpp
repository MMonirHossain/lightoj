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

int n;
int priority[16][16];
int dp[16][(1<<16)+2];
//int ans=0;


int answer(int pos, int bitmap){

        //if(__builtin_popcount(bitmap)==n){ans=max(ans,total);}


        //cerr<<"Pos & BIT: "<<pos<<" "<<bitmap<<"\n";
        if(pos>=n){return 0;}
        if(dp[pos][bitmap]!=-1){return dp[pos][bitmap];}

        for(int i=0;i<n;i++){
            if( bitmap & (1<<i) )continue;

            //cout<<priority[pos][i]<<" ";
            dp[pos][bitmap]=max(dp[pos][bitmap], answer(pos+1, bitmap|(1<<i) )+priority[pos][i] );
        }

        //cerr<<" RETURN "<<dp[pos][bitmap]<<"\n\n";
        return dp[pos][bitmap];
}



void solve(int c){

    cin>>n;
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>priority[j][i];
            }
    }
    memset(dp,-1,sizeof dp);

    int ans=answer(0,0);


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
