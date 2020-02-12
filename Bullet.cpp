#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
//�R���X�g���N�^
Bullet::Bullet(GameObject * parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

//�f�X�g���N�^
Bullet::~Bullet()
{
}

//������
void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet2.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 0.7f);
	AddCollider(collision);
}

//�X�V
void Bullet::Update()
{
	transform_.position_.vecZ += 0.3f;
}

//�`��
void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Bullet::Release()
{
}