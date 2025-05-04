#include <cassert>
#include <iostream>
#include <memory>
#include <string>

#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>

using apache::thrift::protocol::TBinaryProtocolT;
using apache::thrift::transport::TMemoryBuffer;

void test_i32_roundtrip() {
    auto buffer = std::make_shared<TMemoryBuffer>();
    TBinaryProtocolT<TMemoryBuffer> proto(buffer);

    int32_t in = 0x12345678;
    proto.writeI32(in);

    buffer->resetBuffer();
    int32_t out = 0;
    proto.readI32(out);

    assert(in == out);
    std::cout << "test_i32_roundtrip passed\n";
}

void test_i64_roundtrip() {
    auto buffer = std::make_shared<TMemoryBuffer>();
    TBinaryProtocolT<TMemoryBuffer> proto(buffer);

    int64_t in = 0x1122334455667788;
    proto.writeI64(in);

    buffer->resetBuffer();
    int64_t out = 0;
    proto.readI64(out);

    assert(in == out);
    std::cout << "test_i64_roundtrip passed\n";
}

void test_double_roundtrip() {
    auto buffer = std::make_shared<TMemoryBuffer>();
    TBinaryProtocolT<TMemoryBuffer> proto(buffer);

    double in = 3.14159265359;
    proto.writeDouble(in);

    buffer->resetBuffer();
    double out = 0.0;
    proto.readDouble(out);

    assert(in == out);
    std::cout << "test_double_roundtrip passed\n";
}

void test_string_roundtrip() {
    auto buffer = std::make_shared<TMemoryBuffer>();
    TBinaryProtocolT<TMemoryBuffer> proto(buffer);

    std::string in = "Thrift is fast";
    proto.writeString(in);

    buffer->resetBuffer();
    std::string out;
    proto.readString(out);

    assert(in == out);
    std::cout << "test_string_roundtrip passed\n";
}

int main() {
    try {
        test_i32_roundtrip();
        test_i64_roundtrip();
        test_double_roundtrip();
        test_string_roundtrip();
        std::cout << "\n🎉 All Thrift binary protocol roundtrip tests passed successfully!\n";
    } catch (const apache::thrift::TException& ex) {
        std::cerr << "Thrift exception: " << ex.what() << '\n';
        return 1;
    } catch (const std::exception& ex) {
        std::cerr << "Standard exception: " << ex.what() << '\n';
        return 1;
    } catch (...) {
        std::cerr << "Unknown error occurred\n";
        return 1;
    }
    return 0;
}
