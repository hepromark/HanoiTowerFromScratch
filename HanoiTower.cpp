//
// Created by markd on 2023-08-23.
//
#include <iostream>
#include "HanoiTower.h"
// Constructors
HanoiTower::Disk::Disk() {
    value_ = 0;
    next_ = nullptr;
};

HanoiTower::Disk::Disk(int value) {
    value_ = value;
    next_ = nullptr;
};

HanoiTower::Peg::Peg() {
    size_ = 0;
    top_ = nullptr;
}

HanoiTower::HanoiTower(int n) {
    // Initialize pegs
    peg_array_ = new Peg*[3];

    // Initialize disks
    for (int i = 0; i < 3; i++) {
        peg_array_[i] = new Peg();
    }
    // starting peg [index 0] starts with all disks
    for (int disk_size = n; disk_size > 0; disk_size--) {
        Disk* new_disk = new Disk(disk_size);
        push(peg_array_[0], new_disk);
    }
    
    // Initialize move counter
    move_count_ = 0; 
}

// Destructors
HanoiTower::Peg::~Peg() {
    Disk* curr_disk = top_;
    while (curr_disk != nullptr)
    {
        Disk* next_disk = curr_disk->next_;
        delete curr_disk;
        curr_disk = next_disk;
    }
}

HanoiTower::~HanoiTower() {
    for (int i =0; i < 3; i++) {
        delete peg_array_[i];
        peg_array_[i] = nullptr;
    }
    delete peg_array_;
    peg_array_ = nullptr;
}

// Private Peg Methods
void HanoiTower::push(HanoiTower::Peg *peg,
                                   HanoiTower::Disk *new_disk) {
    // empty peg
    if (peg->size_ == 0) {
        peg->top_ = new_disk;
        peg->size_++;
        return;
    }
    new_disk->next_ = peg->top_;
    peg->top_ = new_disk;
    peg->size_++;
}

HanoiTower::Disk* HanoiTower::pop(HanoiTower::Peg *peg) {
    // if peg is empty
    if (get_size(peg) == 0)
        return nullptr;

    // remove top disk
    Disk* popped = peg->top_;
    peg->top_ = peg->top_->next_;
    popped->next_ = nullptr;
    peg->size_--;

    return popped;
}

int HanoiTower::peek(HanoiTower::Peg *peg) {
    if (is_empty(peg))
        return -1;
    return peg->top_->value_;
}

bool HanoiTower::is_empty(HanoiTower::Peg *peg) {
    return (peg->top_ == nullptr);
}

int HanoiTower::get_size(HanoiTower::Peg *peg) {
    return peg->size_;
}

int HanoiTower::get_move_counter() {
    return move_count_;
}

void HanoiTower::move_recursive(int num_pegs,
                                HanoiTower::Peg *start,
                                HanoiTower::Peg *end,
                                HanoiTower::Peg *mid,
                                bool draw_moves) {

    // base case
    if (num_pegs == 1) {
        // n = 1 can move directly
        push(end, pop(start));
        move_count_++;

        // Draw each move
        if (draw_moves) draw_game();

        return;
    }
    // recursive case
    // 1. move (n-1) disks from Start to Mid
    // 'end' peg becomes the mid peg
    move_recursive(num_pegs - 1, start, mid, end, draw_moves);

    // 2. move remaining 1 disk from Start to End
    move_recursive(1, start, end, mid, draw_moves);

    // 3. move all disks at Mid to End
    // 'start' peg becomes the mid peg
    move_recursive(num_pegs - 1, mid, end, start, draw_moves);
}

void HanoiTower::draw_game() {
    // Print current position of each disk and pegs
    std::cout << "---------" << std::endl;
    for (int i = 0; i < 3; i++) {
        if (i == 0) std::cout << "Peg A: ";
        if (i == 1) std::cout << "Peg B: ";
        if (i == 2) std::cout << "Peg C: ";
        Disk *curr_disk = peg_array_[i]->top_;
        while (curr_disk != nullptr) {
            std::cout << curr_disk->value_;
            curr_disk = curr_disk->next_;
        }
        std::cout << std::endl;
    }
    std::cout << "---------" << std::endl;
}

void HanoiTower::play_game(bool draw_moves) {
    move_recursive(peg_array_[0]->size_,
                   peg_array_[0],
                   peg_array_[2],
                   peg_array_[1],
                   draw_moves);
    std::cout << "Total Moves: " << get_move_counter() << std::endl;
}



