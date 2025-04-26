//
// Created by Kamisato on 2025/4/23.
//

#ifndef PICTURECONVERT_H
#define PICTURECONVERT_H
#include <QObject>
#include <QString>
#include <QDir>
#include <QImage>
#include <QDebug>
#include "TextAreaLog.h"

#include "PathReceiver.h"


class PictureConvert final : public QObject {
    Q_OBJECT

public:
    explicit PictureConvert(PathReceiver *pathReceiver, TextAreaLog *textAreaLog, QObject *parent = nullptr);

    Q_INVOKABLE  void batchProcessImages() const;

private:
    PathReceiver *m_pathReceiver;
    TextAreaLog *m_textAreaLog;

    void processImage(const QString &imagePath) const;
};


#endif //PICTURECONVERT_H
