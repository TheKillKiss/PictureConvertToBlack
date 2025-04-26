//
// Created by Kamisato on 2025/4/25.
//
#include "AppContext.h"
#include <QQmlContext>

AppContext::AppContext(const QQmlApplicationEngine &engine)
    : pictureConvert(&pathReceiver, &textAreaLog) {
    engine.rootContext()->setContextProperty("textAreaLog", &textAreaLog);
    engine.rootContext()->setContextProperty("pathReceiver", &pathReceiver);
    engine.rootContext()->setContextProperty("pictureConvert", &pictureConvert);

    textAreaLog.addLog("HELLO~");
}
