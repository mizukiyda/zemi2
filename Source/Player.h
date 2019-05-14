
extern int Player_Init();
extern int Player_Dpct();
extern int Player_Draw();
extern int Player_End();

extern int MAP_Player_Pos_Init_x();
extern int MAP_Player_Pos_Init_y();

extern int Player_Check();
extern int Player_Move();
typedef struct {
	int x;		//現在位置
	int y;		//現在位置
	int nx;
	int ny;
}P_PLAYER;	//Pos_Player
	
typedef enum {
	P_Object_Wall,      //行けない場所
	P_Object_Load,      //歩ける場所
	P_Object_Goal,      //ゴール
}P_Object;	//物体


