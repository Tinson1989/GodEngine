#pragma once

#include"Runtime/Math/Matrix.h"
#include"Runtime/Math/Vector.h"

namespace GodEngine {
	class IRenderResource{
	};

	struct ConstantBuffer
	{
		Matrix4x4f	world;
		Matrix4x4f	view;
		Matrix4x4f	projection;
		Vector4f	debugColor;
		Vector4f	pbrParameter;
		Vector4f	camPos;
		
	};

	struct ConstantBufferLighting {
		Vector4f	SunLightDir;
		Vector4f	SunLightColor;

		Vector4f	PointLightDir[4];
		Vector4f	PointLightColor[4];
	};

	struct ConstantBufferAnimation {
		Matrix4x4f boneMatrix[32];
	};
}