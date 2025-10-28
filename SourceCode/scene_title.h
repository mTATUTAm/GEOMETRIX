#ifndef SCENE_TITLE_H
#define SCENE_TITLE_H

extern float start_x;
extern float start_y;       // 上端
extern float grid_size;  // 正方形のサイズ
extern float cell_size; // = 270.0f

extern float player_size;




//Function Prototype Declaration
void title_init();
void title_deinit();
void title_update();
void title_render();


#endif // !SCENE_TITLE_H