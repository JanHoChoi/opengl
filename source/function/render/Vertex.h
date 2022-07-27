#pragma once

#include "core/math/Vector3.h"
#include "core/math/Vector2.h"

namespace LearnOpenGL
{
	struct Vertex
	{
		Vector3 position = { 0.0f, 0.0f, 0.0f };
		Vector3 color = { 0.0f, 0.0f, 0.0f };
		Vector2 uv = { 0.0f, 0.0f };
	};
}
