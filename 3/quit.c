// This file contains the code to execute menu option
// 8) Quit

#include "header.h"

void quit(MYSQL *conn) {
    mysql_close(conn);
    exit(0);
}