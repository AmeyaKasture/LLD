#include <iostream>
#include <memory>
#include <string>

class INotificationSender {
public:
    virtual ~INotificationSender() = default;

    virtual void send(const std::string& recipient,
                      const std::string& message) = 0;
};


// Email implementation
class EmailSender : public INotificationSender {
public:
    void send(const std::string& recipient,
              const std::string& message) override {
        std::cout << "[EMAIL] To: " << recipient
                  << " | Message: " << message << std::endl;
    }
};

// SMS implementation
class SmsSender : public INotificationSender {
public:
    void send(const std::string& recipient,
              const std::string& message) override {
        std::cout << "[SMS] To: " << recipient
                  << " | Message: " << message << std::endl;
    }
};

// Push Notification implementation
class PushNotificationSender : public INotificationSender {
public:
    void send(const std::string& recipient,
              const std::string& message) override {
        std::cout << "[PUSH] To: " << recipient
                  << " | Message: " << message << std::endl;
    }
};

class NotificationService {
private:
    // COMPOSITION: NotificationService HAS-A sender
    std::unique_ptr<INotificationSender> sender;

public:
    // DEPENDENCY INJECTION via constructor
    explicit NotificationService(
        std::unique_ptr<INotificationSender> sender)
        : sender(std::move(sender)) {}

    void notify(const std::string& user,
                const std::string& message) {
        sender->send(user, message);
    }
};


class MockNotificationSender : public INotificationSender {
public:
    void send(const std::string& recipient,
              const std::string& message) override {
        std::cout << "[MOCK] To: " << recipient
                  << " | Message: " << message << std::endl;
    }
};


void testNotificationService() {
    std::cout << "\n--- Running Unit Test ---\n";
    auto mockSender = std::make_unique<MockNotificationSender>();
    NotificationService service(std::move(mockSender));

    service.notify("test_user", "test_message");
}

int main() {
    std::cout << "=== Notification System Demo ===\n\n";

    // Email Notification
    {
        auto emailSender = std::make_unique<EmailSender>();
        NotificationService emailService(std::move(emailSender));
        emailService.notify("user@example.com", "Welcome to our platform!");
    }

    // SMS Notification
    {
        auto smsSender = std::make_unique<SmsSender>();
        NotificationService smsService(std::move(smsSender));
        smsService.notify("+91-9999999999", "Your OTP is 123456");
    }

    // Push Notification
    {
        auto pushSender = std::make_unique<PushNotificationSender>();
        NotificationService pushService(std::move(pushSender));
        pushService.notify("device_id_123", "You have a new message");
    }

    // Run unit test
    testNotificationService();

    return 0;
}