#include <iostream>
#include <fstream>
#include <memory>
#include <string>

// Interface for Logger
class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void log(const std::string& message) = 0;
};

// FileLogger: Writes logs to a file
class FileLogger : public ILogger {
private:
    std::ofstream ofs;

public:
    explicit FileLogger(const std::string& filename) {
        ofs.open(filename, std::ios::app);
        if (!ofs.is_open()) {
            throw std::runtime_error("Failed to open file: " + filename);
        }
    }

    void log(const std::string& message) override {
        ofs << message << std::endl;
    }

    ~FileLogger() {
        if (ofs.is_open()) ofs.close();
    }
};

// ConsoleLogger: Writes logs to the console
class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

// Application class using dependency injection
class Application {
private:
    std::shared_ptr<ILogger> logger;

public:
    explicit Application(std::shared_ptr<ILogger> logger) : logger(std::move(logger)) {}

    void run() {
        logger->log("Application started");
        logger->log("Performing some tasks...");
        logger->log("Application finished");
    }
};

int main() {
    try {
        // Use FileLogger
        std::shared_ptr<ILogger> fileLogger = std::make_shared<FileLogger>("app.log");
        Application app1(fileLogger);
        app1.run();

        // Use ConsoleLogger
        std::shared_ptr<ILogger> consoleLogger = std::make_shared<ConsoleLogger>();
        Application app2(consoleLogger);
        app2.run();
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}