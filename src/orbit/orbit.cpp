// #include "mat4/mat4.h"
#include "math/src/orbit/orbit.h"



namespace RDTY::MATH
{
	// Orbit::Orbit (void)
	// {
	// 	rotation_speed_x = 0.0f;
	// 	rotation_speed_y = 0.0f;

	// 	translation_speed_x = 0.0f;
	// 	translation_speed_y = 0.0f;
	// 	translation_speed_z = 0.0f;
	// }

	void Orbit::setRotation (void)
	{
		object.setRotX(rotation_speed_x);
		// object.setRotY(rotation_speed_y);
	}

	void Orbit::rotate (void)
	{
		object.postRotX(rotation_speed_x);
		object.preRotY(rotation_speed_y);
	}

	void Orbit::rotate2 (const float& rotation_speed_x, const float& rotation_speed_y)
	{
		object.postRotX(rotation_speed_x);
		object.preRotY(rotation_speed_y);
	}

	void Orbit::rotate3 (const float rotation_speed_x, const float rotation_speed_y)
	{
		object.postRotX(rotation_speed_x);
		object.preRotY(rotation_speed_y);
	}

	void Orbit::transX (void)
	{
		object.transX(translation_speed_x);
	}

	void Orbit::transY(void)
	{
		object.transY(translation_speed_y);
	}

	void Orbit::transZ (void)
	{
		object.transZ(translation_speed_z);
	}

	void Orbit::update (void)
	{
		object.update();

		view_matrix = object.mat;

		view_matrix.invns32();
	}
}
