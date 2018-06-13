#include <iostream>
#include <type_traits>
#include <cassert>
#include "crc32.h"

int main () {
    // ===========
    // Simple test
    // ===========
    {
        constexpr auto ct_test = crc32::compile_time("Hello world");
        const     auto rt_test = crc32::run_time("Hello world");
        assert(ct_test == rt_test);

        std::cout << std::hex << ct_test << "\n";
        std::cout << std::hex << rt_test << "\n";
        std::cout << std::endl;
    }
    
    // =========
    // Long test
    // =========
    {
        constexpr auto ct_test = crc32::compile_time(
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
        const auto rt_test = crc32::run_time(
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
        assert(ct_test == rt_test);
        std::cout << std::hex << ct_test << "\n";
        std::cout << std::hex << rt_test << "\n";
        std::cout << std::endl;
    }

}
