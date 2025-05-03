#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class TodoList
{
private:
    std::string filename;

    std::vector<std::string> loadTasks()
    {
        std::vector<std::string> tasks;
        std::ifstream ifs(filename);
        std::string line;
        while (std::getline(ifs, line))
        {
            tasks.push_back(line);
        }
        return tasks;
    }

    void saveTasks(const std::vector<std::string> &tasks)
    {
        std::ofstream ofs(filename, std::ios::trunc);
        for (const auto &task : tasks)
        {
            ofs << task << "\n";
        }
    }

public:
    TodoList(const std::string &file) : filename(file) {}

    void addTask(const std::string &task)
    {
        std::ofstream ofs(filename, std::ios::app);
        if (ofs)
        {
            ofs << "[ ] " << task << "\n";
            std::cout << "Task added: " << task << std::endl;
        }
    }

    void viewTasks()
    {
        if (!fs::exists(filename))
        {
            std::cout << "No tasks yet." << std::endl;
            return;
        }

        std::ifstream ifs(filename);
        std::string line;
        int index = 1;
        while (std::getline(ifs, line))
        {
            std::cout << index++ << ". " << line << std::endl;
        }
    }

    void markTaskDone(int taskNumber)
    {
        auto tasks = loadTasks();
        if (taskNumber <= 0 || taskNumber > tasks.size())
        {
            std::cout << "Invalid task number." << std::endl;
            return;
        }

        if (tasks[taskNumber - 1].find("[ ]") != std::string::npos)
        {
            tasks[taskNumber - 1].replace(0, 3, "[x]");
            saveTasks(tasks);
            std::cout << "Task " << taskNumber << " marked as done." << std::endl;
        }
        else
        {
            std::cout << "Task already completed." << std::endl;
        }
    }
};

int main()
{
    TodoList todo("todo.txt");

    int choice;
    std::string input;
    int taskNumber;

    while (true)
    {
        std::cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Exit\nChoose: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1)
        {
            std::cout << "Enter task description: ";
            std::getline(std::cin, input);
            todo.addTask(input);
        }
        else if (choice == 2)
        {
            todo.viewTasks();
        }
        else if (choice == 3)
        {
            std::cout << "Enter task number to mark as done: ";
            std::cin >> taskNumber;
            todo.markTaskDone(taskNumber);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            std::cout << "Invalid choice. Try again.";
        }
    }

    return 0;
}
