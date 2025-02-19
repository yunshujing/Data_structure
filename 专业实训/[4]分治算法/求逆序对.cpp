#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define mod3 998244353
#define mod7 1000000007
const int N = 1e6 + 10;
const double eps =1e-4;

int merge(int a[], int lt, int mid, int rt) {
    int i = lt;
    int j = mid+1;
    int k = 0;
    int temp[rt - lt+1];
    int count = 0; // 记录逆序对的数目
    while (i <= mid && j <= rt) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
            count += mid - i + 1; // 统计逆序对的数目
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= rt) {
        temp[k++] = a[j++];
    }
    for (int i = 0; i < k; i++) {
        a[lt + i] = temp[i];
    }
    return count;
}

int mergeSort(int a[], int lt, int rt) {
    if (lt >= rt) {
        return 0;
    }
    int mid = (lt + rt) / 2;
    int count = 0;
    count += mergeSort(a, lt, mid);
    count += mergeSort(a, mid + 1, rt);
    count += merge(a, lt, mid, rt);
    return count;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout << fixed << setprecision(6);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = mergeSort(a, 0, n-1);
    cout << count << endl;

    return 0;
}
