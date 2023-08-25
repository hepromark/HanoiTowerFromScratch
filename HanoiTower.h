//
// Created by markd on 2023-08-23.
//

#ifndef HANOI_TOWER_RECURSION_HANOITOWER_H
#define HANOI_TOWER_RECURSION_HANOITOWER_H


class HanoiTower {
    friend class Test;
private:
    // Structure to represent disks to be moved
    struct Disk {
        Disk();
        explicit Disk(int value);
        int value_;  // the size of the disk
        Disk *next_;
    };

    // Structure for pegs of the tower
    struct Peg {
        // Default constructor and destructor
        Peg();
        ~Peg();
        int size_;
        Disk *top_{};
    };

    // Stack DS for disk movement between pegs
    // Implemented with Singly LinkedList
    void push(Peg* peg, Disk* new_disk);
    Disk* pop(Peg* peg);
    int peek(Peg* peg);
    bool is_empty(Peg* peg);
    int get_size(Peg* peg);

    // Array containing all pegs in game
    Peg** peg_array_;

    // Move counter
    int move_count_;

public:
    // Constructor with n = number of disks on starting peg
    explicit HanoiTower(int n);

    //Destructor
    ~HanoiTower();

    // Gameplay
    void move_recursive(int num_pegs, Peg* start, Peg* end, Peg* mid, bool draw_moves);
    int get_move_counter();
    void play_game(bool draw_moves);

    // Display method
    void draw_game();
};


#endif //HANOI_TOWER_RECURSION_HANOITOWER_H
