//这是2019年12月15日数据结构实验课上的过程代码文件
//希尔排序
#include <stdio.h>
#include <iostream>
using namespace std;
//挖坑填数
int AdjustArray(int sort_arr[], int left,int right){
    int i=left; 
    int j=right;
    int x=sort_arr[left];//把left位置的数暂存到变量x中
    while (i<j)
    {
        //从左到右寻找小于x的数来填挖去x之后留下的坑
        while (i<j && sort_arr[j]>=x)
        {
            j--;

        }
        if (i < j)
        {
            sort_arr[i]=sort_arr[j];
            //将j中的数填到i中，在j处形成了一个新的坑
            i++;
        }
        
        //从左到右找大于或等于x的数值来填sort_arr[j]
        while (i<j && sort_arr[i]< x)
        {
            i++;
        }
        if (i<j)
        {
            sort_arr[j]=sort_arr[i];
            //将i中的数填到j中，i处又成为了坑，虽然地址已经发生了改变
            j--;
        }
    }
    sort_arr[i]=x;//将暂存的哨兵填到坑里
    return i;
}

void quick_sort(int sort_arr[], int left, int right){
    if (left<right)
    {
        int i=AdjustArray(sort_arr,left,right);
        quick_sort(sort_arr,left,i-1);
        quick_sort(sort_arr,i+1,right);
    }
    
}

int main(){
    int sort_arr_0[10];
    cout<<"请输入十个想排序的数："<<endl;
    for (int i = 0; i < 10; i++)
    {
        cin>>sort_arr_0[i];
    }
    cout<<"排序之前的数组："<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<sort_arr_0[i];
    }
    cout<<endl;
    quick_sort(sort_arr_0,0,9);
    cout<<"排序之后的数组;"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<sort_arr_0[i]<<"<";
    }
    cout<<"infinity";
    cout<<endl;
}