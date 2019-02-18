#include "Camera2.h"
#include "Application.h"
#include "Mtx44.h"

#define PI 3.14159265

Camera2::Camera2()
{
	targetYDist.SetZero();
	vectorFromCar.SetZero();
	cameraAngle = 0;
	magnitudeFromCar = 0;
	magnitudeOpp = 0;
	magnitudeAdj = 0;
	angleFromCar = 0;
	yawNew = 0;
	unitVectorUp = Vector3(0, 1, 0);
	positionBelowCamera.SetZero();
}

Camera2::~Camera2()
{
}

void Camera2::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	//this->up = defaultUp = right.Cross(view).Normalized();
}

void Camera2::Init(const Vector3& pos, const Vector3& target, const Vector3& up, const Vector3& Cpos, const Vector3 Ctarget, const Vector3 Cposition)
{
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	//this->up = defaultUp = right.Cross(view).Normalized();
	this->vectorFromCar = this->position - Cpos;
	magnitudeFromCar = vectorFromCar.Length();
	Vector3 Cview = (Ctarget - Cposition).Normalized();
	this->angleFromCar = (acos((Cview.Dot(-(view)))) * 180.0 / PI) - 90;
	magnitudeOpp = sin(angleFromCar * PI / 180.0) * magnitudeFromCar;
	magnitudeAdj = cos(angleFromCar * PI / 180.0) * magnitudeFromCar;
	// / (Cview.Length() * view.Length())
}

void Camera2::Update(double dt, const Vector3& Cview, const Vector3& Cposition, bool Cturning, float Crotation, const Vector3& Ctarget)
{
	static const float CAMERA_SPEED = 50.f;
	
	//float yaw = (float)(CAMERA_SPEED * dt);

	//length = (0, 40, 121);
	//position = Cposition + (view.Dot(length));
	//Vector3 Carview = (Ctarget - Cposition).Normalized();
	//Vector3 view = -Carview;
	/*Vector3 view = -(Cview);
	view = view.Normalized();
	this->positionBelowCamera = (Vector3 (view) * magnitudeAdj) + Cposition;
	Vector3 position1 = (this->unitVectorUp * magnitudeOpp) + this->positionBelowCamera;
	this->position = Vector3(position1.x, position1.y + 40, position1.z + 121);
	Vector3(target) = Vector3(Cposition.x, Cposition.y + cameraAngle, Cposition.z);*/
	//position = 
	//Vector3 position1 = (Cposition - direction) * 3;
	
	//target = Cposition + targetYDist;
	//Vector3 direction = Vector3(sin(yaw), 0, cos(yaw));

	//if (Cturning)
	//{ = Crotation * (PI / 180.0f);
	/*float yaw = Crotation;
	Vector3 direction = Vector3(sin(yaw * (PI / 180.0)), 0, cos(yaw * (PI / 180.0)));
	direction = Cposition + (direction * magnitudeAdj);
	//Vector3 position1 = (Vector3(Cposition + direction)).Normalized();
	//position = Vector3(position1.x, position1.y + 40, position1.z + 121;
	position = direction + Vector3(0, 40, 121);
	target = Vector3(Cposition.x, Cposition.y + cameraAngle, Cposition.z);*/
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	target = position + view;
	position = Cposition - Cview * magnitudeAdj + Vector3(0, 40, 0);
	target = Cposition + Vector3(0, cameraAngle, 0);
	/*position1.x = position1.x * magnitudeOpp;
	position1.z = position1.z * magnitudeAdj;*/
	//position = Vector3(position1.x, position1.y, position1.z) + Vector3(0, 40, 121);
	//target = Vector3(Cposition.x, Cposition.y + cameraAngle, Cposition.z);
		//target = Cposition;


		/*Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		up = rotation * up;
		view = rotation * view;
		target = Cposition + targetYDist;
		//position = Cposition + (length + view);
		positionBelowCamera = -(Cview * magnitudeAdj) + Cposition;
		position = (unitVectorUp * magnitudeOpp) + positionBelowCamera;
		//yaw = sin(yawNew * PI/180);
		yawNew += yaw;*/
	//}
}

void Camera2::Update(double dt)
{
	static const float CAMERA_SPEED = 50.f;

	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	target = position + view;

	/*if (Application::IsKeyPressed('A'))
	{*/
		/*float yaw = (float)(turn_speed * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		up = rotation * up;
		view = rotation * view;
		target = position + view;
		yawNew += yaw;

		if (speed >= 30)
		{
			speed--;
		}*/

		/*float yaw = (float)(CAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		up = rotation * up;
		view = rotation * view;
		target = position + view;
	}*/
	/*if (target.z >-498.f && target.z < 498.f && target.x > -498.f && target.x < 498.f && target.y > -498.f && target.y < 498.f)
	{
		if (Application::IsKeyPressed('J')) //left
		{
			position = position - right;
			target = position + view;
		}
		else if (Application::IsKeyPressed('L')) //right
		{
			position = position + right;
			target = position + view;
		}
		else if (Application::IsKeyPressed('I')) //up
		{
			position = position + view.Normalized();
			target = position + view;
		}
		else if (Application::IsKeyPressed('K')) // down
		{
			position = position - view.Normalized();
			target = position + view;
		}
		else if (Application::IsKeyPressed('Q'))
		{
			position = position + up;
			target = position + view;
		}
		else if (Application::IsKeyPressed('E'))
		{
			position = position - up;
			target = position + view;
		}
	}
	else
	{
		if (target.x >= 500.f)
			position.x = position.x - 1;
		else
			position.x = position.x + 1;

		if (target.y >= 900.f)
		{
			position.y = position.y - 1;
		}
		else
		{
			position.y = position.y + 1;
		}
		if (target.z >= 480.f)
			position.z = position.z - 1;
		else
			position.z = position.z + 1;
	}
	if (Application::IsKeyPressed(VK_LEFT))
	{
		float yaw = (float)(CAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		up = rotation * up;
		view = rotation * view;
		target = position + view;
	}
	else if (Application::IsKeyPressed(VK_RIGHT))
	{
		float yaw = (float)(-CAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		up = rotation * up;
		view = rotation * view;
		target = position + view;;
	}
	else if (Application::IsKeyPressed(VK_UP))
	{
		float pitch = (float)(CAMERA_SPEED * dt);
		view = (target - position).Normalized();
		right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, right.x, right.y, right.z);

		right = rotation * right;
		view = rotation * view;
		target = position + view;
	}
	else if (Application::IsKeyPressed(VK_DOWN))
	{
		float pitch = (float)(-CAMERA_SPEED * dt);
		view = (target - position).Normalized();
		right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, right.x, right.y, right.z);

		right = rotation * right;
		view = rotation * view;
		target = position + view;
	}
	else if (Application::IsKeyPressed('R'))
	{
		Reset();
	}*/
}

void Camera2::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
}