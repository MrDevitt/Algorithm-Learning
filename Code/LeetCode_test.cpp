#include<cstdio>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        int i = 0,j = 0;
        while (i < nums1.size() && j < nums2.size()){
            if (nums1[i] < nums2[j]){
                num.push_back(nums1[i++]);
            }
            else{
                num.push_back(nums2[j++]);
            }
        }
        if(i==nums1.size()){
            while(j<nums2.size())
                num.push_back(nums2[j++]);
        }
        else{
            while(i<nums1.size())
                num.push_back(nums1[i++]);
        }
        int n = num.size(); 
        if(n%2==0){
            return (double)(num[n / 2] + num[n / 2 - 1]);
        }
        else{
            return (double)num[(n - 1) / 2];
        }
    }
};

int main(){
    vector<int> n1, n2;
    n1.push_back(1);
    n1.push_back(2);
    n2.push_back(3);
    n2.push_back(4);
    Solution sol;
    double res = sol.findMedianSortedArrays(n1, n2);
    return 0;
}