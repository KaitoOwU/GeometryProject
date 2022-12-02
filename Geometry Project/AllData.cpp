#include "AllData.h"

std::string GetAppPath() {
	char cExeFilePath[256];
	GetModuleFileNameA(NULL, cExeFilePath, 256);
	std::string exeFilePath = cExeFilePath;
	int exeNamePos = exeFilePath.find_last_of("\\/");
	std::string appPath = exeFilePath.substr(0, exeNamePos + 1);
	return appPath;
}

std::string GetAssetsPath()
{
	return GetAppPath() + "\\Assets";
}

std::string GetAssetsPath(std::string fileName)
{
	return GetAssetsPath() + fileName;
}

sf::Vector2f Normalize(sf::Vector2f& vector)
{
	float oldNorm = sqrt(vector.x * vector.x + vector.y * vector.y);
	return sf::Vector2f(vector.x / oldNorm, vector.y / oldNorm);
}
