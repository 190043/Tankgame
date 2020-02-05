#include "Cannon.h"
#include "Engine/Model.h"
//コンストラクタ
Cannon::Cannon(GameObject * parent)
	:GameObject(parent, "Cannon"), hModel_(-1)
{
}

//デストラクタ
Cannon::~Cannon()
{
}

//初期化
void Cannon::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TankHead.fbx");
	assert(hModel_ >= 0);
}

//更新
void Cannon::Update()
{
}

//描画
void Cannon::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Cannon::Release()
{
}