#include <sstream>

#include "record.hpp"

Record::Record(std::string const& source, std::string const& destination, Date const& date, Time const& time, unsigned int duration)
    : source_(source), destination_(destination), date_(date), time_(time), duration_(duration)
{
}

Record Record::from_string(std::string s) {
    std::string source, destination, date, time, duration;

    std::stringstream iss(s);
    std::getline(iss, source, '\t');
    std::getline(iss, destination, '\t');
    std::getline(iss, date, '\t');
    std::getline(iss, time, '\t');
    std::getline(iss, duration, '\t');

    return Record(source, destination, Date::from_string(date), Time::from_string(time), std::stoi(duration));
}

std::string Record::to_string() const {
    std::stringstream oss;
    oss << source_ << "\t" << destination_ << "\t" << date_ << "\t" << time_ << "\t" << duration_;
    return oss.str();
}

bool Record::is_source(std::string const& source) const { return source_ == source; }

bool Record::is_destination(std::string const& destination) const { return destination_ == destination; }

Date const& Record::date() const { return date_; }

Time const& Record::time() const { return time_; }

unsigned int Record::duration() const { return duration_; }

std::ostream& operator<<(std::ostream& os, Record const& r) {
    os << r.to_string();
    return os;
}
