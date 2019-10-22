#include <sstream>

#include "time.hpp"

Time::Time() {}

unsigned int Time::hours() const { return hours_; }
unsigned int Time::minutes() const { return minutes_; }

Time Time::from_string(std::string s) {
    std::stringstream iss(s);

    Time instance;

    std::string hours_s, minutes_s;
    std::getline(iss, hours_s, ':');
    std::getline(iss, minutes_s, ':');

    instance.hours_ = std::stoi(hours_s);
    instance.minutes_ = std::stoi(minutes_s);

    return instance;

}

std::string Time::to_string() const {
    std::stringstream oss;
    oss << hours_ << ":" << minutes_;
    return oss.str();
}

bool operator<(Time const& t1, Time const& t2) {
    if (t1.hours() < t2.hours()) return true;
    if (t2.hours() < t1.hours()) return false;
    return t1.minutes() < t2.minutes();
}

std::ostream& operator<<(std::ostream& os, Time const& t) {
    os << t.to_string();
    return os;
}
