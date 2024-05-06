#ifndef ROUND_H
#define ROUND_H

#include <string>
#include <cmath>
#include <assert.h>


void roundToPlace(std::string* str, int roundingPos)
{
    assert(str->length() > 0 && "Passed in empty string");
    size_t posPeriod = str->find('.');
    if (posPeriod != std::string::npos)
    {
        int finalRoundPos = 0;
        if (roundingPos > 0)
        {
            finalRoundPos += posPeriod + 1 + roundingPos;
        }
        else
        {
            finalRoundPos += posPeriod + roundingPos;
        }

        if (finalRoundPos > str->length() - 1)
        {
            str->append(str->length() - 1 - finalRoundPos, '0');
        }
        else
        {
            str->erase(finalRoundPos, str->length() - finalRoundPos);
        }

        return;
    }

    if (roundingPos >= 0)
    {
        return;
    }

    str->replace(str->length() + roundingPos - 1, std::abs(roundingPos), std::abs(roundingPos), '0');

    return;
}

std::string roundToPlace(std::string str, int roundingPos)
{
    assert(str.length() > 0 && "Passed in empty string");
    size_t posPeriod = str.find('.');
    if (posPeriod != std::string::npos)
    {
        int finalRoundOffPos = 0;
        if (roundingPos > 0)
        {
            finalRoundOffPos += posPeriod + 1 + roundingPos;
        }
        else 
        {
            finalRoundOffPos += posPeriod + roundingPos;
        }

        if (finalRoundOffPos > str.length() - 1)
        {
            str.append(str.length() - 1 - finalRoundOffPos, '0');
        }
        else
        {
            //int roundUpPos = finalRoundOffPos - 1;
            //while (roundUpPos >= 0)
            //{
            //    if (static_cast<int>(str[roundUpPos + 1]) < 5)
            //    {
            //        break;
            //    }

            //    int valueToRound = static_cast<int>(str[roundUpPos]);
            //    if (finalRoundOffPos - roundUpPos > 1 && valueToRound != 9)
            //    {
            //        break;
            //    }

            //    if (valueToRound == 9 && roundUpPos == 0)
            //    {
            //        str[0] = '0';
            //        str.insert(0, 1, '1');
            //    }
            //    else if (valueToRound == 9)
            //    {
            //        str[roundUpPos] = '0';
            //    }
            //    else
            //    {

            //    }

            //    str[roundUpPos - 1] = static_cast<char>(roundUpPos);                
            //}
            //

            //if (roundingPos <= 0)
            //{

            //}
            str.erase(finalRoundOffPos, str.length() - finalRoundOffPos);
        }


        return str;
    }

    if (roundingPos >= 0)
    {
        return str;
    }

    str.replace(str.length() + roundingPos - 1, std::abs(roundingPos), std::abs(roundingPos), '0');

    return str;
}

void roundToLeastSignificant(std::string* str)
{
    assert(("Passed in empty string", str->length() > 0));
    size_t posPeriod = str->find('.');
    size_t pos = str->find_last_not_of('0') + 1; ;
    if (posPeriod != std::string::npos)
    {
        if (posPeriod > pos)
        {
            pos = posPeriod;
        }

        str->erase(pos, str->length() - pos);
    }
    else
    {
        str->replace(pos, str->length() - pos, str->length() - pos, '0');
    }
}

std::string roundToLeastSignificant(std::string str)
{
    assert(("Passed in empty string", str.length() > 0));
    size_t posPeriod = str.find('.');
    size_t pos = str.find_last_not_of('0') + 1; ;
    if (posPeriod != std::string::npos)
    {
        if (posPeriod > pos)
        {
            pos = posPeriod;
        }

        str.erase(pos, str.length() - pos);
    }
    else
    {
        str.replace(pos, str.length() - pos, str.length() - pos, '0');
    }

    return str;
}

#endif // ROUND_H