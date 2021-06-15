#ifndef EXCEPTION_IMPORT_HPP
#define EXCEPTION_IMPORT_HPP

#include "exception-base.hpp"

class BuildException : public BaseException {
public:
  BuildException(
      const std::string &filename, const std::string &classname, const int line,
      const char *time,
      const std::string &info =
          "Can't build model")
      : BaseException(filename, classname, line, time, info) {}
};

class InvalidSourceException : public BaseException {
public:
  InvalidSourceException(const std::string &filename,
                         const std::string &classname, const int line,
                         const char *time,
                         const std::string &info =
                             "Failed to open non - existing or broken source.")
      : BaseException(filename, classname, line, time, info) {}
};


class NoDirectorException : public BaseException {
public:
    NoDirectorException(const std::string &filename, const std::string &classname,
                        const int line, const char *time,
                        const std::string &info = "Camera is not chosen.")
            : BaseException(filename, classname, line, time, info) {}
};

class NoCameraException : public BaseException {
public:
    NoCameraException(const std::string &filename, const std::string &classname,
                      const int line, const char *time,
                      const std::string &info = "Camera is not chosen.")
            : BaseException(filename, classname, line, time, info) {}
};


#endif // EXCEPTION_IMPORT_HPP
