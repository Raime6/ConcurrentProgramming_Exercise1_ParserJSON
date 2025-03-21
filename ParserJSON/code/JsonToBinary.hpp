
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/

#pragma once



#include "BinaryWriter.hpp"



#include <functional>
#include <algorithm>
#include <unordered_map>



using namespace std;



namespace ParserJson
{    
    class JsonToBinary
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

                User() : gender(""), name(""), surname(""), age(0), email(""), country("") {}
            };

            const unordered_map< string, function< void() > > flagMap =
            {
                { "gender" , [this]() {            isGender  = true; } },
                { "name"   , [this]() {            isName    = true; } },
                { "first"  , [this]() { if(isName) isFirst   = true; } },
                { "last"   , [this]() { if(isName) isLast    = true; } },
                { "dob"    , [this]() {            isDob     = true; } },
                { "age"    , [this]() { if(isDob)  isAge     = true; } },
                { "email"  , [this]() {            isEmail   = true; } },
                { "country", [this]() {            isCountry = true; } }
            };
    
        private:

            BinaryWriter binaryWriter;

            User user;

            bool      isResults;
            bool       isGender;
            bool         isName;
            bool        isFirst;
            bool         isLast;
            bool          isDob;
            bool          isAge;
            bool        isEmail;
            bool      isCountry;

            int     objectCount;
            int  objectKeyCount;

        public:

            JsonToBinary(std::ofstream& stream) :
                binaryWriter (stream),
                user               (),
                isResults     (false),
                isGender      (false),
                isName        (false),
                isFirst       (false),
                isLast        (false),
                isDob         (false),
                isAge         (false),
                isEmail       (false),
                isCountry     (false),
                objectCount       (0),
                objectKeyCount    (0)
            {}

            void WriteUser();

            void toLowerCase(string & str)
            {
                transform(str.begin(), str.end(), str.begin(), ::tolower);
            }

        public:

            bool Null() { return true; }

            bool Bool(bool boolean) { return true; }

            bool Int(int integer32) { return true; }

            bool Uint(unsigned uInteger32)
            {
                if (isDob && isAge)
                {
                    user.age = uInteger32;
                    isAge    = false;
                    isDob    = false;
                }

                return true;
            }

            bool Int64(int64_t integer64)    { return true; }

            bool Uint64(uint64_t uInteger64) { return true; }

            bool Double(double doubleNum)    { return true; }

            bool String(const char* str, size_t length, bool copy)
            {
                string value(str);

                if (isGender)
                {
                    user.gender  = value;
                    isGender     = false;
                }
                else if (isFirst)
                {
                    if (isName)
                    {
                        user.name = value;
                        isFirst   = false;
                    }
                }
                else if (isLast)
                {
                    if (isName)
                    {
                        user.surname = value;
                        isLast       = false;
                        isName       = false;
                    }
                }
                else if (isEmail)
                {
                    user.email   = value;
                    isEmail      = false;
                }
                else if (isCountry)
                {
                    user.country = value;
                    isCountry    = false;
                }

                return true;
            }

            bool StartObject()
            {
                if (objectKeyCount == 0)
                    binaryWriter.put< uint32_t >(0);

                objectKeyCount++;

                return true;
            }
            
            bool Key(const char* str, size_t length, bool copy)
            {
                string  key(str);
                toLowerCase(key);

                if (isResults)
                {
                    auto it = flagMap.find(key);

                    if (it != flagMap.end())
                        it->second();
                }
                else if (key == "results" && !isResults)
                {
                    isResults = true;
                }

                return true;
            }
            bool EndObject(size_t memberCount)
            {
                objectKeyCount--;

                if (objectKeyCount == 0)
                {
                    auto stream = binaryWriter.GetStream();

                    if (stream)
                    {
                        stream->seekp(0, ios::beg);
                        binaryWriter.put< uint32_t >(objectCount);
                    }
                }
                else if (objectKeyCount == 1)
                {
                    WriteUser();
                    objectCount++;
                }

                return true;
            }

            bool StartArray() { return true; }

            bool EndArray(size_t elementCount) { return true; }

            bool RawNumber(const char* str, size_t length, bool copy) { return true; }
    };

    inline void JsonToBinary::WriteUser()
    {
        binaryWriter.put<string> (user. gender);
        binaryWriter.put<string> (user.   name);
        binaryWriter.put<string> (user.surname);
        binaryWriter.put<uint8_t>(user.    age);
        binaryWriter.put<string> (user.  email);
        binaryWriter.put<string> (user.country);
    }
};