#include "core/standardUse.h"
#include "platform/windows/WindowsFile.h"

#include <fstream>

namespace VIIL
{
	static const int fileReadBufferSize = 2048;

	WindowsFile::WindowsFile(const std::string& newFilePath)
	{
		filePath = newFilePath;
	}

	std::string WindowsFile::readFileToString() const
	{
		std::string contents;
		std::ifstream inStream;
		char buffer[fileReadBufferSize];

		inStream.open(filePath);

		while (inStream.getline(buffer, fileReadBufferSize))
		{
			contents.append(buffer);
			contents.append("\n");
		}

		inStream.close();

		return contents;
	}
}
