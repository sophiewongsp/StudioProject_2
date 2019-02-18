#include "Car.h"

Car::Car()
{
	Cposition.Set(0, 0, 1);
	Ctarget.Set(0, 0, 0);
	Cup.Set(0, 1, 0);

	yawNew = 0.0f;
	speed = 0.0f;
}

Car::~Car()
{
}

void Car::init(const Vector3& cpos, const Vector3& ctarget, const Vector3& cup)
{
	this->Cposition = cpos;
	this->Ctarget = ctarget;
	Vector3 Cview = (ctarget - Cposition).Normalized();
	Vector3 Cright = Cview.Cross(cup);
	Cright.y = 0;
	Cright.Normalize();
	this->Cup = Cright.Cross(Cview).Normalized();
}

void Car::update(double dt)
{
	Cview = (Ctarget - Cposition).Normalized();
	Cright = Cview.Cross(Cup);
	Ctarget = Cposition + Cview;

	static const float turn_speed = 50.f;

	//std::cout << Cview << std::endl;
	//std::cout << Cposition.z << std::endl;
	std::cout << speed << std::endl;

	if (Application::IsKeyPressed('W'))
	{
		acceleration = true;
		turning = false;

		Cposition.x = Cposition.x + Cview.x * speed * dt;
		Cposition.z = Cposition.z + Cview.z * speed * dt;
		Ctarget = Cposition + Cview;

		if (acceleration == true && turning == false)
		{
			if (speed <= 50)
			{
				speed++;
			}
		}
	}
	if (Application::IsKeyPressed('S'))
	{
		Cposition.x = Cposition.x - Cview.x * speed * dt;
		Cposition.z = Cposition.z - Cview.z * speed * dt;
		Ctarget = Cposition + Cview;
	}
	if (Application::IsKeyPressed('A'))
	{
		turning = true;

		float yaw = (float)(turn_speed * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		Cup = rotation * Cup;
		Cview = rotation * Cview;
		Ctarget = Cposition + Cview;
		yawNew += yaw;

		if (turning == true)
		{
			if (speed >= 30)
			{
				speed--;
			}
		}
	}
	if (Application::IsKeyPressed('D'))
	{
		turning = true;

		float yaw = (float)(-turn_speed * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		Cup = rotation * Cup;
		Cview = rotation * Cview;
		Ctarget = Cposition + Cview;
		yawNew += yaw;

		if (turning == true)
		{
			if (speed >= 30)
			{
				speed--;
			}
		}
	}
	if (Application::IsKeyPressed(VK_SPACE))
	{
		speed = 100;
	}
}