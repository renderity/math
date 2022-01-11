// size_t
#include <cstddef>



namespace RDTY::MATH::UTIL
{
	void makeBezierCurve3Point
	(
		float*,
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

	void makeBezierCurve3Point
	(
		double*,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&
	);

	void makeBezierCurve3Sequence
	(
		float*,
		const float&,
		const float&,
		const float&,
		const float&,
		const float&,
		const float&,
		const float&,
		const float&,
		const size_t&
	);

	void makeBezierCurve3Sequence
	(
		double*,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&,
		const double&,
		const size_t&
	);

	void makeBezierCurve3Sequence2
	(
		float*,
		const float&,
		const float&,
		const float&,
		const float&,
		const size_t&
	);

	void makeBezierCurve3Sequence2
	(
		double*,
		const double&,
		const double&,
		const double&,
		const double&,
		const size_t&
	);
}
