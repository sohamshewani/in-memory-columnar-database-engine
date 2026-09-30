#include "core.h"

int main() {
    // Entry point for the database engine
    initDatabase();
    // Example of adding a column to the database
    addColumnToDatabase("example_column", "integer");
    // Example of adding a row to the database
    addRowToDatabase("example_row");
    // Example of a scan operation
    scanDatabase();
    // Cleanup
    cleanupDatabase();
    return 0;
}