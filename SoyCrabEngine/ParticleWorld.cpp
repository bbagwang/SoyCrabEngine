#include "ParticleWorld.h"

ParticleWorld::ParticleWorld(unsigned MaxContacts, unsigned Iterations /*= 0*/)
{

}

ParticleWorld::~ParticleWorld()
{

}

unsigned ParticleWorld::GenerateContacts()
{
	unsigned Limit = MaxContacts;
	ParticleContact* NextContact = Contacts;
	for (auto& Iter : ContactGenerators)
	{
		unsigned Used = Iter->AddContact(NextContact, Limit);
		Limit -= Used;
		NextContact += Used;
		//�� �̻� ������ ����� ������ ����.
		//�������� �����Ǵ� ������ ��ϵ��� ���ϰ� ��������.
		if (Limit <= 0)
			break;
	}

	//���� ���� ������ ������ ��ȯ�Ѵ�.
	return MaxContacts - Limit;
}

void ParticleWorld::Integrate(real Duration)
{
	for (auto& Iter : Particles)
	{
		Iter->Integrate(Duration);
	}
}

void ParticleWorld::RunPhysics(real Duration)
{
	//���� ����, �� �߻��⸦ �����Ѵ�.
	Registry.UpdateForces(Duration);

	//�� ���� ��ü�� �����Ѵ�.
	Integrate(Duration);

	//������ �����Ѵ�.
	unsigned UsedContacts = GenerateContacts();

	//���� ó�� ����.
	if (UsedContacts)
	{
		if (CalculateIterations)
			Resolver.SetIterations(UsedContacts * 2);
		Resolver.ResolveContacts(Contacts, UsedContacts, Duration);
	}
}

void ParticleWorld::StartFrame()
{
	//������ ������ ���� �շ��� ���� ����� ���� �ʱ�ȭ�Ѵ�.
	for (auto& Iter : Particles)
	{
		Iter->ClearAccumulator();
	}
}