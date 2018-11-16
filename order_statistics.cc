#include <bits/extc++.h>
using namespace __gnu_pbds;

template<typename K, typename V, class Earlier = std::less<K>>
using OrderStatsMap = tree<
  K, V, Earlier,
  rb_tree_tag,  // or splay_tree_tag
  tree_order_statistics_node_update  // extension policy
>;

template<typename K, class Earlier = std::less<K>>
using OrderStatsSet = OrderStatsMap<K, null_type, Earlier>;

int main() {
  OrderStatsSet<int> s;
  for (auto k : {12, 505, 30, 100}) {
    s.insert(k);
  }

  // The order of the keys should be: 12, 30, 100, 505.
  assert(12 == *s.find_by_order(0));
  assert(100 == *s.find_by_order(2));
  assert(s.end() == s.find_by_order(4));

  assert(0 == s.order_of_key(10));
  assert(1 == s.order_of_key(30));
  assert(4 == s.order_of_key(1000));
}
