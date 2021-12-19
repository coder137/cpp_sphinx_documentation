#pragma once

/**
 * @brief This is a free function
 * Not namespaced or embedded inside a class / struct
 */
inline void free_function() {}

/**
 * @brief Free function template takes in a template type T and return a copy
 *
 * @tparam T Can be any type that is copyable
 * @param t Pass by const ref
 * @return T Copy and return from function using RVO
 */
template <typename T> inline T free_function_template(const T &t) { return t; }
