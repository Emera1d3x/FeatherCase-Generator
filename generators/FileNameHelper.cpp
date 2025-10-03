#include "FileNameHelper.h"
#include <string>

std::string fileNameHelper(std::string name, int extension, int testCaseNumber)
{
  std::string extensionString = "";
  if (extension == 0)
  {
    extensionString = ".in";
  }
  else
  {
    extensionString = ".txt";
  }
  std::string fileName = name + "." + std::to_string(testCaseNumber) + extensionString;
  return fileName;
}
