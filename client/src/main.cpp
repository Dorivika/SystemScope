#include "../include/client.hpp"

int main() {
    try {
        SystemMonitorClient client;
        client.connect("ws://localhost:9002");
        client.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}