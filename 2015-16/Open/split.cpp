http://www.usaco.org/index.php?page=viewproblem2&cpid=645

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define trav(a, x) for (auto& a: x)
#define ins insert
#define pq priority_queue
#define sz(x) (int)x.size()
#define rsz resize
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define endl "\n"

typedef long long ll;
typedef pair<long long, long long> pii; 

void setIO(string s){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

ll N, ans, original;

int main() {
    //setIO("split"); 
    cin >> N;
    pii xy[N], yx[N];
    ll maxY[N], minY[N], maxY2[N], minY2[N], maxX[N], minX[N], maxX2[N], minX2[N];
    for (ll i = 0; i < N; i++){
        ll a, b; cin >> a >> b;
        xy[i].f = a; xy[i].s = b;
        yx[i].f = b; yx[i].s = a;
    }
    sort(xy, xy + N); sort(yx, yx + N);
    original = (yx[N - 1].f - yx[0].f) * (xy[N - 1].f - xy[0].f);
    
    maxY[0] = xy[0].s; minY[0] = xy[0].s; maxX[0] = yx[0].s; minX[0] = yx[0].s;
    for (ll i = 1; i < N; i++){
        maxY[i] = max(maxY[i - 1], xy[i].s);
        minY[i] = min(minY[i - 1], xy[i].s);
        maxX[i] = max(maxX[i - 1], yx[i].s);
        minX[i] = min(minX[i - 1], yx[i].s);
    }
    
    maxY2[N - 1] = xy[N - 1].s; minY2[N - 1] = xy[N - 1].s; maxX2[N - 1] = yx[N - 1].s; minX2[N - 1] = yx[N - 1].s;
    for (ll i = N - 2; i >= 0; i--){
        maxY2[i] = max(maxY2[i + 1], xy[i].s);
        minY2[i] = min(minY2[i + 1], xy[i].s);
        maxX2[i] = max(maxX2[i + 1], yx[i].s);
        minX2[i] = min(minX2[i + 1], yx[i].s);
    }
    
    for (ll i = 1; i < N - 1; i++){
        if (xy[i].f == xy[i + 1].f) continue;
        ll en1 = (maxY[i] - minY[i]) * (xy[i].f - xy[0].f);
        ll en2 = (maxY2[i + 1] - minY2[i + 1]) * (xy[N - 1].f - xy[i + 1].f);
        ans = max(original - (en1 + en2), ans);
    }
    
    for (ll i = 1; i < N - 1; i++){
        if (yx[i].f == yx[i + 1].f) continue;
        ll en1 = (maxX[i] - minX[i]) * (yx[i].f - yx[0].f);
        ll en2 = (maxX2[i + 1] - minX2[i + 1]) * (yx[N - 1].f - yx[i + 1].f);
        ans = max(original - (en1 + en2), ans);
    }
    
    cout << ans << endl;
    return 0;
}

