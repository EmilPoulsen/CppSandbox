#ifndef GUILIBRARY_H
#define GUILIBRARY_H
#include <string>
#include <algorithm>

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

private:
    void convertStringToUpper(std::string &str);

};

#endif // GUILIBRARY_H
