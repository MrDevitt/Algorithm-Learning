#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Status
{
    ListNode *node;
    bool operator < (const Status & temp) const{
        return node->val > temp.node->val;//Ð¡¶Ñ¶¥
    }
};

class Solution {
public:
    priority_queue<Status> pq;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto node:lists){
            if(node){
                pq.push({node});
            }
        }
        ListNode res;
        ListNode *cur_ptr = &res;
        while(!pq.empty()){
            Status temp = pq.top();
            pq.pop();
            cur_ptr->next = temp.node;
            cur_ptr = cur_ptr->next;
            if(temp.node->next)
                pq.push({temp.node->next});
        }
        return res.next;
    }
};
int main(){
    pair<ListNode *, int> key;

}