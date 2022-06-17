#pragma once

// Tells VS whether to specify the functions and classes marked with XMMATHLIB_DLLEXPORT
// as to be exported in the *.lib that accompanies the *.dll or not.
// If no class or function is marked with __declspec(dllexport), then XMMathLib.lib won't be generated.
#ifdef _WIN32 
    #if TESTMATH_DLLEXPORT
        #define DLLEXPORT __declspec(dllexport)
    #else
        #define DLLEXPORT __declspec(dllimport)
    #endif
#else
    #define DLLEXPORT
#endif