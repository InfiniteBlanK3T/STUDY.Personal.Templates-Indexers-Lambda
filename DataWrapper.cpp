#include "DataWrapper.h"
#include <fstream>


DataWrapper::DataWrapper():
	fSize(0),
	fData(nullptr)
{}

DataWrapper::~DataWrapper()
{
	delete(fData);
}

const DataMap& DataWrapper::operator[](size_t aIndex) const
{
	return fData[aIndex];
}

bool DataWrapper::load(const std::string& aFileName)
{
	fstre
}
