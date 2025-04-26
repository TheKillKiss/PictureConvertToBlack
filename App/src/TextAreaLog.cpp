//
// Created by Kamisato on 2025/4/23.
//

#include "../inc/TextAreaLog.h"

TextAreaLog::TextAreaLog(QObject *parent) : QObject(parent) {
}

void TextAreaLog::addLog(const QString &message) {
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
    QString log = "[" + time + "] " + message;
    emit logMessage(log);
}

QTextStream & TextAreaLog::stream() {
    return logStream;
}

