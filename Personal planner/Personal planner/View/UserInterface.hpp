#pragma once
#include <iostream>
#include <vector>
#include "mysql_connection.h"
#include <cppconn\resultset.h>
#include <cppconn\resultset_metadata.h>
#include <View\UserOptionEnum.hpp>

class UserInterface
{
public:
	UserInterface();
	~UserInterface();
	void printInfoMessage(std::string& p_message);
	void printResults(sql::ResultSet& p_resultSet);
	UserOptionEnum getInputFromUser();
};

