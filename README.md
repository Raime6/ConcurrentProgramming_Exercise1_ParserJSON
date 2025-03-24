# Concurrent Programming JSON Parser
</br>

## General Description
A small C++ project that reads a **JSON file**, converts its content into **binary code**, and writes it to another file. The process is carried out with the help of the RapidJSON library and **concurrent parsing (SAX)**.

## Process explanation
When the program is executed, an empty file is generated. The program then starts reading the JSON file and **parsing it concurrently** with the assistance of a handler that detects key elements in the JSON code (StartObject, Key, Int, String, EndObject, etc.). When a key is detected, it triggers a **lambda function stored in an unordered map**, which activates a flag. This ensures that when the key's value is later read, it can be stored in a struct. While reading a JSON object, its values are stored in a struct so that, when the program finishes reading the object, the entire struct is written to the binary file created at the start of the execution.

## Binary scheme
**gender**    = STRING  
**name**      = STRING  
**surname**   = STRING  
**age**       = UINT8  
**email**     = STRING  
**country**   = STRING  
**user**      = gender, name, surname, age, email, country  
**userCount** = UINT32  
**file**      = userCount, user[userCount]  
