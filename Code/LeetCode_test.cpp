#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        bool sign=true;
        bool overflow=false;
        bool flag=false;//表示已经开始读数字或者符号
        long long res=0LL;
        long long m1 = (long long)INT_MAX;
        long long m2 = -(long long)INT_MIN;
        for(char c:s){
            if((c=='+'||c=='-')&&!flag){
                sign=c=='-'?false:true;
                flag=true;
                continue;
            }
            if(c!=' '&&(c<'0'||c>'9'))
                break;
            if(c==' '){
                if(flag) break;
                continue;
            }
            else{
                res=res*10LL+(c-'0');
                flag=true;
                res = sign? min(res, (long long)INT_MAX) : min(res, -(long long)INT_MIN);
            }
        }
        return sign?res:-res;
    }
};
int main(){
    string s = "words and 987" ;
    int n = 1534236469;
    Solution sol;
    //int res=sol.reverse(n);
   // cout<<sol.reverse(n);
    int k=sol.myAtoi(s);
    // printf("%d", std::stoi(s));
    cout << (long)INT_MAX << '\n'
         << -(long)INT_MIN << '\n'
         << (long long)INT_MAX + 1 << '\n'
         << -(long long)INT_MIN;
    return 0;
}