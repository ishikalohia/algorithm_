#include <iostream>
#include<stack>
#include<cstring>
using namespace std;

bool checkBalanced(string exp) {
    stack<int>s;
    int elseif=0;
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='{'||exp[i]=='('||exp[i]=='['){
            s.push(exp[i]);
        }else if(exp[i]=='}'||exp[i]==')'||exp[i]==']'){
            elseif=1;
            if(s.empty()){
                return false;
            }else if(exp[i]==')'&&s.top()=='('||exp[i]=='}'&&s.top()=='{'||exp[i]==']'&&s.top()=='['){
                s.pop();
            }else{
                return false;
            }
        }
    }
    if(elseif==0){
    return false;}
    if(s.size()==0){
        return true;
    }else{
        return false;
    }
}

int main() 
{
    string input;
    cin >> input;
    if(checkBalanced(input)){
    cout<<"true";
    }else{
    cout<<"false";
    }
}
