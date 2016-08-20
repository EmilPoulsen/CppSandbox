#ifndef GUILIBRARY_H
#define GUILIBRARY_H
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class GuiLibrary
{
public:
    GuiLibrary();
    void startGui();
    void printUserOptions();
    std::string readUserInput();
    void printHelp();
    void printInvalidInput(std::string &input);
    bool userSelectedExitOption(std::string &input);
    void printExitMessege();
    std::string askTitleOrAuthor();
    std::string enterSearchString();
    void convertStringToUpper(std::string &str);
    void printStringVectorOnSeparateLines(const std::vector<string> &outputVector);
    void printString(const std::string &output);
private:


};

#endif // GUILIBRARY_H
