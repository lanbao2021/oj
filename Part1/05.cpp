#include <iostream>
#include <vector>
using namespace std;
// 用第一个元素将带排序的序列划分成左右两个部分
int Partition(vector<int> &data, int low, int high){
    int pivot = data[low]; // 第一个元素作为枢轴
    while(low < high){ // 从右边开始，然后左边，循环往复
        while(low < high && data[high] > pivot) --high;
        data[low] = data[high]; // 比枢轴小的元素移动到左端
        while(low < high && data[low] <= pivot) ++low;
        data[high] = data[low]; // 比枢轴大的元素移动到右端
    }
    data[low] = pivot; // 枢轴元素存放到最终位置
    return low; // 返回存放枢轴元素的最终位置，用于下一次partition操作
}

void QuickSort(vector<int> &data, int low, int high){
    if(low < high){
        int pivot_pos = Partition(data, low, high);
        QuickSort(data, low, pivot_pos-1); // 划分左子表
        QuickSort(data, pivot_pos+1, high); // 划分右子表
    }
}
int main(){
    int len, k;
    cin >> len >> k;

    vector<int> data;
    int in;
    for(int i=0; i<len; i++){
        cin >> in;
        data.push_back(in);
    }
    QuickSort(data, 0, len-1);
    cout << data[len-k];
    return 0;
}