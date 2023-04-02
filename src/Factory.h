/**
 * @file Factory.h
 * @author Tuomas Lahtinen (tuomas123lahtinen@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <memory>

namespace skeleton::factory
{
   // Get a default implementation of class
   template <typename T, class D> std::unique_ptr<T> getDefault(D);
} // namespace skeleton::factory
