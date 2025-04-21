#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Logger
{
private:
    vector<string> logs;
    const size_t MAX_LOGS = 1000;

    void storeLog(const string &severity, const string &source, const string &message)
    {
        string formatted = "[" + severity + "] (" + source + "): " + message;
        if (logs.size() >= MAX_LOGS)
        {
            logs.erase(logs.begin());
        }
        logs.push_back(formatted);
    }

public:
    void logInfo(const string &source, const string &message)
    {
        storeLog("INFO", source, message);
    }

    void logWarning(const string &source, const string &message)
    {
        storeLog("WARN", source, message);
    }

    void logError(const string &source, const string &message)
    {
        storeLog("ERROR", source, message);
    }

    friend class Auditor;
};

class Auditor
{
private:
    bool authenticated;
    const string auditorPass = "admin123";

public:
    Auditor() : authenticated(false) {}

    bool authenticate(const string &password)
    {
        authenticated = (password == auditorPass);
        return authenticated;
    }

    void viewLogs(const Logger &logger) const
    {
        if (!authenticated)
        {
            cout << "Access Denied. Auditor not authenticated.\n";
            return;
        }

        cout << "\n--- AUDIT LOGS ---\n";
        for (const string &log : logger.logs)
        {
            cout << log << endl;
        }
        cout << "------------------\n";
    }
};

int main()
{
    Logger systemLogger;

    systemLogger.logInfo("Network", "Connected to server.");
    systemLogger.logWarning("Database", "Query took too long.");
    systemLogger.logError("Auth", "Failed login attempt detected.");
    systemLogger.logInfo("UI", "User clicked login.");

    Auditor audit;
    audit.viewLogs(systemLogger);
    audit.authenticate("wrongpass");
    audit.viewLogs(systemLogger);

    audit.authenticate("admin123");
    audit.viewLogs(systemLogger);

    return 0;
}
