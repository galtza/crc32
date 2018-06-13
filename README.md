# Compile-time CRC-32

Usage:

```c++
...
#include "crc32.h"
...

int main () {
    ...
    constexpr auto text_hash_ct = crc32::compile_time("Hello world");
    ...
    const auto text_hash_rt = crc32::run_time("Hello world");
    ...
    return 0;
}
```
