#ifndef LIST_EXCEPTIONS_H
#define LIST_EXCEPTIONS_H

#include <exception>
#include <string>
#include <cstring>

class BaseExceptions : public std::exception
{
public:
    BaseExceptions(std::string time,
               std::string filename, std::string classname, std::string methodname)
    {
        error_info = "\nTime: " + time + \
                     "\nFile: " + filename + \
                     "\nClass: " + classname + \
                     "\nMethod: " + methodname;
    }

    const char* what() const noexcept override
    {
        std::string message = "\nERROR: Something is wrong with your list." + error_info;
        char *cmessage = new char[message.size() + 1];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }

protected:
    std::string error_info;
};

class MemoryError : public BaseExceptions
{
public:
    MemoryError(std::string time, std::string filename, std::string classname, std::string methodname) :
            BaseExceptions(time, filename, classname, methodname) {};

    const char* what() const noexcept override
    {
        std::string message = "\nERROR: Unable to allocate memory. " + error_info;
        char *cmessage = new char[message.size() + 1];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class EmptyList : public BaseExceptions
{
public:
    EmptyList(std::string time, std::string filename, std::string classname, std::string methodname) :
            BaseExceptions(time, filename, classname, methodname) {};

    const char* what() const noexcept override
    {
        std::string message = "\nERROR: List is empty. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};

class IteratorError : public BaseExceptions
{
public:
    IteratorError(std::string time, std::string filename, std::string classname, std::string methodname) :
            BaseExceptions(time, filename, classname, methodname) {};

    const char* what() const noexcept override
    {
        std::string message = "\nERROR: Invalid iterator. " + error_info;
        char *cmessage = new char[1 + message.size()];
        std::strcpy(cmessage, message.c_str());
        return cmessage;
    }
};


#endif