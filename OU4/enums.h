#ifndef ENUMS_H
#define ENUMS_H
#include <string>

class Enums{
public:
    enum ItemTypes{
        Fiction,
        NonFiction,
        CD,
        NonApplicable,
        Journal,
        Last
    };
    static const std::string ToString(ItemTypes v)
    {
        switch (v)
        {
            case Fiction:   return "Fiction";
            case NonFiction:   return "NonFiction";
            case CD: return "CD";
            case Journal: return "Journal";
            case NonApplicable: return "NonApplicable";
            default:      return "[Unknown type]";
        }
    }
};

#endif // ENUMS_H
