#include "Base.h"

Address::Address()
{

}

Address::~Address()
{

}

std::string Address::get_contry()
{
	return contry;
}

std::string Address::get_subject()
{
	return subject;
}

std::string Address::get_town()
{
	return town;
}

std::string Address::get_outside()
{
	return outside;
}

std::string Address::get_house()
{
	return house;
}

std::string Address::get_flat()
{
	return flat;
}

void Address::set_contry(std::string _contry)
{
	contry = _contry;
}

void Address::set_subject(std::string _subject)
{
	subject = _subject;
}

void Address::set_town(std::string _town)
{
	
	town = _town;
}

void Address::set_outside(std::string _outside)
{
	outside = _outside;
}

void Address::set_house(std::string _house)
{
	house = _house;
}

void Address::set_flat(std::string _flat)
{
	flat = _flat;
}
