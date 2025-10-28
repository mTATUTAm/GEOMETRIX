#include "all.h"


void note_update(Note* notes, int note_count)
{
    // ▼ プレイヤーの前の座標（staticで維持）
    static int prev_grid_x = grid_x;
    static int prev_grid_y = grid_y;

    for (int i = 0; i < note_count; i++)
    {
        Note& note = notes[i];
        if (note.hit) continue;
        if (note.hit || abs(note.time - music_timer) > 120)

            continue;

        int diff = abs(music_timer - note.time);

        // ▼ ダッシュノーツ判定
        if (note.type == 2 && diff <= JUDGE_MISS)
        {
            int dx = grid_x - prev_grid_x;
            int dy = grid_y - prev_grid_y;

			bool dash_down = (0 < grid_y - prev_grid_y);
			bool dash_right = (0 < grid_x - prev_grid_x);
			bool dash_up = (grid_y - prev_grid_y < 0);
			bool dash_left = (grid_x - prev_grid_x < 0);


            bool correct_dash = ((dash_down && note.dir_rend.y == 1) || (dash_up && note.dir_rend.y == -1) ||
                (dash_right && note.dir_rend.x == 1) || (dash_left && note.dir_rend.x == -1));


            if (correct_dash && (STATE(0) & PAD_TRG1))
            {
                note.hit = true;
                note.judge = (diff <= JUDGE_PERFECT) ? JUDGE_PERFECT :
                    (diff <= JUDGE_GOOD) ? JUDGE_GOOD :
                    JUDGE_MISS;
                note.judge_timer = 30;

                // 音・スコア
                switch (note.judge)
                {
                case JUDGE_PERFECT:
                    music::play(SOUND_PERFECT, false);
                    result_note.score += 1000;
                    result_note.perfect++;
                    result_note.combo++;

                    // 最大コンボ更新

                    if (result_note.combo > result_note.max_combo)
                    {
                        result_note.max_combo = result_note.combo;
                    }

                    break;

                case JUDGE_GOOD:
                    music::play(SOUND_GOOD, false);
                    result_note.score += 500;
                    result_note.good++;
                    result_note.combo++;

                    // 最大コンボ更新
                    if (result_note.combo > result_note.max_combo)
                    {
                        result_note.max_combo = result_note.combo;
                    }

                    break;

                case JUDGE_MISS:
                    music::play(SOUND_MISS, false);
                    result_note.miss++;

                    // ミスでコンボリセット
                    result_note.combo = 0;
                    break;
                }
            }
        }

        // ▼ スライドノーツ判定
        else if (note.type == 1)
        {
            if (diff <= JUDGE_MISS)
            {
                int move_x = grid_x - prev_grid_x;
                int move_y = grid_y - prev_grid_y;

                if (grid_x == note.pos.x && grid_y == note.pos.y &&
                    move_x == note.dir.x && move_y == note.dir.y)
                {
                    note.hit = true;

                    if (diff <= JUDGE_PERFECT)
                    {
                        note.judge = JUDGE_PERFECT;
                        music::play(SOUND_PERFECT, false);
                        result_note.score += 1000;
                        result_note.perfect++;      // perfect 加算
                        result_note.combo++;        // コンボ加算
                    }
                    else if (diff <= JUDGE_GOOD)
                    {
                        note.judge = JUDGE_GOOD;
                        music::play(SOUND_GOOD, false);
                        result_note.score += 500;
                        result_note.good++;         // good 加算
                        result_note.combo++;        // コンボ加算
                    }
                    else
                    {
                        note.judge = JUDGE_MISS;
                        music::play(SOUND_MISS, false);
                        result_note.miss++;         // miss 加算
                        result_note.combo = 0;      // コンボリセット
                    }

                    // 最大コンボ更新
                    if (result_note.combo > result_note.max_combo)
                    {
                        result_note.max_combo = result_note.combo;
                    }

                    note.judge_timer = 30;
                }
            }
        }

        // ▼ ステイノーツ判定
        else if (note.type == 0)
        {
            bool is_now = (grid_x == note.pos.x && grid_y == note.pos.y);
            bool was_before = (prev_grid_x == note.pos.x && prev_grid_y == note.pos.y);
            int diff_time = music_timer - note.time;

            if (abs(diff_time) <= 4 && is_now)
            {
                note.hit = true;
                note.judge = JUDGE_PERFECT;
                note.judge_timer = 30;
                music::play(SOUND_PERFECT, false);
                result_note.score += 1000;
                result_note.perfect++;
                result_note.combo++;
            }
            else if (diff_time <= 0 && diff_time >= -7 && was_before && !is_now)
            {
                note.hit = true;
                note.judge = JUDGE_GOOD;
                note.judge_timer = 30;
                music::play(SOUND_GOOD, false);
                result_note.score += 500;
                result_note.good++;
                result_note.combo++;
            }
            else if (diff_time > 0 && diff_time <= 7 && is_now && !was_before)
            {
                note.hit = true;
                note.judge = JUDGE_GOOD;
                note.judge_timer = 30;
                music::play(SOUND_GOOD, false);
                result_note.score += 500;
                result_note.good++;
                result_note.combo++;
            }
            else if (diff_time > 7)
            {
                note.hit = true;
                note.judge = JUDGE_MISS;
                note.judge_timer = 30;
                music::play(SOUND_MISS, false);
                result_note.miss++;
                result_note.combo = 0;
            }

            // 最大コンボ更新
            if (result_note.combo > result_note.max_combo)
            {
                result_note.max_combo = result_note.combo;
            }
        }

            // ▼ 時間超過ミス（どのタイプでも共通）
            if (!note.hit && music_timer - note.time > 20)
            {
                note.hit = true;
                note.judge = JUDGE_MISS;
                note.judge_timer = 30;
                music::play(SOUND_MISS, false);
                result_note.miss++;
                result_note.combo = 0;

                // 最大コンボ更新は不要（missなので）
            }
    }

    // ▼ 最後に前フレームの位置を更新
    prev_grid_x = grid_x;
    prev_grid_y = grid_y;
}


