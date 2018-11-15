#include <bits/extc++.h>
constexpr int64_t Modulo = 1000000007;
auto multiply_modulo = [](int64_t a, int64_t b) {
  return a * b % Modulo;
};
int64_t identity_element(decltype(multiply_modulo)) {
  return 1;
}
bool fermat_little_theorem_holds(int64_t x) {
  auto inverse = __gnu_cxx::power(x, Modulo - 2, multiply_modulo);
  return 0 == x || 1 == multiply_modulo(x, inverse);
}
