#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb emplace_back
#define ll long long int
#define ss second
#define ff first
#define mm map
#define vs vector<string>
#define vi vector<ll>
#define loop(i, a, b) for (int i = (a); i < (b); i++)
const int mod = 1e9 + 7;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif
void _print(vector<ll> v1)
{
    cerr << "[ ";
    for (int i : v1)
    {
        cerr << i << " ";
    }
    cerr << "]" << endl;
}
void _print(ll m)
{
    cerr << m;
}
void _print(int m)
{
    cerr << m;
}
void _print(char m)
{
    cerr << m;
}
void _print(string m)
{
    cerr << m;
}
void _print(double m)
{
    cerr << m;
}
void _print(float m)
{
    cerr << m;
}
void _print(bool m)
{
    cerr << m;
}
void file_i_o()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}
int binaryExponens(long long int a, long long int b)
{
    //complexity : log(n)
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b = b >> 1;
    }
    return ans;
}
int binarymul(long long int a, long long int b)
{
    int ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % mod;
        }
        a = (a + a) % mod;
        b = b >> 1;
    }
    return ans;
}
int largeBinaryExponens(long long a, long long b)
{
    //complexity: log^2(N)
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = binarymul(ans, a);
        }
        a = binarymul(a, a);
        b = b >> 1;
    }
    return ans;
}

vector<vector<int>> matrixmultivect(vector<vector<int>> &a, vector<vector<int>> &b)
{
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    loop(i, 0, n - 1)
    {
        loop(j, 0, n - 1)
        {
            loop(k, 0, n - 1)
            {
                ans[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }
    return ans;
}
vector<vector<int>> matrixExponentiate(vector<vector<int>> &a, int n)
{
    if (n == 0)
    {
        int sz = a.size();
        vector<vector<int>> ans(sz, vector<int>(sz, 0));
        loop(i, 0, sz - 1)
        {
            ans[i][i] = 1;
        }
        return ans;
    }
    if (n == 1)
    {
        return a;
    }
    vector<vector<int>> temp = matrixExponentiate(a, n / 2);
    vector<vector<int>> ans = matrixmultivect(temp, temp);

    if (n & 1)
    {
        ans = matrixmultivect(ans, a);
    }
    return ans;
}

void matrixmultiara(int **ara, int **ara2, int r1, int c1, int r2, int c2)
{
    int c[r1][c2];
    loop(i, 0, r1 - 1)
    {
        loop(j, 0, c2 - 1)
        {
            c[i][j] = 0;
            loop(k, 0, c1 - 1)
            {
                c[i][j] += ara[i][k] * ara2[k][j];
            }
        }
    }

    loop(i, 0, r1 - 1)
    {
        loop(j, 0, c2 - 1)
        {
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
}
void digitscounter(string n)
{
    cout << n.length() << endl;
}

long long firstdigits(int n, int k)
{
    long double product = n * log10(n);
    long double decimal_part = product - floor(product);
    decimal_part = pow(10, decimal_part);
    long long digits = pow(10, k - 1);
    return decimal_part * digits;
}
vi bigadd(vi m, vi n)
{
    reverse(m.begin(), m.end());
    reverse(n.begin(), n.end());

    vi ans;
    int carry = 0;
    int len = min(m.size(), n.size());
    int l;
    loop(i, 0, len - 1)
    {
        l = m[i] + n[i] + carry;
        carry = l / 10;
        ans.pb(l % 10);
    }
    if (m.size() > len)
    {
        loop(i, len, m.size() - 1)
        {
            l = m[i] + carry;
            carry = l / 10;
            ans.pb(l % 10);
        }
    }
    if (n.size() > len)
    {
        loop(i, len, n.size() - 1)
        {
            l = n[i] + carry;
            carry = l / 10;
            ans.pb(l % 10);
        }
    }
    while (carry)
    {
        ans.pb(carry % 10);
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

//  cheat shit
//         n is a string
//         transform(n.begin(), n.end(), n.begin(), ::tolower);
// sort(ar, ar + size, greater<int>())
// get max value in a array *max_element(ara, ara + n)
vector<int> divisor(int a)
{
    vector<int> sm;
    for (int i = 1; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            if (a / i == i)
            {
                sm.pb(i);
            }
            else
            {
                sm.pb(i);
                sm.pb(a / i);
            }
        }
    }
    return sm;
}

ll GridPath3(int m, int n)
{
    /*total path in the grid to go m,n
	using dp*/
    ll count[m][n];
    loop(i, 0, m - 1)
    {
        count[i][0] = 1;
    }
    loop(i, 0, n - 1)
    {
        count[0][i] = 1;
    }
    loop(i, 1, m - 1)
    {
        loop(j, 1, n - 1)
        {
            count[i][j] = count[i - 1][j] + count[i][j - 1];
        }
    }
    return count[m - 1][n - 1];
}
int GridPath2(int m, int n)
{
    /*total path in the grid to go m,n
	with 1D storage
*/
    vector<int> dp(n, 1);
    loop(i, 1, m - 1)
    {
        loop(j, 0, n - 1)
        {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}
ll npr(ll n, ll r)
{
    //npr=n*(n-1)....(n-r+1)
    int p = n;
    int k = n - r + 1;
    while (n > k)
    {
        n--;
        p *= n;
    }
    return p;
}
ll ncr(ll m, ll n)
{
    ll p = 1;
    if (m - n > n)
    {
        n = m - n;
    }
    ll co = 1;
    loop(i, n + 1, m)
    {
        p *= i;
        if (co <= m - n)
        {
            p /= co;
            co++;
        }
    }
    return p;
}
ll GridPath(ll m, ll n)
{
    n = max(m, n);
    m = (m + n - 2);
    n--;
    return ncr(m, n);
}
int squ(vector<char> &sm, int m)
{

    if (m <= 0)
        return 0;
    int ans = 0;
    if (sm[m] != '?')
    {
        ans = squ(sm, m - 1);
        if (m > 0 && sm[m] == sm[m - 1])
            ans++;
    }
    else
    {
        sm[m] = 'R';
        int c1 = squ(sm, m - 1);
        if (m > 0 && sm[m] == sm[m - 1])
            c1++;
        sm[m] = 'B';
        int c2 = squ(sm, m - 1);
        if (m > 0 && sm[m] == sm[m - 1])
            c2++;
        ans = min(c1, c2);
    }
    return ans;
}
int dp[10000009];
int rec(int ara[], int n, int i)
{
    if (i >= n - 1)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MAX - 5;

    for (int j = 1; j <= ara[i]; j++)
    {
        ans = min(ans, rec(ara, n, j + i) + 1);
    }
    return dp[i] = ans;
}
int minJumps(int arr[], int n)
{
    memset(dp, -1, sizeof(dp));
    return rec(arr, n, 0);
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    bool ans = false;
    bool ok = false;
    int row = matrix.size();
    int col = matrix[0].size();
    int pos = INT_MAX;
    for (int i = 1; i < row; i++)
    {
        if (matrix[i][col - 1] >= target && matrix[i - 1][col - 1] < target)
        {
            pos = i;
            ok = true;
        }
    }
    if (matrix[0][col - 1] >= target)
    {
        pos = 0;
        ok = true;
    }
    if (ok == false)
        return false;
    for (int i = 0; i < col; i++)
    {
        if (matrix[pos][i] == target)
        {
            ans = true;
            break;
        }
    }
    return ans;
}
ll ans[200020];
ll aa[10], bb[10];
ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
int main()
{

    file_i_o();
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    
    return 0;
}

