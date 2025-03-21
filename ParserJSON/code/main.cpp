
/**
* 
*	Open Source Code
*	
*	Author: Xavier Canals
* 
**/



#include "Asset.hpp"
#include "JsonToBinary.hpp"



#include "rapidjson/reader.h"
#include <rapidjson/istreamwrapper.h>



#include <fstream>
#include <iostream>



using namespace ParserJson;
using namespace rapidjson;



int main(int, const char * arguments [])
{

	// JSON File
	Reader reader;

	ifstream jsonFile("../../binaries/assets/users.1000.json");
	if (!jsonFile.is_open()) {
		cout << "ERROR while opening JSON file." << endl;
		return 1;
	}

	IStreamWrapper isw(jsonFile);

	// Binary File
	asset.initialize(arguments[0]);
	ofstream binFile(asset.getAssetPath("binFile.bin"), ofstream::binary);

	// JSON Handler
	JsonToBinary jsonToBinary(binFile);

	// Parsing JSON File
	if (!reader.Parse(isw, jsonToBinary)) {
		cout << "ERROR while parsin the JSON file: " << reader.GetParseErrorCode() << endl;
		cout << "Error position: "					 << reader.GetErrorOffset()	   << endl;
		return 1;
	}

	return 0;
}
