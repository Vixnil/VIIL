#pragma once
#include <VIIL.h>

class BackgroundLayer : public VIIL::Layer
{
public:
	BackgroundLayer():
		Layer("BackgroundLayer")
	{
		VIIL::RendererAction::setClearColor({ .5f, .3f, .7f, 1.0f });
		VL_APP_TRACE("Constructed Background layer");
	}

	void onUpdate() override
	{
		VIIL::RendererAction::clear();
	}
};
