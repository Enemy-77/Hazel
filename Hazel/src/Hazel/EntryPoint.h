#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int* argu, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARNING("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello! Var = {0}", a);


	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif // HZ_PLATFORM_WINDOW
