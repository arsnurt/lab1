#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;

// ------- modular arithmetic -------
ll mod;
ll norm(ll x) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}
ll mod_add(ll a, ll b) { return norm(a + b); }
ll mod_sub(ll a, ll b) { return norm(a - b); }
ll mod_mul(ll a, ll b) { return norm((__int128)a * b); }

// pow(a, e) mod mod (e ≥ 0)
ll mod_pow(ll a, long long e) {
    ll r = 1 % mod;
    while (e > 0) {
        if (e & 1) r = mod_mul(r, a);
        a = mod_mul(a, a);
        e >>= 1;
    }
    return r;
}

// multiplicative inverse mod p (Fermat)
ll mod_inv(ll a) {
    return mod_pow(a, mod - 2);
}

// ------- polynomial operations over Z_mod[x] -------
vector<ll> trim(const vector<ll>& a) {
    vector<ll> r = a;
    while (r.size() > 1 && r.back() == 0) r.pop_back();
    return r;
}

// polynomial addition
vector<ll> poly_add(const vector<ll>& a, const vector<ll>& b) {
    size_t n = max(a.size(), b.size());
    vector<ll> r(n, 0);
    for (size_t i = 0; i < n; i++) {
        if (i < a.size()) r[i] = mod_add(r[i], a[i]);
        if (i < b.size()) r[i] = mod_add(r[i], b[i]);
    }
    return trim(r);
}

// polynomial subtraction
vector<ll> poly_sub(const vector<ll>& a, const vector<ll>& b) {
    size_t n = max(a.size(), b.size());
    vector<ll> r(n, 0);
    for (size_t i = 0; i < n; i++) {
        if (i < a.size()) r[i] = mod_add(r[i], a[i]);
        if (i < b.size()) r[i] = mod_sub(r[i], b[i]);
    }
    return trim(r);
}

// polynomial multiplication
vector<ll> poly_mul(const vector<ll>& a, const vector<ll>& b) {
    if (a.empty() || b.empty()) return {0};
    vector<ll> r(a.size() + b.size() - 1, 0);
    for (size_t i = 0; i < a.size(); i++)
        for (size_t j = 0; j < b.size(); j++)
            r[i + j] = mod_add(r[i + j], mod_mul(a[i], b[j]));
    return trim(r);
}

// polynomial division: a = q*b + r
pair<vector<ll>, vector<ll>> poly_divmod(vector<ll> a, vector<ll> b) {
    a = trim(a);
    b = trim(b);

    if (b.size() == 1 && b[0] == 0)
        throw runtime_error("division by zero polynomial");

    if (a.size() < b.size())
        return {{0}, a};

    vector<ll> q(a.size() - b.size() + 1, 0);
    ll inv = mod_inv(b.back());

    while (a.size() >= b.size() && !(a.size() == 1 && a[0] == 0)) {
        size_t da = a.size() - 1;
        size_t db = b.size() - 1;
        ll coef = mod_mul(a.back(), inv);
        size_t shift = da - db;
        q[shift] = coef;

        for (size_t i = 0; i <= db; i++)
            a[shift + i] = mod_sub(a[shift + i], mod_mul(coef, b[i]));

        a = trim(a);
    }
    return {trim(q), trim(a)};
}

// reduce polynomial modulo modulus polynomial of degree n
vector<ll> poly_mod_reduce(const vector<ll>& poly, const vector<ll>& mod_a, int n) {
    vector<ll> r = poly;
    r.resize(max<int>(r.size(), n));

    for (int deg = (int)r.size() - 1; deg >= n; deg--) {
        ll c = r[deg];
        if (c == 0) continue;
        int offset = deg - n;
        for (int i = 0; i < n; i++) {
            r[offset + i] = mod_add(r[offset + i], mod_mul(c, mod_a[i]));
        }
        r[deg] = 0;
    }
    r.resize(n);
    return r;
}

// multiply polynomials modulo mod_poly
vector<ll> multiply_mod(const vector<ll>& p, const vector<ll>& q, const vector<ll>& mod_a, int n) {
    vector<ll> prod = poly_mul(p, q);
    return poly_mod_reduce(prod, mod_a, n);
}

// compute x^k mod relation
vector<ll> poly_pow_x(long long k, const vector<ll>& mod_a, int n) {
    vector<ll> x(n, 0);
    if (n > 1) x[1] = 1; else x[0] = 1;

    if (k >= 0) {
        vector<ll> r(n, 0);
        r[0] = 1;
        vector<ll> b = x;
        long long e = k;

        while (e > 0) {
            if (e & 1) r = multiply_mod(r, b, mod_a, n);
            b = multiply_mod(b, b, mod_a, n);
            e >>= 1;
        }
        return r;
    }

    // k < 0: x^{-1} is computed by solving x*x^{-1} = 1 mod poly
    // Here modulus polynomial is: X^n - sum(a_i X^i)
    // So mod_poly = [-a_0, -a_1, ..., -a_{n-1}, 1]

    vector<ll> mod_poly(n + 1, 0);
    for (int i = 0; i < n; i++) mod_poly[i] = mod_sub(0, mod_a[i]);
    mod_poly[n] = 1;

    // compute inverse of x polynomial (degree 1)
    // Use extended Euclid for polynomials mod p
    // Implement minimal version: gcd(x, mod_poly)
    auto poly_extend = [&](auto self, vector<ll> A, vector<ll> B)
        -> tuple<vector<ll>, vector<ll>, vector<ll>> {
        vector<ll> s0 = {1}, s1 = {0};
        vector<ll> t0 = {0}, t1 = {1};

        while (!(B.size() == 1 && B[0] == 0)) {
            auto div = poly_divmod(A, B);
            vector<ll> q = div.first;
            vector<ll> r = div.second;

            A = B;
            B = r;

            auto ns = poly_sub(s0, poly_mul(q, s1));
            auto nt = poly_sub(t0, poly_mul(q, t1));

            s0 = s1; s1 = ns;
            t0 = t1; t1 = nt;
        }
        return {A, s0, t0};
    };

    auto[g, s, t] = poly_extend(poly_extend, x, mod_poly);

    if (!(g.size() == 1 && g[0] != 0)) {
        throw runtime_error("x not invertible");
    }

    ll inv_g = mod_inv(g[0]);
    for (auto &v : s) v = mod_mul(v, inv_g);

    s.resize(n);
    auto inv_x = poly_mod_reduce(s, mod_a, n);

    return poly_pow_x(-k, mod_a, n); // recursive call ok
}

// ----------------- demo ---------------------
int main() {
    mod = 1000000007; // prime field
    int n = 2;
    vector<ll> mod_a = {1, 1}; // x^2 = x + 1

    for (int k = 1; k <= 100; k++) {
        auto v = poly_pow_x(k, mod_a, n);
        cout << "x^" << k << " = (" << v[0] << ") + (" << v[1] << ")*x\n";
    }

    return 0;
}
