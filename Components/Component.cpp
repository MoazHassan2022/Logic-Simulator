#include "Component.h"

Component::Component(const GraphicsInfo& r_GfxInfo) :IsSelected(0)
{
	m_GfxInfo = r_GfxInfo;	

}

GraphicsInfo Component::Getm_GfxInfo() {
	return m_GfxInfo;
}

Component::Component()
{}

Component::~Component()
{}

void Component::setLabel(string label) {
	m_Label = label;
};

string Component::getlabel() {
	return m_Label;
};

