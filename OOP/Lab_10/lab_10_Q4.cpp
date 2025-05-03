#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class RotatingLogger
{
private:
    std::string filename;
    size_t maxSize;
    int logCount;

    void rotateLog()
    {
        std::string newName = "log" + std::to_string(logCount++) + ".txt";
        fs::rename(filename, newName);
        std::cout << "Rotated log to: " << newName << std::endl;
    }

public:
    RotatingLogger(const std::string &file, size_t sizeLimit)
        : filename(file), maxSize(sizeLimit), logCount(1) {}

    void log(const std::string &message)
    {
        if (fs::exists(filename) && fs::file_size(filename) > maxSize)
        {
            rotateLog();
        }

        std::ofstream ofs(filename, std::ios::app);
        if (ofs)
        {
            ofs << message << "\n";
        }
    }
};

// Example usage
int main()
{
    RotatingLogger logger("log.txt", 1024); // 1 KB limit for testing

    for (int i = 0; i < 100; ++i)
    {
        logger.log("Log entry number " + std::to_string(i));
    }

    return 0;
}
