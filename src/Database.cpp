#include "../include/Database.hpp"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}


Database::Database()
{
    this->db = nullptr;
}

Database::~Database()
{
    close();
}

void Database::close()
{
      sqlite3_close(db);

      db = nullptr;

}

bool Database::createOrOpenDatabase(std::string path)
{
    return createDatabase(path);
}

bool Database::execute(std::string query)
{
    return queryExecutor(query);
}

/*bool Database::isDatabaseOpen()
{
    return (db == nullptr) ? false : true;
} */


bool Database::queryExecutor(std::string query)     // receives a string containing an sql command
{

  char* messaggeError;

  return (sqlite3_exec(this->db,
                              query.c_str(),      // sql string is converted to char array required by the function
                              NULL,
                              0,
                              &messaggeError) != SQLITE_OK) ? false : true;    // in case, cout messaggeError

}

bool Database::createDatabase(std::string path)
{
  std::string databaseName;

  databaseName = path + ".db";         // add .db at the end of string to form "databaseName".db
                                      // databaseName is converted to char array that is required by the sqlite3_open function

  return (sqlite3_open(databaseName.c_str(), &this->db) != SQLITE_OK) ? false : true; /** result is inverted **/

}
