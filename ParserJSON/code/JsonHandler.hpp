
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/



#include "BinaryWriter.hpp"



#include <cstdint>



namespace ParserJson
{
    class JsonHandler
    {
        private:

            BinaryWriter binaryWriter;

        public:

            JsonHandler(std::ostream& stream) : binaryWriter(stream) {};

        public:

            //bool Null() { cout << "Null()" << endl; return true; }
            //bool Bool(bool b) { cout << "Bool(" << boolalpha << b << ")" << endl; return true; }
            bool Int(int i) { return binaryWriter.put(i); }
            //bool Uint(unsigned u) { cout << "Uint(" << u << ")" << endl; return true; }
            //bool Int64(int64_t i) { cout << "Int64(" << i << ")" << endl; return true; }
            //bool Uint64(uint64_t u) { cout << "Uint64(" << u << ")" << endl; return true; }
            //bool Double(double d) { cout << "Double(" << d << ")" << endl; return true; }
            bool String(const char* str, size_t length, bool copy) { return binaryWriter.put(std::string(str, length)); }
            //bool StartObject() { cout << "StartObject()" << endl; return true; }
            /*bool Key(const char* str, size_t length, bool copy) {
                cout << "Key(" << str << ", " << length << ", " << boolalpha << copy << ")" << endl;
                return true;
            }*/
            //bool EndObject(size_t memberCount) { cout << "EndObject(" << memberCount << ")" << endl; return true; }
            //bool StartArray() { cout << "StartArray()" << endl; return true; }
            //bool EndArray(size_t elementCount) { cout << "EndArray(" << elementCount << ")" << endl; return true; }
    };
};