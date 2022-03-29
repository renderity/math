#ifndef __RDTY_MATH_ORBIT__
#define __RDTY_MATH_ORBIT__



#include "math/src/mat4/mat4.h"
#include "math/src/object/object.h"



namespace RDTY::MATH
{

	struct alignas(16) Orbit
	{
		RDTY::MATH::Mat4 projection_matrix;
		RDTY::MATH::Mat4 view_matrix;
		RDTY::MATH::Object object;

		float rotation_speed_x {};
		float rotation_speed_y {};
		float translation_speed_x {};
		float translation_speed_y {};
		float translation_speed_z {};



		Orbit (void) = default;

		~Orbit (void) = default;

		void setRotation (void);
		void rotate (void);
		// use const float& macro
		void rotate2 (const float&, const float&);
		void rotate3 (const float, const float);
		void transX (void);
		void transY (void);
		void transZ (void);
		void update (void);
	};
}



#endif
