/*
 _________________________________________
/                                         \
| ; Title:  cp template                   |
| ; Author: Sharishth Singh               |
| ; Date:   22 May 2022                   |
\                                         /
 -----------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
*/
#include "bits/stdc++.h"
#include <fstream>
#include <iostream>
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
int **memorized_dp_array;
int no_of_vertix = 0;
int **adj_matrix;


int n;
int fun(int i,int j){
    cout << i << ' ' << endl;
    if(memorized_dp_array[i][j] != -1){
        return memorized_dp_array[i][j];
    }
    if(i == n-1 && j == n-1){
        return memorized_dp_array[i][j] = 1;
    }
    else{ if(adj_matrix[i][j+1] == 1 && i == n-1){
        return memorized_dp_array[i][j] = fun(i, j+1);
    }
    else{
        if(adj_matrix[i+1][j] == 1 && j == n-1){
            return memorized_dp_array[i][j] = fun(i+1, j);
        }
        else{
            if(adj_matrix[i][j+1] == 1 && adj_matrix[i+1][j] == 1)
            {
                return memorized_dp_array[i][j] = fun(i, j+1)+fun(i+1, j);
            }
            else{
                if(adj_matrix[i][j+1] == 1){
                    return memorized_dp_array[i][j] = fun(i, j+1);
                }
                else{
                    if(adj_matrix[i+1][j] == 1)
                    {
                        return memorized_dp_array[i][j] = fun(i+1, j);
                    }
                    else{
                        return memorized_dp_array[i][j] = 0;
                    }
                }
            }
        }
    }
    }
}



void solution() {

    memorized_dp_array = new int *[n];
    for (int i = 0; i < n; i++) {
        memorized_dp_array[i] = new int[n];
    }
    cout << "eu" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            memorized_dp_array[i][j] = -1;
        }
    }
    std::cout << memorized_dp_array[0][0] << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << memorized_dp_array[i][j] << " ";
        }
        cout << endl;
    }
    std::cout << "no" << endl;
    /* cin >> n; */
    /* adj_matrix = new int *[n]; */
    /* for (int i = 0; i < n; i++) { */
    /*     adj_matrix[i] = new int[n]; */
    /* } */
    /* for (int i = 0; i < n; i++) { */
    /*     for (int j = 0; j < n; j++) { */
    /*         char q; */
    /*         cin >> q; */
    /*         if(q == '.') */
    /*             adj_matrix[i][j] = 1; */
    /*         else */
    /*             adj_matrix[i][j] = 0; */
    /*     } */
    /* } */

    /* /1* for (int i = 0; i < n; i++) { *1/ */
    /* /1*     for (int j = 0; j < n; j++) { *1/ */
    /* /1*         cout << adj_matrix[i][j] << " "; *1/ */
    /* /1*     } *1/ */
    /* /1*     cout<< endl; *1/ */
    /* /1* } *1/ */
    /* std::cout << fun(0,0) << endl; */
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
