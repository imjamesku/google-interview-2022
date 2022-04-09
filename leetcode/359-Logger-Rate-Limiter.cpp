#include <unordered_map>
using namespace std;

// 6m20s42
class Logger {
   public:
    Logger() {
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (lastPrintedTime.count(message)) {
            if (timestamp - lastPrintedTime[message] >= 10) {
                lastPrintedTime[message] = timestamp;
                return true;
            } else {
                return false;
            }
        } else {
            lastPrintedTime[message] = timestamp;
            return true;
        }
    }

   private:
    unordered_map<string, int> lastPrintedTime{};
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */