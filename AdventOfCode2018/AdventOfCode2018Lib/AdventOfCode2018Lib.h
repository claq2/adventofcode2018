// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the ADVENTOFCODE2018LIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// ADVENTOFCODE2018LIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ADVENTOFCODE2018LIB_EXPORTS
#define ADVENTOFCODE2018LIB_API __declspec(dllexport)
#else
#define ADVENTOFCODE2018LIB_API __declspec(dllimport)
#endif

// This class is exported from the dll
//class ADVENTOFCODE2018LIB_API CAdventOfCode2018Lib {
//public:
//	CAdventOfCode2018Lib(void);
//	// TODO: add your methods here.
//};

//extern ADVENTOFCODE2018LIB_API int nAdventOfCode2018Lib;

//ADVENTOFCODE2018LIB_API int fnAdventOfCode2018Lib(void);
