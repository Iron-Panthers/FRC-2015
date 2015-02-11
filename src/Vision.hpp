#ifndef VISION_HPP
#define VISION_HPP
#include <iostream>
#include <WPILib.h>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>

class Vision
{
public:
	Vision();
	float distanceToBox();
	float angleToBox();

	/*struct Scores
	{
		double rectangularity;
		double aspectRatioVertical;
		double aspectRatioHorizontal;
	};*/
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
private:
	const std::string cameraIP;
	AxisCamera camera;
	//Scores *scores;

	const float FOV;
	const float CAM_PROJECTION;
	const float WREAL;

};

#endif
