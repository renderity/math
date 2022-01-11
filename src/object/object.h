#ifndef __RDTY_MATH_OBJECT__
#define __RDTY_MATH_OBJECT__



#include "math/src/vec4/vec4.h"
#include "math/src/quat/quat.h"
#include "math/src/mat4/mat4.h"



namespace RDTY::MATH
{
	struct alignas(16) Object
	{
		Mat4 mat;
		Quat quat;
		Vec4 pos;
		Vec4 origin;
		Vec4 aux_vec;



		Object (void) = default;

		~Object (void) = default;

		void setRot    (const void*, const float&);
		void preRot    (const void*, const float&);
		void postRot   (const void*, const float&);
		void setRotX   (const float&);
		void preRotX   (const float&);
		void postRotX  (const float&);
		void setRotY   (const float&);
		void preRotY   (const float&);
		void postRotY  (const float&);
		void setRotZ   (const float&);
		void preRotZ   (const float&);
		void postRotZ  (const float&);
		void setTrans  (const void*);
		void trans     (const void*, const float&);
		void setTransX (const float&);
		void transX    (const float&);
		void setTransY (const float&);
		void transY    (const float&);
		void setTransZ (const float&);
		void transZ    (const float&);
		void update    (void);
		void update128 (void);
		void update2   (void);
		void update2_128   (void);
	};
}



#endif
