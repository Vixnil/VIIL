#pragma once

#include "standardUse.h"
#include "core/input/inputValues.h"

struct GraphicsDeleter;

namespace VIIL
{
	class Graphics
	{
	protected:
		bool isInit;
	public:

		virtual void prepareDelete() = 0;
		virtual void createWindow(unsigned int& width, unsigned int& height, std::string titleString, void* userData) = 0;
		virtual void swapBuffers() = 0;

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