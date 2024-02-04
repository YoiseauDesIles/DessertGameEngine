#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Dessert/Events/ApplicationEvent.h"
#include "Window.h"


namespace Dessert {

	class DESSERT_API Application
	{
	public: 
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& event);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//To be defined in the client
	Application* CreateApplication();

}

