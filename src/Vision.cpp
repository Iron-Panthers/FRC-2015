#include "Vision.hpp"
#include <vector>
#define Y_IMAGE_RES 480
#define VIEW_ANGLE 49
#define PI 3.141592653
#define RECTANGULARITY_LIMIT 40
#define ASPECT_RATIO_LIMIT 55
#define AREA_MINIMUM 150
#define TAPE_WIDTH_LIMIT 50
#define VERTICAL_SCORE_LIMIT 50
#define LR_SCORE_LIMIT 50
#define MAX_PARTICLES 8





Vision::Vision()
	:cameraIP(std::string("localhost")), camera(cameraIP), FOV(62.85913123), CAM_PROJECTION(2), WREAL(20)
{

}

float Vision::distanceToBox()
{
	ColorImage *image;
	camera.GetImage(image);

	Threshold threshold(170, 185, 90, 255, 20, 255);
	ParticleFilterCriteria2 criteria[] = {
		IMAQ_MT_AREA, AREA_MINIMUM, 65535, false, false
	};

	BinaryImage *thresholdImage = image->ThresholdHSV(threshold);
	BinaryImage *convexHullImage = thresholdImage->ConvexHull(false);
	BinaryImage *filteredImage = convexHullImage->ParticleFilter(criteria, 1);

	std::vector<ParticleAnalysisReport> *reports = filteredImage->GetOrderedParticleAnalysisReports();
	for(int i = 0; i < reports->size(); i++)
	{
		ParticleAnalysisReport report = reports->at(i);
		Rect rectangle = report.boundingRect;
		std::cout << "Height: " << rectangle.height << "\t"
				  << "Width: " << rectangle.width << "\t"
				  << "Top: " << rectangle.top << "\t"
				  << "Left: " << rectangle.left << std::endl;
	}
	//scores = new Scores[reports->size()];
	float wfake = reports->at(0).boundingRect.width;
	float theta = FOV * wfake / CAM_PROJECTION;
	float distance = WREAL / tan(theta * M_PI / 180);
	std::cout << "wfake: " << wfake << '\t'
			  << "theta: " << theta << '\t'
			  << "distance: " << distance << std::endl;
	return distance;
}

float Vision::angleToBox()
{
	return 0;
}


