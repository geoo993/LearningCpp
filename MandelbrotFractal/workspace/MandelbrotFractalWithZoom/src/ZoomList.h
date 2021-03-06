/*
 * ZoomList.h
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include "Zoom.h"

namespace fractalnamespace {

class ZoomList {
private:
	double m_xCenter{0};
	double m_yCenter{0};
	double m_scale{1.0};

	int m_width{0};
	int m_height{0};

public:
	std::vector<Zoom> zooms{};
	std::vector<std::pair<double,double>> m_zoom_positions;
	std::vector<double> m_zoom_scale;

	ZoomList(int width, int height);
	void addUp(const Zoom &zoom);
	void addDown(const Zoom &zoom);
	void reset(int index);
	void resize();
	std::pair<double, double> doZoom(int x, int y);
};

}

#endif /* ZOOMLIST_H_ */
