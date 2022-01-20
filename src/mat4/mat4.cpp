#define SET\
(\
	e0, /**/ e4, /**/ e8 , /**/ e12,\
	e1, /**/ e5, /**/ e9 , /**/ e13,\
	e2, /**/ e6, /**/ e10, /**/ e14,\
	e3, /**/ e7, /**/ e11, /**/ e15\
)\
\
	data[0] = e0; /**/ data[4] = e4; /**/ data[8]  = e8 ; /**/ data[12] = e12;\
	data[1] = e1; /**/ data[5] = e5; /**/ data[9]  = e9 ; /**/ data[13] = e13;\
	data[2] = e2; /**/ data[6] = e6; /**/ data[10] = e10; /**/ data[14] = e14;\
	data[3] = e3; /**/ data[7] = e7; /**/ data[11] = e11; /**/ data[15] = e15;



#include <cstddef> // size_t
// memcpy, memset
#include <cstring>
// printf
#include <cstdio>
// tan
#include <cmath>

#include "math/src/mat4/mat4.h"



namespace RDTY::MATH
{
	namespace CONST
	{
		extern const size_t FLOAT_SIZE_16;
	}

	alignas(16) const float CONST_MUL [4] { 2.0f, 2.0f, 2.0f, 0.0f };
	alignas(16) const float CONST_ONE [4] { 1.0f, 1.0f, 1.0f, 0.0f };

	alignas(16) const float IDENT_12 [12]
	{
		1.0f, /**/ 0.0f, /**/ 0.0f, /**/ 0.0f,
		0.0f, /**/ 1.0f, /**/ 0.0f, /**/ 0.0f,
		0.0f, /**/ 0.0f, /**/ 1.0f, /**/ 0.0f
	};

	alignas(16) const float IDENT_16 [16]
	{
		1.0f, /**/ 0.0f, /**/ 0.0f, /**/ 0.0f,
		0.0f, /**/ 1.0f, /**/ 0.0f, /**/ 0.0f,
		0.0f, /**/ 0.0f, /**/ 1.0f, /**/ 0.0f,
		0.0f, /**/ 0.0f, /**/ 0.0f, /**/ 1.0f
	};

	alignas(16) const float ZERO_16 [16]
	{
		0.0f, /**/ 0.0f, /**/ 0.0f, /**/ 0.0f,
		0.0f, /**/ 0.0f, /**/ 0.0f, /**/ 0.0f,
		0.0f, /**/ 0.0f, /**/ 0.0f, /**/ 0.0f,
		0.0f, /**/ 0.0f, /**/ 0.0f, /**/ 0.0f
	};



	Mat4::Mat4 (void)
	{
		memcpy(data, IDENT_16, CONST::FLOAT_SIZE_16);
	}

	Mat4::Mat4 (const void* src)
	{
		memcpy(data, src, CONST::FLOAT_SIZE_16);
	}

	Mat4::Mat4 (const Mat4& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_16);
	}

	Mat4::Mat4 (const Mat4&& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_16);
	}

	Mat4::Mat4 (std::initializer_list<float> list)
	{
		size_t count = 0;

		for (float element : list)
		{
			data[count++] = element;

			if (count == 16)
			{
				break;
			}
		}

		transp32();
	}

	// Mat4::~Mat4 (void) {}



	void Mat4::operator = (const void* src)
	{
		memcpy(data, src, CONST::FLOAT_SIZE_16);
	}

	void Mat4::operator = (const Mat4& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_16);
	}

	void Mat4::operator = (const Mat4&& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_16);
	}



	// inline ?
	inline void Mat4::zero (void)
	{
		memset(data, 0, CONST::FLOAT_SIZE_16);
	}

	void Mat4::ident (void)
	{
		memcpy(data, IDENT_16, CONST::FLOAT_SIZE_16);

		// // compare performance with
		// memset(data, 0, FLOAT_SIZE_16);
		// data[0] = 1.0f;
		// data[5] = 1.0f;
		// data[10] = 1.0f;
		// data[15] = 1.0f;
	}

	void Mat4::makeProjPersp
	(
		const float& fov,
		const float& aspect,
		const float& _near,
		const float& _far,
		const float& zoom
	)
	{
		const float top = _near * tan(0.017453292f * 0.5f * fov) / zoom;
		const float height = 2.0f * top;
		const float bottom = top - height;
		const float width = aspect * height;
		const float left = -0.5f * width;
		const float right = left + width;

		SET
		(
			2.0f * _near / (right - left), /**/ 0.0f                         , /**/ (right + left) / (right - left) , /**/ 0.0f                                   ,
			0.0f                         , /**/ 2.0f * _near / (top - bottom), /**/ (top + bottom) / (top - bottom) , /**/ 0.0f                                   ,
			0.0f                         , /**/ 0.0f                         , /**/ -(_far + _near) / (_far - _near), /**/ -(2.0f * _far * _near) / (_far - _near),
			0.0f                         , /**/ 0.0f                         , /**/ -1.0f                           , /**/ 0.0f
		)

		// // compare performance with
		// memset(data, 0, CONST::FLOAT_SIZE_16);
		// data[0] = 2.0f * _near / (right - left);
		// data[5] = 2.0f * _near / (top - bottom);
		// data[8] = (right + left) / (right - left);
		// data[9] = (top + bottom) / (top - bottom);
		// data[10] = -(_far + _near) / (_far - _near);
		// data[11] = -1.0f;
		// data[14] = -(2.0f * _far * _near) / (_far - _near);
	}

	void Mat4::makeProjPersp
	(
	  const float& left,
	  const float& right,
	  const float& top,
	  const float& bottom,
	  const float& _near,
	  const float& _far
	)
	{
		SET
		(
	    2.0f * _near / (right - left), /**/ 0.0f                         , /**/ (right + left) / (right - left) , /**/ 0.0f                                   ,
	    0.0f                         , /**/ 2.0f * _near / (top - bottom), /**/ (top + bottom) / (top - bottom) , /**/ 0.0f                                   ,
	    0.0f                         , /**/ 0.0f                         , /**/ -(_far + _near) / (_far - _near), /**/ -(2.0f * _far * _near) / (_far - _near),
	    0.0f                         , /**/ 0.0f                         , /**/ -1.0f                           , /**/ 0.0f
	 	)
	}

	void Mat4::print (void)
	{
		printf("%f %f %f %f\n", data[0], data[4], data[8] , data[12]);
		printf("%f %f %f %f\n", data[1], data[5], data[9] , data[13]);
		printf("%f %f %f %f\n", data[2], data[6], data[10], data[14]);
		printf("%f %f %f %f\n", data[3], data[7], data[11], data[15]);
		printf("\n");
	}
}



#undef SET
