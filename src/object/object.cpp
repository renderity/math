#include "math/src/object/object.h"



namespace RDTY::MATH
{
	void Object::setRot (const void* vector_addr, const float& angle)
	{
		quat.makeRot32(vector_addr, angle);
	}

	void Object::preRot (const void* vector_addr, const float& angle)
	{
		quat.preRot32(vector_addr, angle);
	}

	void Object::postRot (const void* vector_addr, const float& angle)
	{
		quat.postRot32(vector_addr, angle);
	}



	void Object::setRotX (const float& angle)
	{
		quat.makeRotX32(angle);
	}

	void Object::preRotX (const float& angle)
	{
		quat.preRotX32(angle);
	}

	void Object::postRotX (const float& angle)
	{
		quat.postRotX32(angle);
	}



	void Object::setRotY (const float& angle)
	{
		quat.makeRotY32(angle);
	}

	void Object::preRotY (const float& angle)
	{
		quat.preRotY32(angle);
	}

	void Object::postRotY (const float& angle)
	{
		quat.postRotY32(angle);
	}



	void Object::setRotZ (const float& angle)
	{
		quat.makeRotZ32(angle);
	}

	void Object::preRotZ (const float& angle)
	{
		quat.preRotZ32(angle);
	}

	void Object::postRotZ (const float& angle)
	{
		quat.postRotZ32(angle);
	}



	void Object::setTrans (const void* vector_addr)
	{
		pos = vector_addr;
	}

	void Object::trans (const void* vector_addr, const float& value)
	{
		aux_vec = vector_addr;

		aux_vec.muls(value);

		pos.add(&aux_vec);
	}



	void Object::setTransX (const float& value)
	{
		pos.data[0] = value;
	}

	void Object::transX (const float& value)
	{
		pos.data[0] += value;
	}



	void Object::setTransY (const float& value)
	{
		pos.data[1] = value;
	}

	void Object::transY (const float& value)
	{
		pos.data[1] += value;
	}



	void Object::setTransZ (const float& value)
	{
		pos.data[2] = value;
	}

	void Object::transZ (const float& value)
	{
		pos.data[2] += value;
	}



	// void Object::_update (void)
	// {
	// 	// remove?
	// 	quat.norm();
	// 	// mat.makeRotQuat(quat);
	// 	// mat.preTrans(pos);
	// 	// MAT4::premul(this, &parent);
	// }

	// orbit
	void Object::update (void)
	{
		quat.norm();
		mat.makeRotationFromQuat32(&quat);
		mat.postTrans32(&pos);
	}

	void Object::update128 (void)
	{
		quat.norm();
		mat.makeRotationFromQuat128(&quat);
		mat.postTrans128(&pos);
	}

	// first person
	void Object::update2 (void)
	{
		quat.norm();
		mat.makeRotationFromQuat32(&quat);
		mat.preTrans32(&pos);
	}

	void Object::update2_128 (void)
	{
		quat.norm();
		mat.makeRotationFromQuat128(&quat);
		mat.preTrans128(&pos);
	}
}
