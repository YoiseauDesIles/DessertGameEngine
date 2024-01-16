#include <Dessert.h>


class Sandbox : public Dessert::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Dessert::Application* Dessert::CreateApplication()
{
	return new Sandbox();
}
