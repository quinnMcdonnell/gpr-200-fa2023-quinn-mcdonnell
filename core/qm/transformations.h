#pragma once
#include "../ew/ewMath/mat4.h"
#include "../ew/ewMath/vec3.h"

namespace qm
{
	inline ew::Mat4 Identity()
	{
		return ew::Mat4(
			1, 0, 0, 0, //column
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	};
	
	inline ew::Mat4 Scale(ew::Vec3 s) 
	{ 
		ew::Mat4 n = Identity();
		n[0][0] = s.x;
		n[1][1] = s.y;
		n[2][2] = s.z;

		return n;

	};

	inline ew::Mat4 RotateX(float rad) 
	{ 
		ew::Mat4 pitch = ew::Mat4(
			1, 0, 0, 0, //Column
			0, cos(rad), -sin(rad), 0,
			0, sin(rad), cos(rad), 0,
			0, 0, 0, 1
		);

		return pitch;
	};

	inline ew::Mat4 RotateY(float rad) 
	{ 
		ew::Mat4 yaw = ew::Mat4(
			cos(rad), 0, sin(rad), 0,
			0, 1, 0, 0,
			-sin(rad), 0, cos(rad), 0,
			0, 0, 0, 1
		);

		return yaw;
	};

	inline ew::Mat4 RotateZ(float rad) 
	{ 
		ew::Mat4 roll = ew::Mat4(
			cos(rad), -sin(rad), 0, 0,
			sin(rad), cos(rad), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);

		return roll;
	};

	inline ew::Mat4 Translate(ew::Vec3 t) 
	{ 
		ew::Mat4 n = Identity();
		n[3][0] = t.x;
		n[3][1] = t.y;
		n[3][2] = t.z;

		return n;
	};

	//Identity Matrix

	struct Transform {
		ew::Vec3 position = ew::Vec3(0.0f, 0.0f, 0.0f);
		ew::Vec3 rotation = ew::Vec3(0.0f, 0.0f, 0.0f); //Euler angles (degrees)
		ew::Vec3 scale = ew::Vec3(1.0f, 1.0f, 1.0f);
		ew::Mat4 getModelMatrix() const
		{
			ew::Mat4 modelMatrix = Translate(position) * RotateX(rotation.x) * RotateY(rotation.y) * RotateZ(rotation.z) * Scale(scale);
			return modelMatrix;
		}
	};
}