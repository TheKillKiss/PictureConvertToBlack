//
// Created by Kamisato on 2025/4/23.
//

#include <QFileInfoList>
#include <QImageReader>

#include "PictureConvert.h"
#include "TextAreaLog.h"

PictureConvert::PictureConvert(PathReceiver *pathReceiver, TextAreaLog *textAreaLog, QObject *parent)
    : QObject(parent), m_pathReceiver(pathReceiver), m_textAreaLog(textAreaLog) {
}

void PictureConvert::batchProcessImages() const {
    QString inputPath = m_pathReceiver->getInputPath();
    QString outputPath = m_pathReceiver->getOutputPath();

    QDir dir(inputPath);

    dir.setNameFilters({"*.png", "*.jpg", "*.jpeg", "*.bmp", "*.gif"});
    dir.setFilter(QDir::Files);

    QFileInfoList files = dir.entryInfoList();
    for (const QFileInfo &fileInfo: files) {
        QString imagePath = fileInfo.absoluteFilePath();

        processImage(imagePath);
    }
}

void PictureConvert::processImage(const QString &imagePath) const {
    QImage image(imagePath);
    if (image.isNull()) {
        qWarning() << "Failed to load image:" << imagePath;
        m_textAreaLog->addLog("图片加载失败:" + imagePath);
        return;
    }

    QImage grayImage = image.convertToFormat(QImage::Format_Grayscale8);

    QString outputPath = m_pathReceiver->getOutputPath();
    QString outputFileName = QFileInfo(imagePath).fileName();
    QString outputFilePath = outputPath + "/" + outputFileName;

    if (grayImage.save(outputFilePath)) {
        qDebug() << "图片转换成功:" << outputFilePath;
        m_textAreaLog->addLog("图片转换成功:\n" + outputFilePath + "\n");
    } else {
        qWarning() << "图片转换失败:" << outputFilePath;
        m_textAreaLog->addLog("图片转换失败:" + outputFilePath);
    }
}
