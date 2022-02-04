#define SET(x, y, z, w) data[0] = x; data[1] = y; data[2] = z; data[3] = w;



#include <cstddef> // size_t
// uint8_t
#include <cstdint>
// memcpy, memset
#include <cstring>
// printf
#include <cstdio>
// sqrt
#include <cmath>

#include "math/src/quat/quat.h"



namespace RDTY::MATH
{
	namespace CONST
	{
		extern const uint8_t FLOAT_SIZE_4;

		alignas(16) extern const float ZERO_4 [4];
		alignas(16) extern const float IDENT_4 [4];
	}



	Quat* Quat::New (void)
	{
		Quat* quat { new Quat };

		return quat;
	}



	Quat::Quat (void)
	{
		memcpy(data, CONST::IDENT_4, CONST::FLOAT_SIZE_4);

		// // compare performance with
		// memset(data, 0, FLOAT_SIZE_4);
	}

	Quat::Quat (const void* src)
	{
		memcpy(data, src, CONST::FLOAT_SIZE_4);
	}

	Quat::Quat (const Quat& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_4);
	}

	Quat::Quat (const Quat&& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_4);
	}

	Quat::Quat (std::initializer_list<float> list)
	{
		size_t count = 0;

		for (float element : list)
		{
			data[count++] = element;

			if (count == 4)
			{
				break;
			}
		}
	}

	// Quat::~Quat (void) {}



	void Quat::operator = (const void* src)
	{
		memcpy(data, src, CONST::FLOAT_SIZE_4);
	}

	void Quat::operator = (const Quat& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_4);
	}

	void Quat::operator = (const Quat&& src)
	{
		memcpy(data, &src, CONST::FLOAT_SIZE_4);
	}



	void Quat::reset (void)
	{
		memcpy(data, CONST::ZERO_4, CONST::FLOAT_SIZE_4);
	}

	void Quat::set (const float& x, const float& y, const float& z, const float& w)
	{
		SET(x, y, z, w)
	}

	void Quat::ident (void)
	{
		memcpy(data, CONST::IDENT_4, CONST::FLOAT_SIZE_4);
	}

	// TODO simd
	float Quat::len (void)
	{
		return sqrt((data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]) + (data[3] * data[3]));
	}

	float Quat::lensq (void)
	{
		return (data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]) + (data[3] * data[3]);
	}

	void Quat::norm (void)
	{
		const float invlen = 1.0f / sqrt((data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]) + (data[3] * data[3]));

		data[0] *= invlen;
		data[1] *= invlen;
		data[2] *= invlen;
		data[3] *= invlen;
	}

	void Quat::print (void)
	{
		printf("%f %f %f %f\n\n", data[0], data[1], data[2], data[3]);
	}
}



#undef SET
