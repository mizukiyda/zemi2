#include"Dxlib.h"
#include"stdlib.h"
//#include"Enemy.h"
//#include"MAP.h"
//#include"Player.h"


int Enemyalive;          //敵の画像の変数(生)
int Enemydeath;          //敵の画像の変数(死)


int Enemy_Init() {
	Enemyalive=LoadGraph("resource/Image/Enemy.png");
	Enemydeath=LoadGraph("resource/Image/Enemydeath.png");
	return 0;
}
int Enemy_Dpct() {
	/*
	switch () {          //ランダムに動く
	case E_Up:           //上

	case E_Right:        //右

	case E_Down:         //下

	case E_Left:         //左

	case E_Stop:         //止
	}
	*/
	return 0;
}

int Enemy_Move() {
	return 0;

}
int Enemy_Draw() {
	DrawGraph(100, 100, Enemyalive, true);
	return 0;
}
int Enemy_End() {
	return 0;
}