//
// Created by Kamisato on 2025/4/22.
//

#ifndef PATHRECEIVER_H
#define PATHRECEIVER_H

#include <QObject>
#include <QString>
#include <QDebug>

class PathReceiver final : public QObject {
    Q_OBJECT
public:
    explicit PathReceiver(QObject *parent = nullptr);

    Q_INVOKABLE void setPaths(const QString &inputPath, const QString &outputPath);

    QString getInputPath() const;
    QString getOutputPath() const;

private:
    QString m_inputPath;
    QString m_outputPath;
};

#endif //PATHRECEIVER_H
