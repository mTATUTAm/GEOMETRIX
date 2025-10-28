#ifndef SCENE_TITLE_H
#define SCENE_TITLE_H

extern float start_x;
extern float start_y;       // ��[
extern float grid_size;  // �����`�̃T�C�Y
extern float cell_size; // = 270.0f

extern float player_size;




//Function Prototype Declaration
void title_init();
void title_deinit();
void title_update();
void title_render();


#endif // !SCENE_TITLE_H