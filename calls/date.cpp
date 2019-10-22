#include <sstream>

#include "date.hpp"

Date::Date() {}

unsigned int Date::year() const { return year_; }
unsigned int Date::month() const { return month_; }
unsigned int Date::day() const { return day_; }

Date Date::from_string(std::string s) {
    std::stringstream iss(s);

    Date instance;

    std::string year_s, month_s, day_s;
    std::getline(iss, day_s, '.');
    std::getline(iss, month_s, '.');
    std::getline(iss, year_s, '.');

    instance.year_ = std::stoi(year_s);
    instance.month_ = std::stoi(month_s);
    instance.day_ = std::stoi(day_s);

    if (instance.year_ < 2000) instance.year_ += 2000;

    return instance;
}

std::string Date::to_string() const {
    std::stringstream oss;
    oss << day_ << "." << month_ << "." << year_;
    return oss.str();
}

bool operator<(Date const& d1, Date const& d2) {
    if (d1.year() < d2.year()) return true;
    if (d2.year() < d1.year()) return false;

    if (d1.month() < d2.month()) return true;
    if (d2.month() < d1.month()) return false;

    return d1.day() < d2.day();
}

std::ostream& operator<<(std::ostream& os, Date const& d) {
    os << d.to_string();
    return os;
}
