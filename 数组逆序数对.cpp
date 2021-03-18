#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long mergeAndCount(int arr[], int l, int m, int r){
    long long cnt = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j, k;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for(i = 0; i < n2; i++){
        R[i] = arr[m + 1 + i];
    }
    i = 0;
    j = 0;
    k = l;
    //从小到大排序
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else{
            for(int p=i;p<n1;p++){
                cout<<L[p] <<","<< R[j]<<endl;
            }
            arr[k] = R[j];
            cnt += (n1 - i);
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k++] = L[i];
        i++;
    }

    while(j < n2){
        arr[k++] = R[j];
        j++;
    }

    return cnt;

}

long long MergeSortAndCount(int arr[], int l, int r){
    long long cnt = 0, cnt1, cnt2, cnt3;
    if(l >= r)
        return 0;
    else {
        int middle = l + (r - l) / 2;
        cnt1 = MergeSortAndCount(arr, l, middle);
        cnt2 = MergeSortAndCount(arr, middle + 1, r);
        cnt3 = mergeAndCount(arr, l, middle, r);
    }
    return cnt1 + cnt2 + cnt3;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int [n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << MergeSortAndCount(arr, 0, n - 1) << endl;
    return 0;
}
