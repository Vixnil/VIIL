#pragma once
#include "core/standardUse.h"
#include "core/Layer.h"

namespace VIIL
{
	using LayerVector = std::vector<std::shared_ptr<Layer>>;

	/*
	* Object to handle vector operations on a list of Layer objects.
	* To support rendering, introducing the concept of an overlay to add to
	* the end of the vector instead of only adding to the front.
	*/
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