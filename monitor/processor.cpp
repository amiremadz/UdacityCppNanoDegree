#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
  return static_cast<float>(LinuxParser::ActiveJiffies()) / LinuxParser::Jiffies(); 
}
