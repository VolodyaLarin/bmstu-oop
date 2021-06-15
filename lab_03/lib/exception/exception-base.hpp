#ifndef LAB_03_EXCEPTION_BASE_HPP
#define LAB_03_EXCEPTION_BASE_HPP

#include <exception>
#include <string>
#include <time.h>

class BaseException : public std::exception {
public:
  explicit BaseException(const std::string &filename,
                         const std::string &classname, const int line,
                         const char *time, const std::string &info) {
    _msg = "In: " + filename + "\n inside: " + classname +
           "\nat line: " + std::to_string(line) + "\nat: " + time +
           "\noccured: " + info;
  }
  [[nodiscard]] const char *what() const noexcept override { return _msg.c_str(); }

private:
  std::string _msg;
};

#endif // LAB_03_EXCEPTION_BASE_HPP
