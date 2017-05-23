﻿#include <iostream>
#include <memory>
#include "Controller\Connector.hpp"
#include "Model\Event.hpp"

int main(void)
{
	Connector connector;
	std::unique_ptr<Event> event(Event::createEvent("test", "2012-09-09"));
	std::cout << event->getDate() << std::endl;
	//sql::Connection& conn = connector.getConnection();

	return 0;
}