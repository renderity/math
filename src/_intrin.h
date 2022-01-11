#ifndef __RDTY_MATH_INTRIN__
#define __RDTY_MATH_INTRIN__



#ifdef __wasm__
	#include <wasm_simd128.h>

	#define __m128 __f32x4
	#define _mm_load_ps wasm_v128_load
	#define _mm_load_ps1 wasm_v128_load32_splat
	#define _MM_SHUFFLE(a, b, c, d) (a * 4) + 0, (a * 4) + 1, (a * 4) + 2, (a * 4) + 3, (b * 4) + 0, (b * 4) + 1, (b * 4) + 2, (b * 4) + 3, (c * 4) + 0, (c * 4) + 1, (c * 4) + 2, (c * 4) + 3, (d * 4) + 0, (d * 4) + 1, (d * 4) + 2, (d * 4) + 3
	#define _mm_shuffle_ps __builtin_wasm_shuffle_i8x16
	// make wasm_f32x4_make(1.0f, -1.0f, 1.0f, -1.0f) constant
	#define _mm_addsub_ps(a, b) wasm_f32x4_add(a, wasm_f32x4_mul(b, wasm_f32x4_make(1.0f, -1.0f, 1.0f, -1.0f)))
	#define _mm_store_ps wasm_v128_store
	#define _mm_set1_ps wasm_f32x4_splat
	#define _mm_mul_ps wasm_f32x4_mul
	#define _mm_add_ps wasm_f32x4_add
	#define _mm_sub_ps wasm_f32x4_sub

	inline __m128 _mm_loadr_ps (const float* __p)
	{
		__m128 __v = _mm_load_ps(__p);

		return (__m128) _mm_shuffle_ps(__v, __v, _MM_SHUFFLE(3, 2, 1, 0));
	}
#else
	#include <immintrin.h>
#endif



#endif
