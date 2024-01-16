#pragma once

#ifdef DGE_PLATFORM_WINDOWS

extern Dessert::Application* Dessert::CreateApplication();

int main(int argc, char** argv) {

	auto app = Dessert::CreateApplication();
	app->Run();
	delete app;

}


#endif 
