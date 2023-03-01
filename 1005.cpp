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


ll n,k;

ll answer(ll r,ll c,ll k){
    if(k>r || k>c){return 0;}
    if(k==0LL){return 1;}
    if(r==1LL){return c;}
    return c*answer(r-1,c-1,k-1)+answer(r-1,c,k);
}



void solve(int c){

    cin>>n>>k;

    ll ans=answer(n,n,k);
    printf("Case %d: %lld\n",c,ans);

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
