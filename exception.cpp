#pragma once

#include <iostream>
using namespace std;

#define OK 0
#define INVALID_VALUE -1
#define ALREADY_EXISTS -2
#define NOT_EXISTS -3
string getErrorString(int error_code)
{
    switch (error_code){
        case 0:
            return "OK";
            break;
        case 1:
            return "INVALID_VALUE";
            break;
        case 2:
            return "ALREADY_EXISTS";
            break;
        case 3:
            return "NOT_EXISTS";
            break;
        default: 
            return "UNKNOWN_ERROR";
    }
}
int err(int error_code, string error_string)
{
    cerr << "/!\\ " << clock() << ": " << error_string << endl;
    return error_code;
}
