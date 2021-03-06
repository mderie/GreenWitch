
#ifndef CONFIGURATION_FILES
#define CONFIGURATION_FILES

#include <string>
#include <map> // We could also use unordered map here...
#include <vector>

class ConfigurationFile
{
private:
  std::map<std::string, std::map<std::string, std::string> > m_contents; // The "> > " means I'm old school :)
public:
	ConfigurationFile(const std::string &filename);
	~ConfigurationFile();
	std::string keyValue(const std::string &section, const std::string &key);
	std::vector<std::string> keyNames(const std::string &section);
};

#endif // CONFIGURATION_FILES
