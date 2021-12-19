#pragma once

/**
 * @brief CrtpClass for additional functionality
 *
 * @tparam T Class requiring special functionality
 */
template <typename T> class CrtpClass {
public:
  /**
   * @brief Functionality 1
   *
   */
  void AddFunctionality1() {}

  /**
   * @brief Functionality 2
   *
   */
  void AddFunctionality2() {}
};

/**
 * @brief BaseClass for generic functionality
 *
 */
class BaseClass : public CrtpClass<BaseClass> {
public:
  /**
   * @brief Generic function
   *
   */
  void GenericFunc() {}

  /**
   * @brief Virtual function with default implementation
   *
   */
  virtual void VirtualFunc() {}

  /**
   * @brief Pure Virtual function with no default implementation
   * Meant to be overriden by DerivedClass
   * This also makes BaseClass abstract
   *
   */
  virtual void PureVirtualFunc() = 0;
};

/**
 * @brief DerivedClass for specialized functionality
 *
 */
class DerivedClass : public BaseClass {
public:
  /**
   * @brief Specialized functionality
   *
   */
  void SpecializedFunc() {}

  /**
   * @brief Virtual function is overriden from BaseClass
   *
   */
  void VirtualFunc() override {}

  /**
   * @brief Pure Virtual function implementation is provided from BaseClass
   *
   */
  void PureVirtualFunc() override {}
};
