#pragma once
#include "core/standardUse.h"
#include "core/LayerStack.h"
#include "platform/interface/Window.h"
#include "input/inputValues.h"

namespace VIIL
{
	class Application
	{
		using layerPtnr = std::shared_ptr<VIIL::Layer>;

		/*
		* There will only be one instance of application at run time. 
		* Once initialized this pointer will keep track of the object
		* to be easily referenced.
		*/
		static Application* applicationInstance;

		//Private Object variables
		bool appIsRunning;
		bool appIsMinimized;
		std::shared_ptr<Window> appWindow;
		VIIL::LayerStack layerStack;

	public:
		LogConfig appLogConfig;
		VIIL::LEVEL engineLogLevel;

		Application(VIIL::LEVEL engineLogLevel, const LogConfig& appLogData, VIIL::Window::WindowData windDef);

		virtual ~Application();
		void run();
		void doStart();
		void OnEvent(Event& event);
		void pushLayer(layerPtnr layer);
		void pushOverlay(layerPtnr overlay);

		inline static Application& getApp() { return *applicationInstance; }
		inline Window& getWindow() { return *(appWindow.get()); }

		/*
		* Needs to be virtual in case sub classes of application has pointers
		* that need to be cleaned up.
		*/
		virtual void prepareDelete() {}

	private:
		//Event handlers
		bool windowCloseHandler(WindowClose& event);
		bool windowResizeHandler(WindowResize& event);
	};

	/*
	* The application is being stored as a unique pointer to be shared and since there will
	* only ever be one application object at run time. Since Application may have pointers within it
	* the application method for cleaning up memory needs to be called when the application pointer 
	* is itself cleaned up.
	* 
	* Also, had issues where Application was not being destructed properly before adding a defined deleter.
	*/
	struct ApplicationDeleter
	{
		void operator()(Application* app) const
		{
			app->prepareDelete();
			delete app;
		}
	};

	/*
	* This is what allows users of the engine to create and customize their own application.
	* Users will provide the implementation of this function which will be used in Entry.h
	* to create and start the application.
	*/
	std::unique_ptr<VIIL::Application, VIIL::ApplicationDeleter> createApplication();
}

