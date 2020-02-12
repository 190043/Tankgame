#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
//コンストラクタ
Bullet::Bullet(GameObject * parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

//デストラクタ
Bullet::~Bullet()
{
}

//初期化
void Bullet::Initialize()
{
	hModel_ = Model::Load("Bullet2.fbx");
	assert(hModel_ >= 0);

	SphereCollider* collision = new SphereCollider(XMVectorSet(0, 0, 0, 0), 0.7f);
	AddCollider(collision);
}

//更新
void Bullet::Update()
{
	transform_.position_.vecZ += 0.3f;
}

//描画
void Bullet::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Bullet::Release()
{
}