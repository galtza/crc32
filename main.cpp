#include <iostream>
#include <type_traits>
#include <cassert>
#include "crc32.h"

int main () {

    // Simple test
    constexpr auto short_ct = crc32::compile_time("Hello world");
    const     auto short_rt = crc32::run_time("Hello world");
    assert(short_ct == short_rt);

    std::cout << std::hex << short_ct << "\n";
    std::cout << std::hex << short_rt << "\n";
    std::cout << std::endl;

    // Long test
    constexpr auto long_ct = crc32::compile_time(
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
        "Pellentesque iaculis neque sem, eget congue justo euismod"
        " nec. Mauris ornare, sem sit amet ullamcorper vestibulum,"
        " urna arcu tristique massa, sit amet imperdiet velit dolor"
        " vel felis. Aliquam non arcu aliquam, mattis eros non,"
        " porttitor lectus. Maecenas sed augue a dui gravida interdum."
        " Cras quis risus est. Donec sed tincidunt lectus, at tempor "
        "tortor. Duis ut convallis purus. Nam mattis felis eros, quis "
        "fermentum enim vulputate in."
    );
    const auto long_rt = crc32::run_time(
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
        "Pellentesque iaculis neque sem, eget congue justo euismod"
        " nec. Mauris ornare, sem sit amet ullamcorper vestibulum,"
        " urna arcu tristique massa, sit amet imperdiet velit dolor"
        " vel felis. Aliquam non arcu aliquam, mattis eros non,"
        " porttitor lectus. Maecenas sed augue a dui gravida interdum."
        " Cras quis risus est. Donec sed tincidunt lectus, at tempor "
        "tortor. Duis ut convallis purus. Nam mattis felis eros, quis "
        "fermentum enim vulputate in."
    );
    assert(long_ct == long_rt);
    std::cout << std::hex << long_ct << "\n";
    std::cout << std::hex << long_rt << "\n";
    std::cout << std::endl;
}
