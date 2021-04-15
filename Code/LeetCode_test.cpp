#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
        int l = 0, r = nums.size() - 1, pre;
        if(nums[l]==target||nums[r]==target)
            return true;
        if(nums[l]<target){
            while(1){
                l++;
                if(nums[l]==target)
                    return true;
                if(nums[l]<nums[l-1])
                    return false;
            }
        }
        else if(target>nums[r])
            return false;
            else{
                r--;
                if(nums[r]==target)
                    return true;
                if(nums[r]>nums[r+1])
                    return false;
            }
    }
};
int main(){
    vector<int> k(3, 9);
    k.push_back(8);
    k.push_back(7);
    k[0] = -1;
    vector<int>::iterator it= lower_bound(k.begin(), k.end(), 9);
    printf("%d\n%d", abs(INT_MAX),abs(INT_MIN+1));
    printf("%d\n", accumulate(k.begin(),k.end(),0));
    return 0;
}
