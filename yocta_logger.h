/**
* @fileoverview Copyright (c) 2017,2018, by Stefano Gualandi
*
* @author stefano.gualandi@gmail.com (Stefano Gualandi)
*/

#include <string>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <memory>

// In order to use PRId64
#include <inttypes.h>


namespace yocta {
// Why Yocto? Please, read the following link:
// Wikipedia: https://en.wikipedia.org/wiki/Yocto-

// Verbosity levels
enum VerbosityLevel { ERROR = 0, WARN = 1, INFO = 2, DEBUG = 3 };

class Logger {
 public:
   // Standard c'tor
   Logger() : stream(stdout), vl(VerbosityLevel::INFO) {}
   // Log to the given filename
   Logger(const std::string& filename)
      : stream(std::fopen(filename.c_str(), "w")),
        vl(VerbosityLevel::INFO)
   {}
   // Flush, close, and de c'tor
   ~Logger() {
      fflush(stream);
      if (stream != stdout)
         std::fclose(stream);
   }
   // Set verbosity level
   void setVerbosityLevel(VerbosityLevel verbosity) {
      vl = verbosity;
   }
   // Flush out the buffer stream
   void flush() const {
      fflush(stream);
   }
   // ---- Dump message functions ---- //
   void error(const std::string& message) const {
      dump("[ERROR]", message);
      // Flush right away for errors
      fflush(stream);
   }

   void warn(const std::string& message) const {
      if (vl >= VerbosityLevel::WARN)
         dump("[WARN ]", message);
   }

   void info(const std::string& message) const {
      if (vl >= VerbosityLevel::INFO)
         dump("[INFO ]", message);
   }

   void debug(const std::string& message) const {
      if (vl >= VerbosityLevel::DEBUG)
         dump("[DEBUG]", message);
   }

 private:
   // Output stream
   std::FILE* stream;
   // Verbosity level
   VerbosityLevel vl;

   // Dump the message to the stream, with datetime format
   void dump(const char* msg, const std::string& message) const {
      using namespace std;
      using namespace std::chrono;
      // get current time
      auto now = system_clock::now();
      std::time_t now_time = system_clock::to_time_t(now);
      // get datetime
      char date[100];
      strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", localtime(&now_time));
      // Get milliseocnds
      auto since_epoch = now.time_since_epoch();
      auto s = duration_cast<std::chrono::seconds>(since_epoch);
      since_epoch -= s;
      milliseconds milli = duration_cast<milliseconds>(since_epoch);
      // dump the string
      fprintf(stream, "%s.%.3" PRId64 " %s %s\n", date, milli.count(), msg, message.c_str());
   }
};


// Support for forwarding the content of fprintf to my logger class
// From Stackoverflow at:
// https://stackoverflow.com/questions/2342162/stdstring-formatting-like-sprintf
template<typename ... Args>
std::string fmt(const std::string& format, Args ... args) {
   size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
   std::unique_ptr<char[]> buf(new char[size]);
   snprintf(buf.get(), size, format.c_str(), args ...);
   return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

} // End namespace Yocto
