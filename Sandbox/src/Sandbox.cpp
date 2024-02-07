#include <Dessert.h>


class ExampleLayer : public Dessert::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		//DGE_INFO("ExampleLayer::Update");

		if (Dessert::Input::isKeyPressed(DGE_KEY_TAB))
			DGE_TRACE("TAB key is pressed");
	}

	void OnEvent(Dessert::Event& event) override
	{
		if (event.GetEventType() == Dessert::EventType::KeyPressed)
		{
			Dessert::KeyPressedEvent& e = (Dessert::KeyPressedEvent&)event;
			DGE_TRACE("{0}", (char)e.getKeyCode());
		}
	}
};

class Sandbox : public Dessert::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Dessert::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Dessert::Application* Dessert::CreateApplication()
{
	return new Sandbox();
}
