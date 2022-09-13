/*
 ______________________________________
/           Title: cp template         \
|        Author: Sharishth Singh       |
\           Date: 22 May 2022          /
 --------------------------------------
        \   ^__^
         \  (xx)\_______
            (__)\       )\/\
             U  ||----w||
                ||     ||
*/

#include "bits/stdc++.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <system_error>
#include <type_traits>
#include <utility>
#include <vector>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
using namespace chrono;
#undef int
#define int long long int
#define endl '\n'
#define pi 3.1415926535
#define MOD 1000000007
#define INF 1100000000000000000
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
   cin.tie(0);                                                                  \
   cout.tie(0);                                                                 \
   cerr.tie(0);
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;
unordered_map<int, vector<int>> tree;
int *vis;
char **grid;

bool fun(const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
   if(a.first == b.first){
      return a.second.second < b.second.second;
   }
   else{
      return a.first < b.first;

   }
}

void solution(){
   priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> ma;
   int n;
   cin >> n;
   int ans = -1e9;
   vector<pair<int,pair<int,int>>> cus;
   int room = 1;
   vector<pair<int,int>>a;
   int u = 0;
   while(n--){
      int q,w;
      cin >> q >> w;
      cus.push_back(make_pair(q, make_pair(w, u)));
      u++;
   }
   sort(cus.begin(),cus.end(),fun);
   for (auto i : cus) {
      if(ma.size() == 0){
         ma.push(make_pair( i.second.first,room ));
         a.push_back(make_pair(i.second.second, room));
         room++;
      }else{
         /* std::cerr << ma.top().first << endl; */
         if(ma.top().first < i.first){
            a.push_back(make_pair( i.second.second,ma.top().second ));
            ma.push(make_pair(i.second.first, ma.top().second));
            ma.pop();
         }else{
            /* std::cerr << " room "<< room << endl; */
            /* std::cerr << "" << i.first << " " << i.second.first  << " "<< i.second.second<< endl; */
            ma.push(make_pair( i.second.first,room ));
            a.push_back(make_pair(i.second.second, room));
            room++;
         }
      }
      ans = max(ans,(int)ma.size());
   }
   std::cout << ans << endl;
   /* pmap(a); */
   sort(a.begin(),a.end());
   /* pmap(a); */
   for (auto i : a) {
      std::cout << i.second << " ";
   }
   std::cout << endl;
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
   return 0;
}

