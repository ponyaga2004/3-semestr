#ifndef __time_hpp
#define __time_hpp

#include <string>

class Time {
public:
    static Time from_string(std::string s);
    std::string to_string() const;

    unsigned int hours() const;
    unsigned int minutes() const;

private:
    Time();

private:
    unsigned int hours_;
    unsigned int minutes_;
};

bool operator<(Time const& t1, Time const& t2);

std::ostream& operator<<(std::ostream& os, Time const& t);

#endif
