#pragma once
#include "core/standardUse.h"

namespace VIIL
{
    //Stolen from Martin Broadhurt
    //http://www.martinbroadhurst.com/how-to-trim-a-stdstring.html
    std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        str.erase(0, str.find_first_not_of(chars));
        return str;
    }

    //Stolen from Martin Broadhurt
    //http://www.martinbroadhurst.com/how-to-trim-a-stdstring.html
    std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        str.erase(str.find_last_not_of(chars) + 1);
        return str;
    }

    //Stolen from Martin Broadhurt
    //http://www.martinbroadhurst.com/how-to-trim-a-stdstring.html
    std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
    {
        return ltrim(rtrim(str, chars), chars);
    }
}
