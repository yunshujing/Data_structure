#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

void merge(int a[], int lt, int mid, int rt) {
    int i = lt;
    int j = mid+1;
    int k = 0;
    int temp[rt - lt+1];
    while (i <= mid && j <= rt) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= rt) {
        temp[k++] = a[j++];
    }
    for(k=0,i=lt;i<=rt;i++){
        a[i]=temp[k++];
    }
}
void mergeSort(int a[], int lt, int rt) {
    if (lt >= rt) {
        return;
    }
    int mid = (lt + rt) / 2;
    mergeSort(a, lt, mid);
    mergeSort(a, mid + 1, rt);
    merge(a, lt, mid, rt);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        int a[m];
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }
        mergeSort(a, 0, m-1);
        for (int i = 0; i < m; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}