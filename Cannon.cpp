#include "Cannon.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Bullet.h"
//�R���X�g���N�^
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1),
	SWING_SPEED(3.0f)
{
}

//�f�X�g���N�^
Cannon::~Cannon()
{
}

//������
void Cannon::Initialize()
{
	//���f���f�[�^�̃��[�h
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);  
}

//�X�V
void Cannon::Update()
{
	if (Input::IsKey(DIK_RIGHT))
	{//�E�����N���b�N�����ꍇ�A�E�։�]����B
		transform_.rotate_.vecY += SWING_SPEED;
	}

	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.vecY -= SWING_SPEED;
	}

	if (Input::IsKeyDown(DIK_SPACE))
	{   //SPACE���������ꍇ�A�e���o��
		Bullet* pBullet = Instantiate<Bullet>(FindObject("PlayScene"));
		pBullet->SetPosition(transform_.position_);
	}
}

//�`��
void Cannon::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//�J��
void Cannon::Release()
{
}