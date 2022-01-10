//
// Created by pollini on 10/01/2022.
//

#ifndef RL_DA_ZERO_GAMESTATE_H
#define RL_DA_ZERO_GAMESTATE_H


class GameState {
public:
    virtual void update() = 0;
    virtual void handleInput() = 0;
//    virtual bool onEnter() = 0;
//    virtual bool onExit() = 0;
};


#endif //RL_DA_ZERO_GAMESTATE_H