Sprite* stay_note;
Sprite* slide_note;
Sprite* slide_note_ghost;
Sprite* dash_note;
Sprite* dash_note_ghost;


float clamp(float val, float min_val, float max_val)
{
    if (val < min_val) return min_val;
    if (val > max_val) return max_val;
    return val;
}

void draw_note(const Note& notes)
{
    float cx = 420 + 135 + notes.pos.x * 270; // グリッド中央x
    float cy = 135 + notes.pos.y * 270;       // グリッド中央y

    float grid_cx_right = 420 + notes.pos.x * 270; // line 中央x
	float grid_cx_left = 690 + notes.pos.x * 270; // line 中央x
	float grid_cy_up = 270 + notes.pos.y * 270;      // line 中央y
	float grid_cy_down = notes.pos.y * 270;      // line 中央y

    float scale = 2.5f;
    float alpha = 1.0f;
    float scale_right = 1.5f;
    float scale_left = 1.5f;

    
    int time_until = notes.time - music_timer;



    float t = clamp(1.0f - time_until / 50.0f, 0.0f, 1.0f);

	alpha = 1.0f - (time_until / 50.0f);

    scale = 2.5f - 1.5f * (1.0f - (1.0f - t) * (1.0f - t));

    scale_right = 1.0f * (1.0f - (1.0f - t) * (1.0f - t));
    scale_left = 2.5f - 1.5f * (1.0f - (1.0f - t) * (1.0f - t));

    stay_note = sprite_load(L"./Data/Images/stay_note.png");
    slide_note = sprite_load(L"./Data/Images/slide_note.png");
    dash_note = sprite_load(L"./Data/Images/dash_note.png");
	slide_note_ghost = sprite_load(L"./Data/Images/slide_note_ghost.png");
	dash_note_ghost = sprite_load(L"./Data/Images/dash_note_ghost.png");

    switch (notes.type)
    {
    case 0: // ステイ
        sprite_render
        (
            stay_note,
            cx, cy,
            scale, scale,
            0, 0,
            270, 270,
            135, 135,
            0,
            1, 0, 0, alpha 
        );
        break;

    case 1: // スライド（矢印）
        if (notes.dir.x == 1 && notes.dir.y == 0) //right
        {
            sprite_render
            (
                slide_note_ghost,
                grid_cx_right, cy,
                1.0f, 1.0f,
                0, 0,
                270, 270,
                135, 135,
                1.57,
                0.4f, 0.4f, 0.4f, 0.8f
            );
            sprite_render
            (
                slide_note,
                grid_cx_right * scale_right, cy,
                scale, scale,
                0, 0,
                270, 270,
                135, 135,
                1.57,
                1, 0, 0, alpha
            );
        }
        else if (notes.dir.x == -1 && notes.dir.y == 0) //left
        {
            sprite_render
            (
                slide_note_ghost,
                grid_cx_left, cy,
                1.0f, 1.0f,
                0, 0,
                270, 270,
                135, 135,
                4.71,
                0.4f, 0.4f, 0.4f, 0.8f
            );
            sprite_render
            (
                slide_note,
                grid_cx_left * scale_left, cy,
                scale, scale,
                0, 0,
                270, 270,
                135, 135,
                4.71,
                1, 0, 0, alpha
            );
        }
        else if (notes.dir.x == 0 && notes.dir.y == -1) //up
        {
            sprite_render
            (
                slide_note_ghost,
                cx, grid_cy_up,
                1.0f, 1.0f,
                0, 0,
                270, 270,
                135, 135,
                0,
                0.4f, 0.4f, 0.4f, 0.8f
            );
            sprite_render
            (
                slide_note,
                cx, grid_cy_up * scale_left,
                scale, scale,
                0, 0,
                270, 270,
                135, 135,
                0,
                1, 0, 0, alpha
            );
        }
        else if (notes.dir.x == 0 && notes.dir.y == 1) //down
        {
            sprite_render
            (
                slide_note_ghost,
                cx, grid_cy_down,
                1.0f, 1.0f,
                0, 0,
                270, 270,
                135, 135,
                3.14,
                0.4f, 0.4f, 0.4f, 0.8f
            );
            sprite_render
            (
                slide_note,
                cx, grid_cy_down * scale_right,
                scale, scale,
                0, 0,
                270, 270,
                135, 135,
                3.14,
                1, 0, 0, alpha
            );
        }
        break;

    case 2: // ダッシュ（強光矢印）
        if (notes.dir_rend.x == 1 && notes.dir_rend.y == 0) //right
        {
            sprite_render
            (
                dash_note_ghost,
                grid_cx_right, cy,
                1.0f, 1.0f,
                0, 0,
                270, 270,
                135, 135,
                1.57,
                0.4f, 0.4f, 0.4f, 0.8f
            );
            sprite_render
            (
                dash_note,
                grid_cx_right * scale_right, cy,
                scale, scale,
                0, 0,
                270, 270,
                135, 135,
                1.57,
                1, 0, 0, alpha
            );
        }
        else if (notes.dir_rend.x == -1 && notes.dir_rend.y == 0) //left
        {
            sprite_render
            (
                dash_note_ghost,
                grid_cx_left, cy,
                1.0f, 1.0f,
                0, 0,
                270, 270,
                135, 135,
                4.71,
                0.4f, 0.4f, 0.4f, 0.8f
            );
            sprite_render
            (
                dash_note,
                grid_cx_left * scale_left, cy,
                scale, scale,
                0, 0,
                270, 270,
                135, 135,
                4.71,
                1, 0, 0, alpha
            );
        }
        else if (notes.dir_rend.x == 0 && notes.dir_rend.y == -1) //up
        {
            sprite_render
            (
                dash_note_ghost,
                cx, grid_cy_up,
                1.0f, 1.0f,
                0, 0,
                270, 270,
                135, 135,
                0,
                0.4f, 0.4f, 0.4f, 0.8f
            );
            sprite_render
            (
                dash_note,
                cx, grid_cy_up * scale_left,
                scale, scale,
                0, 0,
                270, 270,
                135, 135,
                0,
                1, 0, 0, alpha
            );
        }
        else if (notes.dir_rend.x == 0 && notes.dir_rend.y == 1) //down
        {
            sprite_render
            (
                dash_note_ghost,
                cx, grid_cy_down,
                1.0f, 1.0f,
                0, 0,
                270, 270,
                135, 135,
                3.14,
                0.4f, 0.4f, 0.4f, 0.8f
            );
            sprite_render
            (
                dash_note,
                cx, grid_cy_down * scale_right,
                scale, scale,
                0, 0,
                270, 270,
                135, 135,
                3.14,
                1, 0, 0, alpha
            );
        }
        break;
    }
}

