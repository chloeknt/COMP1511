// Assignment 2 21T1 COMP1511: Beats by CSE
// beats.c
//
// This program was written by Chloe Toh (z5362296)
// on 07/04/2021
//
// Version 1.0.0: Assignment released.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Add any extra #includes your code needs here.

#include "beats.h"

// Add your own #defines here.

typedef struct note *Note;
//////////////////////////////////////////////////////////////////////

// You don't have to use the provided struct track, you are free to
// make your own struct instead.
// If you use the provided struct track, you will have to add fields
// to store other information.

struct track {
    // TODO: You will have to add extra fields here in Stage 2.
    struct beat *head;
};

// You don't have to use the provided struct beat, you are free to
// make your own struct instead.
// If you use the provided struct beat, you may add fields
// to it to store other information.

struct beat {
    // You may choose to add or change fields in this struct.
    struct note *notes;
    struct beat *next;
};

// You don't have to use the provided struct note, you are free to
// make your own struct instead.
// If you use the provided struct note, you add fields
// to it to store other information.

struct note {
    // You may choose to add or change fields in this struct.
    int octave;
    int key;
    struct note *next;
};

// Add any other structs you define here.

//////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functions you create here.
Note create_note(int octave, int key, Note note);
Note loop_notes(int octave, int key, Note note);
void print_notes(Note note);
int count_notes(Note note, int octave);

// Return a malloced Beat with fields initialized.
Beat create_beat(void) {
    Beat new_beat = malloc(sizeof (struct beat));
    assert(new_beat != NULL);

    new_beat->next = NULL;
    new_beat->notes = NULL;

    // You do not need to change this function, unless you change
    // the implementation of struct beat.

    return new_beat;
}

// You need to implement the following functions.
// You can find descriptions of what each function should do in beats.h

//////////////////////////////////////////////////////////////////////
//                        Stage 1 Functions                         //
//////////////////////////////////////////////////////////////////////

// Add a note to the end of a beat.
int add_note_to_beat(Beat beat, int octave, int key) {
    //New note not valid
    //Valid octave (-1 < octave < 10)
    if (octave < 0 || octave >= 10) {
        return INVALID_OCTAVE;
    //Valid key (-1 < key < 12)
    } else if (key < 0 || key >= 12) {
        return INVALID_KEY;
    } else {  
        //Inserting into an empty list, no checks need to be made 
        if (beat->notes == NULL) {
            Note new_note = create_note(octave, key, NULL);
            beat->notes = new_note; 
            return VALID_NOTE;
        //Inserting into a populated list, check the previous node 
        } else {
            Note prev = loop_notes(octave, key, beat->notes);
            if (octave > prev->octave) {
                Note new_note = create_note(octave, key, prev->next);
                prev->next = new_note;
                return VALID_NOTE;
            } else if (octave == prev->octave && key > prev->key) {
                Note new_note = create_note(octave, key, prev->next);
                prev->next = new_note;
                return VALID_NOTE;
            } else {
                return NOT_HIGHEST_NOTE;
            }       
        }
    }
}


// Print the contents of a beat.
void print_beat(Beat beat) {
    print_notes(beat->notes);
    printf("\n");
}

// Count the number of notes in a beat that are in a given octave.
int count_notes_in_octave(Beat beat, int octave) {
    int number = count_notes(beat->notes, octave);
    return number;
}

//Count the notes 
int count_notes(Note note, int octave) {
    int number = 0;
    Note curr = note;
    while (curr != NULL) {
        if (octave == curr->octave) {
        number++;
        }
        curr = curr->next;
    }
    return number;
}


//Print the note nodes
void print_notes(Note note) {
    Note curr = note;
    int first = 0;
    while (curr != NULL) {
        if (first == 0 && curr->key < 10) {
            printf(" %d 0%d ", curr->octave, curr->key);
            first = 1;
        } else if (first == 0 && curr->key >= 10) {
            printf(" %d %d ", curr->octave, curr->key);
            first = 1;
        } else if (first == 1 && curr->key < 10) {
            printf("| %d 0%d ", curr->octave, curr->key);
        } else if (first == 1 && curr->key >= 10){
            printf("| %d %d ", curr->octave, curr->key);
        }
        curr = curr->next;
    }
}

//Allocate memory for a note node
//Populate that node with new_octave, new_key and new_next
//Return a pointer to the allocated memory
Note create_note(int new_octave, int new_key, Note new_next) {
    Note new_note = malloc(sizeof(struct note));
    new_note->next = NULL;
    new_note->octave = new_octave;
    new_note->key = new_key;
    return new_note; 
}

//Loop through the note nodes and find the previous note
//Check that it is a valid note, if so, add a note
Note loop_notes(int octave, int key, Note note) {
    Note prev = note;
    Note curr = note;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
    }
    return prev;
 }


//////////////////////////////////////////////////////////////////////
//                        Stage 2 Functions                         //
//////////////////////////////////////////////////////////////////////

// Return a malloced track with fields initialized.
Track create_track(void) {
    // Note: there is no fprintf in this function, as the
    // Stage 1 autotests call create_track but expect it to return NULL
    // (so this function should do nothing in Stage 1).

    return NULL;
}

// Add a beat after the current beat in a track.
void add_beat_to_track(Track track, Beat beat) {
    printf("add_beat_to_track not implemented yet.\n");
    return;
}

// Set a track's current beat to the next beat.
int select_next_beat(Track track) {
    printf("select_next_beat not implemented yet.\n");
    return TRACK_STOPPED;
}

// Print the contents of a track.
void print_track(Track track) {
    printf("print_track not implemented yet.\n");
    return;
}

// Count beats after the current beat in a track.
int count_beats_left_in_track(Track track) {
    printf("count_beats_left_in_track not implemented yet.\n");
    return 0;
}

//////////////////////////////////////////////////////////////////////
//                        Stage 3 Functions                         //
//////////////////////////////////////////////////////////////////////

// Free the memory of a beat, and any memory it points to.
void free_beat(Beat beat) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_beat but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than print an error).
    return;
}

// Free the memory of a track, and any memory it points to.
void free_track(Track track) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_track but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than print an error).
    return;
}

// Remove the currently selected beat from a track.
int remove_selected_beat(Track track) {
    printf("remove_selected_beat not implemented yet.");
    return TRACK_STOPPED;
}
