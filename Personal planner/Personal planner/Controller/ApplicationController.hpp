#pragma once
#include <Model\Event.hpp>
#include <View\Messages.hpp>
#include <View\UserInterface.hpp>
#include <Controller\Connector.hpp>
#include <Controller\StatementDatabase.hpp>

class ApplicationController
{
private:
	std::shared_ptr<Event> eventModel;
	UserInterface view;
public:
	ApplicationController() = default;
	~ApplicationController() = default;
	void run();
private:
	Event* getEventFromInput();
};

