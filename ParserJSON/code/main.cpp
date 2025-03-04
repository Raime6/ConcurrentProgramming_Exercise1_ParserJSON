
/**
* 
*	Open Source Code
*	
*	Author: Xavier Canals
* 
**/



#include "Asset.hpp"
#include "JsonReader.hpp"
#include "JsonWriter.hpp"



#include "rapidjson/reader.h"



#include <fstream>
#include <iostream>



using namespace ParserJson;
using namespace rapidjson;
using namespace std;



int main(int, const char * arguments [])
{

	// JSON File
	Reader reader;
	//StringStream ss("../../binaries/assets/users.1000.json");
	//StringStream ss("../../binaries/assets/prueba.json");

	ifstream jsonFile("../../binaries/assets/users.1000.json");
	if (!jsonFile.is_open()) {
		cout << "ERROR while opening JSON file." << endl;
		return 1;
	}

	string jsonContent((istreambuf_iterator<char>(jsonFile)), istreambuf_iterator<char>());

	StringStream ss(jsonContent.c_str());

	// Binary File
	asset.initialize(arguments[0]);
	ofstream binFile(asset.getAssetPath("binFile.bin"), ofstream::binary);

	// JSON Handler
	JsonWriter jsonWriter(binFile);

	// Parsing JSON File
	if (!reader.Parse(ss, jsonWriter)) {
		cout << "ERROR while parsin the JSON file: " << reader.GetParseErrorCode() << endl;
		cout << "Error position: " << reader.GetErrorOffset() << endl;
		return 1;
	}



	// Read Binary file
	ifstream binInputFile(asset.getAssetPath("binFile.bin"), ifstream::binary);
	if (!binInputFile.is_open()) {
		cout << "ERROR while opening binary file." << endl;
		return 1;
	}

	JsonReader jsonReader(binInputFile);

	jsonReader.read();

	return 0;
}
