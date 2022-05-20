#include "bits/stdc++.h"
#include <climits>
using namespace std;
#define parr(x)                                                                 \
    cout << #x << ' ' << '[' << ' ';                                            \
for (auto z : x)                                                                \
cout << z << ' ';                                                               \
cout << ']' << endl
#define pmap(x)                                                                 \
    cout << #x << ' ' << '{' << ' ';                                            \
for (auto z : x)                                                                \
cout << '(' << ' ' << z.first << ' ' << z.second << ' ' << ')' << ' ';          \
cout << '}' << endl
#define fast                                                                    \
    ios_base::sync_with_stdio(false);                                           \
cin.tie(NULL);                                                                  \
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

bool isPrime(int n) {
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
} // O(sqrt(n))

int binarysearch(int a[], int ele, int n) {
    int l = 0, r = n - 1;
    while (r >= l) {
        int mid = (l + r) / 2;
        if (a[mid] == ele) {
            return mid;
        } else {
            if (a[mid] > ele) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return -1;
}

int Binary_Search_right(int a[], int ele, int n) // right most closest element
{
    int l = -1, r = n;
    while (r > l + 1) {
        int mid = (l + r) / 2;
        if (a[mid] < ele) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r + 1;
}

int Binary_Search_left(vector<int> a, int ele,
        int n) // left most closest element
{
    a.resize(n);
    int l = -1, r = n;
    while (r > l + 1) {
        int mid = (l + r) / 1;
        if (a[mid] <= ele) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l + 1;
}

// prime upto n
bool is_prime[90000001];
vector<int> prime;
void seive() {
    int maxN = 90000000;
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= maxN; i++) {
        if (!is_prime[i]) {
            for (int j = i * i; j <= maxN; j += i) {
                is_prime[j] = true;
            }
        }
    }
    for (int i = 2; i <= maxN; i++) {
        if (!is_prime[i])
            prime.push_back(i);
    }
} // O(nlnln(n))

map<int, int> factor_map;
void primeFactor(int N) {
    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            int cnt = 0;
            while (N % i == 0) {
                cnt++, N /= i;
            }
            factor_map[i] = cnt;
        }
    }
    if (N > 1)
        factor_map[N] = 1;
} // O(sqrt(N))

// prime factor using seive
int ar[1000001];
void seive_factor() {
    int maxN = 1000000;
    for (int i = 1; i <= maxN; i++)
        ar[i] = -1;

    for (int i = 2; i <= maxN; i++) {
        if (ar[i] == -1) {
            for (int j = i; j <= maxN; j += i) {
                if (ar[j] == -1) {
                    ar[j] = i;
                }
            }
        }
    }
}
vector<int> getFactor(int n) {
    vector<int> ret;
    while (n != 1) {
        ret.push_back(ar[n]);
        n = n / ar[n];
    }
    return ret;
}

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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int F[1000001];
int C(int n, int k, int P) {
    if (k > n)
        return 0;

    int res = F[n];
    res = (res * power(F[k], P - 2, P)) % P;
    res = (res * power(F[n - k], P - 2, P)) % P;
    return res;
}

// int dp[1000][1000];

int round(int n, int m) {
    if ((int)(n / m) != ((double)n / (double)m)) {
        return n / m + 1;
    } else {
        return n / m;
    }
}

int phi_array[10000001];
void phi_for_n_queryies(int n) {
    for (int i = 1; i <= n; i++) {
        phi_array[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (phi_array[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi_array[j] /= i;
                phi_array[j] *= (i - 1);
            }
        }
    }
}

int phi(int n) { // count co-prime upto n
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res /= i;
            res *= (i - 1);

            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        res /= n, res *= (n - 1);
    }

    return res;
}

/* MOD
   a == b (mod n)  => a = n*k + b
   => a^k == b^k (mod n)

   x^y (mod n)     => (x%n)^y

   (R/N)%P => (R%P) * (X%P)   [ (N*X)%P = 1 ] iff GCD(N,P) = 1

   if P is prime Number (x^(p-1)%13 = 1) => X = a^(-1) = a^(P-2) (mod P)
   */

/* NUMBER OF INTEGER CO-PRIME WITH P

   P^(x-1)(P-1)
   */

/* KNAPSACK

   Subset with sum equal to k (y/n)
   Subset sum equal to k (count)
   Equil sum subset(min diff) (y/n)
   Subset diff min (count)
   Diff b/w subset equal k (count)
   target sum (count)
   */
int ans;
int ans1 = INT_MAX;
int sol(int arr[], int n, int k, int r) {
    if (k == 0) {
        if (ans1 >= r) {
            ans = n;
            ans1 = r;
        }
        return r;
    }
    if (n == 0) {
        return 0;
    }
    return max(
            {r, sol(arr, n - 1, k - 1, r + arr[n - 1]), sol(arr, n - 1, k, 0)});
}

int answ(int arr[], int i, int j) {
    if (i >= j) {
        return 0;
    }
    if (memorized_dp_array[i][j] != -1) {
        return memorized_dp_array[i][j];
    }

    int min_1 = INT_MAX;

    for (int k = i; k <= j - 1; k++) {
        int temp =
            answ(arr, i, k) + answ(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        cout << temp << endl;
        if (temp < min_1) {
            min_1 = temp;
        }
    }
    return memorized_dp_array[i][j] = min_1;
}

vector<int> printDivisors(int n) {
    vector<int> a;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)
                a.push_back(i);

            else
                a.push_back(i), a.push_back(n / i);
        }
    }
    return a;
}

