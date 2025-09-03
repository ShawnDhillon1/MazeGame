#include "Position.h" //includes header file
#include <cstdlib>
// initializes position object
Position::Position(int x, int y) : x(x), y(y) {}
//declare const bevause operator doesnt modify object
bool Position::operator==(const Position& other) const {
    return x == other.x && y == other.y;
}

bool Position::operator!=(const Position& other) const {
   //returns true if objects not equal false otherwise  
    return !(*this == other);
}

int Position::manhattanDistance(const Position& other) const {
    //returns true if objects not equal false otherwise
    return abs(x - other.x) + abs(y - other.y);
}
