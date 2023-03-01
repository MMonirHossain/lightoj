#include<bits/stdc++.h>

using namespace std;

//#define test

#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define inf 1e18
#define mod 1000000007
#define limit 100005
#define ceil(a,b) (ll)((a+b-1)/b)


int dp[25][3];
int arr[25][3];
int cnt=0;

int n;
int answer(int pos, int color){

        if(pos==n){return arr[pos][color];}
        if(dp[pos][color]!=-1){return dp[pos][color];}
                cnt++;
        int a,b;
        if(color==0){a=1;b=2;}
        else if(color==1){a=0;b=2;}
        else if(color==2){a=0;b=1;}

        return dp[pos][color]=min(answer(pos+1,a)+arr[pos][color],answer(pos+1,b)+arr[pos][color]);

}



void solve(int c){

    cin>>n;
    for(int i=1;i<=n;i++){
            dp[i][0]=dp[i][1]=dp[i][2]=-1;
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
    }

    int ans=min(answer(1,0),answer(1,1));
    ans=min(ans,answer(1,2));

    cout<<"Case "<<c<<": "<<ans<<"\n";
    //cerr<<cnt<<"\n";
}//end of8 solve()



int main(){
Fast;
int t=1;
cin>>t;
for(int i=1;i<=t;i++){
        cnt=0;
    solve(i);
}

return 0;
}
