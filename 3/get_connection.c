#include "header.h"

MYSQL* get_connection() {
    static char *host ="helios.vse.gmu.edu";
    static char *user = USERNAME;
    static char *pass = PASSWORD;
    static char *dbname = DBNAME;

    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!(mysql_real_connect(conn,host, user, pass,dbname,0,NULL,0))){
        fprintf(stderr, "\nError %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    printf("\nConnection Successful\n\n");


    return conn;

}