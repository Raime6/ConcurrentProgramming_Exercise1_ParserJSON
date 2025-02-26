
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/



#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>




class BinaryWriter
{
	std::ostream& writer;



public:

	BinaryWriter(std::ostream& givenWriter) : writer(givenWriter)
	{
		assert(writer.good());
	}



	bool good() const
	{
		return writer.good();
	}

	template <typename T>
	bool put(const T& value);

	template<>
	bool put< uint8_t >(const uint8_t& value)
	{
		writer.write(reinterpret_cast<const char*> (&value), sizeof(uint8_t));
		return good();
	}

	template<>
	bool put< uint32_t >(const uint32_t& value)
	{
		writer.write(reinterpret_cast<const char*> (&value), sizeof(uint32_t));
		return good();
	}

	template<>
	bool put< std::string >(const std::string& value)
	{
		std::vector<unsigned char> utf8_bytes(value.begin(), value.end());

		uint32_t length = utf8_bytes.size();

		put(length);

		writer.write(reinterpret_cast<const char*>(utf8_bytes.data()), length);

		return good();
	}
};
