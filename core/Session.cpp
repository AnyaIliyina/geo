#include "Session.h"

Session::Session(int user_id, QString session_start, QString session_finish)
{
}

Session::Session(int id)
{
}

Session::~Session()
{
}

int Session::session_id()
{
	return 0;
}

bool Session::insertIntoDatabase()
{
	return false;
}

bool Session::createTable()
{
	return false;
}

bool Session::completeTable()
{
	return false;
}
