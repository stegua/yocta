/**
* @fileoverview Copyright (c) 2018, by Stefano Gualandi
*
* @author stefano.gualandi@gmail.com (Stefano Gualandi)
*/

#include <cstdio>

#include "yocta_logger.h"

int main(int argc, char* argv[]) {
   // Log to console (stdout)
   yocta::Logger logger;
   logger.info(yocta::fmt("let %d, %f, %s", 12, 0.1, "hello"));
   logger.error(yocta::fmt("try %d, %f, %s", 12, 0.2, "world"));

   // Log to the file "prova.log"
   logger.setFileStream("prova.log");
   logger.setVerbosityLevel(yocta::VerbosityLevel::WARN);
   logger.info(yocta::fmt("log %d, %f, %s", 12, 0.3, "world"));
   logger.error(yocta::fmt("yct %d, %f, %s", 12, 0.4, "hello"));

   return EXIT_SUCCESS;
}
