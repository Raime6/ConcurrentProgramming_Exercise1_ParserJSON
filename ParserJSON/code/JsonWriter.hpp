
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



using namespace std;



namespace ParserJson
{    
    class JsonWriter
    {
        private:

            struct User
            {
                string  gender;
                string    name;
                string surname;
                int        age;
                string   email;
                string country;
            };
    
        private:

            BinaryWriter binaryWriter;

            User user;

        public:

            JsonWriter(std::ostream& stream) : binaryWriter(stream) {};

            void WriteUser();

        public:

            bool Null()
            {
                return true;
            }

            bool Bool(bool boolean)
            {
                return true;
            }

            bool Int(int integer32)
            {
                return true;
            }

            bool Uint(unsigned uInteger32)
            {
                return true;
            }

            bool Int64(int64_t integer64)
            {
                return true;
            }

            bool Uint64(uint64_t uInteger64)
            {
                return true;
            }

            bool Double(double doubleNum)
            {
                return true;
            }

            bool String(const char* str, size_t length, bool copy)
            {
                return true;
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
                return true;
            }

            bool EndArray(size_t elementCount)
            {
                return true;
            }

            bool RawNumber(const char* str, size_t length, bool copy)
            {
                return true;
            }
    };

    inline void JsonWriter::WriteUser()
    {
        binaryWriter.put<string> (user. gender);
        binaryWriter.put<string> (user.   name);
        binaryWriter.put<string> (user.surname);
        binaryWriter.put<uint8_t>(user.    age);
        binaryWriter.put<string> (user.  email);
        binaryWriter.put<string> (user.country);
    }
};