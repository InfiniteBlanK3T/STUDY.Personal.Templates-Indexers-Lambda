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
	std::fstream file (aFileName,std::ifstream::in);
	bool Result = false;	
	if ( file )
	{		
		if (file >> fSize)
		{
			{				
				fData = new DataMap[fSize];
				for ( size_t i = 0; i < fSize; i++ )
				{
					file >> fData[i];
				}
				Result = true;				
			}
		}
		file.close();		
	}
	return Result;
}

size_t DataWrapper::size() const noexcept
{
	return fSize;
}
