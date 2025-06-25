
#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <string>

class InputHandler {
public:
    static std::string getString(const std::string& prompt);
    static double getDouble(const std::string& prompt);
    static int getInt(const std::string& prompt);
    static bool getYesNo(const std::string& prompt);
    
    static void clearInputStream();
    static void waitForEnter();
};

#endif
