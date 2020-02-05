#include "Cannon.h"
#include "Engine/Model.h"
//�R���X�g���N�^
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1)
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