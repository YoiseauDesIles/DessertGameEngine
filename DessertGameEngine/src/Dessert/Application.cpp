#include "dgepch.h"

#include "Application.h"
#include "Dessert/Core.h"

#include "Dessert/Events/ApplicationEvent.h"
#include "Dessert/Log.h"


namespace Dessert {
	
	Application::Application()
	{
		
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		
		if (e.IsInCategory(EventCategoryApplication))
			DGE_TRACE(e);
		if (e.IsInCategory(EventCategoryInput))
			DGE_TRACE(e); 
			


		while (true) {

		}
	}

}
