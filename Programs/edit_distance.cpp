#include<iostream>
#include<cstring>
using namespace std;

int edhelper(char* s1,char* s2,int m,int n,int** dp){
    if(m==0){
        return n;
    }
    if(n==0){
        return m;
    }
    if(dp[m][n]>-1){
        return dp[m][n];
    }
    int ans;
    if(s1[0]==s2[0]){
        ans=edhelper(s1+1,s2+1,m-1,n-1,dp);
    }else{
        int option1=1+edhelper(s1+1,s2,m-1,n,dp);
        int option2=1+edhelper(s1,s2+1,m,n-1,dp);
        int option3=1+edhelper(s1+1,s2+1,m-1,n-1,dp);
        ans=min(option1,min(option2,option3));
    }
    dp[m][n]=ans;
    return ans;
}

int editDistance(string s1, string s2){
    int m=s1.length();
    int n=s2.length();
    char c1[m+1];
    char c2[n+1];
    strcpy(c1, s1.c_str()); 
    strcpy(c2, s2.c_str()); 
    int ** dp=new int *[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    int ans=edhelper(c1,c2,m,n,dp);
    for(int i=0;i<=m;i++){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}

int main(){

  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  cout << editDistance(s1,s2) << endl;
}
