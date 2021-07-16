#include "DxLib.h"

void my_init_back_img(void);
void my_init_variable(void);

void my_draw_back(void);
void my_draw_score_board(void);

void my_timer(void);

int my_get_key(void);

int key[256];

int Bg_1st;

int gamecount;

int Color_White;
int Color_Maroon;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	my_init_back_img();
	my_init_variable();

	while (ScreenFlip()==0 && ProcessMessage()==0
		 && ClearDrawScreen()==0 && my_get_key()==0){

		my_draw_back();
		my_draw_score_board();

		my_timer();
	}
	DxLib_End();
	return 0;
}

void my_init_back_img(){
	Bg_1st = LoadGraph("../images/Bg_1st.bmp");
}

void my_init_variable(){
	gamecount = 0;
	Color_White = GetColor(255, 255, 255);
	Color_Maroon = GetColor(128, 0, 0);
}


void my_draw_back(){
	DrawGraph(0, 0, Bg_1st, TRUE);
	DrawLine(0, 240, 440, 240, Color_White);
	DrawLine(220, 0, 220, 480, Color_White);
	DrawFormatString(220, 240, Color_White, "(0,0)");
}

void my_draw_score_board(){
	DrawBox(440,0,640,480,Color_Maroon,true);
	DrawFormatString(460, 20, Color_White, "gamecount = %d", gamecount);
}

void my_timer(){
	gamecount++;
}
	
int my_get_key(){
	char keys[256];
	GetHitKeyStateAll(keys);
	for (int i = 0; i < 256; i++){
		if (keys[i] != 0){
			key[i]++;
		}
		else{
			key[i] = 0;
		}
	}
	return 0;
}