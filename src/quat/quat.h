#ifndef __RDTY_MATH_QUAT__
#define __RDTY_MATH_QUAT__



#include <initializer_list>



namespace RDTY::MATH
{
	// Needs to be dirived from Vec4 ?
	struct alignas(16) Quat
	{
		static Quat* New (void);



		alignas(16) float data [4];



		Quat (void);
		Quat (const void* src);
		Quat (const Quat& src);
		Quat (const Quat&& src);
		Quat (std::initializer_list<float> list);

		~Quat (void) = default;



		void operator = (const void* src);
		void operator = (const Quat& src);
		void operator = (const Quat&& src);



		void reset (void);
		void set (const float&, const float&, const float&, const float&);
		void ident (void);
		float len (void);
		float lensq (void);
		void norm (void);
		void mul32 (const void*, const void*);
		void mul128 (const void*, const void*);
		void premul128 (const void*);
		void premul32 (const void*);
		void postmul32 (const void*);
		void postmul128 (const void*);
		void makeRot32 (const void*, const float&);
		void makeRot128 (const void*, const float&);
		void preRot32 (const void*, const float&);
		void preRot128 (const void*, const float&);
		void postRot32 (const void*, const float&);
		void postRot128 (const void*, const float&);
		void makeRotX32 (const float&);
		void preRotX32 (const float&);
		void preRotX128 (const float&);
		void postRotX32 (const float&);
		void postRotX128 (const float&);
		void makeRotY32 (const float&);
		void preRotY32 (const float&);
		void preRotY128 (const float&);
		void postRotY32 (const float&);
		void postRotY128 (const float&);
		void makeRotZ32 (const float&);
		void preRotZ32 (const float&);
		void preRotZ128 (const float&);
		void postRotZ32 (const float&);
		void postRotZ128 (const float&);
		void print (void);
	};
}



#endif
