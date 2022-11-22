#include <iostream>
#include <type_traits>
#include <cassert>
#include "crc32.h"

int main() {
    using namespace std;

#undef TEST_STRING
#define TEST_STRING "Hello world"

    const auto     short_cstring                    = TEST_STRING;
    constexpr auto ref_result_from_literal_crc_32   = (uint32_t)qcstudio::crc32::from_literal(TEST_STRING);
    constexpr auto ref_result_from_literal_crc_32_c = (uint32_t)qcstudio::crc32::from_literal(TEST_STRING, qcstudio::crc32::crc_32_c_poly);
    const auto     result_from_string_crc_32        = (uint32_t)qcstudio::crc32::from_string(short_cstring);
    const auto     result_from_string_crc_32_c      = (uint32_t)qcstudio::crc32::from_string(short_cstring, qcstudio::crc32::crc_32_c_poly);
    const auto     result_from_buffer_crc_32        = (uint32_t)qcstudio::crc32::from_buffer((uint8_t*)short_cstring, strlen(short_cstring));
    const auto     result_from_buffer_crc_32_c      = (uint32_t)qcstudio::crc32::from_buffer((uint8_t*)short_cstring, strlen(short_cstring), qcstudio::crc32::crc_32_c_poly);

    assert(result_from_string_crc_32 == ref_result_from_literal_crc_32);
    assert(result_from_buffer_crc_32 == ref_result_from_literal_crc_32);
    assert(result_from_string_crc_32_c == ref_result_from_literal_crc_32_c);
    assert(result_from_buffer_crc_32_c == ref_result_from_literal_crc_32_c);

    cout << "\"" << TEST_STRING << "\"\n";
    cout << endl;
    cout << "crc-32 polynomial\n";
    cout << "0x" << hex << (uint32_t)ref_result_from_literal_crc_32 << "(from_literal)\n";
    cout << "0x" << hex << (uint32_t)result_from_string_crc_32 << "(from_string)\n";
    cout << "0x" << hex << (uint32_t)result_from_buffer_crc_32 << "(from_buffer)\n";
    cout << endl;
    cout << "crc-32-c polynomial\n";
    cout << "0x" << hex << (uint32_t)ref_result_from_literal_crc_32_c << "(from_literal)\n";
    cout << "0x" << hex << (uint32_t)result_from_string_crc_32_c << "(from_string)\n";
    cout << "0x" << hex << (uint32_t)result_from_buffer_crc_32_c << "(from_buffer)\n";
    cout << endl;
}
