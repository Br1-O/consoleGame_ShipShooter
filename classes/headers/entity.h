#if !defined(ENTITY_H)
#define ENTITY_H

//abstract class for in-game entities
class Entity
{
public:

    //getters

    //returns X coordinate
    virtual int getX() const = 0;
    //returns Y coordinate
    virtual int getY() const = 0;
    //returns the max size of the class along X axis
    virtual size_t getWidth() const = 0;
    //returns the max size of the class along Y axis
    virtual size_t getHeight() const = 0;

    //methods

    //shows object into screen
    virtual void create() const = 0;
    //erases object from screen
    virtual void erase() const = 0;
    //moves object in screen
    virtual void move() = 0;

    //destructor
    virtual ~Entity() = default;
};

#endif
