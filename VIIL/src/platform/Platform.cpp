#include "core/standardUse.h"
#include "platform/Platform.h"

namespace VIIL
{
	std::unique_ptr<Platform> Platform::plat = std::make_unique<Platform>();
}