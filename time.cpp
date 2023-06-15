#include <iostream>
#include <chrono>
bool isValidTime(int hour, int minute, int second) {
    if (hour < 0 || hour > 23)
        return false;

    if (minute < 0 || minute > 59)
        return false;

    if (second < 0 || second > 59)
        return false;

    return true;
}int main() {
    // Get the current time

    
    auto currentTime = std::chrono::system_clock::now();
    time_t currentTime_t = std::chrono::system_clock::to_time_t(currentTime);
    tm* currentTime_tm = localtime(&currentTime_t);

    // Set the desired time to 9:00 PM
    tm desiredTime_tm = *currentTime_tm; // Initialize with current time
    desiredTime_tm.tm_hour = 21; // 9 PM
    desiredTime_tm.tm_min = 0;
    desiredTime_tm.tm_sec = 0;
    time_t desiredTime_t = mktime(&desiredTime_tm);

    // Convert time_t to std::chrono::time_point
    auto currentTimePoint = std::chrono::system_clock::from_time_t(currentTime_t);
    auto desiredTimePoint = std::chrono::system_clock::from_time_t(desiredTime_t);

    // Compare the time objects
    if (currentTimePoint < desiredTimePoint) {
        std::cout << "The current time is earlier than 9:00 PM." << std::endl;
    } else if (currentTimePoint > desiredTimePoint) {
        std::cout << "The current time is later than 9:00 PM." << std::endl;
    } else {
        std::cout << "The current time is 9:00 PM." << std::endl;
    }

    return 0;
}
