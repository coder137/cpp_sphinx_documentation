#pragma once

/**
 * @brief Vector 3 struct containing int types
 *
 */
struct vector_3_s {
  int x, y, z;
};

/**
 * @brief Vector 3 struct using template T type
 *
 * @tparam T Any type T
 */
template <typename T> struct vector_3_st { T x, y, z; };
