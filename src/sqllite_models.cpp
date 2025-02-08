#include "../include/db.h"
#include <sqlite3.h>
#include <iostream>

int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	for (int i = 0; i < argc; i++) {
		std::cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "\n";
	}
	std::cout << "\n";
	return 0;
}

void run_sqlite_commands(sqlite3 *db){
	// create a schema
	const char *sql = "CREATE TABLE COMPANY( ID INT PRIMARY KEY     NOT NULL, NAME           TEXT    NOT NULL, AGE            INT     NOT NULL, ADDRESS        CHAR(50),SALARY         REAL );";
	execute_sql_command(db, sql);
	// insert data
	const char *sql1 = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES (1, 'Paul', 32, 'California', 20000.00 );";
	execute_sql_command(db, sql1);
	// select from the table
	const char *sql3 = "SELECT * from COMPANY;";
	// print output of the select command
	std::cout << "Select command output:\n";
	sqlite3_exec(db, sql3, callback, 0, 0);


	// drop the table
	const char *sql2 = "DROP TABLE COMPANY;";
	execute_sql_command(db, sql2);


	// close the database
    sqlite3_close(db);
	std::cout << "Closed database successfully\n\n";
	// delete the database file
	std::remove("database.db");
}

// function to execute sqlite commands
void execute_sql_command(sqlite3 *db, const char *sql){
	char *zErrMsg = 0;
	int rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
		std::cout << "SQL error: " << zErrMsg << "\n";
		sqlite3_free(zErrMsg);
	} else {
		std::cout << "Command executed successfully\n\n";
	}
}

