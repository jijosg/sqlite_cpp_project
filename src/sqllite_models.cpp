#include "../include/db.h"
#include <sqlite3.h>
#include <iostream>

void run_sqlite_commands(sqlite3 *db){
	// create a schema
	const char *sql = "CREATE TABLE COMPANY( ID INT PRIMARY KEY     NOT NULL, NAME           TEXT    NOT NULL, AGE            INT     NOT NULL, ADDRESS        CHAR(50),SALARY         REAL );";
	
	// execute the schema
	char *zErrMsg = 0;
	int rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		std::cout << "SQL error: " << zErrMsg << "\n";
		sqlite3_free(zErrMsg);
	} else {
		std::cout << "Table created successfully\n\n";
	}
	// drop the table
	const char *sql2 = "DROP TABLE COMPANY;";
	rc = sqlite3_exec(db, sql2, 0, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		std::cout << "SQL error: " << zErrMsg << "\n";
		sqlite3_free(zErrMsg);
	} else {
		std::cout << "Table dropped successfully\n\n";
	}


	// close the database
    sqlite3_close(db);
	std::cout << "Closed database successfully\n\n";
}