#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    vector<string> res;
public:
    void generate(int l,int r,string s){
        if(l==0&&r==0){
            res.push_back(s);
            return;
        }
        if(l==r){
            generate(l-1,r,s+'(');
        }
        else{
            if(l!=0)generate(l-1,r,s+'(');
            generate(l,r-1,s+')');
        }
    }

    vector<string> generateParenthesis(int n) {
        string s="";
        generate(n,n,s);
        return res;
    }
};


int main(){
    vector<int> nums({-1, 0, 1, 2, -1, -4});
    string s = "([)]";
    int n = 4;
    Solution sol;
    sol.isValid(s);
    return 0;
}
