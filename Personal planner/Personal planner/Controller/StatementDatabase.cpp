#include "StatementDatabase.hpp"

StatementDatabase::StatementDatabase(sql::Connection& p_connection)
{
	statement = p_connection.createStatement();
}

StatementDatabase::~StatementDatabase()
{
	delete statement;
}

sql::ResultSet& StatementDatabase::insertEvent(Event& p_event)
{
	try 
	{
		std::string l_query = "INSERT INTO Events (EventName, Time) VALUES('"
			+ p_event.getEventName() + "','" + p_event.getDate() + "');";
		std::cout << l_query << std::endl;
		return *statement->executeQuery(l_query);
	}
	catch (sql::SQLException &e) 
	{
		if (e.getErrorCode())
		{
			std::cout << "# ERR: SQLException in " << __FILE__;
			std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
			std::cout << "# ERR: " << e.what();
			std::cout << " (MySQL error code: " << e.getErrorCode();
			std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;
		}
	}
}

sql::ResultSet& StatementDatabase::getAllRecords()
{
	return *statement->executeQuery(QUERY_ALL_EVENTS);
}
