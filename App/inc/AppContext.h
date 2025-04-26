//
// Created by Kamisato on 2025/4/25.
//

#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include <QQmlApplicationEngine>

#include "PathReceiver.h"
#include "PictureConvert.h"

class AppContext {
public:
    explicit AppContext(const QQmlApplicationEngine &engine);
private:
    TextAreaLog textAreaLog;
    PathReceiver pathReceiver;
    PictureConvert pictureConvert;
};

#endif //APPCONTEXT_H
