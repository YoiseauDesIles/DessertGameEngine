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
	}

	void OnEvent(Dessert::Event& event) override
	{
		DGE_INFO("{0}", event);
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
