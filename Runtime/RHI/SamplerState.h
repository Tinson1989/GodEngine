#pragma once

#include "Runtime/Interface/IResource.h"

namespace GodEngine {

	class ISamplerState : public IRenderResource {
	public:
		virtual void SetState() = 0;
	};
	
}