#pragma once
#include "SoyCrabEngine.h"

class ParticleForceGenerator
{
public:
	//�־��� ���ڿ� �����ϴ� ���� ����ϰ� ������Ʈ �ϱ� ���� �� �޼��带 ������
	virtual void UpdateForce(Particle* Particle, real Duration) = 0;
};

#pragma region GravityGenerator
//�߷��� �����ϴ� �� �߻���
//�ν��Ͻ� �ϳ��� ���� ���� ���ڿ� ��� ����.
class ParticleGravityGenerator : public ParticleForceGenerator
{
private:
	//�߷� ���ӵ�
	Vector3 Gravity;
public:
	//�־��� ���ӵ��� �� �߻��� �ν��Ͻ� ����
	ParticleGravityGenerator(const Vector3& Gravity) : Gravity(Gravity) {}
	//�־��� ���ڿ� �߷� ����
	virtual void UpdateForce(Particle* Particle, real Duration);
};
#pragma endregion

#pragma region DragGenerator
//�巹�� ���� �����ϴ� �� �߻���
//�ν��Ͻ� �ϳ��� ���� ���� ���ڿ� ��� ����.
class ParticleDragGenerator : public ParticleForceGenerator
{
	//Drag Force ��
	//�巹�� �� = -�ӵ�(�巹�� ���1(k1)*(���� �ӵ��� ũ��)+�巹�� ���2(k2)*(���� �ӵ��� ũ��)^2)
private:
	//Drag Coefficient (�巹�� ���)
	//�ӵ��� �������� �巡�� ��ʻ�� ����
	real k1;
	//�ӵ��� ������ �������� �巹�� ��ʻ�� ����
	//k2���� Ŭ���� �ӵ��� �������� ���� �ް��� �巹�װ� ������.
	//�ӵ��� �ι� �������� ���������� 4�谡 �Ǵ� �Ͱ� ���� �ƶ�.
	real k2;
public:
	//�־��� ��ʻ���� �� �߻��� ��ü ����
	ParticleDragGenerator(real k1, real k2) : k1(k1), k2(k2) {}
	//�־��� ���ڿ� �巹�� �� ����
	virtual void UpdateForce(Particle* Particle, real Duration);
};
#pragma endregion