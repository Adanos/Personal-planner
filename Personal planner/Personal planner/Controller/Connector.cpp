#include "Connector.hpp"

Connector::Connector()
{
	driver = get_driver_instance();
	connection = driver->connect("tcp://127.0.0.1:3306", "root", "password");
	connection->setSchema("myschema");
}

Connector::~Connector()
{
	delete connection;
}
