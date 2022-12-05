#include "AllData.h"
#include <iostream>

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
	return GetAppPath() + "\Assets";
}

std::string GetAssetsPath(std::string fileName)
{
	std::cout << GetAssetsPath() + "\\" + fileName << std::endl;
	return GetAssetsPath() + "\\" + fileName;
}

bool IsOverlappingCircleOnCircle(sf::Vector2f aPosition, float aRadius, sf::Vector2f bPosition, float bRadius)
{
	sf::Vector2f aToB = bPosition - aPosition;
	float sqDistance = aToB.x * aToB.x + aToB.y * aToB.y;
	return sqDistance <= (aRadius + bRadius) * (aRadius + bRadius);
}

bool IsOverlappingBoxOnBox(sf::Vector2f aPosition, sf::Vector2f aSize, sf::Vector2f bPosition, sf::Vector2f bSize)
{
	sf::Vector2f aToBAbs = { abs(bPosition.x - aPosition.x), abs(bPosition.y - aPosition.y) };
	return (aToBAbs.x <= (aSize.x + bSize.x) * 0.5f) && (aToBAbs.y <= (aSize.y + bSize.y) * 0.5f);
}

bool IsOverlappingCircleOnBox(sf::Vector2f circlePosition, float radius, sf::Vector2f boxPosition, sf::Vector2f boxSize)
{
	sf::Vector2f boxToCircleAbs = { abs(circlePosition.x - boxPosition.x), abs(circlePosition.y - boxPosition.y) };

	if (boxToCircleAbs.x > (boxSize.x / 2.f + radius)) { return false; }
	if (boxToCircleAbs.y > (boxSize.y / 2.f + radius)) { return false; }

	if (boxToCircleAbs.x <= (boxSize.x / 2.f)) { return true; }
	if (boxToCircleAbs.y <= (boxSize.y / 2.f)) { return true; }

	float sqCornerDistance = (boxToCircleAbs.x - boxSize.x / 2.f) * (boxToCircleAbs.x - boxSize.x / 2.f) +
		(boxToCircleAbs.y - boxSize.y / 2.f) * (boxToCircleAbs.y - boxSize.y / 2.f);

	return sqCornerDistance <= radius * radius;
}

sf::Vector2f ConvertAngleToDirection(float degree, bool flipX, bool flipY)
{
	return ConvertRadianToDirection(DegreeToRadian(degree), flipX, flipY);
}

sf::Vector2f ConvertRadianToDirection(float radian, bool flipX, bool flipY)
{
	return sf::Vector2f(cos(radian) * (flipX ? -1.f : 1.f), sin(radian) * (flipY ? -1.f : 1.f));
}

float DegreeToRadian(float degree)
{
	return degree * PI / 180.f;
}

float RadianToDegree(float radian)
{
	return radian * 180.f / PI;
}

float GetMagnitude(sf::Vector2f v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

sf::Vector2f Normalize(sf::Vector2f v)
{
	if (v.x == 0.f && v.y == 0.f)
		return { 0.f, 0.f };
	return v / GetMagnitude(v);
}

float Dot(sf::Vector2f a, sf::Vector2f b)
{
	return a.x * b.x + a.y * b.y;
}

float GetDistance(sf::Vector2f a, sf::Vector2f b)
{
	return GetMagnitude(b - a);
}

float GetDistanceToLine(sf::Vector2f position, sf::Vector2f a, sf::Vector2f b)
{
	sf::Vector2f proj = GetProjectionOnLine(position, a, b);
	return GetMagnitude(proj - position);
}


sf::Vector2f GetProjectionOnLine(sf::Vector2f position, sf::Vector2f a, sf::Vector2f b)
{
	sf::Vector2f AP = position - a;
	sf::Vector2f AB = b - a;
	return a + Normalize(AB) * Dot(Normalize(AP), Normalize(AB));
}

float Lerp(float a, float b, float t)
{
	return a + (b - a) * t;
}

sf::Vector2f Lerp(sf::Vector2f a, sf::Vector2f b, float t)
{
	return a + (b - a) * t;
}