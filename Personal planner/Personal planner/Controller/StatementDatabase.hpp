#pragma once
#include <iostream>
#include "mysql_connection.h"
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <Model\Event.hpp>
class StatementDatabase
{
private:
	const std::string QUERY_ALL_EVENTS = "SELECT * from `myschema`.`Events`";
	sql::Statement *statement;
public:
	StatementDatabase(sql::Connection& p_connection);
	~StatementDatabase();
	sql::ResultSet& insertEvent(Event& p_event);
	sql::ResultSet& getAllRecords();
};

