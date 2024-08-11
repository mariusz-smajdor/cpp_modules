#include <string>
#include <iostream>

class Harl {

private:
    void _debug(void);
    void _info(void);
    void _warning(void);
    void _error(void);
    int _getLevelIndex(std::string& level);

public:
    Harl();
    ~Harl();
    void complain(std::string level);

};
