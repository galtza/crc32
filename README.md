# Compile-time CRC-32

Usage:

```c++
...
#include "crc32.h"
...

int main () {
    ...
    constexpr auto text_hash_ct = crc32::from_literal("Hello world");
    ...
    const auto text_hash_rt = crc32::from_string("Hello world");
    ...
    std::cout << (uint32_t)text_hash_ct << std::endl;
    return 0;
}
```
