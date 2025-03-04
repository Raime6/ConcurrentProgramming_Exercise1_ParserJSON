
/**
*
*	Open Source Code
*
*	Author: Xavier Canals
*
**/

#pragma once



namespace ParserJson
{
    enum VariableType
    {
        NULLVALUE,
        OBJECT,
        ENDOBJECT,
        ARRAY,
        ENDARRAY,
        KEY,
        NUMBER,
        STRING,
        BOOLEAN
    };
};