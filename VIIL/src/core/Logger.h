#pragma once

#include "core/core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace VIIL
{
	enum class LEVEL : int
	{
		LV_TRACE = 0,
		LV_INFO,
		LV_WARN,
		LV_ERROR,
		LV_FATAL,
		LV_UNKNOWN
	};

	struct LogConfig
	{
		const std::string logName;
		const std::string logPatrn;
		const VIIL::LEVEL logLevel;

		LogConfig(std::string name, std::string patrn, VIIL::LEVEL level) :
			logName(name), logPatrn(patrn), logLevel(level)
		{

		}

	};

	class Logger
	{
		static const char* defaultAppName;

		static std::shared_ptr<spdlog::logger> engineLogger;
		static std::shared_ptr<spdlog::logger> appLogger;

	public:
		static const char* defaultLogPattern;
		
	public:
		static void init(const LogConfig& engineConfiguration, const LogConfig& appConfiguration);
		static void initEngineLogger(const LogConfig& engineConfiguration);

		inline static std::shared_ptr<spdlog::logger>& getEngineLogger() { return engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& getAppLogger() { return appLogger; }

		void Logger::changeLogLevel(LEVEL& logLevel);
	private:
		static spdlog::level::level_enum engineLevelToImplLevel(LEVEL logLevel);
	};

}

#ifdef VIIL_BUILD_RLS
#define VL_ENGINE_TRACE(...)
#define VL_ENGINE_INFO(...)
#define VL_ENGINE_WARN(...)
#define VL_ENGINE_ERROR(...)
#define VL_ENGINE_FATAL(...) 

#define VL_APP_TRACE(...)
#define VL_APP_INFO(...)
#define VL_APP_WARN(...)
#define VL_APP_ERROR(...)
#define VL_APP_FATAL(...)
#else
#define VL_ENGINE_TRACE(...) VIIL::Logger::getEngineLogger()->trace(__VA_ARGS__)
#define VL_ENGINE_INFO(...) VIIL::Logger::getEngineLogger()->info(__VA_ARGS__)
#define VL_ENGINE_WARN(...) VIIL::Logger::getEngineLogger()->warn(__VA_ARGS__)
#define VL_ENGINE_ERROR(...) VIIL::Logger::getEngineLogger()->error(__VA_ARGS__)
#define VL_ENGINE_FATAL(...) VIIL::Logger::getEngineLogger()->critical(__VA_ARGS__)

#define VL_APP_TRACE(...) VIIL::Logger::getAppLogger()->trace(__VA_ARGS__)
#define VL_APP_INFO(...) VIIL::Logger::getAppLogger()->info(__VA_ARGS__)
#define VL_APP_WARN(...) VIIL::Logger::getAppLogger()->warn(__VA_ARGS__)
#define VL_APP_ERROR(...) VIIL::Logger::getAppLogger()->error(__VA_ARGS__)
#define VL_APP_FATAL(...) VIIL::Logger::getAppLogger()->critical(__VA_ARGS__)
#endif
