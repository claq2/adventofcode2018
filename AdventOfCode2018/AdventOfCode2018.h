// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the ADVENTOFCODE2018_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// ADVENTOFCODE2018_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ADVENTOFCODE2018_EXPORTS
#define ADVENTOFCODE2018_API __declspec(dllexport)
#else
#define ADVENTOFCODE2018_API __declspec(dllimport)
#endif

#include <vector>

// This class is exported from the dll
class ADVENTOFCODE2018_API Day01 {
public:
	Day01(void);
	int Part1(std::vector<int> input);
};
