#include "Vision.hpp"

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

	Threshold threshold(60, 100, 90, 255, 20, 255);
	ParticleFilterCriteria2 criteria[] = {
			(IMAQ_MT_AREA, 	AREA_MINIMUM, 65535, false, false)
	};

	ColorImage *image;
	image = new RGBImage("/testImage.jpg");
	BinaryImage *thresholdImage = image->ThresholdHSV(threshold);
	BinaryImage *convexHullImage =  thresholdImage->convexHull(false);
	BinaryImage	*filteredImage = convexHullImage->ParticleFilter(criteria, 1);
	vector<ParticleAnalysisReport> *reports	= filteredImage->GetOrderedParticleAnalysisReports();
	scores = new scores[reports->size()];


Vision::Vision()
	: cameraIP(std::string("localhost")), camera(cameraIP)
{

}

float Vision::distanceToBox()
{
	for(unsigned i = 0; i<reports->size(); i++)
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
				printf("particle: %d is a Middle Goal centerX: %f centerY: %f \n", i, report->center_mass_x_normalized, report->center_mass_y_normalized);			}
				printf("Distance: %f \n", computeDistance(thresholdImage, report, true));
		} else {
			printf("partice: %d is not a goal centter X: %f centerY: %f \n", i, report->center_mass_x_normalized, report->center_mass_y_normalized);
		}
	print("rect: %f ARinner: %f \n", scores[i].rectangularity, scores[i].aspectRatioInner);
	printf("ARouter: %f xEdge: %f yEdge: %f \n", scores[i].aspectRatioOuter, scores[i].xEdge, scores[i].yEdge);


	Scores.rectangularity = particalArea / boundingBoxArea * 100;
	scores.aspectRatioVertical = 4 / 32;
	Scores.aspectRatioVertical = 23.5 / 4;
};

float Vision::angleToBox()
{

return 0;
};
