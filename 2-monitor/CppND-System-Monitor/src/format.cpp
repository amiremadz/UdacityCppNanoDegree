#include <string>
#include <iomanip>
#include <sstream>
#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  std::ostringstream formatted_time;
  long hour = seconds / 3600;
  long rest = seconds % 3600;
  long minute = rest / 60;
  long second = rest % 60;
  formatted_time << std::setfill('0') << std::setw(2) << hour << ':' 
                 << std::setfill('0') << std::setw(2) << minute << ':'
                 << std::setfill('0') << std::setw(2) << second;
  return formatted_time.str();
}
