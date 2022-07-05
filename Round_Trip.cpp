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
#include <climits>
#include <map>
#include <stack>
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
map<int, vector<int>> tree;
/* int *vis; */
char **grid;

map<int,int> vis;
vector<int> b;
bool dfs (int start){
   std::stack<int> st;
   st.push(start);
   vis[start] = 1;
   b.clear();
   b.push_back(start+1);
   stack<int> current_parrent;
   vector<int> ::iterator it;
   if(tree[st.top()].size() == 0){
      return false;
   }
   while(st.size() != 0){
      bool ch = false;
      for (auto i : tree[st.top()]) {
         if(vis[i] != 1){
            current_parrent.push(st.top());
            st.push(i);
            b.push_back(i+1);
            ch = true;
            vis[i] = 1;
            break;
         }
         else{
            if(current_parrent.size()>=1){
               if(i != current_parrent.top()){
                  b.push_back(i+1);
                  return true;
               }
            }
         }
      }
      if(ch == false){
         int t = st.top();
         b.pop_back();
         st.pop();
         if(st.size()>=1){
            it = tree[st.top()].begin();
            for (auto i : tree[st.top()]) {
               if(t != i){
                  it++;
               }
               else{
                  break;
               }
            }
            tree[st.top()].erase(it);
         }
         if(current_parrent.size()>=1){
            current_parrent.pop();
         }
      }
   }
   return false;
}


void solution() {
   int n,q;
   cin >> n >> q;
   for (int i = 0; i < q; i++) {
      int w,e;
      cin >> w >> e;
      tree[w-1].push_back(e-1);
      tree[e-1].push_back(w-1);
   }
   bool ch = false;
   for (int i = 0; i < n; i++) {
      if(vis[i] != 1)
      {
         ch = dfs(i);
         if(ch == true){
            break;
         }
      }
   }
   if(ch == false){
      std::cout << "IMPOSSIBLE" << endl;
   }
   else{
      vector<int> y;
      parr(b);
      y.push_back(b[b.size()-1]);
      for (int i = b.size()-2; i>=0; i--) {
         if(b[i] != y[0]){
            y.push_back(b[i]);
         }
         else{
            break;
         }
      }
      y.push_back(b[b.size()-1]);
      std::cout << y.size() << endl;
      for (auto i : y) {
         std::cout << i << " ";
      }
      std::cout << endl;
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

