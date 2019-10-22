#ifndef __commands_hpp
#define __commands_hpp

#include <vector>

#include "record.hpp"

void command_load(std::vector<Record>& records);
void command_save(std::vector<Record> const& records);
void command_add(std::vector<Record>& records);
void command_delete(std::vector<Record>& records);
void command_show_all(std::vector<Record> const& records);
void command_show_in_range(std::vector<Record> const& records);
void command_show_sorted_by_age(std::vector<Record> const& records);
void command_show_sorted_by_duration(std::vector<Record> const& records);
void command_show_by_source(std::vector<Record> const& records);
void command_show_by_destination(std::vector<Record> const& records);

bool sort_by_age_predicate(Record const& r1, Record const& r2);
bool sort_by_duration_predicate(Record const& r1, Record const& r2);

void header();

#endif
