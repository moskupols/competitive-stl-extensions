int main(int argc, const char* argv[]) {
  static_assert(32 == __builtin_ctz(0));
  static_assert(0 == __builtin_ctz(0b1111));
  static_assert(2 == __builtin_ctz(0b10100));
  return __builtin_ctz(argc);
}
