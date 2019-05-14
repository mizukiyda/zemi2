#include"DxLib.h"
#include"Player.h"
#include"MAP.h"
#include "Keyboard.h"
#include"Enemy.h"

//ループ用
static int i, j, k;

//Playerの画像
int Player[12];				//プレイヤー画像の変数(今回は12分割なので12)
int None;					//画像のスタンバイ状態(静止状態)
int Player_Animetion;		//Playerのアニメーション

//Playerの構造体関係
P_PLAYER player;	
E_Drct drct;				//向き

//Player用の変数
int count_x;		//Mapサイズのカウント(x)
int count_y;		//Mapサイズのカウント(y)

//Playerのフラグ
int Move_Flg;		//Playerが動いるいるかどうかのフラグ

int Player_Init() {

	//Playerの初期位置(Mapからもらう)
	player.x = MAP_Player_Pos_Init_x();
	player.y = MAP_Player_Pos_Init_y();

	//画像の取得
	Player[12] = {};
	LoadDivGraph("Resource/Image/Player.png", 12, 3, 4, 64, 64,Player);  //配列「Player」へ画像を入れる
	None = 7;			//正面を向いている状態
	Player_Animetion = 0;		//何もしていない状態

	//移動
	count_x = 0;
	count_y = 0;
	Move_Flg = false;

	return 0;
}

int Player_Dpct() {

	//if (Move_Flg = false) {
		//上
		if (Keyboard_Get(KEY_INPUT_UP) == 1)   //↑
		{
			player.y--;
			drct = E_Drct_Up;
		}
		//左
		if (Keyboard_Get(KEY_INPUT_LEFT) == 1)  //←
		{
			player.x--;
			drct = E_Drct_Left;
		}
		//下
		if (Keyboard_Get(KEY_INPUT_DOWN) == 1)  //↓
		{
			player.y++;
			drct = E_Drct_Down;
		}
		//右
		if (Keyboard_Get(KEY_INPUT_RIGHT) == 1) //→
		{
			player.x++;
			drct = E_Drct_Right;
		}

		//Playerの移動先のチェック（壁か道か）
		if (drct != E_Drct_Stop)  //キーが入力されているなら
		{
			Player_Check();
		}
		//移動させる
		if (Move_Flg = true) {//移動先が道だった時
			Player_Move();
		}
	//}
	return 0;
}

int Player_Check() {


	return 0;
}

int Player_Move() {

	switch (drct) {

		//上
	case E_Drct_Up:
		count_y--;
		break;
		//左
	case E_Drct_Left:
		count_x--;
		break;
		//下
	case E_Drct_Down:
		count_y++;
		break;
		//右
	case E_Drct_Right:
		count_x++;
		break;
	}
	return 0;
}

int Player_Draw() {

	//Playerの表示
	DrawGraph(player.x , player.y , Player[0], TRUE);
	//上
	/*if (drct == E_Drct_Up)
	{
		DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[0], TRUE);
	}
	//左
	if (drct == E_Drct_Left)
	{
		DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y,  Player[9], TRUE);
	
	}
	//下
	if (drct == E_Drct_Down)
	{
		DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y,  Player[6], TRUE);
		
	}
	//右
	if (drct == E_Drct_Right)
	{
		DrawGraph(player.x * MAP_SIZE + count_x, player.y * MAP_SIZE + count_y, Player[3], TRUE);
		
	}
	*/

	
	if (drct == E_Drct_Up)
	{
		DrawGraph(player.x , player.y , Player[0], TRUE);
	}
	//左
	if (drct == E_Drct_Left)
	{
		DrawGraph(player.x , player.y , Player[9], TRUE);

	}
	//下
	if (drct == E_Drct_Down)
	{
		DrawGraph(player.x  , player.y  , Player[6], TRUE);

	}
	//右
	if (drct == E_Drct_Right)
	{
		DrawGraph(player.x , player.y, Player[3], TRUE);

	}

	//デバッグ用処理
	DrawFormatString(700, 20, GetColor(255, 0, 0), "1:上 2:右 3:下 4:左");
	DrawFormatString(700, 40, GetColor(255, 0, 0), "Drct:%d", drct);
	DrawFormatString(700, 60, GetColor(255, 0, 0), "x = %d   y = %d", player.x,player.y);


	return 0;
}

int MAP_Player_Pos_Init_x() {

	return player.x;
}

int MAP_Player_Pos_Init_y() {

	return player.y;
}

int Player_End() {

	return 0;
}