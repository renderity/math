// Is there a need to define simd functions since compiler properly vectorize scalar functions?
// Need to test!

#ifndef __RDTY_MATH_VEC4__
#define __RDTY_MATH_VEC4__



// size_t
#include <cstddef>
#include <initializer_list>
#include <vector>



namespace RDTY::MATH
{
	struct alignas(16) Vec4
	{
		alignas(16) float data [4];



		Vec4 (void);
		Vec4 (const void* src);
		Vec4 (const Vec4& src);
		Vec4 (const Vec4&& src);
		Vec4 (std::initializer_list<float> list);

		~Vec4 (void) = default;



		void operator = (const void* src);
		void operator = (const Vec4& src);
		void operator = (const Vec4&& src);



		void reset (void);
		void set (const float&, const float&, const float&, const float&);
		// todo
		float len (void);
		// todo
		float lensq (void);
		void add (const void*);
		void adds (const float&);
		void sub (const void*);
		void subs (const float&);
		void mul (const void*);
		void muls (const float&);
		void div (const void*);
		void divs (const float&);
		void norm (void);
		void print (void);



		void makeBezierCurve3Point
		(
			const float&,
			const float&,
			const float&,
			const float&,
			const float&,
			const float&,
			const float&,
			const float&,
			const float&
		);

		void makeBezierCurve2Point3D
		(
			const Vec4&,
			const Vec4&,
			const Vec4&,
			const float&
		);

		void makeBezierCurve3Point3D
		(
			const Vec4&,
			const Vec4&,
			const Vec4&,
			const Vec4&,
			const float&
		);

		void makeCatmullRomSpline3ControlPoint3D
		(
			const Vec4&,
			const Vec4&,
			const Vec4&,
			const float&
		);

		static void makeCatmullRomSpline3Points3D
		(
			std::vector<Vec4>&,
			std::vector<Vec4>&,
			const size_t&,
			const float&
		);

		static void makeCatmullRomSpline3PointsClosed3D
		(
			std::vector<Vec4>&,
			std::vector<Vec4>&,
			const size_t&,
			const float&
		);
	};
}



#endif
