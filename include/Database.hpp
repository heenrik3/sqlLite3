#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <cstdbool>
#include <string>
#include <new>

#include "sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName);

class Database
{
    public:

      Database();
      virtual ~Database();
      void close();
      bool createOrOpenDatabase(std::string path);
      bool execute(std::string query);

    private:
      sqlite3 *db;                                // database connection
      bool createDatabase(std::string path);
      bool queryExecutor(std::string query);
};
#endif // DATABASE_HPP
