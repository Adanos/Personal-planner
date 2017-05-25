#include "ApplicationController.hpp"

void ApplicationController::run()
{
	bool l_isFinished = false;
	UserOptionEnum l_userOption;
	Connector l_connector;
	sql::Connection& l_connection = l_connector.getConnection();
	StatementDatabase l_statementDatabase(l_connection);
	std::shared_ptr<sql::ResultSet> l_resultSet(&l_statementDatabase.getAllRecords());

	while (!l_isFinished)
	{
		view.printInfoMessage(Messages::INFO_MESSAGE);
		l_userOption = view.getInputFromUser();

		if (l_userOption == UserOptionEnum::SELECT)
		{
			l_resultSet.reset(&l_statementDatabase.getAllRecords());
			view.printResults(*l_resultSet);
		}
		else if (l_userOption == UserOptionEnum::INSERT)
		{
			view.printInfoMessage(Messages::INPUT_EVENT_MESSAGE);
			eventModel.reset(getEventFromInput());
			l_resultSet.reset(&l_statementDatabase.insertEvent(*eventModel));
		}
		else if (l_userOption == UserOptionEnum::FINISH_PROGRAM)
			l_isFinished = true;
	}
}

Event* ApplicationController::getEventFromInput()
{
	std::string l_eventName, l_date;
	Event* l_event = nullptr;
	
	std::cout << Messages::ENTER_EVENT_NAME;
	std::cin.sync();
	std::getline(std::cin, l_eventName);
	std::cin.clear();
	std::cout << Messages::ENTER_DATE;
	std::getline(std::cin, l_date);

	l_event = Event::createEvent(l_eventName, l_date);

	while (l_event == nullptr)
	{
		std::cout << Messages::INCORRECT_DATE << std::endl;
		std::cout << Messages::ENTER_CORRECT_DATE;
		std::cin.sync();
		std::cin.clear();
		std::getline(std::cin, l_date);
		l_event = Event::createEvent(l_eventName, l_date);
	}
	
	return l_event;
}
