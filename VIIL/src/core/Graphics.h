#pragma once

#include "standardUse.h"

struct GraphicsDeleter;

namespace VIIL
{
	class Graphics
	{
	protected:
		bool isInit;
	public:

		virtual void prepareDelete() {};
		inline bool getIsInit() { return isInit; }
	}; 

	struct GraphicsDeleter
	{
		void operator()(Graphics* gphs) const
		{
			gphs->prepareDelete();
			delete gphs;
		}
	};

	std::unique_ptr<Graphics, GraphicsDeleter> initializeGraphics();
}