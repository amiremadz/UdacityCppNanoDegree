#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <sstream>

#include <iostream>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, version, kernel;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() { 
  float total = 0.f;
  float free = 0.f;
  std::stringstream filename;
  filename << kProcDirectory << kMeminfoFilename;
  std::ifstream filestream(filename.str());
  if (filestream.is_open()) {
    std::string line;
    for (int cnt = 0; cnt < 2; ++cnt)  {
      std::getline(filestream, line);
      std::replace(line.begin(), line.end(), ':', ' ');
      std::stringstream linestream(line);
      std::string key;
      float value;
      linestream >> key >> value;
      if (key == "MemTotal") {
        total = value;
      } else if (key == "MemFree") {
        free = value;
      }
    }     
  }  
  return (total - free) / total; 
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  std::stringstream filename;
  filename << kProcDirectory << kUptimeFilename;
  std::ifstream filestream(filename.str());
  long up_time = 0;
  long idle_time = 0;
  if (filestream.is_open()){
    std::string line;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> up_time >> idle_time;
  }  
  return up_time; 
}

struct Stat {
  std::string cpu;
  long user;
  long nice;
  long system;
  long idle;
  long iowait;
  long irq;
  long softirq;
  long steal;
  long guest;
  long guestnice; 
  long user_time;
  long nice_time;
  long idle_time;
  long system_time;
  long virtual_time;
  long total_time;
    
  void populate(const std::string &line) {
    std::istringstream linestream(line);
    linestream >> cpu >> user >> nice >> system >> idle >> iowait >> 
               irq >> softirq >>   steal >> guest >> guestnice;    
    user_time = user - guest;
    nice_time = nice - guestnice;
    idle_time = idle + iowait;
    system_time = system + irq + softirq;
    virtual_time = guest + guestnice;    
    total_time = user_time + nice_time + idle_time + system_time + virtual_time;
  }
};

struct CpuInfo {
  long utime;
  long stime;
  long cutime;
  long cstime;
  long starttime;
  long active;
  float seconds;
  float totaltime;

  void populate(const string &line) {
    std::istringstream linestream(line);
    std::string ignore;
    for(int i = 0; i < 13; i++) linestream >> ignore;
    linestream >> utime >> stime >> cutime >> cstime ;
    for(int i = 0; i < 4; i++) linestream >> ignore;
    linestream >> starttime;
    long times = utime + stime + cutime + cstime;
    active =  times + starttime;
    seconds = LinuxParser::UpTime() - (starttime / sysconf(_SC_CLK_TCK));
    totaltime = times / sysconf(_SC_CLK_TCK);
  }  
};

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { 
  std::ostringstream filename;
  filename << kProcDirectory << kStatFilename;
  std::ifstream filestream(filename.str());
  
  Stat data;    
  if (filestream.is_open()) {
    std::string line;
    std::getline(filestream, line);
    data.populate(line);
  }
  return data.total_time; 
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) { 
  std::stringstream filename;
  filename << kProcDirectory << pid << kStatFilename;
  std::ifstream filestream(filename.str());
  CpuInfo info;    
  if (filestream.is_open()) {
    std::string line;
    std::getline(filestream, line);
    info.populate(line);
  }
  return info.active; 
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { 
  return LinuxParser::Jiffies() - LinuxParser::IdleJiffies(); 
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { 
  std::ostringstream filename;
  filename << kProcDirectory << kStatFilename;
  std::ifstream filestream(filename.str());
  Stat data;
  if (filestream.is_open()) {
    std::string line;
    std::getline(filestream, line);
    data.populate(line);
  }
  return data.idle_time;
}

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { 
  std::vector<string> cpu;
  std::ostringstream filename;
  filename << kProcDirectory << kStatFilename;
  std::ifstream filestream(filename.str());
  if (filestream.is_open()) {
    string line;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    std::string value;
    while (linestream >> value) {
      if (value != "cpu") {
        cpu.push_back(value);
      }      
    }
  }
  return cpu; 
}

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() { 
  int total = 0;
  std::ostringstream filename;
  filename << kProcDirectory << kStatFilename;
  std::ifstream filestream(filename.str());
  if (filestream.is_open()) {
    string line;
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      string key;
      linestream >> key;
      if (key == "processes") {
        linestream >> total;
        break;
      }
    }
  }  
  return total; 
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { 
  int running = -1;
  std::ostringstream filename;
  filename << kProcDirectory << kStatFilename;
  std::ifstream filestream(filename.str());
  if (filestream.is_open()) {
    std::string line;
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      string key;
      linestream >> key;
      if (key == "procs_running") {
        linestream >> running;
        break;
      }
    }
  }  
  return running; 
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
  std::string cmd_line;
  std::ostringstream filename;
  filename << kProcDirectory << pid << kCmdlineFilename;
  std::ifstream filestream(filename.str());
  if (filestream.is_open()) {    
    std::getline(filestream, cmd_line);
  }  
  return cmd_line;
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) { 
  long memory = 0;
  std::ostringstream filename;
  filename << kProcDirectory << pid << kStatusFilename;
  std::ifstream filestream(filename.str());
  if (filestream.is_open()) {
    std::string line;
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      std::string key;
      linestream >> key;
      if (key == "VmSize") {
        linestream >> memory;
        break;
      }
    }    
  }
  std::ostringstream ram;
  ram << 0.001 * memory;  
  return ram.str(); 
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) { 
  std::string uid;
  std::ostringstream filename;
  filename << kProcDirectory << pid << kStatusFilename;
  std::ifstream filestream(filename.str());
  if (filestream.is_open()) {
    std::string line;
    while (std::getline(filestream, line)) {
      std::istringstream linestream(line);
      std::string key;
      linestream >> key;
      if (key == "Uid:") {
        linestream >> uid;
        break;
      }
    }    
  }
  return uid; 
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) { 
  std::string usrname;
  std::string uid = LinuxParser::Uid(pid);
       
  std::string filename(kPasswordPath);
  std::ifstream filestream(filename);
  if (filestream.is_open()) {
    std::string line;
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      std::string pwd;
      std::string uid_curr;
      linestream >> usrname >> pwd >> uid_curr;       
      if (uid_curr == uid) {
        break;
      }
    }
  }

  return usrname; 
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
  std::ostringstream filename;
  filename << kProcDirectory << pid << kStatFilename;
  std::ifstream filestream(filename.str());
  long start_time = 0;    
  if (filestream.is_open()) {
    std::string line;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    for (int i = 0; i < 22; ++i) {
      linestream >> start_time;
    }
    start_time /= sysconf(_SC_CLK_TCK);
  } 
  return LinuxParser::UpTime() - start_time;
}

float LinuxParser::CpuUtilization(int pid) {
  std::ostringstream filename;
  filename << kProcDirectory << pid << kStatFilename;
  std::ifstream filestream(filename.str());
  CpuInfo info;    
  if (filestream.is_open()) {
    std::string line;
    std::getline(filestream, line);
    info.populate(line);
  }
  return info.totaltime / info.seconds;
}



