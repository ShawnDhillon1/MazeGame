#ifndef POSITION_H
#define POSITION_H
//represents a point in grid representing x and y coordinates
class Position {
public:
    int x, y; //store x and y coordinates
    Position(int x = 0, int y = 0);//create Position object
    //compares current Position with another Position object
    // return true if x and y equal
    bool operator==(const Position& other) const;

    //compares current Position with another Position object
    //return true if either x and y coordinates are equal
    bool operator!=(const Position& other) const;
    
    //MD measure of distance b/w two points in grid-based system
    // sum of absolute differences x and y
    int manhattanDistance(const Position& other) const;
};

#endif
