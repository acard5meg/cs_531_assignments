#include "header.h"

bool checkLegalCharacters(char c) {

    bool to_return;

    // contains all illegal characters as specified by problem
    // if more illegal characters are added in the future add 
    // additional switch cases
    switch(c) {
        case '!': to_return = false; break;
        case '@': to_return = false; break;
        case '#': to_return = false; break;
        case '$': to_return = false; break;
        case '%': to_return = false; break;
        case '^': to_return = false; break;
        case '(': to_return = false; break;
        case ')': to_return = false; break;
        default: to_return = true;
    }

    return to_return;
}
