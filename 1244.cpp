#include<bits/stdc++.h>
using namespace std;

#define ll int
#define mod 10007
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define dim 4

ll T[dim][dim]={{1,1,1,1},
                        {1,0,0,0},
                        {0,1,0,1},
                        {0,1,1,0}};
ll S[dim][1]={{1},{1},{0},{0}};
ll I[dim][dim];

void multiply(ll A[dim][dim],ll B[dim][dim]){
    ll temp[dim][dim];

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            temp[i][j]=0;
            for(int k=0;k<dim;k++){
                temp[i][j]=(temp[i][j]+(A[i][k]*B[k][j])%mod)%mod;
            }
        }
    }
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            A[i][j]=temp[i][j];
        }
    }

}


void power(int k){

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            if(i==j)I[i][j]=1;
            else I[i][j]=0;
        }
    }

    T[0][0]=1;T[0][1]=1;T[0][2]=1;T[0][3]=1;
    T[1][0]=1;T[1][1]=0;T[1][2]=0;T[1][3]=0;
    T[2][0]=0;T[2][1]=1;T[2][2]=0;T[2][3]=1;
    T[3][0]=0;T[3][1]=1;T[3][2]=1;T[3][3]=0;

    while(k){
        if(k&1){multiply(I,T);k--;}
        else {multiply(T,T),k=k/2;}
    }



}



void solve(int c){
    cout<<"Case "<<c<<": ";
    int n;
    cin>>n;

    if(n==1){cout<<1<<"\n";return;}
    power(n-1);

//    for(int i=0;i<dim;i++){
//        for(int j=0;j<dim;j++){
//            cout<<I[i][j]<<" ";
//        }cout<<"\n";
//    }


    ll temp[dim][1];
    for(int i=0;i<dim;i++){
        for(int j=0;j<1;j++){
            temp[i][j]=0;
            for(int k=0;k<dim;k++){
                temp[i][j]=(temp[i][j]+(I[i][k]*S[k][j])%mod)%mod;
            }
        }
    }

    cout<<temp[0][0]<<"\n";

}


int main(){
Fast;
int t;
cin>>t;
for(int i=1;i<=t;i++){
    solve(i);
}

return 0;
}