int reverse(int n) {
    int reversed_number = 0, remainder;
    while (n != 0) {
        remainder = n % 10;
        reversed_number = reversed_number * 10 + remainder;
        n /= 10;
    }
    return reversed_number;
}

void adj_mat_for_graph(int k, int n) {
    /* int n; */
    /* cin >> n; // number of vertices */
    no_of_vertix = n;
    adj_matrix = new int *[no_of_vertix];
    for (int i = 0; i < no_of_vertix; i++) {
        adj_matrix[i] = new int[no_of_vertix];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    /* int k; // number of edges */
    /* cin >> k; */
    for (int i = 0; i < k; i++) {
        int h, m;
        cin >> h >> m;
        adj_matrix[h - 1][m - 1] = 1;
    }
    /* for(int i = 0;i<n;i++){ */
    /*     for(int j = 0;j<n;j++){ */
    /*         cout << adj_matrix[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
}

void bfs(int root, int n, int k) {
    int start;
    start = root - 1;
    queue<int> qu;
    bool vis[n];
    qu.push(start);
    vis[start] = true;
    while (qu.size() != 0) {
        for (int i = 0; i < n; i++) {
            if (adj_matrix[qu.front()][i] == 1 && vis[i] != true) {
                qu.push(i);
                vis[i] = true;
            }
        }
        qu.pop();
    }
}
void dfs(int n, int k, vector<int> stk, bool vis[]) {
    parr(stk);
    for (int i = 0; i < n; i++) {
        if (adj_matrix[stk[stk.size() - 1]][i] == 1 && vis[i] == false) {
            stk.push_back(i);
            vis[i] = true;
            /* parr(stk); */
            dfs(n, k, stk, vis);
        }
    }
    stk.pop_back();
}
void dfs_int(int root, int n, int k) {
    bool vis[n];
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    /* memset(vis,false,n); */
    vector<int> stk;
    stk.push_back(root - 1);
    vis[root - 1] = true;
    dfs(n, k, stk, vis);
    parr(vis);
}

void solution() {
    /* int n; */
    /* cin >> n; */

    /* string num; */
    /* cin >> num; */

    /* int start_1 = 0,start_2 = 1; */
    /* int end_1 = n-1,end_2 = n-2; */

    /* int ans = 0; */
    /* while(start_1 < end_1){ */
        /* if(num[start_1] != num[end_1]){ */
        /*     cout << start_1 << " "<< end_1 << endl; */
        /*     if(num[start_1] == '1' && num[start_1+1] == '1' && num[end_1] == '0' && num[end_1-1] == '0'){ */
        /*         num[start_1] = '0' , num[start_1+1] = '0', num[end_1] = '0', num[end_1-1] = '0'; */
        /*         ans++; */
        /*         start_1+=2,end_1-=2; */
        /*     } */
        /*     else */
        /*     { */
        /*         if(num[start_1] == '0' && num[start_1+1] == '0' && num[end_1] == '1' && num[end_1-1] == '1'){ */
        /*             num[start_1] = '0' , num[start_1+1] = '0', num[end_1] = '0', num[end_1-1] = '0'; */
        /*             ans++; */
        /*             start_1+=2,end_1-=2; */
        /*         } */
        /*         else */
        /*         { */
        /*             ans++; */
        /*             start_1+=1,end_1-=1; */
        /*         } */
        /*     } */
        /* } */
        /* else{ */
        /*     start_1+=1,end_1-=1; */
        /* } */
    /* } */
    /* cout << ans << endl; */
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    int sum = 0;
    int ma = -INT_MAX;
    for(int i = 0;i<n;i++){
        sum += arr[i];
        if(ma < sum) ma = sum;
        if(sum < 0) sum = 0;
    }
    cout << ma << endl;
}

int32_t main() {
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

    while (test_cases--) {
        /* cout << "Case #"<< a << ": "; */
        fast;
        solution();
    }
}
