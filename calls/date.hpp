#ifndef __date_hpp
#define __date_hpp

#include <string>

class Date {
public:
    static Date from_string(std::string s);
    std::string to_string() const;

    unsigned int year() const;
    unsigned int month() const;
    unsigned int day() const;

private:
    Date();

private:
    unsigned int year_;
    unsigned int month_;
    unsigned int day_;
};

bool operator<(Date const& d1, Date const& d2);

std::ostream& operator<<(std::ostream& os, Date const& d);

#endif
