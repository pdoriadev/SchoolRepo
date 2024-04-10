#ifndef RESULT_H
#define RESULT_H

#include <string>

struct result
{
private:
    bool success = true;
    std::string message = "";
public:
    result (){};
    result(bool _suc, std::string _mess)
    {
        success = _suc;
        message = _mess;
    }

    bool gSuccess() {return success;}
    std::string gMessage() {return message;}
};

struct resultSettable
{
    bool success = true;
    std::string message = "";

    resultSettable (){};
    resultSettable(bool _suc, std::string _mess)
    {
        success = _suc;
        message = _mess;
    }

    bool gSuccess() {return success;}
    std::string gMessage() {return message;}
};

#endif // RESULT_H


