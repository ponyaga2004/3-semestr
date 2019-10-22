#include <iostream>
#include <fstream>
#include <algorithm>

#include "commands.hpp"
#include "record.hpp"

void command_load(std::vector<Record>& records) {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ifstream ifs(filename);

    records.clear();

    std::string line;
    while (std::getline(ifs, line)) {
        records.push_back(Record::from_string(line));
    }
}

void command_save(std::vector<Record> const& records) {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ofstream ofs(filename);
    for (size_t i = 0; i < records.size(); ++i) {
        ofs << records.at(i) << std::endl;
    }
    ofs.close();
}

void command_add(std::vector<Record>& records) {
    std::string source, destination, date, time;
    unsigned int duration;

    std::cout << "Enter source: ";
    std::cin >> source;
    std::cout << "Enter destination: ";
    std::cin >> destination;
    std::cout << "Enter date: ";
    std::cin >> date;
    std::cout << "Enter time: ";
    std::cin >> time;
    std::cout << "Enter duration: ";
    std::cin >> duration;

    records.push_back(Record(source, destination, Date::from_string(date), Time::from_string(time), duration));
}

void command_delete(std::vector<Record>& records) {
    size_t index;
    std::cout << "Enter index: ";
    std::cin >> index;
    --index;

    if (index >= records.size()) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    records.erase(records.begin() + index);
}

void command_show_all(std::vector<Record> const& records) {
    header();
    for (size_t i = 0; i < records.size(); ++i) {
        std::cout << i+1 << "\t" << records.at(i) << std::endl;
    }
}

void command_show_in_range(std::vector<Record> const& records) {
    std::string begin_string, end_string;
    std::cout << "Enter period begin: ";
    std::cin >> begin_string;
    std::cout << "Enter period end: ";
    std::cin >> end_string;

    Date begin = Date::from_string(begin_string);
    Date end = Date::from_string(end_string);

    std::vector<Record> clone = records;
    std::sort(clone.begin(), clone.end(), sort_by_age_predicate);
    int idx = 1;
    header();
    for (size_t i = 0; i < clone.size(); ++i) {
        Record r = clone.at(i);

        if (r.date() < begin) { continue; }
        if (end < r.date()) { break; }

        std::cout << idx << "\t" << r << std::endl;
        ++idx;
    }
}

void command_show_sorted_by_age(std::vector<Record> const& records) {
    std::vector<Record> clone = records;
    std::sort(clone.begin(), clone.end(), sort_by_age_predicate);
    header();
    for (size_t i = 0; i < clone.size(); ++i) {
        std::cout << i+1 << "\t" << clone.at(i) << std::endl;
    }
}

void command_show_sorted_by_duration(std::vector<Record> const& records) {
    std::vector<Record> clone = records;
    std::sort(clone.begin(), clone.end(), sort_by_duration_predicate);
    header();
    for (size_t i = 0; i < clone.size(); ++i) {
        std::cout << i+1 << "\t" << clone.at(i) << std::endl;
    }
}

void command_show_by_source(std::vector<Record> const& records) {
    std::string source;
    std::cout << "Enter source: ";
    std::cin >> source;

    int idx = 1;
    header();
    for (size_t i = 0; i < records.size(); ++i) {
        Record const& r= records.at(i);
        if (r.is_source(source)) {
            std::cout << idx << "\t" << r << std::endl;
            ++idx;
        }
    }
}

void command_show_by_destination(std::vector<Record> const& records) {
    std::string desctination;
    std::cout << "Enter destination: ";
    std::cin >> desctination;

    int idx = 1;
    header();
    for (size_t i = 0; i < records.size(); ++i) {
        Record const& r= records.at(i);
        if (r.is_destination(desctination)) {
            std::cout << idx << "\t" << r << std::endl;
            ++idx;
        }
    }

}

bool sort_by_age_predicate(Record const& r1, Record const& r2) {
    Date d1 = r1.date();
    Time t1 = r1.time();
    Date d2 = r2.date();
    Time t2 = r2.time();

    if (d1 < d2) return true;
    if (d2 < d1) return false;
    return t1 < t2;
}

bool sort_by_duration_predicate(Record const& r1, Record const& r2) {
    return r1.duration() < r2.duration();
}

void header() {
    std::cout << "#\tSource\tDestination\tDate\tTime\tDuration" << std::endl;
}
