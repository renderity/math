#ifndef __RDTY_MATH_INTRIN__
#define __RDTY_MATH_INTRIN__



#if defined(__GNUC__)
	#define INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
	#define INLINE __forceinline
#endif



#ifdef __wasm__
	#include <wasm_simd128.h>

	#define __m128 __f32x4
	#define _mm_load_ps wasm_v128_load
	#define _mm_load_ps1 wasm_v128_load32_splat
	#define _mm_addsub_ps(a, b) wasm_f32x4_add(a, wasm_f32x4_mul(b, wasm_f32x4_make(1.0f, -1.0f, 1.0f, -1.0f)))
	#define _mm_store_ps wasm_v128_store
	#define _mm_set1_ps wasm_f32x4_splat
	#define _mm_mul_ps wasm_f32x4_mul
	#define _mm_add_ps wasm_f32x4_add
	#define _mm_sub_ps wasm_f32x4_sub
	#define _mm_shuffle_ps __builtin_wasm_shuffle_i8x16

	#define _MM_SHUFFLE(a, b, c, d)\
		(d * 4), (d * 4) + 1, (d * 4) + 2, (d * 4) + 3,\
		(c * 4), (c * 4) + 1, (c * 4) + 2, (c * 4) + 3,\
		(_MM_SHUFFLE_EL(b) * 4), (_MM_SHUFFLE_EL(b) * 4) + 1, (_MM_SHUFFLE_EL(b) * 4) + 2, (_MM_SHUFFLE_EL(b) * 4) + 3,\
		(_MM_SHUFFLE_EL(a) * 4), (_MM_SHUFFLE_EL(a) * 4) + 1, (_MM_SHUFFLE_EL(a) * 4) + 2, (_MM_SHUFFLE_EL(a) * 4) + 3

	// #define _MM_SHUFFLE(b, a, d, c)\
	// 	__shuf1(a), __shuf2(a), __shuf3(a), __shuf4(a),\
	// 	__shuf1(b), __shuf2(b), __shuf3(b), __shuf4(b),\
	// 	__shuf1c, __shuf2c, __shuf3c, __shuf4c,\
	// 	__shuf1d, __shuf2d, __shuf3d, __shuf4d,

	constexpr int __shuf1 (const int x)
	{
		return (x + 4);
	}

	constexpr int __shuf2 (const int x)
	{
		return ((x + 4) + 1);
	}

	constexpr int __shuf3 (const int x)
	{
		return ((x + 4) + 2);
	}

	constexpr int __shuf4 (const int x)
	{
		return ((x + 4) + 3);
	}

	/**
	 * Used to wrap last 2 argumants of _MM_SHUFFLE
	 * if first 2 arguments of _mm_shuffle_ps are different.
	*/
	constexpr int _MM_SHUFFLE_EL (const int x)
	{
		return (x + 4);
	}

	INLINE __m128 _mm_loadr_ps (const float* __p)
	{
		__m128 __v = _mm_load_ps(__p);

		return (__m128) _mm_shuffle_ps(__v, __v, _MM_SHUFFLE(3, 2, 1, 0));
	}

	// make wasm_f32x4_make(1.0f, -1.0f, 1.0f, -1.0f) constant
#else
	#define _MM_SHUFFLE_EL(x) x

	#include <immintrin.h>
#endif



#undef INLINE



#endif
