#include <bits/extc++.h>
using namespace __gnu_pbds;

template<typename K, typename V, class Earlier = std::less<K>>
using RankedMap = tree<
  K, V, Earlier,
  rb_tree_tag,  // or splay_tree_tag
  tree_order_statistics_node_update  // extension policy
>;

template<typename K, class Earlier = std::less<K>>
using RankedSet = RankedMap<K, null_type, Earlier>;

int main() {
}
