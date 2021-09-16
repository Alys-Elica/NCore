#ifndef NCLOGS_H
#define NCLOGS_H

#include "ncore_global.h"

#include <string>
#include <fstream>

namespace NCore {
	class NCORE_EXPORT NCLogs
	{
	public:
		enum Level {
			Fatal,
			Error,
			Warning,
			Info,
			Debug
		};

		NCLogs();
		~NCLogs();

		static void initLog(const std::string& filepath);

		static void fatal(const std::string& source, const std::string& message);
		static void error(const std::string& source, const std::string& message);
		static void warning(const std::string& source, const std::string& message);
		static void info(const std::string& source, const std::string& message);
		static void debug(const std::string& source, const std::string& message);

	private:
		std::ofstream m_logFile;

		void initFile(const std::string& filename);

		static inline NCLogs* getEngineLog();
		void log(const std::string& source, const Level& level, const std::string& message);
	};
}

#endif // NCLOGS_H
