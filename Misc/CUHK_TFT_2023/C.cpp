#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef
tree<
  pair<long long, int>,
  null_type,
  less<long long>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int main(void) {
  ios::sync_with_stdio(false);
  
  int n;
  long long s;
  cin >> n >> s;

  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int l = 0, r = 0;
  long long sum = 0, ans = 0, cnt = 0;
  ordered_set st;
  st.insert(0);


  for (int i = 0; i < n; i++) {
    sum += a[i];
    auto it = st.lower_bound(sum-s);
    if (it == st.begin()) {
      st.insert(sum);
      continue;
    }
    it--;

    int num = (int) st.order_of_key(*it) + 1;
    ans += max(0, num);

    st.insert(sum);
  }

  cout << ans << "\n";
  return 0;
}
