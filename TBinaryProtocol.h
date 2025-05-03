#ifndef T_BINARY_PROTOCOL_H
#define T_BINARY_PROTOCOL_H

#include <cstdint>
#include <string>
#include <memory>

namespace apache {
namespace thrift {
namespace transport {
class TTransport;
}

namespace protocol {

template <typename Transport_, typename ByteOrder_ = void>
class TBinaryProtocolT {
 public:
  explicit TBinaryProtocolT(std::shared_ptr<Transport_> trans) : trans_(trans) {}

  uint32_t writeI32(const int32_t i32) {
    // Example: just a stub
    // Normally you would serialize the int32_t in big endian format
    (void)i32;
    return 4;
  }

  uint32_t readI32(int32_t& i32) {
    // Example: just a stub
    i32 = 0;
    return 4;
  }

  uint32_t writeI64(const int64_t i64) {
    (void)i64;
    return 8;
  }

  uint32_t readI64(int64_t& i64) {
    i64 = 0;
    return 8;
  }

  uint32_t writeDouble(const double dub) {
    (void)dub;
    return 8;
  }

  uint32_t readDouble(double& dub) {
    dub = 0.0;
    return 8;
  }

  uint32_t writeString(const std::string& str) {
    (void)str;
    return 4 + static_cast<uint32_t>(str.size());
  }

  uint32_t readString(std::string& str) {
    str = "example";
    return 4 + static_cast<uint32_t>(str.size());
  }

 private:
  std::shared_ptr<Transport_> trans_;
};

using TBinaryProtocol = TBinaryProtocolT<apache::thrift::transport::TTransport>;

} // namespace protocol
} // namespace thrift
} // namespace apache

#endif // T_BINARY_PROTOCOL_H
