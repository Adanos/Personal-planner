#include <iostream>
#include <memory>
#include <Controller\Connector.hpp>
#include <Model\Event.hpp>
#include <Controller\StatementDatabase.hpp>

void printEvents(std::shared_ptr<sql::ResultSet>& resultSet)
{
	while (resultSet->next())
	{
		std::cout << "MySQL replies: ";
		std::cout << resultSet->getString("EventName") << std::endl;
		std::cout << resultSet->getString("Time") << std::endl;
		std::cout << resultSet->getString("IdEvents") << std::endl;
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