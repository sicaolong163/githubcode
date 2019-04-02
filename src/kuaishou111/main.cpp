#include<iostream>
#include<vector>
using  namespace std;

vector<int>nums;
void print(vector<int>&nums){
    for (int i = 0; i < nums.size(); ++i)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
//找出中序遍历的顺序；
void inOrder(vector<int>&nums,int i,vector<int>&in ){
    if(i<0||i>=nums.size())return ;
//    if(i<0||i>nums.size()/2)return ;
    inOrder(nums,i*2+1,in);
    in.emplace_back(nums[i]);
    inOrder(nums,i*2+2,in);
}
void test(){
//    vector<int>nums={10,5,15,3,7,13,18};
    int val;
    bool flag=true;
    while(cin>>val){
        nums.push_back(val);
    }
    vector<int>in;
    inOrder(nums,0,in);//将中序遍历的结果存入到in数组中；然后再看看是不是递增的就可以了；
    for(int i=0;i<in.size()-1;i++){
        if(in[i]>=in[i+1]){
            flag=false;
            break;
        }
    }
    cout<< (flag?"True":"False")<<endl;
}
int main(){
    test();
    return 0;
}
