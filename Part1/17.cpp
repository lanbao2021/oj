#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// 输入数据要学会“getline函数和istringstream的使用”
// 参考文章1：https://blog.csdn.net/qq_35987777/article/details/107675938
// 参考文章2：http://c.biancheng.net/view/1345.html

int Partition(vector<int> &A, int low, int high){
    int pivot = A[low];
    while(low<high){
        while(low<high && A[high]>=pivot) high--;
        A[low] = A[high];
        while(low<high && A[low]<=pivot) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(vector<int> &A, int low, int high){
    if(low<high){
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos -1);
        QuickSort(A, pivotpos+1, high);
    }
}


int main(){
    string str;
    vector<int> data;
    getline(cin, str);
    istringstream is(str);
    string s;
    while(is>>s){
        data.push_back(stoi(s));
    }
    // cout << "data: ";
    // for(auto& i:data)
    //     cout << i << ' ';
    // cout << endl;

    string str2;
    vector<int> data2;
    getline(cin, str2);
    istringstream is2(str2);
    string s2;
    while(is2>>s2){
        data2.push_back(stoi(s2));
    }
    // cout << "data: ";
    // for(auto& i:data2)
    //     cout << i << ' ';
    // cout << endl;


    QuickSort(data, 0, data.size()-1);
    QuickSort(data2, 0, data2.size()-1);

    
    
    int n=0, i=0, j=0;
    while(i<data.size() && j<data2.size()){
        if(data[i] <= data2[j]){
            n++;
            i++;
            j++;
            continue;
        }
        if(data[i] > data2[j]){
            j++;
            continue;
        }
    }
    cout << n << endl;

    
    return 0;
}