#pragma once
#include <iostream>
#include <boost/regex.hpp>

class Event
{
public:
	static const std::string regExDate;
private:
	std::string eventName;
	std::string date;
	Event();
	Event(std::string p_eventName, std::string p_date);

public:
	Event(const Event& p_other) = default;
	Event& operator=(const Event& p_other) = default;
	~Event() = default;

	std::string getEventName()
	{
		return eventName;
	}
	std::string getDate()
	{
		return date;
	}

	friend void swap(Event& p_first, Event& p_second)
	{
		using std::swap;
		swap(p_first.eventName, p_second.eventName);
		swap(p_first.date, p_second.date);
	}

	static Event* createEvent(std::string p_eventName, std::string p_date);
};

