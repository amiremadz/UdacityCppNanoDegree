#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "system.h"

using std::set;
using std::size_t;

System::System() : cpu_(Processor()) {
  vector<int> pids = LinuxParser::Pids();
  for (int pid : pids) {
    processes_.emplace_back(Process(pid));
  }  
}

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
  return processes_; 
}

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() { return kernel_ = LinuxParser::Kernel(); }

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { return mem_util_ = LinuxParser::MemoryUtilization(); }

// TODO: Return the operating system name
std::string System::OperatingSystem() { return os_ = LinuxParser::OperatingSystem(); }

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() { return running_processes_ = LinuxParser::RunningProcesses(); }

// TODO: Return the total number of processes on the system
int System::TotalProcesses() { return total_processes_ = LinuxParser::TotalProcesses(); }

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { return uptime_ = LinuxParser::UpTime(); }

