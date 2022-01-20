#include <cstddef> // size_t



namespace RDTY::MATH::CONST
{
	extern const size_t FLOAT_SIZE = sizeof(float);
	extern const size_t FLOAT_SIZE_3 { sizeof(float) * 3 };
	extern const size_t FLOAT_SIZE_4 { sizeof(float) * 4 };
	extern const size_t FLOAT_SIZE_8 { sizeof(float) * 8 };
	extern const size_t FLOAT_SIZE_12 { sizeof(float) * 12 };
	extern const size_t FLOAT_SIZE_16 { sizeof(float) * 16 };

	alignas(16) extern const float ZERO_4 [4] { 0.0f, 0.0f, 0.0f, 0.0f };
	alignas(16) extern const float IDENT_4 [4] { 0.0f, 0.0f, 0.0f, 1.0f };
}
