#pragma once
#include "Runtime/Interface/IResource.h"


namespace GodEngine {
	class IBlendState : public IRenderResource {
	public:
		virtual void SetEnable(bool enable) = 0;
	};
}