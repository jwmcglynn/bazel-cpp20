#include "sample/sample.h"

#include <cstdint>
#include <cstddef>

namespace sample {

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  auto result = Sample::Parse(std::string_view(reinterpret_cast<const char*>(data), size));
  (void)result;

  return 0;
}

}  // namespace sample
