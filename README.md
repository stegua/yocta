# yocta
Modern C++ minimalist utilities

[https://ci.appveyor.com/api/projects/status/github/yocta?branch=master&svg=true](https://ci.appveyor.com/api/projects/status/github/yocta?branch=master&svg=true)


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

The previous code will give as ouput:

```
$ ./yct
2018-02-24 21:49:08.805 [INFO ] let 12, 0.100000, hello
2018-02-24 21:49:08.805 [WARN ] try 12, 0.200000, world
$ more prova.log
2018-02-24 21:49:08.806 [NOTE ] yct 12, 0.40, hello
$ 
```
