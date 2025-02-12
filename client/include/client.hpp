#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

typedef websocketpp::client<websocketpp::config::asio_client> WebSocketClient;

class SystemMonitorClient {
public:
    SystemMonitorClient();
    void connect(const std::string& uri);
    void run();

private:
    WebSocketClient client;
    websocketpp::connection_hdl hdl;

    void on_open(WebSocketClient* c, websocketpp::connection_hdl hdl);
    void on_message(WebSocketClient* c, websocketpp::connection_hdl hdl, WebSocketClient::message_ptr msg);
};

#endif // CLIENT_HPP