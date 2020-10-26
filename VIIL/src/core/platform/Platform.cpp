#include "standardUse.h"
#include "Platform.h"

namespace VIIL
{
	std::unique_ptr<Platform> Platform::plat = std::make_unique<Platform>();
}