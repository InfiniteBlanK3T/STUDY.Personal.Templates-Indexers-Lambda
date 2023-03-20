#include "DataWrapper.h"
#include <fstream>

DataWrapper::DataWrapper():
	fSize(0),
	fData(nullptr)
{}

DataWrapper::~DataWrapper()
{
	delete[] fData;
}

const DataMap& DataWrapper::operator[](size_t aIndex) const
{
	return fData[aIndex];
}

bool DataWrapper::load(const std::string& aFileName)
{
	std::fstream file;
	file.open(aFileName);
	if (file.is_open())
	{		
		file >> fSize;
		while (file >> fData[fSize])
		{
			fSize++;
		}

		return 0;
	}
	else
	{
		return 1;
	}
}

size_t DataWrapper::size() const noexcept
{
	return fSize;
}
