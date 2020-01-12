#pragma once

#define FMT_HEADER_ONLY
#define FMT_DEPRECATED // Necessary in v6.0.0 of fmt library to avoid a Intel C++ v19.0 compiler error.
// Add path to include files, e.g. "fmt/include", to project properties under "VC++ Directories" and "Include Directories".

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Hazel {

	class HAZEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> GetCoreLog() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> GetClientLog() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core Log macros
#define  HZ_CORE_TRACE(...)    ::Hazel::Log::GetCoreLog()->trace(__VA_ARGS__)
#define  HZ_CORE_INFO(...)     ::Hazel::Log::GetCoreLog()->info(__VA_ARGS__)
#define  HZ_CORE_WARNING(...)  ::Hazel::Log::GetCoreLog()->warn(__VA_ARGS__)
#define  HZ_CORE_ERROR(...)    ::Hazel::Log::GetCoreLog()->error(__VA_ARGS__)
#define  HZ_CORE_FATAL(...)    ::Hazel::Log::GetCoreLog()->fatal(__VA_ARGS__)

//Client Log macros
#define  HZ_TRACE(...)         ::Hazel::Log::GetClientLog()->trace(__VA_ARGS__)
#define  HZ_INFO(...)          ::Hazel::Log::GetClientLog()->info(__VA_ARGS__)
#define  HZ_WARNING(...)       ::Hazel::Log::GetClientLog()->warn(__VA_ARGS__)
#define  HZ_ERROR(...)         ::Hazel::Log::GetClientLog()->error(__VA_ARGS__)
#define  HZ_FATAL(...)         ::Hazel::Log::GetClientLog()->fatal(__VA_ARGS__)

//if dist build



