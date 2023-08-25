#include <iostream>
#include <cassert>

#include "HanoiTower.h"

class Test {
public:
    // Constructor tests
    static bool test_game_constructor_destructor();

    // Peg and Disks stack implementation tests
    static bool test1();
    static bool test2();
    static bool test3();

    // Recursive Algorithm Test
    static bool test_recursive_1();
    static bool test_recursive_2();
};

bool Test::test_game_constructor_destructor() {
    // Testing n constructor and destructor
    HanoiTower tower = HanoiTower(3);
    assert(tower.peg_array_[0]->size_ == 3);
    assert(tower.peg_array_[1]->size_ == 0);
    assert(tower.peg_array_[2]->size_ == 0);
    return true;
}

bool Test::test1() {
    // Testing pop()
    HanoiTower tower = HanoiTower(3);

    for (int i = 0; i < 3; i++) {
        HanoiTower::Disk* disk = tower.pop(tower.peg_array_[0]);
        assert(disk->value_ == i+1);
    }
    assert(tower.peg_array_[0]->size_ == 0);
    assert(tower.pop(tower.peg_array_[0]) == nullptr);
    assert(tower.pop(tower.peg_array_[1]) == nullptr);
    assert(tower.pop(tower.peg_array_[2]) == nullptr);
    return true;
}

bool Test::test2() {
    // Testing peek()
    HanoiTower tower = HanoiTower(4);
    assert(tower.peek(tower.peg_array_[0]) == 1);
    tower.pop(tower.peg_array_[0]);
    assert(tower.peek(tower.peg_array_[0]) == 2);
    tower.pop(tower.peg_array_[0]);
    assert(tower.peek(tower.peg_array_[0]) == 3);
    tower.pop(tower.peg_array_[0]);
    assert(tower.peek(tower.peg_array_[0]) == 4);

    return true;
}

bool Test::test3() {
    // Testing pop() from one peg to push() onto another peg
    HanoiTower tower = HanoiTower(4);
    tower.push(tower.peg_array_[1], tower.pop(tower.peg_array_[0]));
    assert(tower.peek(tower.peg_array_[1]) == 1);
    assert(tower.peek(tower.peg_array_[0]) == 2);
    tower.push(tower.peg_array_[2], tower.pop(tower.peg_array_[0]));
    assert(tower.peek(tower.peg_array_[2]) == 2);
    assert(tower.peek(tower.peg_array_[0]) == 3);

    return true;
}

bool Test::test_recursive_1() {
    // test base case
    HanoiTower tower = HanoiTower(3);
    // move top disk from Peg A to Peg C
    tower.move_recursive(1,
                         tower.peg_array_[0],
                         tower.peg_array_[1],
                         tower.peg_array_[2],
                         false);

    // move top disk from Peg A to Peg B
    tower.move_recursive(1,
                         tower.peg_array_[0],
                         tower.peg_array_[2],
                         tower.peg_array_[1],
                         false);

    assert(tower.peek(tower.peg_array_[0]) == 3);
    assert(tower.peek(tower.peg_array_[1]) == 1);
    assert(tower.peek(tower.peg_array_[2]) == 2);

    return true;
}

bool Test::test_recursive_2() {
    // Test recursive algorithm
    int NUM_DISKS = 5;
    HanoiTower tower = HanoiTower(NUM_DISKS);
    tower.draw_game();
    tower.move_recursive(NUM_DISKS,
                         tower.peg_array_[0],
                         tower.peg_array_[2],
                         tower.peg_array_[1],
                         false);

    assert(tower.is_empty(tower.peg_array_[0]));
    assert(tower.is_empty(tower.peg_array_[1]));
    assert(tower.peg_array_[2]->size_ == NUM_DISKS);

    return true;
}
int main() {
//    Test test = Test();
//    std::cout << test.test_game_constructor_destructor() << std::endl;
//    std::cout << test.test1() << std::endl;
//    std::cout << test.test2() << std::endl;
//    std::cout << test.test3() << std::endl;
//    std::cout << test.test_recursive_1() << std::endl;
//    std::cout << test.test_recursive_2() << std::endl;
    int const NUM_DISKS = 5;
    HanoiTower game = HanoiTower(NUM_DISKS);
    game.play_game(false);
}
