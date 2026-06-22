#pragma once
#include <iterator>
#include <iostream>

// Робимо так, щоб ptin_iterator працював як звичайний консольний ввід
template <typename T>
using ptin_iterator = std::istream_iterator<T>;