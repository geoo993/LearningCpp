/*
 * ZoomList.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#include "ZoomList.h"

namespace fractalnamespace {

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height) {

}

void ZoomList::addUp(const Zoom &zoom){
	zooms.push_back(zoom);

	m_xCenter += (zoom.x - m_width/2) * m_scale;
	m_yCenter += (zoom.y - m_height/2) * m_scale;

	m_scale *= zoom.scale;
	//m_scale = m_scale * zoom.scale;

	m_zoom_positions.push_back(std::make_pair(m_xCenter, m_yCenter));
	m_zoom_scale.push_back(m_scale);

}

void ZoomList::addDown(const Zoom &zoom){
	zooms.push_back(zoom);

	m_xCenter += (zoom.x - m_width/2) * m_scale;
	m_yCenter += (zoom.y - m_height/2) * m_scale;

	m_scale = m_scale / zoom.scale;

	m_zoom_positions.push_back(std::make_pair(m_xCenter, m_yCenter));
	m_zoom_scale.push_back(m_scale);
}

void ZoomList::reset(int index){

	m_xCenter = m_zoom_positions[index].first;
	m_yCenter = m_zoom_positions[index].second;
	m_scale = m_zoom_scale[index];

}

void ZoomList::resize(){

	m_zoom_positions.erase (m_zoom_positions.begin() + 1, m_zoom_positions.end());
	m_zoom_scale.erase (m_zoom_scale.begin() + 1, m_zoom_scale.end());
	zooms.clear();

}

std::pair<double, double> ZoomList::doZoom(int x, int y) {

	double xFractal = (x - m_width/2) * m_scale + m_xCenter;
	double yFractal = (y - m_height/2) * m_scale + m_yCenter;

	return std::pair<double, double>(xFractal, yFractal);
}

}
