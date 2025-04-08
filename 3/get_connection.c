#include "header.h"

MYSQL* get_connection() {
    static char *host ="helios.vse.gmu.edu";
    static char *user ="acard";
    static char *pass = "zyleewhy";
    static char *dbname = DBNAME;
    // unsigned int port =3306;
    // static char *unix_socket = NULL;
    // unsigned int flag = 0;

    MYSQL *conn; //The mysql_init() function allocates or initialises a MYSQL object suitable for mysql real_connect()
    conn = mysql_init(NULL);
    if (!(mysql_real_connect(conn,host, user, pass,dbname,0,NULL,0))){
        fprintf(stderr, "\nError %s [%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }
    printf("\nConnection Successful\n\n");


    return conn;

}