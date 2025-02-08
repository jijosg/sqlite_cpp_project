#ifndef DB_H
#define DB_H

#include <sqlite3.h>

void run_sqlite_commands(sqlite3 *db);
void execute_sql_command(sqlite3 *db, const char *sql);

#endif //DB_H