#include "dgepch.h"
#include "WindowsWindow.h"


namespace Dessert {

	static bool s_GLFWInitialized = false;


	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}


	Dessert::WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	Dessert::WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void Dessert::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void Dessert::WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;

	}

	bool Dessert::WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

	void Dessert::WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		DGE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			//TODO glfwTerminate on system shutdown
			int success = glfwInit();
			DGE_CORE_ASSERT(success, "Could not initialize GLFW");

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

	}

	void Dessert::WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}


}
