# CRC

This parameterized CRC class implements all CRC algorithms in [the book](https://reveng.sourceforge.io/crc-catalogue/).

See `test.cpp` for usage examples.

## Requirements

C++11

This library uses the `#pragma once` directive, which is non-standard but widely supported. You either need a compiler that supports it or replace the directive with include guards.

## Usage

There are three ways to use the library.

### Direct Calculation

Note: Only use this if you don't care about performance.

`#include` the `include/crc/crc.h` file in your program and use the fitting instantiation line from the `declarations/` directory (or your own one), for example

```
using CRC_64_XZ = CRC<64, 0x42f0e1eba9ea3693, true, true, 0xffffffffffffffff, 0xffffffffffffffff>;
```

Then you can directly calculate the respective CRC values from a byte buffer:

```
const char *buf = "123456789";
const size_t length = 9;
const uint64_t result = CRC_64_XZ::calc(buf, length);
```

### Using Precomputed Tables

Build the library in the standard cmake way

```
cmake -B build .
cmake --build build
```

or, for older versions of cmake,

```
mkdir build
cd build
cmake ..
make
```

During the build, the CRC header files and lookup tables will be generated. You can find them in the build directory at `tables/include/crc/` and `tables/src/`, respectively.
For example, for the `crc_64_xz` algorithm, you need

* `include/crc/crc.h`
* `tables/include/crc/crc_64_xz.h`
* `tables/src/crc_64_xz.cpp`

Copy them into your project and make sure the paths work out.

Then you can use the class like this:

```
const char *buf = "123456789";
const size_t length = 9;
CRC_64_XZ crc;
crc.update(buf, length);
const uint64_t result = crc.value();
```

The `update()` method can be called repeatedly, if necessary.

If you only need the CRC value for a single byte buffer, you can also use this equivalent shortcut:

```
const uint64_t result = CRC_64_XZ::compute(buf, length);
```


### Using as a sub library

You can use the library as a subdirectory in a cmake project.
First, decide which CRC algorithm(s) you need, set the build options accordingly and then add the subdirectory.
For example, if you only need the `crc_64_xz` algorithm, your cmake file could look like this.

```
set(CRC_BUILD_COMBINED OFF)
set(CRC_BUILD_crc_64_xz ON)
add_subdirectory(crc)
```

(The `CRC_BUILD_COMBINED` builds a single library that contains all the CRC algorithms which is usually not needed.)

Then you can link against the library like you are used to:

```
add_executable(main main.cpp)
target_link_libraries(main crc_64_xz)
```

which makes the needed header files available.
Computation works the same as in the second method.
For example:

```
#include <crc/crc_64_xz.h>

int main(int argc, char **argv){
	const char *buf = "123456789";
	const size_t length = 9;

	CRC_64_XZ crc;
	crc.update(buf, length);
	const uint64_t result_1 = crc.value();

	const uint64_t result_2 = CRC_64_XZ::compute(buf, length);

	return 0;
}
```

