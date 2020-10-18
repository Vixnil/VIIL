#pragma once
#include "standardUse.h"
#include "Layer.h"

namespace VIIL
{
	using LayerVector = std::vector<std::shared_ptr<Layer>>;

	class LayerStack
	{
		LayerVector layerList;
		LayerVector::iterator layerInserter;

	public:
		LayerStack();
		~LayerStack();

		void addLayer(std::shared_ptr<Layer> layer);
		void addOverlay(std::shared_ptr<Layer> overlay);
		void removeLayer(std::shared_ptr<Layer> layer);
		void removeOverlay(std::shared_ptr<Layer> overlay);

		LayerVector::iterator begin() { return layerList.begin(); }
		LayerVector::iterator end() { return layerList.end(); }
	};

}