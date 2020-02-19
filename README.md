# Compile-time CRC-32

#### Usage:

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

#### Compile and execute for *nix:

```bash
$ premake5 gmake
$ make -C .build
$ .out/crc32/x64/Debug/crc32 
```

#### Generate VS solution for windows:

```windows
$ premake5 vs2017
```
