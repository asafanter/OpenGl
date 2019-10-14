#ifndef GL_TYPES_H
#define GL_TYPES_H

#include <string>

#define INT8(x) static_cast<int8>(x)
#define INT16(x) static_cast<int16>(x)
#define INT32(x) static_cast<int32>(x)
#define INT64(x) static_cast<int64>(x)
#define UINT8(x) static_cast<uint8>(x)
#define UINT16(x) static_cast<uint16>(x)
#define UINT32(x) static_cast<uint32>(x)
#define UINT64(x) static_cast<uint64>(x)
#define REAL32(x) static_cast<real32>(x)
#define REAL64(x) static_cast<real64>(x)
#define BYTES(x) reinterpret_cast<int8*>(x)
#define UBYTES(x) reinterpret_cast<uint8*>(x)

using int8 = char;
using int16 = short;
using int32 = int;
using int64 = long long;
using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using real32 = float;
using real64 = double;

using string = std::string;

#endif // GL_TYPES_H
