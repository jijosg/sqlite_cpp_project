#include "main.h"
#include "linkedList/linkedList.c" // Include linked list implementation
#include "wrapper/wrapper.c"       // Include wrapper implementation
#include "sqlite3.h"

// Simple logging macro
#define LOG(msg, ...) printf("[LOG] " msg "\n", ##__VA_ARGS__)

int main(){
    LOG("Program started");
    LOG("Math Working: sqrt(5)=%f", sqrt(5));
    LOG("Hello from main");
    helloFromWrapper();
    helloFromLinkedList();

    // SQLite database pointer
    sqlite3 *db;
    int rc = sqlite3_open(":memory:", &db);
    if (rc == SQLITE_OK) {
        LOG("SQLite database opened successfully");
        sqlite3_stmt *stmt;
        const char *sql = "SELECT 1;";
        rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
        if (rc == SQLITE_OK) {
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                int value = sqlite3_column_int(stmt, 0);
                LOG("SELECT 1 result: %d", value);
            } else {
                LOG("No result from SELECT 1");
            }
            sqlite3_finalize(stmt);
        } else {
            LOG("Failed to prepare SELECT 1 statement: %d", rc);
        }
        sqlite3_close(db);
        LOG("SQLite database closed");
    } else {
        LOG("Failed to open SQLite database: %d", rc);
    }
    LOG("Program exiting");
    return 0; // Exit program
}