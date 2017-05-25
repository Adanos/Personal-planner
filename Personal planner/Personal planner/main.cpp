#include <iostream>
#include <memory>
#include <Controller\Connector.hpp>
#include <Model\Event.hpp>
#include <Controller\StatementDatabase.hpp>
#include <cppconn\resultset_metadata.h>

void printEvents(std::shared_ptr<sql::ResultSet>& resultSet)
{
	sql::ResultSetMetaData *rsmd = resultSet->getMetaData();
	std::string name = rsmd->getColumnName(1);
	std::vector<std::string> columnNames;

	std::cout << "MySQL replies: " << std::endl;;
	for (int i = 1; i <= rsmd->getColumnCount(); ++i)
	{
		std::string name = rsmd->getColumnName(i);
		std::cout << name << ";";
		columnNames.push_back(name);
	}

	std::cout << std::endl;

	while (resultSet->next())
	{
		for (auto columnName : columnNames)
			std::cout << resultSet->getString(columnName) << ";";
			
		std::cout << std::endl;
	}
}

int main(void)
{
	Connector connector;
	std::unique_ptr<Event> event(Event::createEvent("test zdarzenia 3", "2017-01-09 2:00"));
	sql::Connection& connection = connector.getConnection();
	StatementDatabase statementDatabase(connection);
	std::shared_ptr<sql::ResultSet> resultSet(&statementDatabase.getAllRecords());

	printEvents(resultSet);

	if (event)
	{
		resultSet.reset(&statementDatabase.insertEvent(*event));
		std::cout << event->getDate() << std::endl;
	}
	else std::cout << "empty event" << std::endl;
	
	resultSet.reset(&statementDatabase.getAllRecords());

	printEvents(resultSet);

	return 0;
}