#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
//コンストラクタ
Tank::Tank(GameObject * parent)
	:GameObject(parent, "Tank"), hModel_(-1)
{
}

//デストラクタ
Tank::~Tank()
{
}

//初期化
void Tank::Initialize()
{
	//モデルデータのロード
	hModel_ = Model::Load("TankBody.fbx");
	assert(hModel_ >= 0);//assert = アサートと読む！　　　成功した場合０以上の数字が入るが、失敗した場合-1が入り、絶対にできないようになっている。
}

//更新
void Tank::Update()
{
	XMVECTOR move = { 0.0f, 0.0f, 0.1f, 0.0f };     //順番に x, y, z, もう一つといった順番になっている。もう一つは四次元限定なので、3次元の場合は
	//ほとんど使うことはない

	XMMATRIX matt;
	matt = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.vecY));//この場合は、mattという変数がvecY度に回転させる

	move = XMVector3TransformCoord(move, matt);
	//ベクトルを行列に適応できるようにする。この場合、()にあるmoveはmattに応じてできるようにする


	if (Input::IsKey(DIK_W))
	{
		transform_.position_ += move;
	}

	if (Input::IsKey(DIK_S))
	{
		transform_.position_ -= move;
	}

	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.vecY -= 3;
	}

	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.vecY += 3;
	}
	Camera::SetTarget(transform_.position_);

}

//描画
void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

//開放
void Tank::Release()
{
}