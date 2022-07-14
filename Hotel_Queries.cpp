/*
    _________________________________________
   /                                         \
   | ; Title: cp template                    |
   | ; Author:  Sharishth Singh              |
   | ; Date: 22 May 2022                     |
   \                                         /
    -----------------------------------------
      \  ^__^
       \ (oo)\_______
         (__)\       )\/\
             ||----w |
             ||     ||
*/

#include "bits/stdc++.h"
#include <algorithm>
#include <cctype>
#include <climits>
#include <map>
#include <memory>
#include <utility>
#include <vector>
using namespace std;
#define parr(x)                                                                 \
   cerr << #x << ' ' << '[' << ' ';                                             \
   for (auto z : x)                                                             \
      cerr << z << ' ';                                                         \
   cerr << ']' << endl
#define pmap(x)                                                                 \
   cerr << #x << ' ' << '{' << ' ';                                             \
   for (auto z : x)                                                             \
      cerr << '(' << ' ' << z.first << ' ' << z.second << ' ' << ')' << ' ';    \
   cerr << '}' << endl
#define fast                                                                    \
   ios_base::sync_with_stdio(false);                                            \
   cin.tie(NULL);                                                               \
   cout.tie(NULL);                                                              \
   cerr.tie(NULL);
/* #undef int */
/* #define int unsigned long long int */
#define endl '\n'
#define pi 3.1415926535
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
map<int, vector<int>> tree;
int *vis;
char **grid;

int n_ = 0;
int *arr;

void segment_tree(int A[],int n){
   int start = 1;
   while(start < n)
   {
      start *= 2;
   }
   int size = 2*start-1;
   n_ = start;
   arr = new int[size];
   int j = 0;
   for (int i = start-1; i < start + n-1; i++) {
      arr[i] = A[j];
      j++;
   }
   for (int i = size-1; i >= 0; i-=2) {
      arr[( i/2 )-1] = max( arr[i] , arr[i-1] ) ;
   }
   /* for (int i = 0; i < size; i++) { */
   /*    std::cout << arr[i] << " "; */
   /* } */
   /* std::cout << endl; */
}


int sum (int a /* 1 */,int b /* n */ ,int ele){ // a = staring index b = ending index
   int t = 1;
   while(true){
      if(arr[t-1] >= ele){
         if(arr[t*2-1] >= ele){
            t *= 2;
         }
         else{
            if(arr[( t*2 + 1 )-1] >= ele){
               t = t*2 + 1;
            }
            else{
               return 0;
            }
         }
      }
      else{
         return 0;
      }
      if(t >= a+n_ && t <= b+n_){
         return t;
      }
   }
}

void add(int k,int x){ // k = index x = element
   /* k += n_; */
   arr[k-1] -= x;
   k /= 2;
   while(k != 0){
      arr[k-1] = max(arr[2*k-1], arr[2*k]);
      k /= 2;
   }
}


void solution() {
   int n,q;
   cin >> n >> q;
   int a[n];
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   segment_tree(a, n);
   for (int i = 0; i < q; i++) {
      int w;
      cin >> w;
      int l = sum(0,n-1,w);
      if(l != 0){
         std::cout << l-n_+1 << " ";
         add(l, w);
      }
      else{
         std::cout << 0 << " ";
      }
   }
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   /* int a = 1; */
   while (test_cases--) {
      /* std::cout << "Case #"<< a << ": "; */
      solution();
      /* a++; */
   }
   cerr << "=====" << endl;
   cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}
