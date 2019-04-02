#include<iostream>
#include<vector>
#include<sstream>
#include<deque>
#include<algorithm>
#include<cmath>
#include<list>
#include<stack>
#include<string>
using namespace  std;
struct  ListNode{
    int val;
    ListNode *next;
    ListNode (int x):val(x),next(nullptr){}
};
ListNode *createList(vector<int>&nums){
    ListNode *dummy=new ListNode(0);
    ListNode *cur=dummy;
    for(int i=nums.size()-1;i>=0;i--){
        cur->next=new ListNode(nums[i]);
        cur=cur->next;
    }
    return dummy->next;
}
void printList(ListNode *head){
    if(!head)return ;
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode *p1=l1,*p2=l2;
        ListNode *dummy=new ListNode(0);
        ListNode *cur=dummy;
        int carry=0,val1=0,val2=0,sum=0;
        while(p1||p2||carry){
             val1=p1?p1->val:0;
             val2=p2?p2->val:0;
             sum=val1+val2+carry;
             cur->next=new ListNode(sum%10);
             carry=sum/10;
             if(p1)p1=p1->next;
             if(p2)p2=p2->next;
             cur=cur->next;
        }
        return dummy->next;
    }
};
void test002(){
    vector<int>nums1={2,4,3};
    vector<int>nums2={5,6,4};
    ListNode *l1=createList(nums1);
    ListNode *l2=createList(nums2);
    ListNode *res=Solution().addTwoNumbers(l1,l2);
    printList(res);

}

//int main(){
//    test002();
//    return 0;
//}
