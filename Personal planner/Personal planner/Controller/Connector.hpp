#pragma once
#include <memory>
#include "mysql_connection.h"
#include <cppconn/driver.h>

class Connector
{
private:
	sql::Driver *driver;
	sql::Connection *connection;

public:
	Connector();
	~Connector();
	sql::Connection& getConnection() const { return *connection; }
};

