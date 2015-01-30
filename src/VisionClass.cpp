#include "VisionClass.hpp"

#define Y_IMAGE_RES 480
#define VIEW_ANGLE 49
#define PI 3.141592653
#define RECTANGULARITY_LIMIT 40
#define ASPECT_RATIO_LIMIT 55

struct Scores
{
	double rectangularity;
	double aspectRatioVertical;
	double aspectRatioHorizontal;
};

struct TargetReport
{
	int verticalIndex;
	int horizontalIndex;
	bool Hot;
	double totalScore;
	double leftScore;
	double rightScore;
	double tapeWidthScore;
	double verticalScore;
};

Vision::Vision()
	: cameraIP(std::string("localhost")), camera(cameraIP)
{

}

float Vision::distanceToBox()
{
	Scores.rectangularity = particalArea / boundingBoxArea * 100;
	scores.aspectRatioVertical = 4 / 32;
	Scores.aspectRatioVertical = 23.5 / 4;
};

float Vision::angleToBox()
{

return 0;
};

