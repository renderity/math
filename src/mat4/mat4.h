#ifndef __RDTY_MATH_MAT4__
#define __RDTY_MATH_MAT4__



#include <initializer_list>



namespace RDTY::MATH
{
	struct alignas(16) Mat4
	{
		static Mat4* New (void);
		// static Mat4& New (void);



		alignas(16) float data [16];

		Mat4 (void);
		Mat4 (const void* src);
		Mat4 (const Mat4& src);
		Mat4 (const Mat4&& src);
		Mat4 (std::initializer_list<float> list);

		~Mat4 (void) = default;



		void operator = (const void* src);
		void operator = (const Mat4& src);
		void operator = (const Mat4&& src);



		void zero (void);
		void ident (void);

		void makeProjPersp
		(
			#ifdef __wasm__
				const float,
				const float,
				const float,
				const float,
				const float
			#else
				const float&,
				const float&,
				const float&,
				const float&,
				const float&
			#endif
		);

		void makeProjPersp
		(
			#ifdef __wasm__
				const float,
				const float,
				const float,
				const float,
				const float,
				const float
			#else
				const float&,
				const float&,
				const float&,
				const float&,
				const float&,
				const float&
			#endif
		);

		// Parameters are of void* type to allow using with both vector and scalar float types.
		// make const void* ?
		void mul32 (const void*, const void*);
		void mul128 (const void*, const void*);
		void transp32 (void);
		void transp128 (void);
		void preTrans32 (const void*);
		void preTrans128 (const void*);
		void postTrans32 (const void*);
		void postTrans128 (const void*);
		void makeRotationFromQuat32 (const void*);
		void makeRotationFromQuat128 (const void*);
		void invns32 (void);
		void invns128 (void);
		void print (void);
	};
}



#endif
