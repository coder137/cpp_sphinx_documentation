#pragma once

#include <string>

namespace nested::n {

void namespaced_free_function();

struct namespaced_struct_s {
  int i;
  float f;
  std::string str;
};

class namespaced_class {
public:
  namespaced_class() = default;

  // Public setter
  void class_func(int i, float f, const std::string &str) {
    private_func_i(i);
    private_func_f(f);
    private_func_str(str);
  }

  // Getters
  int get_int() { return i_; }
  float get_float() { return f_; }
  const std::string &get_str() { return str_; }

private:
  // Private setter
  void private_func_i(int i) { i_ = i; }
  void private_func_f(float f) { f_ = f; }
  void private_func_str(const std::string &str) { str_ = str; }

private:
  int i_{0};
  float f_{0.0};
  std::string str_{""};
};

} // namespace nested::n
