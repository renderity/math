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

#define MUL(dst, left, right)\
\
	const float e0 = (left[0] * right[0]) + (left[4] * right[1]) + (left[8]  * right[2]) + (left[12] * right[3]);\
	const float e1 = (left[1] * right[0]) + (left[5] * right[1]) + (left[9]  * right[2]) + (left[13] * right[3]);\
	const float e2 = (left[2] * right[0]) + (left[6] * right[1]) + (left[10] * right[2]) + (left[14] * right[3]);\
	const float e3 = (left[3] * right[0]) + (left[7] * right[1]) + (left[11] * right[2]) + (left[15] * right[3]);\
\
	const float e4 = (left[0] * right[4]) + (left[4] * right[5]) + (left[8]  * right[6]) + (left[12] * right[7]);\
	const float e5 = (left[1] * right[4]) + (left[5] * right[5]) + (left[9]  * right[6]) + (left[13] * right[7]);\
	const float e6 = (left[2] * right[4]) + (left[6] * right[5]) + (left[10] * right[6]) + (left[14] * right[7]);\
	const float e7 = (left[3] * right[4]) + (left[7] * right[5]) + (left[11] * right[6]) + (left[15] * right[7]);\
\
	const float e8 = (left[0] * right[8]) + (left[4] * right[9]) + (left[8]  * right[10]) + (left[12] * right[11]);\
	const float e9 = (left[1] * right[8]) + (left[5] * right[9]) + (left[9]  * right[10]) + (left[13] * right[11]);\
	const float e10 = (left[2] * right[8]) + (left[6] * right[9]) + (left[10] * right[10]) + (left[14] * right[11]);\
	const float e11 = (left[3] * right[8]) + (left[7] * right[9]) + (left[11] * right[10]) + (left[15] * right[11]);\
\
	const float e12 = (left[0] * right[12]) + (left[4] * right[13]) + (left[8]  * right[14]) + (left[12] * right[15]);\
	const float e13 = (left[1] * right[12]) + (left[5] * right[13]) + (left[9]  * right[14]) + (left[13] * right[15]);\
	const float e14 = (left[2] * right[12]) + (left[6] * right[13]) + (left[10] * right[14]) + (left[14] * right[15]);\
	const float e15 = (left[3] * right[12]) + (left[7] * right[13]) + (left[11] * right[14]) + (left[15] * right[15]);\
\
	dst[0] = e0; /**/ dst[4] = e4; /**/ dst[8]  = e8 ; /**/ dst[12] = e12;\
	dst[1] = e1; /**/ dst[5] = e5; /**/ dst[9]  = e9 ; /**/ dst[13] = e13;\
	dst[2] = e2; /**/ dst[6] = e6; /**/ dst[10] = e10; /**/ dst[14] = e14;\
	dst[3] = e3; /**/ dst[7] = e7; /**/ dst[11] = e11; /**/ dst[15] = e15;

#define MAKE_ROTATION_FROM_QUAT(mat, quat)\
\
	const float xy = 2.0f * quat[0] * quat[1];\
	const float xz = 2.0f * quat[0] * quat[2];\
	const float yz = 2.0f * quat[1] * quat[2];\
\
	const float zw = 2.0f * quat[2] * quat[3];\
	const float yw = 2.0f * quat[1] * quat[3];\
	const float xw = 2.0f * quat[0] * quat[3];\
\
	const float xx = 2.0f * quat[0] * quat[0];\
	const float yy = 2.0f * quat[1] * quat[1];\
	const float zz = 2.0f * quat[2] * quat[2];\
\
	mat[0] = 1.0f - yy - zz; /**/ mat[4] = xy - zw       ; /**/ mat[8]  = xz + yw       ; /**/ mat[12] = 0.0f;\
	mat[1] = xy + zw       ; /**/ mat[5] = 1.0f - xx - zz; /**/ mat[9]  = yz - xw       ; /**/ mat[13] = 0.0f;\
	mat[2] = xz - yw       ; /**/ mat[6] = yz + xw       ; /**/ mat[10] = 1.0f - xx - yy; /**/ mat[14] = 0.0f;\
	mat[3] = 0.0f          ; /**/ mat[7] = 0.0f          ; /**/ mat[11] = 0.0f          ; /**/ mat[15] = 1.0f;



#include "math/src/mat4/mat4.h"



namespace RDTY::MATH
{
	void Mat4::mul32 (const void* left, const void* right)
	{
		float* _left = (float*) left;
		float* _right = (float*) right;

		MUL(data, _left, _right)
	}

	void Mat4::transp32 (void)
	{
		const float e0 = data[0] ; /**/ const float e4 = data[1] ; /**/ const float e8  = data[2] ; /**/ const float e12 = data[3] ;
		const float e1 = data[4] ; /**/ const float e5 = data[5] ; /**/ const float e9  = data[6] ; /**/ const float e13 = data[7] ;
		const float e2 = data[8] ; /**/ const float e6 = data[9] ; /**/ const float e10 = data[10]; /**/ const float e14 = data[11];
		const float e3 = data[12]; /**/ const float e7 = data[13]; /**/ const float e11 = data[14]; /**/ const float e15 = data[15];

		data[0] = e0; /**/ data[4] = e4; /**/ data[8]  = e8 ; /**/ data[12] = e12;
		data[1] = e1; /**/ data[5] = e5; /**/ data[9]  = e9 ; /**/ data[13] = e13;
		data[2] = e2; /**/ data[6] = e6; /**/ data[10] = e10; /**/ data[14] = e14;
		data[3] = e3; /**/ data[7] = e7; /**/ data[11] = e11; /**/ data[15] = e15;
	}

	void Mat4::preTrans32 (const void* vec)
	{
		const float* _vec = (const float*) vec;

		data[12] += _vec[0];
		data[13] += _vec[1];
		data[14] += _vec[2];
	}



	void Mat4::postTrans32 (const void* vec)
	{
		float* _vec = (float*) vec;

		data[12] += (data[0] * _vec[0]) + (data[4] * _vec[1]) + (data[8]  * _vec[2]);
		data[13] += (data[1] * _vec[0]) + (data[5] * _vec[1]) + (data[9]  * _vec[2]);
		data[14] += (data[2] * _vec[0]) + (data[6] * _vec[1]) + (data[10] * _vec[2]);
	}

	void Mat4::makeRotationFromQuat32 (const void* quat)
	{
		const float* _quat = (const float*) quat;

		MAKE_ROTATION_FROM_QUAT(data, _quat)
	}

	void Mat4::invns32 (void)
	{
		const float e0 = data[0]; /**/ const float e4 = data[1]; /**/ const float e8  = data[2] ; /**/ const float e12 = -(data[0] * data[12]) - (data[1] * data[13]) - (data[2]  * data[14]);
		const float e1 = data[4]; /**/ const float e5 = data[5]; /**/ const float e9  = data[6] ; /**/ const float e13 = -(data[4] * data[12]) - (data[5] * data[13]) - (data[6]  * data[14]);
		const float e2 = data[8]; /**/ const float e6 = data[9]; /**/ const float e10 = data[10]; /**/ const float e14 = -(data[8] * data[12]) - (data[9] * data[13]) - (data[10] * data[14]);

		SET
		(
			e0  , /**/ e4  , /**/ e8  , /**/ e12,
			e1  , /**/ e5  , /**/ e9  , /**/ e13,
			e2  , /**/ e6  , /**/ e10 , /**/ e14,
			0.0f, /**/ 0.0f, /**/ 0.0f, /**/ 1.0f
		)
	}
}



#undef MAKE_ROTATION_FROM_QUAT
#undef MUL
#undef SET
