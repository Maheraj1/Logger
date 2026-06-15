#include "Log.hpp"
#include <cassert>
#include <cstdarg>
#include <functional>
#include <iostream>
#include <sstream>

namespace Log {

    std::ostream* API::stream = &std::cout;
    std::function<void(bool)> API::assertFunc = [](bool condition) { assert(condition); };

    void Log(const char* fmt, ...) {
        va_list list;
		va_start(list, fmt);
        
        int size = snprintf(NULL, 0, fmt, list);
		char* buffer = new char[size + 1];
        snprintf(buffer, size, fmt, list);
        
        Log((std::string)buffer);
        va_end(list);
    }


    void Log(LogOut& buffer) {
        Log(buffer.str());
    }
    
    void Log(std::string text) {
        *API::stream << text;
    }

    void Error(std::string text, std::string errorType, bool Assert) {
        std::string statement = '(' + errorType + "): " + text + "\n";

        if (Assert)
		{
            Log::Assert(false, statement);
        } else {
            Log::Log("\e[" + std::to_string((int)LogColor::Red) + statement);
        }
    }

    void Assert(bool condition, std::string text) {
        if (!text.empty()) {
            LogOut out;
            out << LogColor::Red << text;
        }

        API::assertFunc(false);
    }

    void Info(std::string text, std::string from) {
        Log("\e[" + std::to_string((int)LogColor::Green) + '(' + from + "): " + text + '\n');
    }

    void Warning(std::string text) {
        Log("\e[" + std::to_string((int)LogColor::Green) + "(Warning): " + text + '\n');
    }

    LogOut::LogOut(std::string str) 
    :std::ostringstream(str)
    { }
}