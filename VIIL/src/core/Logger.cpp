#include "standardUse.h"
#include "Logger.h"

namespace VIIL
{
	const char* Logger::defaultLogPattern = "(%x - %X:%e) - T:%t - P:%P - {%n} %^[%L] : %v%$";
	const char* Logger::defaultAppName = "APP ";

	std::shared_ptr<spdlog::logger> Logger::engineLogger;
	std::shared_ptr<spdlog::logger> Logger::appLogger;

	void Logger::initEngineLogger(const LogConfig& engineConfiguration)
	{
		engineLogger = spdlog::stdout_color_mt(engineConfiguration.logName);
		engineLogger->set_pattern(engineConfiguration.logPatrn);
		engineLogger->set_level(engineLevelToImplLevel(engineConfiguration.logLevel));
	}

	void Logger::init(const LogConfig& engineConfiguration, const LogConfig& appConfiguration)
	{
		engineLogger->set_level(engineLevelToImplLevel(engineConfiguration.logLevel));

		VL_ENGINE_TRACE("Log initialized.");

		if (appConfiguration.logName.empty())
		{
			VL_ENGINE_WARN("Application name not set, using default value ", defaultAppName , ".");
			appLogger = spdlog::stdout_color_mt(defaultAppName);
		}
		else
		{
			if (appConfiguration.logName.length() > engineConfiguration.logName.length())
			{
				VL_ENGINE_WARN("Shortened app log name.");
				appLogger = spdlog::stdout_color_mt(appConfiguration.logName.substr(0, engineConfiguration.logName.length()));
			}
			else
			{
				appLogger = spdlog::stdout_color_mt(appConfiguration.logName);
			}
			
		}

		if (appConfiguration.logPatrn.empty())
		{
			VL_ENGINE_WARN("Application log pattern not set, using default pattern.");
			appLogger->set_pattern(defaultLogPattern);
		}
		else
		{
			appLogger->set_pattern(appConfiguration.logPatrn);
		}

		appLogger->set_level(engineLevelToImplLevel(appConfiguration.logLevel));

		VL_APP_TRACE("Log initialized.");
	}

	void Logger::changeLogLevel(LEVEL& logLevel)
	{
		engineLogger->set_level(engineLevelToImplLevel(logLevel));
	}

	spdlog::level::level_enum Logger::engineLevelToImplLevel(LEVEL logLevel)
	{
		switch (logLevel)
		{
		case LEVEL::LV_TRACE:
			return spdlog::level::trace;
			break;
		case LEVEL::LV_INFO:
			return spdlog::level::info;
			break;
		case LEVEL::LV_WARN:
			return spdlog::level::warn;
			break;
		case LEVEL::LV_ERROR:
			return spdlog::level::err;
			break;
		case LEVEL::LV_FATAL:
			return spdlog::level::critical;
		default:
			VL_ENGINE_WARN("Unknown log level set. Using Trace as default.");
			return spdlog::level::trace;
		}
	}
}