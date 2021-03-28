#include<cstdio>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        unordered_set<char> subs;
        int rp=0;
        int n=s.size();
        for(int lp=0;lp<n;lp++){
            if(lp!=0){
                subs.erase(lp+1);
            }
            while(rp<n&&!subs.count(s[rp])){
                subs.insert(s[rp++]);
            }
            res=max(res,rp-lp);
        }
        return res;
    }
};

int main(){
    string s = "pwwkew";
    Solution sol;
    sol.lengthOfLongestSubstring(s);
    return 0;
}