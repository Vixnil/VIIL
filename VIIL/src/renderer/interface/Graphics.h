#pragma once
#include "core/standardUse.h"
#include "input/inputValues.h"

struct GraphicsDeleter;

namespace VIIL
{
	/*
	* Platform/Rendering API independent graphics class.
	*/
	class Graphics
	{
	protected:
		bool isInit;
	public:

		virtual void prepareDelete() = 0;
		virtual void createWindow(unsigned int& width, unsigned int& height, std::string titleString, void* userData) = 0;
		virtual void swapBuffers() = 0;
		virtual void isVsync(bool isVSyncOn) = 0;

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