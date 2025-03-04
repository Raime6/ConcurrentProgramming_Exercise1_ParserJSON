
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/

#pragma once



#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>




class BinaryReader
{
	std::istream& reader;



public:

	BinaryReader(std::istream& givenReader) : reader(givenReader)
	{
		assert(reader.good());
	}



	bool good() const
	{
		return reader.good();
	}

	uint8_t getUInt8()
	{
		uint8_t value = 0;
		std::cout << value << std::endl;
		reader.read(reinterpret_cast< char* >(&value), sizeof(uint8_t));
		std::cout << value << std::endl;
		return value;
	}

	uint32_t getUInt32()
	{
		uint32_t value = 0;

		reader.read(reinterpret_cast< char* >(&value), sizeof(uint32_t));

		return value;
	}

	uint64_t getUInt64()
	{
		uint64_t value = 0;

		reader.read(reinterpret_cast<char*>(&value), sizeof(uint64_t));

		return value;
	}

	std::string getString()
	{
		uint32_t length = getUInt32();

		std::vector<char> buffer(length);

		reader.read(buffer.data(), length);

		return std::string(buffer.begin(), buffer.end());
	}
};
