
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/



#include <cassert>
#include <iostream>




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
		writer.write(reinterpret_cast< const char * > (&value), sizeof(uint8_t));
	}
};
