#ifndef SERVICECONTROLLER_H
#define SERVICECONTROLLER_H


class ServiceController
{
private:
    ServiceController();

public:
    static ServiceController* getInstance();
};

#endif // SERVICECONTROLLER_H
