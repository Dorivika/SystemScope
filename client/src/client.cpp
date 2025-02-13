#include "client.hpp"

SystemMonitorClient::SystemMonitorClient() {
    client.init_asio();
    client.set_open_handler([this](websocketpp::connection_hdl hdl) {
        on_open(&client, hdl);
    });
    client.set_message_handler([this](websocketpp::connection_hdl hdl, WebSocketClient::message_ptr msg) {
        on_message(&client, hdl, msg);
    });
}

void SystemMonitorClient::connect(const std::string& uri) {
    websocketpp::lib::error_code ec;
    WebSocketClient::connection_ptr con = client.get_connection(uri, ec);
    if (ec) {
        std::cerr << "Connection error: " << ec.message() << std::endl;
        return;
    }
    client.connect(con);
}

void SystemMonitorClient::run() {
    client.run();
}

void SystemMonitorClient::on_open(WebSocketClient* c, websocketpp::connection_hdl hdl) {
    std::cout << "Connected to server" << std::endl;
}

void SystemMonitorClient::on_message(WebSocketClient* c, websocketpp::connection_hdl hdl, WebSocketClient::message_ptr msg) {
    std::cout << "Received: " << msg->get_payload() << std::endl;
}