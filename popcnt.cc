int main(int argc, const char* argv[]) {
  static_assert(0 == __builtin_popcount(0));  // wow so constexpr
  static_assert(4 == __builtin_popcount(0b1111));
  static_assert(3 == __builtin_popcount(0b100101));
  return __builtin_popcount(argc);
}
