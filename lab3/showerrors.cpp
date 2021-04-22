#include "showerrors.h"

Errors::Errors(string error)
{
    m_error = error;
}

void checkInt(QString s)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] > '9' || s[i] < '0') throw Errors("Incorrent INT number (0..9 digits expected)");
    }
}

void checkDouble(QString s)
{
    int cntDots = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '.')
        {
            if (cntDots > 0) throw Errors("Incorrect DOUBLE number (too many dots)");
            if (i + 1 == s.size()) throw  Errors("Incorrect DOUBLE number (last digit is dot)");
            cntDots++;
            continue;;
        }
        if (s[i] > '9' || s[i] < '0') throw Errors("Incorrent DOUBLE number (0..9 digits expected)");
    }
}

void checkDate(QString s)
{
    if (s.length() != 10) throw Errors("Incorrect DATA input. Expected format dd.mm.yyyy");
    if (s[2] != '.' || s[5] != '.') throw Errors("Incorrect DATA input. Expected format dd.mm.yyyy");
    if (s[0] != '0' && s[0] != '1' && s[0] != '2' && s[0] != '3') throw Errors("Incorrect DATA input. Expected format dd.mm.yyyy");
    if (s[3] != '0' && s[3] != '1') throw Errors("Incorrect DATA input. Expected format dd.mm.yyyy");
    if (s[1] > '9' || s[1] < '0') throw Errors("Incorrect DATA input. Expected format dd.mm.yyyy");
}

