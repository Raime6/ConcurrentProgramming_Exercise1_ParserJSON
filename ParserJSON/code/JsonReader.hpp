
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/

#pragma once



#include "BinaryReader.hpp"
#include "JsonVariables.hpp"



namespace ParserJson
{
    class JsonReader
    {
        private:

            BinaryReader binaryReader;

        public:

            JsonReader(std::istream& stream) : binaryReader(stream) {}

        public:

            void read()
            {
                while (binaryReader.good())
                {
                    uint8_t type = binaryReader.getUInt8();  // Leer el tipo del elemento (OBJECT, ARRAY, etc.)
                }
            }

        private:

            void readValue()
            {
                uint8_t type = binaryReader.getUInt8();

                switch (type)
                {
                case STRING:
                {
                    std::string value = binaryReader.getString();
                    std::cout << "\"" << value << "\"";
                    break;
                }
                case NUMBER:
                {
                    uint32_t number = binaryReader.getUInt32();
                    std::cout << number;
                    break;
                }
                case BOOLEAN:
                {
                    uint8_t value = binaryReader.getUInt8();
                    std::cout << (value ? "true" : "false");
                    break;
                }
                case NULLVALUE:
                {
                    std::cout << "null";
                    break;
                }
                default:
                    std::cerr << "ERROR: unexpected value. " << int(type) << std::endl;
                }
            }
    };
};