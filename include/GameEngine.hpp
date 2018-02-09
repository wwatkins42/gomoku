#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <iostream>
# include <chrono>
# include <list>
# include <Eigen/Dense>

# define BOARD_COLS 19
# define BOARD_ROWS 19


typedef struct  s_action {
    Eigen::Array2i                  pos;
    uint8_t                         player_id;
    uint64_t                        id;
    std::chrono::duration<double>   timepoint;
}               t_action;


class GameEngine {

public:
    GameEngine(void);
    GameEngine(GameEngine const &src);
    ~GameEngine(void);
    GameEngine	&operator=(GameEngine const &rhs);

    bool                check_action(t_action &action); // check if action is valid
    bool                check_end(void);
    void                update_game_state(t_action &action); // update the game state given an action

    /* Getters */
    std::list<t_action>                     get_history(void) const;
    uint64_t                                get_history_size(void) const;
    std::chrono::steady_clock::time_point   get_initial_timepoint(void) const;
    /* Setters */

    Eigen::ArrayXXi                         grid;

private:
    std::list<t_action>                     _history;
    std::chrono::steady_clock::time_point   _initial_timepoint;
    /* the possible states of the board cells */
    struct state { enum { free=0, black=-1, white=1, black_free=-10, white_free=10 }; };

};

#endif
