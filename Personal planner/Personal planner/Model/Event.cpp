#include "Event.hpp"

const std::string Event::regExDate = "\\d{4}-\\d{2}-\\d{2}";

Event::Event()
{
}

Event::Event(std::string p_eventName, std::string p_date) : eventName(p_eventName), date(p_date)
{
}

Event::Event(const Event& p_other)
{
	Event temp(p_other);
	swap(*this, temp);
}

Event& Event::operator=(const Event& p_other)
{
	Event temp(p_other);
	swap(*this, temp);

	return *this;
}

Event::Event(Event&& p_other) :Event()
{
	swap(*this, p_other);
}

Event& Event::operator=(Event&& p_other)
{
	swap(*this, p_other);
	return *this;
}

Event::~Event()
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
		l_event = new Event(p_eventName, p_date);
	}

	return l_event;
}
