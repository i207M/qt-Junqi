#ifndef CLIENT_H
#define CLIENT_H

const int P1_PORT = 2077;
const int P2_PORT = 2078;

class Client
{
public:
    Client();
    ~Client();
    bool tryConnect(const char *, int, bool);
    bool showConnectDialog();
    void disconnect();
};

#endif // CLIENT_H
