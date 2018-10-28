
#include "CommonStuffs.hpp"
#include "ConfigurationFiles.hpp"

#include <algorithm>
#include <iostream>
#include <ctime>
#include <sstream>
#include <cstdarg>

// C++17 only : defined in the upcoming C++ 17 standard
// #include <filesystem>
//std::string path = std::filesystem::current_path();

// See https://stackoverflow.com/questions/143174/how-do-i-get-the-directory-that-a-program-is-running-from
// In the meantime :
//#include <experimental/filesystem>
//std::string path = std::experimental::filesystem::current_path();

#ifdef WIN32 // Don't use WINDOWS !
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

// Can't understand why there is no shorter way to perform this conversion...
// In C++ 2011 there is finally to_string() !!!
std::string intToStr(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

// No real standard c++ to do this... See above !
std::string runningFolder()
{
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return ".";
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
	return std::string(cCurrentPath);
}

std::string stringUpper(const std::string &s)
{
  std::string result(s.size(), 0);
  std::transform(s.begin(), s.end(), result.begin(), [] (unsigned char c) { return toupper(c); } ); // Yes a lambda :)
  return result;
}

std::string appendPath(const std::vector<std::string> &pieces)
{
	std::string result;

	for (std::string piece : pieces)
	{
		result += piece; // auto usage was ok here but not in the line below :(
		if (piece.back() != PATH_SEPARATOR)
		{
			result += PATH_SEPARATOR;
		}
	}

	//std::cout << "result = " << result << std::endl;
	result.erase(result.end()-1); // Remove the trailing path separator :-)
	//std::cout << "result2 = " << result << std::endl;
	return result;
}

void join(std::string &dest, const std::string &item, const std::string &delimiter)
{
	if (dest.size() > 0)
	{
		dest += delimiter;
	}

  dest += item;
}

// Source = https://stackoverflow.com/questions/13172158/c-split-string-by-line
std::vector<std::string> split(const std::string& str, const std::string& delimiter)
{
    std::vector<std::string> result;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos)
    {
        result.push_back(str.substr(prev, pos - prev));
        prev = pos + delimiter.size();
    }

    // To get the last substring (or only, if delimiter is not found)
    result.push_back(str.substr(prev));
    return result;
}

// Source : https://stackoverflow.com/questions/150543/forward-an-invocation-of-a-variadic-function-in-c
// And also care about the last named parameter for the call to va_start :
// https://stackoverflow.com/questions/13189365/how-to-remove-this-warning-second-parameter-of-va-start-not-last-named-argume
void logThis2(const char *format, Target t, ...)
{
	char s[512]; // char[512] s; is ok in C# :)
	va_list args;
	va_start(args, t);
	vsnprintf(s, sizeof(s), format, args);
	logThis(s, t);
	va_end(args);
}

// In Rack/plugins/samlp_sandbox :
//
// Log formatted... Almost similar to printf :) But the "..." format string cannot be empty !-(
// #define LOGF(s, ...) logf(stringf(s, __VA_ARGS__).c_str())
//
// C like simple logger
// void logf(const char *s);

void logThis(const char *s, Target t)
{
  time_t rawtime;
  struct tm* timeinfo;
  char timestamp[32]; // Sure there is more C++ way to do this...

  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(timestamp, sizeof(timestamp), "%d/%m/%Y %H:%M:%S", timeinfo);

  std::string fullFilename = appendPath({ runningFolder(), targets[(int) t] }) + ".log";
  //std::cout << "fullFilename = " << fullFilename << std::endl;
  FILE *fLog = fopen(fullFilename.c_str(), "a");
  fprintf(fLog, "%s => %s\n", timestamp, s);
  fclose(fLog);
}
