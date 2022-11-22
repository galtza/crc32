# Compile-time CRC-32

#### Usage example:

```c++
...
#include "crc32.h"
...

int main () {
    ...
    constexpr auto text_hash_ct = qcstudio::crc32::from_literal("Hello world");
    ...
    constexpr auto text_hash_ct = qcstudio::crc32::from_literal("Hello world", qcstudio::crc32::crc_32_c_poly); // use crc-32-c polunomial
    ...
    const auto text_hash_rt = qcstudio::crc32::from_string("Hello world");
    ...
    std::cout << (uint32_t)text_hash_ct << std::endl;
    return 0;
}
```

It allows selecting between the default ***crc-32*** polynomial (0x04C11DB7) and ***crc-32-c*** (0x1EDC6F41), used by Python and Intel (_\_mm\_crc32\_\*_) respectively

#### Generate VS 2019 solution for windows:

```windows
$ premake5 vs2019
```

then open solutions

#### Compile and execute for *nix:

```bash
$ premake5 gmake
$ make -C .build
$ .out/crc32/x64/Debug/crc32 
```

