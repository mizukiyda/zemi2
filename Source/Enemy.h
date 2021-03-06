#ifndef INCLUDE_ENEMY
#define INCLUDE_ENEMY
#define  EnemyCount 4
extern int Enemy_Pos_Init_x();
extern int Enemy_Pos_Init_y();
extern int Enemy_Move1();
extern int Enemy_Move2();
extern int Enemy_Move3();
extern int Enemy_Move4();
extern int Enemy_Init();
extern int Enemy_Dpct();
extern int Enemy_Draw();
extern int Enemy_End();

extern int Enemy_Move();



typedef struct {	//構造体
	int Move_x;		//enemyのx座標
	int Move_y;		//enemyのy座標
	int Type;   //敵のタイプ(種類)
	int Enemy_OnActive;		 //Enemyの生存確認
} S_Enemy;

typedef enum {

	E_Drct_Stop,	//とまる	-> 0
	E_Drct_Up,		//上		-> 1
	E_Drct_Right,	//右		-> 2
	E_Drct_Down,	//下		-> 3
	E_Drct_Left,	//左		-> 4

} E_Drct;  //Drct = Direction(向き)

#endif