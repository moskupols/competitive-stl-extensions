#include <bits/extc++.h>
using namespace std;

using Permutation = vector<size_t>;
size_t ApplyPermCalls = 0;
struct ApplyPerm {
  Permutation operator()(const Permutation& a, const Permutation& b) const {
    ++ApplyPermCalls;
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

using Matrix = vector<vector<double>>;
size_t matrixSize;
auto mul_matrix = [](const Matrix& a, const Matrix& b) {
  Matrix result(matrixSize, vector<double>(matrixSize, 0));
  for (size_t i = 0; i < matrixSize; ++i) {
    for (size_t j = 0; j < matrixSize; ++j) {
      for (size_t k = 0; k < matrixSize; ++k) {
        result[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return result;
};

Matrix identity_element(decltype(mul_matrix)) {
  Matrix result(matrixSize, vector<double>(matrixSize, 0));
  for (size_t i = 0; i < matrixSize; ++i) {
    result[i][i] = 1;
  }
  return result;
}

int main() {
  Permutation perm{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0};
  for (auto x : __gnu_cxx::power(perm, 3'000'000'000'000'000LL, ApplyPerm{perm.size()})) {
    cout << x << ' ';
  }
  cout << '\n';
  cout << "calls: " << ApplyPermCalls << '\n';

  {
    Matrix init{
      {1, 0, 0, 0},
      {0, 2, 0, 0},
      {0, 0, 3, 0},
      {0, 0, 0, 4},
    };
    matrixSize = init.size();
    for (const auto& row : __gnu_cxx::power(init, 10, mul_matrix)) {
      for (auto cell : row) {
        cout << cell << ' ';
      }
      cout << '\n';
    }
  }

  {
    Matrix init{
      {2, 1, 0, 0, 0},
      {0, 2, 1, 0, 0},
      {0, 0, 2, 0, 0},
      {0, 0, 0, 3, 1},
      {0, 0, 0, 0, 3},
    };
    matrixSize = init.size();
    for (const auto& row : __gnu_cxx::power(init, 3, mul_matrix)) {
      for (auto cell : row) {
        cout << cell << ' ';
      }
      cout << '\n';
    }
  }
}
