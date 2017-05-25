#include "UserInterface.hpp"

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::printInfoMessage(std::string& p_message)
{
	std::cout << p_message << std::endl;
}

void UserInterface::printResults(sql::ResultSet& p_resultSet)
{
	int l_columnCount;
	std::string l_name;
	std::vector<std::string> l_columnNames;
	sql::ResultSetMetaData *l_resultSetMetaData = p_resultSet.getMetaData();
	
	l_columnCount = l_resultSetMetaData->getColumnCount();

	std::cout << "MySQL replies: " << "\n";
	for (int i = 1; i <= l_columnCount; ++i)
	{
		l_name = l_resultSetMetaData->getColumnName(i);
		std::cout << l_name << ";";
		l_columnNames.push_back(l_name);
	}

	std::cout << "\n";

	while (p_resultSet.next())
	{
		for (auto columnName : l_columnNames)
			std::cout << p_resultSet.getString(columnName) << ";";

		std::cout << "\n";
	}

	std::cout << std::endl;
}

UserOptionEnum UserInterface::getInputFromUser()
{
	const unsigned short L_MAX_USER_CHOICES = 3;
	unsigned short l_option;
	
	std::cin >> l_option;

	while (std::cin.fail() || !l_option || l_option > L_MAX_USER_CHOICES)
	{
		std::cout << "Error. Enter correct input 1 or 2." << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> l_option;
	}

	return static_cast<UserOptionEnum>(l_option);
}