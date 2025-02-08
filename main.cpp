#include <sqlite3.h>
#include <iostream>
#include "../include/db.h"

int main(){
    sqlite3 *db;
    char *zErrMsg = 0;

    // open the database
    int rc = sqlite3_open("database.db", &db);
	if (rc) {
		std::cout << "Can't open database: " << sqlite3_errmsg(db) << "\n";
	} else {
		std::cout << "Opened database successfully\n\n";
	}
    run_sqlite_commands(db);
    return 0;
}