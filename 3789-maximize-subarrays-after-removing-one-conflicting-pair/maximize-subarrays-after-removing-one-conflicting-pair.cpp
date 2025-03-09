#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll                      long long
#define ar                      array
// #define int                     ll
#define sz(v)                   (int)(v.size())
#define FIO                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld                      long double
#define ull                     unsigned long long
#define fo(i,a,b)               for(int i = a; i<=b ; i++)
#define rfo(i,a,b)              for(int i = a; i>=b ; i--)
#define vii                     vector<int>
#define pq                      priority_queue
#define uomii                   unordered_map<int,int,best_hash>
#define all(v)                  v.begin(),v.end()
#define mp                      make_pair
#define pb                      push_back
#define pob                     pop_back
#define ff                      first
#define ss                      second
#define pii                     pair<int,int>
#define mii                     map<int,int>
#define vvii                    vector<vii>
#define mod                     1000000007
#define inf                     5e18
#define pi                      3.1415926535897932384626433832795
#define cz(x)                   63 - __builtin_clzll(x)



using namespace std;
using namespace __gnu_pbds;
template<class T> using oset =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// https://codeforces.com/blog/entry/68809

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i : x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define pr(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define pr(x...)
#endif

// https://codeforces.com/blog/entry/62393

struct best_hash {
	static uint64_t splitmix64(uint64_t x) {

		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

class Solution {
public:
	long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
		vii v[n + 1];

		for (auto &i : conflictingPairs) {
            if(i[0]>i[1]) swap(i[0],i[1]);
			int a = i[0], b = i[1];
			v[b].pb(a);
		}

		vii firstEnd(n + 1, 0), secondEnd(n + 1, 0);
		vector<ll> fContri(n + 1, 0), sContri(n + 1, 0);

		int last = 0, secondLast = 0;

		ll pairs = 0;
		fo(i, 1, n) {
			for (auto &idx : v[i]) {

				// update last two greatest starting conflicting pairs
				if (idx < secondLast);
				else if (idx >= secondLast and idx <= last) {
					secondLast = idx;
				}
				else {
					secondLast = last;
					last = idx;
				}
			}

			pairs += 1LL * (i - last);

			firstEnd[i] = last, secondEnd[i] = secondLast;
			fContri[i] = i - last;
			sContri[i] = i - secondLast;

			fContri[i] += fContri[i - 1];
			sContri[i] += sContri[i - 1];
		}
        
		ll res = 0;

		for (auto &p : conflictingPairs) {
			int a = p[0], b = p[1];

			if (firstEnd[b] != a) {
				res = max(res, pairs);
				continue;
			}
			auto upto = upper_bound(all(firstEnd), a) - firstEnd.begin();
			upto--;
			// take secondMax from [b,upto]
			ll earlierContri = fContri[upto] - fContri[b - 1];
			ll nwContri = sContri[upto] - sContri[b - 1];
            ll nwPairs = pairs - earlierContri + nwContri;
			res = max(res, nwPairs);
		}

		return res;
	}
};