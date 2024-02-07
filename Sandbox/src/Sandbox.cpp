#include <Dessert.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective

glm::mat4 camera(float Translate, glm::vec2 const& Rotate)
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.f);
	glm::mat4 View = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -Translate));
	View = glm::rotate(View, Rotate.y, glm::vec3(-1.0f, 0.0f, 0.0f));
	View = glm::rotate(View, Rotate.x, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 Model = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	return Projection * View * Model;
}


class ExampleLayer : public Dessert::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

		auto cam = camera(5.0f, { 0.5f, 0.5f });
		
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
