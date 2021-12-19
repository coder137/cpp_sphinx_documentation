#pragma once

#include <string>

namespace nested::n {

/**
 * @brief Just a regular free function inside nested::n namespace
 *
 */
inline void namespaced_free_function() {}

/**
 * @brief Struct holding integer, float and string values grouped together
 *
 */
struct namespaced_struct_s {
  int i;
  float f;
  std::string str;
};

/**
 * @brief Class holding integer, float and string values grouped together
 * Contains class specific behaviour
 *
 */
class namespaced_class {
public:
  namespaced_class() = default;

  // Public setter

  /**
   * @brief Class func to set integer, float and string values together
   *
   * @param i int value
   * @param f float value
   * @param str string value
   */
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
