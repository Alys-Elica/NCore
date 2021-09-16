#include "nclogs.h"

#include <memory>

namespace NCore {
	NCLogs::NCLogs()
	{
	}

	NCLogs::~NCLogs()
	{
		log("NCLogs", Level::Info, "Stopped logging system.");
		m_logFile.close();
	}

	void NCLogs::initLog(const std::string& filepath)
	{
		getEngineLog()->initFile(filepath);
	}

	void NCLogs::fatal(const std::string& source, const std::string& message)
	{
		getEngineLog()->log(source, NCLogs::Fatal, message);
	}

	void NCLogs::error(const std::string& source, const std::string& message)
	{
		getEngineLog()->log(source, NCLogs::Error, message);
	}

	void NCLogs::warning(const std::string& source, const std::string& message)
	{
		getEngineLog()->log(source, NCLogs::Warning, message);
	}

	void NCLogs::info(const std::string& source, const std::string& message)
	{
		getEngineLog()->log(source, NCLogs::Info, message);
	}

	void NCLogs::debug(const std::string& source, const std::string& message)
	{
		getEngineLog()->log(source, NCLogs::Debug, message);
	}

	void NCLogs::initFile(const std::string& filename)
	{
		m_logFile.open(filename, std::ios_base::out | std::ios_base::app);
		log("NCLogs", Level::Info, "Started logging system.");
	}

	inline NCLogs* NCLogs::getEngineLog()
	{
		static std::unique_ptr<NCLogs> glog = std::make_unique<NCLogs>();

		return glog.get();
	}

	void NCLogs::log(const std::string& source, const NCLogs::Level& level, const std::string& message)
	{
		if (m_logFile.is_open()) {
			std::string levels[5] = { "Fatal", "Error", "Warning", "Info", "Debug" };
			m_logFile << "[" << source << "][" << levels[static_cast<int>(level)] << "] " << message << std::endl;
		}
	}
}
