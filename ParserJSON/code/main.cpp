
/**
* 
*	Open Source Code
*	
*	Author: Xavier Canals
* 
**/



#include "Asset.hpp"



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
	StringStream ss("../../binaries/assets/users.1000.json");

	// JSON Handler
	Handler handler;

	// Binary File
	asset.initialize(arguments[0]);
	ifstream binFile(asset.getAssetPath("binFile.bin"));

	// Parsing JSON File
	reader.Parse(ss, handler);

}
