#include "Event.hpp"

const std::string Event::regExDate = "\\d{4}-\\d{2}-\\d{2} \\d{1,2}:\\d{2}";

Event::Event()
{
}

Event::Event(std::string p_eventName, std::string p_date) : eventName(p_eventName), date(p_date)
{
}

Event* Event::createEvent(std::string p_eventName, std::string p_date)
{
	Event *l_event = nullptr;
	boost::regex l_regExDate(Event::regExDate);
	boost::smatch l_match;

	if (boost::regex_search(p_date, l_match, l_regExDate))
	{
		std::string strDate = l_match.str();
		l_event = new Event(p_eventName, strDate);
	}

	return l_event;
}
