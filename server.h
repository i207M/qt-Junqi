#ifndef SERVER_H
#define SERVER_H


class Server
{
public:
    Server();
    ~Server();
    void create();
    bool waitConnection();
    void close();
};

#endif // SERVER_H
