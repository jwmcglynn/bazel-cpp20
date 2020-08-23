#pragma once

#include <string_view>

namespace sample {

class Sample {
public:
  /**
   * Parse a sample input.
   *
   * @return The number of '(' characters the string starts with.
   */
  static int Parse(std::string_view str);
};

}  // namespace sample
