#include "core/standardUse.h"
#include "core/LayerStack.h"

namespace VIIL
{

	LayerStack::LayerStack()
	{
		layerInserter = layerList.begin();

		VL_ENGINE_TRACE("Layer stack contructed");
	}

	LayerStack::~LayerStack()
	{
		VL_ENGINE_TRACE("Layer stack destroyed");
	}

	void LayerStack::addLayer(std::shared_ptr<Layer> layer)
	{
		layerInserter = layerList.emplace(layerInserter, layer);
	}

	void LayerStack::addOverlay(std::shared_ptr<Layer> overlay)
	{
		layerList.emplace_back(overlay);
	}

	void LayerStack::removeLayer(std::shared_ptr<Layer> layer)
	{
		LayerVector::iterator item = std::find(layerList.begin(), layerList.end(), layer);

		if (item != layerList.end())
		{
			layerList.erase(item);
			layerInserter--;
		}
	}

	void LayerStack::removeOverlay(std::shared_ptr<Layer> overlay)
	{
		LayerVector::iterator item = std::find(layerList.begin(), layerList.end(), overlay);

		if (item != layerList.end())
		{
			layerList.erase(item);
		}
	}
}
