/**
* @fileoverview Copyright (c) 2018, by Stefano Gualandi,
*               via Ferrata, 1, Pavia, Italy, 27100
*
* @author stefano.gualandi@gmail.com (Stefano Gualandi)
*
*/

#include <cstdio>

#include "yocta_logger.h"

int main(int argc, char* argv[]) {
   // Log to console (stdout)
   yocta::Logger logger;
   logger.info(yocta::fmt("test %d, %f, %s", 12, 0.3, "hello"));
   logger.error(yocta::fmt("try %d, %f, %s", 12, 0.3, "world"));

   // Lgo to the file "prova.log"
   yocta::Logger fileLogger("prova.log");
   fileLogger.setVerbosityLevel(yocta::VerbosityLevel::WARN);
   fileLogger.info(yocta::fmt("your %d, %f, %s", 12, 0.3, "world"));
   fileLogger.error(yocta::fmt("log %d, %f, %s", 12, 0.3, "hello"));

   return EXIT_SUCCESS;
}
