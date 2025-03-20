
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
#include <rapidjson/istreamwrapper.h>



#include <fstream>
#include <iostream>



using namespace ParserJson;
using namespace rapidjson;



int main(int, const char * arguments [])
{

	// JSON File
	Reader reader;

	ifstream jsonFile("../../binaries/assets/prueba.json");
	if (!jsonFile.is_open()) {
		cout << "ERROR while opening JSON file." << endl;
		return 1;
	}

	IStreamWrapper isw(jsonFile);

	// Binary File
	asset.initialize(arguments[0]);
	ofstream binFile(asset.getAssetPath("binFile.bin"), ofstream::binary);

	// JSON Handler
	JsonWriter jsonWriter(binFile);

	// Parsing JSON File
	if (!reader.Parse(isw, jsonWriter)) {
		cout << "ERROR while parsin the JSON file: " << reader.GetParseErrorCode() << endl;
		cout << "Error position: "					 << reader.GetErrorOffset()	   << endl;
		return 1;
	}



	// Read Binary file
	/*ifstream binInputFile(asset.getAssetPath("binFile.bin"), ifstream::binary);
	if (!binInputFile.is_open()) {
		cout << "ERROR while opening binary file." << endl;
		return 1;
	}

	JsonReader jsonReader(binInputFile);

	jsonReader.read();*/

	return 0;
}
