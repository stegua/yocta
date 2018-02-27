/**
* @fileoverview Copyright (c) 2018, by Stefano Gualandi
*
* @author stefano.gualandi@gmail.com (Stefano Gualandi)
*/

#include "yocta_logger.hh"

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
