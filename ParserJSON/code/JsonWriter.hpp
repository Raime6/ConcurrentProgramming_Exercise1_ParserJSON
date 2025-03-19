
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/

#pragma once



#include "BinaryWriter.hpp"
#include "JsonVariables.hpp"



namespace ParserJson
{    
    class JsonWriter
    {
        private:

            BinaryWriter binaryWriter;

        public:

            JsonWriter(std::ostream& stream) : binaryWriter(stream) {};

        public:

            bool Null()
            {
                return binaryWriter.put<uint8_t>(NULLVALUE);
            }

            bool Bool(bool boolean)
            {
                binaryWriter.put<uint8_t>(BOOLEAN);
                return binaryWriter.put<uint8_t>(boolean);
            }

            bool Int(int integer32)
            {
                binaryWriter.put<uint8_t>(NUMBER);
                return binaryWriter.put<uint32_t>(integer32);
            }

            bool Uint(unsigned uInteger32)
            {
                binaryWriter.put<uint8_t>(NUMBER);
                return binaryWriter.put<uint32_t>(uInteger32);
            }

            bool Int64(int64_t integer64)
            {
                binaryWriter.put<uint8_t>(NUMBER);
                return binaryWriter.put<uint64_t>(integer64);
            }

            bool Uint64(uint64_t uInteger64)
            {
                binaryWriter.put<uint8_t>(NUMBER);
                return binaryWriter.put<uint64_t>(uInteger64);
            }

            bool Double(double doubleNum)
            {
                binaryWriter.put<uint8_t>(NUMBER);
                return binaryWriter.put<uint64_t>(reinterpret_cast<uint64_t>(&doubleNum));
            }

            bool String(const char* str, size_t length, bool copy)
            {
                binaryWriter.put<uint8_t>(STRING);
                return binaryWriter.put<string>(str);
            }

            bool StartObject()
            {
                return true;
            }

            bool Key(const char* str, size_t length, bool copy)
            {
                return true;
            }

            bool EndObject(size_t memberCount)
            {
                return true;
            }

            bool StartArray()
            {
                return binaryWriter.put<uint8_t>(ARRAY);
            }

            bool EndArray(size_t elementCount)
            {
                return true;
            }

            bool RawNumber(const char* str, size_t length, bool copy)
            {
                binaryWriter.put<uint8_t>(NUMBER);
                return binaryWriter.put<string>(str);
            }
    };
};