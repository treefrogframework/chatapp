#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <TActionController>
#include "applicationhelper.h"


class T_CONTROLLER_EXPORT ApplicationController : public TActionController
{
    Q_OBJECT
public:
    ApplicationController();
    virtual ~ApplicationController();

public slots:
    void staticInitialize();
    void staticRelease();

protected:
    virtual bool preFilter();
};

#endif // APPLICATIONCONTROLLER_H
