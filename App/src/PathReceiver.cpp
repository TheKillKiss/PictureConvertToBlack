//
// Created by Kamisato on 2025/4/22.
//
#include "PathReceiver.h"

PathReceiver::PathReceiver(QObject *parent) : QObject(parent) {
}

void PathReceiver::setPaths(const QString &inputPath, const QString &outputPath) {
    if (inputPath.startsWith("file:///")) {
        m_inputPath = inputPath.mid(8);
    } else {
        m_inputPath = inputPath;
    }

    if (outputPath.startsWith("file:///")) {
        m_outputPath = outputPath.mid(8);
    } else {
        m_outputPath = outputPath;
    }

    qDebug() << "接收到的输入路径:" << m_inputPath;
    qDebug() << "接收到的输出路径:" << m_outputPath;
}

QString PathReceiver::getInputPath() const {
    return m_inputPath;
}

QString PathReceiver::getOutputPath() const {
    return m_outputPath;
}
