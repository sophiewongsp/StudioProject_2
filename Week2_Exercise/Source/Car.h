#ifndef CAR_H
#define CAR_H

#include "Application.h"
#include "Mtx44.h"
#include "Vector3.h"
#include "MeshBuilder.h"

class Car
{
public:
	Vector3 Cposition;
	Vector3 Ctarget;
	Vector3 Cup;
	Vector3 Cview;
	Vector3 Cright;
	float yawNew;
	float speed;

	bool nitro = false;
	bool acceleration = false;
	bool turning = false;

	Car();
	~Car();

	virtual void init(const Vector3& cpos, const Vector3& ctarget, const Vector3& cup);
	virtual void update(double dt);
	//virtual void reset();
};

#endif