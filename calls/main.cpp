#include <iostream>
#include <vector>

#include "commands.hpp"

enum Command {
    Load,
    Save,
    Add,
    Delete,
    ShowAll,
    ShowInRange,
    ShowSortedByAge,
    ShowSortedByDuration,
    ShowBySource,
    ShowByDestination,
    Quit,
    Unknown,
};

void menu() {
    std::cout << "Commands:" << std::endl;
    std::cout << "[l] load" << std::endl;
    std::cout << "[s] save" << std::endl;
    std::cout << "[a] add" << std::endl;
    std::cout << "[d] delete" << std::endl;
    std::cout << "[1] show all" << std::endl;
    std::cout << "[2] show in range" << std::endl;
    std::cout << "[3] show by age" << std::endl;
    std::cout << "[4] show by duration" << std::endl;
    std::cout << "[5] show for source" << std::endl;
    std::cout << "[6] show for desctination" << std::endl;
    std::cout << "[q] quit" << std::endl;
}

Command read_command() {
    std::cout << "Enter command: ";

    std::string s;
    std::cin >> s;

    if (s == "l") return Command::Load;
    if (s == "s") return Command::Save;
    if (s == "a") return Command::Add;
    if (s == "d") return Command::Delete;
    if (s == "1") return Command::ShowAll;
    if (s == "2") return Command::ShowInRange;
    if (s == "3") return Command::ShowSortedByAge;
    if (s == "4") return Command::ShowSortedByDuration;
    if (s == "5") return Command::ShowBySource;
    if (s == "6") return Command::ShowByDestination;
    if (s == "q") return Command::Quit;
    return Command::Unknown;
}

void repl() {
    std::vector<Record> records;

    for (;;) {
        menu();
        Command command = read_command();

        switch(command) {
        case Command::Load:
            command_load(records);
            break;
        case Command::Save:
            command_save(records);
            break;
        case Command::Add:
            command_add(records);
            break;
        case Command::Delete:
            command_delete(records);
            break;
        case Command::ShowAll:
            command_show_all(records);
            break;
        case Command::ShowInRange:
            command_show_in_range(records);
            break;
        case Command::ShowSortedByAge:
            command_show_sorted_by_age(records);
            break;
        case Command::ShowSortedByDuration:
            command_show_sorted_by_duration(records);
            break;
        case Command::ShowBySource:
            command_show_by_source(records);
            break;
        case Command::ShowByDestination:
            command_show_by_destination(records);
            break;
        case Command::Quit:
            return;
        case Command::Unknown:
            break;
        }
    }
}

int main()
{
    repl();
    return 0;
}