Sprite* perfect_img = nullptr;
Sprite* good_img = nullptr;
Sprite* miss_img = nullptr;

// 初期化時に一度だけ呼び出す関数
void load_judge_effect_images()
{
    perfect_img = sprite_load(L"./Data/Images/PERFECT_note.png");
    good_img = sprite_load(L"./Data/Images/GOOD_note.png");
    miss_img = sprite_load(L"./Data/Images/MISS_note.png");
}


void draw_judge_effect(Note& note)
{
    if (note.judge_timer > 0)
    {

        float alpha = pow(note.judge_timer / 15.0f, 2); // 時間経過でフェードアウト
        float scale = 1.0f;

        float cx = 420 + 135 + note.pos.x * 270;
        float cy = 135 + note.pos.y * 270;

        Sprite* sprite = nullptr;

        switch (note.judge)
        {
        case JUDGE_PERFECT:
            sprite = perfect_img;
            scale = 1.2f;
            break;
        case JUDGE_GOOD:
            sprite = good_img;
            scale = 1.0f;
            break;
        case JUDGE_MISS:
            sprite = miss_img;
            scale = 1.0f;
            break;
        default:
            break;
        }

        if (sprite)
        {
            sprite_render(
                sprite,
                cx, cy,
                scale, scale,
                0, 0,
                270, 63,
                110, 100,
                0.0f,
                1, 1, 1, alpha
            );
        }
        note.judge_timer--;
    }
}