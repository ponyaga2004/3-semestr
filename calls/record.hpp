#ifndef __record_hpp
#define __record_hpp

#include "date.hpp"
#include "time.hpp"

class Record {
public:
    Record(std::string const& source, std::string const& destination, Date const& date, Time const& time, unsigned int duration);

    static Record from_string(std::string s);
    std::string to_string() const;

    bool is_source(std::string const& source) const;
    bool is_destination(std::string const& destination) const;
    Date const& date() const;
    Time const& time() const;
    unsigned int duration() const;

private:
    std::string source_;
    std::string destination_;
    Date date_;
    Time time_;
    unsigned int duration_;
};

std::ostream& operator<<(std::ostream& os, Record const& r);

#endif
