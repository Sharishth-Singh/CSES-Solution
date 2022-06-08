/*
 _________________________________________
/                                         \
| ; Title: cp template                    |
| ; Author:  Sharishth Singh              |
| ; Date: 22 May 2022                     |
\                                         /
 -----------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/
#include "bits/stdc++.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define parr(x)                                                                 \
    cout << #x << ' ' << '[' << ' ';                                            \
    for (auto z : x)                                                            \
        cout << z << ' ';                                                       \
    cout << ']' << endl
#define pmap(x)                                                                 \
    cout << #x << ' ' << '{' << ' ';                                            \
    for (auto z : x)                                                            \
        cout << '(' << ' ' << z.first << ' ' << z.second << ' ' << ')' << ' ';  \
    cout << '}' << endl
#define fast                                                                    \
    ios_base::sync_with_stdio(false);                                           \
    cin.tie(NULL);                                                              \
    cout.tie(NULL);
#define ff first
#define ss second
#undef int
#define int long long int
#define endl '\n'
#define MOD 1000000007
#define pi 3.1415926535
#define ve vector
int static memorized_dp_array[1001][1001];
int no_of_vertix = 0;
int **adj_matrix;
map<int,vector<int>> tree;

char arr[1001][1001];
int arr_b[1001][1001];

int dir_x[] = {1,0,-1,0};
int dir_y[] = {0,1,0,-1};
int s_i,s_j,e_i,e_j;
int ans = INT_MAX;
map<int,string> ma;
int n,m;
string dir = "DRUL";
string dir1 = "RDLU";
int bfs (int x, int y){
    queue<int>Mx;
    queue<int>My;
    vector<pair<int, int>> ans;
    Mx.push(x);
    My.push(y);
    ans.push_back(make_pair(x, y));
    while(Mx.size() != 0){
        for (int i = 0; i < 4; i++) {
            if(arr[Mx.front()+dir_x[i]][My.front()+dir_y[i]] == '#')continue;
            if(arr[Mx.front()+dir_x[i]][My.front()+dir_y[i]] == '.'){

                arr[Mx.front()+dir_x[i]][My.front()+dir_y[i]] = dir1[3-i];
                arr_b[Mx.front()+dir_x[i]][My.front()+dir_y[i]] = 3-i;
                Mx.push(Mx.front()+dir_x[i]);
                My.push(My.front()+dir_y[i]);

                ans.push_back(make_pair(Mx.front()+dir_x[i], My.front()+dir_y[i]));
            }else{
                if(arr[Mx.front()+dir_x[i]][My.front()+dir_y[i]] == 'B')
                {
                    arr[Mx.front()+dir_x[i]][My.front()+dir_y[i]] = dir1[3-i];
                    arr_b[Mx.front()+dir_x[i]][My.front()+dir_y[i]] = 3-i;
                    return 0;
                }
            }
        }
        Mx.pop();
        My.pop();
    }
}
void solution() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            arr_b[i][j] = 0;
            if(arr[i][j] == 'A'){
                s_i = i,s_j = j;
            }
            if(arr[i][j] == 'B'){
                e_i = i;e_j = j;
            }
        }
    }
    int ans = bfs(s_i,s_j);

    string as = "";
    if(arr[e_i][e_j] != 'B')
    {
        std::cout << "YES" << endl;
        while (arr[e_i][e_j] != 'A') {
            if(arr[e_i][e_j] == 'D'){
                as += 'D';
                e_i += 1;
            }
            if(arr[e_i][e_j] == 'L'){
                as += 'L';
                e_j -= 1;
            }
            if(arr[e_i][e_j] == 'R'){
                as += 'R';
                e_j += 1;
            }
            if(arr[e_i][e_j] == 'U'){
                as += 'U';
                e_i -= 1;
            }
        }
        string f = "";
        for (int i = 0; i < as.length(); i++) {
            if(as[i] == 'D'){
                f += 'U';
            }
            if(as[i] == 'U'){
                f += 'D';
            }
            if(as[i] == 'R'){
                f += 'L';
            }
            if(as[i] == 'L'){
                f += 'R';
            }
        }
        reverse(f.begin(), f.end());
        cout << as.length() << endl;
        std::cout << f << endl;
    }
    else {
    std::cout << "NO" << endl;
    }
}

int32_t main() {

    fast;
    /* memset(memorized_dp_array, -1, sizeof(memorized_dp_array)); */

    /* uncomment below lines to nCk... */

    /* F[0] = F[1] = 1; */
    /* for(int i = 2;i <= 1000000;i++){ */
    /*     F[i] = (F[i-1]*i)%MOD; */
    /* } */
    int test_cases = 1;

    /* phi_for_n_queryies(100000); */
    /* cout << phi_array[5] << endl; */

    /* cin >> test_cases; */

    /* seive(); // no. of prime till k */
    /* seive_factor(); // prime factor of a number */

    //  destination    <- adj_matrix
    // s
    // t
    // a
    // r
    // t
    /* int a = 1; */
    while (test_cases--) {
        /* cout << "Case #"<< a << ": "; */
        /* a++; */
        solution();

    }
}
