//222018321102110 冯朔 快速排序 cpp实现

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
void quicksort(vector<int> &nums, int low, in high){
    if(low<high){
        int i = low, j = high, temp = nums[low];
        while(i<j){
            while(i<j&&nums[j]>=temp) j--;//先 从右向左找第一个小于temp的数，因为在j--的过程中会出现j<i的情况所以while语句中必须包含i<j
            if(i<j) nums[i++] = nums[j];
            while(i<j && nums[i]<= temp) i++;// 后从左向右找第一个大于等于temp的数 
            if(i<j) nums[j--] = nums[i];
        }
        nums[i] = temp;
        quicksort(nums, low, i-1);
        quicksort(nums, i+1, high);
    }
}
 
int main()
{
    int n;
    while(cin>>n){
        vector<int>nums(n);
        for(int i =0;i<n;++i){
            cin>>nums[i];
        }
        quicksort(nums, 0, n-1);
        for(int i =0;i<n;++i){
            cout<<nums[i]<<" ";
        }
    }
    return 0;
}