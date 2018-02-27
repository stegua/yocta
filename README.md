# yocta
Modern C++ minimalist utilities

[![Build Status](https://travis-ci.org/stegua/dotlib.svg?branch=master)](https://travis-ci.org/stegua/yocta) [![Build status](https://ci.appveyor.com/api/projects/status/d2jnxclg20vd0o50?svg=true)](https://ci.appveyor.com/project/stegua/yocta)


## Usage Example
```c++
#include "yocta_logger.h"

int main(int argc, char* argv[]) {
   // Log to console (stdout)
   yocta::Logger logger;
   logger.info("let %d, %f, %s", 12, 0.1, "hello");
   logger.warn("try %d, %f, %s", 12, 0.2, "world");

   // Log to the file "prova.log"
   logger.setFileStream("prova.log");
   logger.setVerbosityLevel(yocta::VerbosityLevel::INFO);
   logger.debug("log %d, %.2f, %s", 12, 0.3, "world");
   logger.note("yct %d, %.2f, %s", 12, 0.4, "hello");

   return EXIT_SUCCESS;
}
```
In order to compile and run the basic `yocta_test` on Linux:
```
$ make
$ make test
``` 
The output of the test will be as follows:
```
$ ./yct
2018-02-24 21:49:08.805 [INFO ] let 12, 0.100000, hello
2018-02-24 21:49:08.805 [WARN ] try 12, 0.200000, world
$ more prova.log
2018-02-24 21:49:08.806 [NOTE ] yct 12, 0.40, hello
$ 
```

### Compilers supported
The following compilers are currently supported:

* clang
* gcc
* MSVC 2017



### MIT License
Copyright (c) 2018 Stefano Gualandi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
