#include <bits/extc++.h>

constexpr int64_t Modulo = 1000000007;  // a prime number
auto multiply_modulo = [](int64_t a, int64_t b) {
  return a * b % Modulo;
};
// this is required to fully define the operation
// will be called through ADL
int64_t identity_element(decltype(multiply_modulo)) {
  return 1;
}
bool fermat_little_theorem_holds(int64_t x) {  // $x^{p} \equiv x\pmod{p}$
  return __gnu_cxx::power(x, Modulo, multiply_modulo) == x % Modulo;
}
