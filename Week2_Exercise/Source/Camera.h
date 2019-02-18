#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3.h"

class Camera
{
public:
	Vector3 position;
	Vector3 target;
	Vector3 up;

	Camera();
	~Camera();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up, const Vector3& Cpos, const Vector3 Ctarget, const Vector3 Cposition);
	virtual void Reset();
	virtual void Update(double dt);
	virtual void Update(double dt, const Vector3& Cview, const Vector3& Cposition, bool Cturning, float Crotation, const Vector3& Ctarget);
};

#endif