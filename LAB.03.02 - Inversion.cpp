#include<bits/stdc++.h>
using namespace std;
const long int MAXN = 1000002;
int n;
int A[MAXN];
long long countt=0;
const int MAX=1e9+7;
void merge(int a[], int const left, int const mid, int const right, long long &countt){
    int const subarrone = mid -left+1;
    int const subarrtwo= right -mid;

    int *leftArr = new int[subarrone];
    int *rightArr = new int[subarrtwo];

    for(int i = 0; i<subarrone; i++){
        leftArr[i]= a[left+i];
    }
    for(int j=0; j< subarrtwo; j++){
        rightArr[j]= a[mid+1+j];
    }

    int i_SubOne = 0;
    int i_SubTwo = 0;
    int i_mergedArr = left;

    while(i_SubOne < subarrone && i_SubTwo < subarrtwo){
        if(leftArr[i_SubOne]<= rightArr[i_SubTwo]){ 
            a[i_mergedArr] = leftArr[i_SubOne];
            i_SubOne++;
        }
        else {
            a[i_mergedArr] = rightArr[i_SubTwo];
            i_SubTwo++;
            countt = (countt+(subarrone - i_SubOne)%MAX)%MAX;
            
        }
        i_mergedArr++;

    }

    while(i_SubOne < subarrone){
        a[i_mergedArr] = leftArr[i_SubOne];
        i_SubOne++;
        i_mergedArr++;
    }


    while(i_SubTwo < subarrtwo){
        a[i_mergedArr] = rightArr[i_SubTwo];
        i_SubTwo++;
        i_mergedArr++;
    }

    delete[] leftArr;
    delete[] rightArr;
}
void merge_sort(int a[], int const begin, int const end, long long &countt){
    if(begin>=end) return ;

    int mid = begin +(end-begin)/2;
    merge_sort(a, begin, mid, countt);
    merge_sort(a, mid+1, end, countt);
    
    merge(a, begin, mid, end, countt);


}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0; i <n ; i++){

        cin >> A[i];
    }
    merge_sort(A, 0, n- 1,countt);
    cout << countt;
    return 0;
}