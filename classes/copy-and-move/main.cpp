#include "copy_and_move_class.h"

int main() {

    // Here we create an instance of our class. We
    // can print the value
    CopyAndMoveClass class_to_move_a("Initial value A");
    class_to_move_a.print();

    // This uses the copy constructor. Now copied_class_a
    // has the same contents as class_to_move_a.
    CopyAndMoveClass copied_class_a = class_to_move_a;
    class_to_move_a.print();
    copied_class_a.print();

    // This uses the move constructor. Now there is nothing
    // in the original class, but the new one is populated.
    CopyAndMoveClass moved_class_a = std::move(class_to_move_a);
    class_to_move_a.print();
    moved_class_a.print();

    // We create another instance of the class, as the old one
    // is empty
    CopyAndMoveClass class_to_move_b("Initial value B");
    
    // Here we use copy assignment. Both values will still be 
    // populated, like the constructor.
    CopyAndMoveClass copied_class_b;
    copied_class_b = class_to_move_b;

    // Both values will still be populated, like the constructor.
    copied_class_b.print();
    class_to_move_b.print();

    // Now we use the move assignment. Like with the constructor,
    // the old object is no longer valid.
    CopyAndMoveClass moved_class_b;
    moved_class_b = std::move(class_to_move_b);
    moved_class_b.print();
    class_to_move_b.print();

    return 0;
}