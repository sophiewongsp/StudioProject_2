#ifndef CAMERA_2_H
#define CAMERA_2_H

#include "Camera.h"
#include "MeshBuilder.h"

class Camera2 : public Camera
{
public:
	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;
	Vector3 targetYDist;
	Vector3 vectorFromCar;
	Vector3 unitVectorUp;

	float cameraAngle;
	float magnitudeFromCar;
	float magnitudeOpp;
	float magnitudeAdj;
	float angleFromCar;
	float yawNew;
	Vector3 positionBelowCamera;

	Camera2();
	~Camera2();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up, const Vector3& Cpos, const Vector3 Ctarget, const Vector3 Cposition);
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt);
	virtual void Update(double dt, const Vector3& Cview, const Vector3& Cposition, bool Cturning, float Crotation, const Vector3& Ctarget);
	virtual void Reset();
};

#endif