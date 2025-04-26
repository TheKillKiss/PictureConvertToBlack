//
// Created by Kamisato on 2025/4/23.
//

#ifndef TEXTAREALOG_H
#define TEXTAREALOG_H

#include <QObject>
#include <QString>
#include <QTextStream>
#include <QDateTime>


class TextAreaLog : public QObject {
    Q_OBJECT

public:
    explicit TextAreaLog(QObject *parent = nullptr);

signals:
    void logMessage(const QString &message);

public slots:
    void addLog(const QString &message);

    QTextStream &stream();

private:
    QString currentLog;
    QTextStream logStream;
};


#endif //TEXTAREALOG_H
