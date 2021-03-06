#include <bits/stdc++.h>
#define LL long long
#define P pair<int, int>
#define lowbit(x) (x & -x)
#define mem(a, b) memset(a, b, sizeof(a))
#define mid ((l + r) >> 1)
#define lc rt<<1
#define rc rt<<1|1
#define endl '\n'
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
using namespace std;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<char> ans;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    int tmp = 0;
    int l = 0, r = n-1;
    while (l <= r) {
    	if (l == r) {
    		if (a[l] > tmp) ans.push_back('L');
    		break;
    	}
    	if (a[l] == a[r]) {
    		if (a[l] <= tmp) break;
    		if (r - l == 1) {
    			ans.push_back('L');
    			break;
    		}
    		if (r - l == 2) {
    			ans.push_back('L');
    			if (a[l+1] > a[l]) ans.push_back('L');
    			break;
    		}
    		int tl = 0, tr = 0, t = tmp;
    		for (int j = r; j >= l; --j) {
    			if (a[j] > t) {
    				t = a[j];
    				tr++;
    			}else break;
    		}
    		t = tmp;
    		for (int j = l; j <= r; ++j) {
    			if (a[j] > t) {
    				t = a[j];
    				tl++;
    			}else break;
    		}
    		tmp = a[l];
    		if (tr > tl) {
    			ans.push_back('R');
    			r--;
    		}else {
    			ans.push_back('L');
    			l++;
    		}
    		continue;
    	}
    	if (a[l] < a[r] && a[l] > tmp) {
    		ans.push_back('L');
    		tmp = a[l];
    		l++;
    	}else if (a[l] < a[r] && a[l] <= tmp && a[r] > tmp) {
    		ans.push_back('R');
    		tmp = a[r];
    		r--;
    	}else if (a[l] > a[r] && a[r] > tmp) {
    		ans.push_back('R');
    		tmp = a[r];
    		r--;
    	}else if (a[l] > a[r] && a[r] <= tmp && a[l] > tmp) {
    		ans.push_back('L');
    		tmp = a[l];
    		l++;
    	}else {
    		break;
    	}
    }
    int len = ans.size();
    cout << len << endl;
    for (int i = 0; i < len; ++i) {
    	cout << ans[i];
    }
    cout << endl;


    return 0;
}