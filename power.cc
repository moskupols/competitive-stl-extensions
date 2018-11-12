#include <bits/extc++.h>
using namespace std;

static constexpr int64_t Modulo = 1'000'000'007;

auto mul = [](int64_t a, int64_t b) {
  return a * b % Modulo;
};

int64_t identity_element(decltype(mul)) {
  return 1;
}

using Permutation = vector<size_t>;

struct ApplyPerm {
  Permutation operator()(const Permutation& a, const Permutation& b) const {
    Permutation result(a.size());
    for (size_t i = 0; i < result.size(); ++i) {
      result[i] = a[b[i]];
    }
    return result;
  }

  size_t n;
};

Permutation identity_element(ApplyPerm apply) {
  Permutation result(apply.n);
  iota(result.begin(), result.end(), 0);
  return result;
}

int main() {
  cout << __gnu_cxx::power(2LL, 1'000'000'000'000'000'000LL, mul) << '\n';

  Permutation perm{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0};
  for (auto x : __gnu_cxx::power(perm, 3'000'000'000'000'000LL, ApplyPerm{perm.size()})) {
    cout << x << ' ';
  }
}
