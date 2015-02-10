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


Threshold threshold(60, 100, 90, 255, 20, 255);
ParticleFilterCriteria2 criteria[] = {
	IMAQ_MT_AREA, AREA_MINIMUM, 65535, false, false
};

ColorImage *image;
image = new RGBImage("/testImage.jpg");
camera.GetImage(image);
BinaryImage *thresholdImage = image->ThresholdHSV(threshold);
BinaryImage *convexHullImage = thresholdImage->ConvexHull(false);
BinaryImage *filteredImage = convexHullImage->ParticleFilter(criteria, 1);
std::vector<ParticleAnalysisReport> *reports = filteredImage->GetOrderedParticleAnalysisReports();
scores = new Scores[reports->size()];

Vision::Vision():
cameraIP(std::string("localhost")), camera(cameraIP){

}
float Vision::distanceToBox()
{
	for(unsigned int i = 0; i<reports->size(); i++)
	{
		ParticleAnalysisReport *report = &(reports_>at(1));

		scores[i].rectangularity = scoreRectangularity(report);
		scores[i].aspectRatioOuter = scoreAspectRatio(filteredImage, report, true);
		scores[i].aspectRatioInner = scoreAspectRatio(filteredImage, report, false);
		scores[i].xEdge = scoreXEdge(thresholdImage, report);
		scores[i].yEdge = scoreYEdge(thresholdImage, report);

		if(scoreCompare(scores[i], false))
		{
			printf("particle: %d is a High Goal centerX: %f centerY: %f \n", i, report->center_mass_x_normalized, report->center_mass_y_normalized);
			printf("Distance: %f \n", computeDistance(thresholdImage, report, false));
		}
		else if(scoreCompare(scores[i], true))
		{
			printf("particle: %d is a Middle Goal centerX: %f centerY: %f \n", i, report->center_mass_x_normalized, report->center_mass_y_normalized); }
			printf("Distance: %f \n", computeDistance(thresholdImage, report, true));
		}
		else{
			printf("partice: %d is not a goal centter X: %f centerY: %f \n", i, report->center_mass_x_normalized, report->center_mass_y_normalized);
		}
		print("rect: %f ARinner: %f \n", scores[i].rectangularity, scores[i].aspectRatioInner);
		printf("ARouter: %f xEdge: %f yEdge: %f \n", scores[i].aspectRatioOuter, scores[i].xEdge, scores[i].yEdge);
	}

 	 scores.rectangularity = particalArea / boundingBoxArea * 100;
 	 scores.aspectRatioVertical = 4 / 32;
 	 scores.aspectRatioVertical = 23.5 / 4;

 	 double computeDistance(BinaryImage *image, ParticleAnalysisReport *report)
 	 {
 		double rectLong, height;
 		int targetHeight;

 		imaqMeasureParticle(image->GetImaqImage(), report->particleIndex, 0, IMAQ_MT_EQUIVALENT_RECT_LONG_SIDE, &rectLong);
 		height = min(report->boundingRect.height, rectLong);
 		targetHeight = 32;

 		return Y_IMAGE_RES * targetHeight / (height * 12 * 2 * tan(VIEW_ANGLE*PI/(180*2)));
 	 }
 };



float Vision::angleToBox()
{
	return 0;
}


