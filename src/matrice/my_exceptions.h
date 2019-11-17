#pragma once
#include <sstream>

class OutOfRangeException : public std::exception {
 public:
  explicit OutOfRangeException() {}
  virtual const char* what() const noexcept override { return _msg.c_str(); }

 private:
  std::string _msg = "OutOfRangeException";
};

class IncompatibleSizeException : public std::exception {
 public:
  explicit IncompatibleSizeException() {}
  virtual const char* what() const noexcept override { return _msg.c_str(); }

 private:
  std::string _msg = "IncompatibleSizeException";
};
