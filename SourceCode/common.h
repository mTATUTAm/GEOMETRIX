#ifndef COMMON_H
#define COMMON_H


//scene labels
#define SCENE_NONE -1
#define SCENE_TITLE 0
#define SCENE_GAME 1
#define SCENE_EAZY 2
#define SCENE_NORMAL 3
#define SCENE_CRY 4
#define SCENE_TUTORIAL 5
#define SCENE_RESULT 6

#define MUSIC_TITLE 1
#define MUSIC_NADE 2
#define MUSIC_NADE_INTRO 3
#define MUSIC_CRY 4
#define MUSIC_CRY_INTRO 5
#define SOUND_CONFIRM 6
#define SOUND_PERFECT 7
#define SOUND_MOVE 8
#define SOUND_GOOD 9
#define SOUND_MISS 10
#define SOUND_DASH 11

#define FADE_NONE 100
#define FADE_DONE 101
#define FADE_IN 102
#define FADE_OUT 103
#define FADE_OUT_START 104

#define RESULT_CRY 0
#define RESULT_NADE 1
#define RESULT_TUTO 2

#define IN_GAME 1
#define IN_RESULT 2
#define IN_SELECT 3


extern int result_tag;

//Declaration of Variables
extern int cur_scene;
extern int next_scene;

extern int grid_x;
extern int grid_y;

extern float player_x;
extern float player_y;

extern int fade_state;

extern float fade_alpha; 
extern float fade_speed;

extern bool allow_x_move;
extern bool allow_y_move;

extern int note_count;
extern int music_timer;




struct Result_date {
    int perfect;
	int good;
	int miss;
	int score;
    int combo;
	int max_score;
    int max_combo;
};

extern Result_date result_note;
extern Result_date result_nade;
extern Result_date result_cry;
extern Result_date result_tuto;

enum JudgeResult {
    JUDGE_NONE = 30,
    JUDGE_MISS = 20,
    JUDGE_GOOD = 14,
    JUDGE_PERFECT = 4
};


struct Note {
    int time;
    int type;
    VECTOR2 pos;
    VECTOR2 dir;
    VECTOR2 dir_rend;
    bool hit;
    JudgeResult judge;
    int judge_timer;
};



/* ===== CONSTANT =====*/
#define SCREEN_W 1920
#define SCREEN_H 1080

#endif