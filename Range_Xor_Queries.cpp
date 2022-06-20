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
#include <cmath>
#include <iostream>
#include <iterator>
#include <queue>
#include <unistd.h>
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
#define bug(x)                                                                  \
   cerr << #x << " : ";                                                         \
   cerr << x << endl
#define ff first
#define ss second
#undef int
#define int long long int
#define endl '\n'
#define pi 3.1415926535
#define ve vector
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
int MOD = 1e9 + 7;
std::map<int, vector<int>> tree;
int *vis;
char **grid;
/* int start; */
int *path;
int ele=0;

int n;
int n_;
int *arr;
int power(int a, int n, int m) {
    int res = 1;

    while (n) {
        if (n % 2) {
            res = (res * a) % m, n--;
        } else {
            a = (a * a) % m, n /= 2;
        }
    }
    return res;
} // O(log(n))

void segment_tree(){
   int start = 1;
   while(start < n) 
   {
      start *= 2;
   }
   int size = 2*start-1;
   n_ = start;
   arr = new int[size];
   for (int i = start-1; i < start + n-1; i++) {
      cin >> arr[i];
   }
   for (int i = size-1; i >= 0; i-=2) {
      arr[( i/2 )-1] = arr[i] ^ arr[i-1] ;
   }
   /* for (int i = 0; i < size; i++) { */
   /*    std::cout << arr[i] << " "; */
   /* } */
   /* std::cout << endl; */
}


int min_ (int a,int b){ // a = staring index b = ending index (machine readable index)
   a += n_,b+=n_;
   int s=arr[a-1];
   a++;
   while(a<=b){
      /* std::cerr << s << endl; */
      if(( a )%2 == 1) 
      {
         s ^= arr[a-1];
         a++;
      }
      if(( b )%2 == 0) 
      {
         s ^= arr[b-1];
         b--;
      }
      a /= 2,b /= 2;
   }
   return s;
}

int add(int k){ // k = index x = element
   k += n_;
   int s = 0;
   s += arr[k-1];
   k /= 2;
   while(k != 0){
      s+= arr[k-1];
      k /= 2;
   }
   return s;
}

void solution() {
   int q;
   cin >> n >> q;
   segment_tree();
   for (int i = 0; i < q; i++) {
      int w,e;
      cin >> w >> e;
      cout << min_(w-1,e-1) << endl;
   }
}

int32_t main() {
   fast;
   int test_cases = 1;
   /* cin >> test_cases; */
   while (test_cases--) {
      solution();
   }
}

