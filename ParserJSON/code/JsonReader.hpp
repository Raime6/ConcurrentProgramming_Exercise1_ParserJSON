
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
                    switch (type)
                    {
                    case OBJECT:
                        std::cout << "{" << std::endl;
                        readObject();
                        break;

                    case ARRAY:
                        std::cout << "[" << std::endl;
                        readArray();
                        break;

                    case ENDOBJECT:
                        std::cout << "}" << std::endl;
                        break;

                    case ENDARRAY:
                        std::cout << "]" << std::endl;
                        break;

                    default:
                        std::cerr << "Unknown type: " << int(type) << std::endl;
                        return;
                    }
                }
            }

        private:
            void readObject()
            {
                bool first = true;

                while (binaryReader.good())
                {
                    uint8_t type = binaryReader.getUInt8();

                    if (type == ENDOBJECT)
                    {
                        std::cout << "}" << std::endl;
                        return;
                    }

                    if (type == KEY)
                    {
                        if (!first)
                        {
                            std::cout << ", ";
                        }
                        first = false;

                        std::string key = binaryReader.getString();
                        std::cout << "\"" << key << "\": ";
                        readValue();
                    }
                    else
                    {
                        std::cerr << "ERROR: expected a key. " << int(type) << std::endl;
                        return;
                    }
                }
            }

            void readArray()
            {
                bool first = true;

                while (binaryReader.good())
                {
                    uint8_t type = binaryReader.getUInt8();

                    if (type == ENDARRAY)
                    {
                        std::cout << "]" << std::endl;
                        return;
                    }

                    if (!first)
                    {
                        std::cout << ", ";
                    }
                    first = false;

                    readValue();
                }
            }

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