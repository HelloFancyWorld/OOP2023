#include "Splash.h"
#include "Object.h"

int Object::act_water(Direction fromwhere, Actor fromwho) {
	// TODO
    int result = 0;
    switch(fromwho)
    {
        case PLAYER:
        case WATER:
        size++;
        if(size == 4)
        {
            int _x = x; int _y = y; Splash* _splash = splash;
            set2void(this->x, this->y, this->splash);
            this->~Object();

            if(_x > 0) result += _splash->map[_x - 1][_y]->act(LEFT, WATER);
            if(_x < _splash->size - 1) result += _splash->map[_x + 1][_y]->act(RIGHT, WATER);
            if(_y > 0) result += splash->map[x][y - 1]->act(UP, WATER);
            if(_y < _splash->size - 1) result += _splash->map[_x][_y + 1]->act(DOWN, WATER);
            
            return (result + 1);
        }
        break;

        case TOXIC:
        size--;
        if(size == 0)
        {
            set2void(this->x, this->y, this->splash);
            this->~Object();
        }
        break;
    }
    return result;
}

int Object::act_void(Direction fromwhere, Actor fromwho) {
	// TODO
    int result = 0;
    switch(fromwho)
    {
        case PLAYER:
            cout << "Error: Cannot act a Void." << endl;
            break;
        case WATER:
            switch(fromwhere)
            {
                case LEFT:
                    if(x > 0) result += splash->map[x - 1][y]->act(LEFT, WATER);
                    break;
                case RIGHT:
                    if(x < splash->size - 1) result += splash->map[x + 1][y]->act(RIGHT, WATER);
                    break;
                case UP:
                    if(y > 0) result += splash->map[x][y - 1]->act(UP, WATER);
                    break;
                case DOWN:
                    if(y < splash->size - 1) result += splash->map[x][y + 1]->act(DOWN, WATER);
                    break;
                case NONE:
                    break;
            }
            break;
        case TOXIC:
            switch(fromwhere)
            {
                case LEFT:
                    if(x > 0) result += splash->map[x - 1][y]->act(LEFT, TOXIC);
                    break;
                case RIGHT:
                    if(x < splash->size - 1) result += splash->map[x + 1][y]->act(RIGHT, TOXIC);
                    break;
                case UP:
                    if(y > 0) result += splash->map[x][y - 1]->act(UP, TOXIC);
                    break;
                case DOWN:
                    if(y < splash->size - 1) result += splash->map[x][y + 1]->act(DOWN, TOXIC);
                    break;
                case NONE:
                    break;
            }
            break;
    }
    return result;
}

int Object::act_barrier(Direction fromwhere, Actor fromwho) {
	// TODO
    switch(fromwho)
    {
        case PLAYER:
            cout << "Error: Cannot act a Barrier." << endl;
            break;
        case WATER:
        case TOXIC:
            break;
    }
    return 0;
}

int Object::act_toxic(Direction fromwhere, Actor fromwho) {
	// TODO
    int result = 0;
    switch(fromwho)
    {
        case PLAYER:
        case TOXIC:
        size++;
        if(size == 4)
        {
            int _x = x; int _y = y; Splash* _splash = splash;
            set2void(this->x, this->y, this->splash);
            this->~Object();

            if (_x > 0) result += _splash->map[_x - 1][_y]->act(LEFT, TOXIC);
            if (_x < _splash->size - 1) result += _splash->map[_x + 1][_y]->act(RIGHT, TOXIC);
            if (_y > 0) result += splash->map[x][y - 1]->act(UP, TOXIC);
            if (_y < _splash->size - 1) result += _splash->map[_x][_y + 1]->act(DOWN, TOXIC);
            return (result - 1);
        }
        break;

        case WATER:
        size--;
        if(size == 0)
        {
            set2void(this->x, this->y, this->splash);
            this->~Object();
        }
        break;
    }
    return result;
}