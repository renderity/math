#define SET(x, y, z, w) data[0] = x; data[1] = y; data[2] = z; data[3] = w;



// uint8_t
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cmath>

#include "math/src/vec4/vec4.h"



namespace RDTY::MATH
{
	namespace CONST
	{
		extern const uint8_t FLOAT_SIZE_4;

		alignas(16) extern const float ZERO_4 [4];
	}



	Vec4::Vec4 (void)
	{
		memcpy(data, CONST::ZERO_4, CONST::FLOAT_SIZE_4);

		// // compare performance with
		// memset(data, 0, FLOAT_SIZE_4);
	}

	Vec4::Vec4 (const void* src)
	{
		memcpy(data, src, CONST::FLOAT_SIZE_4);
	}

	Vec4::Vec4 (const Vec4& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_4);
	}

	Vec4::Vec4 (const Vec4&& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_4);
	}

	Vec4::Vec4 (std::initializer_list<float> list)
	{
		size_t count {};

		for (float element : list)
		{
			data[count++] = element;

			if (count == 4)
			{
				break;
			}
		}
	}

	// Vec4::~Vec4 (void) {}



	void Vec4::operator = (const void* src)
	{
		memcpy(data, src, CONST::FLOAT_SIZE_4);
	}

	void Vec4::operator = (const Vec4& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_4);
	}

	void Vec4::operator = (const Vec4&& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_4);
	}



	void Vec4::reset (void)
	{
		memcpy(data, CONST::ZERO_4, CONST::FLOAT_SIZE_4);
	}

	void Vec4::set (const float& x, const float& y, const float& z, const float& w)
	{
		SET(x, y, z, w)
	}

	void Vec4::add (const void* src)
	{
		float* _src { (float*) src };

		data[0] += _src[0];
		data[1] += _src[1];
		data[2] += _src[2];
		data[3] += _src[3];
	}

	void Vec4::adds (const float& s)
	{
		data[0] += s;
		data[1] += s;
		data[2] += s;
		data[3] += s;
	}

	void Vec4::sub (const void* src)
	{
		float* _src { (float*) src };

		data[0] -= _src[0];
		data[1] -= _src[1];
		data[2] -= _src[2];
		data[3] -= _src[3];
	}

	void Vec4::subs (const float& s)
	{
		data[0] -= s;
		data[1] -= s;
		data[2] -= s;
		data[3] -= s;
	}

	void Vec4::mul (const void* src)
	{
		float* _src { (float*) src };

		data[0] *= _src[0];
		data[1] *= _src[1];
		data[2] *= _src[2];
		data[3] *= _src[3];
	}

	void Vec4::muls (const float& s)
	{
		data[0] *= s;
		data[1] *= s;
		data[2] *= s;
		data[3] *= s;
	}

	void Vec4::div (const void* src)
	{
		float* _src { (float*) src };

		data[0] /= _src[0];
		data[1] /= _src[1];
		data[2] /= _src[2];
		data[3] /= _src[3];
	}

	void Vec4::divs (const float& s)
	{
		data[0] /= s;
		data[1] /= s;
		data[2] /= s;
		data[3] /= s;
	}

	void Vec4::norm (void)
	{
		float len
		{
			static_cast<float>
			(
				sqrt
				(
					(data[0] * data[0]) +
					(data[1] * data[1]) +
					(data[2] * data[2]) +
					(data[3] * data[3])
				)
			)
		};

		data[0] /= len;
		data[1] /= len;
		data[2] /= len;
		data[3] /= len;
	}

	void Vec4::print (void)
	{
		printf("%f %f %f %f\n\n", data[0], data[1], data[2], data[3]);
	}



	void Vec4::makeBezierCurve3Point
	(
		const float& x1,
		const float& y1,
		const float& x2,
		const float& y2,
		const float& x3,
		const float& y3,
		const float& x4,
		const float& y4,
		const float& t
	)
	{
		const float a { 1.0f - t };
		const float b { a * a };
		const float c { t * t };
		const float d { a * b };
		const float e { 3.0f * t * b };
		const float f { 3.0f * c * a };
		const float g { c * t };

		data[0] = (x1 * d) + (x2 * e) + (x3 * f) + (x4 * g);
		data[1] = (y1 * d) + (y2 * e) + (y3 * f) + (y4 * g);
		data[2] = 0.0f;
		data[3] = 0.0f;
	}

	void Vec4::makeBezierCurve2Point3D
	(
		const Vec4& p1,
		const Vec4& p2,
		const Vec4& p3,
		const float& t
	)
	{
		const float a { 1.0f - t };
		const float b { a * a };
		const float c { 2.0f * t * a };
		const float d { t * t };

		reset();

		Vec4 v { p1 };
		v.muls(b);
		add(&v);

		v = p2;
		v.muls(c);
		add(&v);

		v = p3;
		v.muls(d);
		add(&v);
	}

	void Vec4::makeBezierCurve3Point3D
	(
		const Vec4& p1,
		const Vec4& p2,
		const Vec4& p3,
		const Vec4& p4,
		const float& t
	)
	{
		const float a { 1.0f - t };
		const float b { a * a };
		const float c { t * t };
		const float d { a * b };
		const float e { 3.0f * t * b };
		const float f { 3.0f * c * a };
		const float g { c * t };

		reset();

		Vec4 v { p1 };
		v.muls(d);
		add(&v);

		v = p2;
		v.muls(e);
		add(&v);

		v = p3;
		v.muls(f);
		add(&v);

		v = p4;
		v.muls(g);
		add(&v);
	}

	void Vec4::makeCatmullRomSpline3ControlPoint3D
	(
		const Vec4& p1,
		const Vec4& p2,
		const Vec4& p3,
		const float& t
	)
	{
		reset();
		add(&p3);
		sub(&p1);
		muls(t);
		add(&p2);
	}

	void Vec4::makeCatmullRomSpline3Points3D
	(
		std::vector<Vec4>& dst,
		std::vector<Vec4>& points,
		const size_t& segment_count,
		const float& tension
	)
	{
		Vec4 prev_control_point;
		Vec4 next_control_point;

		Vec4* points_data { points.data() };
		const size_t points_size { points.size() };

		for (size_t i {}; i < points_size; ++i)
		{
			Vec4 prev_point { i > 0 ? points_data[i - 1] : points_data[i - 1 + points_size] };
			Vec4 curr_point { points_data[i] };
			Vec4 next_point { i < points_size ? &points_data[i + 1] : &points_data[i + 1 - points_size] };
			Vec4 next_next_point { i < (points_size - 1) ? &points_data[i + 2] : &points_data[i + 2 - points_size] };

			prev_control_point.makeCatmullRomSpline3ControlPoint3D(prev_point, curr_point, next_point, tension);
			next_control_point.makeCatmullRomSpline3ControlPoint3D(curr_point, next_point, next_next_point, -tension);

			for (size_t k {}; k < segment_count; ++k)
			{
				const float t { ((float) k) / ((float) segment_count) };

				Vec4 point;

				if (i == 0)
				{
					point.makeBezierCurve2Point3D(curr_point, next_control_point, next_point, t);
				}
				else if (i == (points_size - 2))
				{
					point.makeBezierCurve2Point3D(curr_point, prev_control_point, next_point, t);
				}
				else
				{
					point.makeBezierCurve3Point3D(curr_point, prev_control_point, next_control_point, next_point, t);
				}

				dst.push_back(point);
			}
		}
	}

	void Vec4::makeCatmullRomSpline3PointsClosed3D
	(
		std::vector<Vec4>& dst,
		std::vector<Vec4>& points,
		const size_t& segment_count,
		const float& tension
	)
	{
		Vec4 prev_control_point;
		Vec4 next_control_point;

		Vec4* points_data { points.data() };
		const size_t points_size { points.size() };

		for (size_t i {}; i < points_size; ++i)
		{
			Vec4 prev_point { i > 0 ? points_data[i - 1] : points_data[i - 1 + points_size] };
			Vec4 curr_point { points_data[i] };
			Vec4 next_point { i < points_size ? &points_data[i + 1] : &points_data[i + 1 - points_size] };
			Vec4 next_next_point { i < (points_size - 1) ? &points_data[i + 2] : &points_data[i + 2 - points_size] };

			prev_control_point.makeCatmullRomSpline3ControlPoint3D(prev_point, curr_point, next_point, tension);
			next_control_point.makeCatmullRomSpline3ControlPoint3D(curr_point, next_point, next_next_point, -tension);

			for (size_t k {}; k < segment_count; ++k)
			{
				const float t { ((float) k) / ((float) segment_count) };

				Vec4 point;

				point.makeBezierCurve3Point3D(curr_point, prev_control_point, next_control_point, next_point, t);

				dst.push_back(point);
			}
		}
	}
}



#undef SET
