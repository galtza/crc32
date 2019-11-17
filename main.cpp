#include <iostream>
#include <type_traits>
#include <cassert>
#include "crc32.h"

int main () {

    using namespace std;

    // Simple test
    constexpr auto short_ct = crc32::from_literal("Hello world");
    const     auto short_rt = crc32::from_string("Hello world");
    assert(short_ct == short_rt);

    cout << hex << (uint32_t)short_ct << "\n";
    cout << hex << (uint32_t)short_rt << "\n";
    cout << endl;

    // Long test
    constexpr auto long_ct = crc32::from_literal(
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
    const auto long_rt = crc32::from_string(
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
    cout << hex << (uint32_t)long_ct << "\n";
    cout << hex << (uint32_t)long_rt << "\n";
    cout << endl;
}
