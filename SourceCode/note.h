#ifndef NOTE_H
#define NOTE_H

//Function Prototype Declaration
void note_update(Note* notes, int note_count);
void draw_note(const Note& note);
void draw_judge_effect(Note& note);
void load_judge_effect_images();



#endif // !NOTE_H