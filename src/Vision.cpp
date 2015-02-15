#include "Vision.hpp"
#include <vector>

Vision::Vision()
	:cameraIP(std::string("10.50.26.20")), camera(cameraIP), FOV(62.85913123), CAM_PROJECTION(2), WREAL(20)
{

}

float Vision::distanceToBox()
{
	ColorImage *image = nullptr;
	camera.GetImage(image);
	Threshold threshold(120, 131, 90, 255, 20, 255);
	ParticleFilterCriteria2 criteria[] = {
		IMAQ_MT_AREA, 500, 65535, false, false
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
	/*std::cout << "wfake: " << wfake << '\t'
			  << "theta: " << theta << '\t'
			  << "distance: " << distance << std::endl;*/
	std::cout << distance << std::endl;
	return distance;
}

float Vision::angleToBox()
{
	return 0;
}


