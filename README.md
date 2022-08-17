# CRC

This parameterized CRC class implements all CRC algorithms in [the book](https://reveng.sourceforge.io/crc-catalogue/).

See `test.cpp` for usage examples.

## Requirements

C++11

This library uses the `#pragma once` directive, which is non-standard but widely supported. You either need a compiler that supports it or replace the directive with include guards.

## Usage

There are two ways to use the library.

### Direct Calculation

Note: Only use this if you don't care about performance.

`#include` the `include/crc.h` file in your program and use the fitting instantiation line from the `declarations/` directory (or your own one), for example

```
using CRC_64_XZ = CRC<64, 0x42f0e1eba9ea3693, true, true, 0xffffffffffffffff, 0xffffffffffffffff>;
```

Then you can directly calculate the respective CRC values from a byte buffer:

```
const char *buf = "123456789";
const size_t length = 9;
uint64_t result = CRC_64_XZ::calc(buf, length);
```

### Using Precomputed Tables

Run the `make.sh` script which will generate the lookup tables for all supported algorithms (might take a few seconds). Then `#include` the desired header file from `tables/include` and compile the corresponding source file from `tables/src/` into your project. They include `include/crc.h`, so make sure it is found.

Then you can use the class like this:

```
const char *buf = "123456789";
const size_t length = 9;
CRC_64_XZ crc;
crc.update(buf, length);
uint64_t result = crc.value();
```

The `update()` method can be called repeatedly, if necessary.

If you only need the CRC value for a single byte buffer, you can also use this equivalent shortcut:

```
const char *buf = "123456789";
const size_t length = 9;
uint64_t result = CRC_64_XZ::compute(buf, length);
```
