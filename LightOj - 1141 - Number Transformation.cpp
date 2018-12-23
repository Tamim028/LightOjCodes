#include<bits/stdc++.h>
using namespace std;

#define _FastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define MAXS (ll)1e17
typedef long long ll;

vector<int> v[1005];
int p[1005], psz, ans[1005];
bool mark[1005];

void pgen(){
    for(int i=4; i<=1001; i+=2){
        mark[i]=1;
    }
    psz=1;
    p[1]=2;
    for(int i=3; i<=1001; i++){
        if(mark[i]==0){
            p[++psz]=i;
            for(int k=i*i; k<=1001; k+=2*i){
                mark[k]=1;
            }
        }
    }

}

void pfact(){
//    for(int i=1; i<psz; i++){
//        cout<<p[i]<<endl;
//    }
    for(int i=2; i<=1000; i++){
        int n=i;
        for(int k=1; k<=psz && p[k]<i; k++){
            if(n%p[k]==0){
                v[i].push_back(p[k]);
                while(n%p[k]==0){
                    n/=p[k];
                }
            }
        }
    }
//    for(int i=2; i<=1000; i++){
//        for(int k=0; k<v[i].size(); k++){
//            cout<<"n: " << i << " "<<v[i][k]<<endl;
//        }
//    }
}

int solve(int n, int hi){
    int cnt[5005];
    for(int i=1; i<=5000; i++){
        cnt[i]=0;
    }
    //cout<<"Here"<<endl;
    for(int i=0; i<v[n].size(); i++){
        int nxt = n+v[n][i];
        cnt[nxt]++; //cnt[6]=1;
        //cout<< n <<" nxt: " << nxt<<endl;
    }
    for(int i=n+1; i<=hi; i++){
        if(cnt[i]>0){ //if coming here possible
            for(int k=0; k<v[i].size(); k++){
                int nxt=i+v[i][k]; //this number + prime facts
                //cout<< i <<" nxt: " << nxt<<endl;
                if(cnt[nxt]>0){
                    cnt[nxt] = min(cnt[nxt], cnt[i]+1);
                }
                else{
                    cnt[nxt] = cnt[i]+1;
                }
            }
        }
    }
    return cnt[hi];
}

int main()
{

    _FastIO;

    pgen();
    pfact();

    int tc,tcase=0,s,t;

    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &s, &t);
        if(s>t){
            printf("Case %d: -1\n", ++tcase);
            continue;
        }
        if(s==t){
            printf("Case %d: 0\n", ++tcase);
            continue;
        }
        //cout<<"Here"<<endl;
        int x=solve(s, t);
        if(x==0){
            printf("Case %d: -1\n", ++tcase);
        }
        else{
            printf("Case %d: %d\n", ++tcase, x);
        }
    }


    return 0;
}

