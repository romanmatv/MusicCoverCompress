#include <QCoreApplication>
#include <QFile>
#include <QImage>
#include <QFileInfo>
#include <QString>
#include <QSettings>

//Thanks to "Rainmeter Project Developers"
#include "Cover.h"
#define MAX_FILENAME_SIZE 4096

QImage scale(QImage img){
    return img.scaled(400, 400, Qt::AspectRatioMode::KeepAspectRatio, Qt::SmoothTransformation);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QStringList files = a.arguments();

    QSettings settings("settings.ini", QSettings::Format::IniFormat);

    files.takeFirst();

    //files << "G:/Dance With The Dead [FLAC]/2014 - Into The Abyss [EP]/01. The Descent (Intro).flac";

    int MAX_IMG_SIZE = settings.value("IMG_SIZE", 400).toInt();
    int IMG_SIZE_OFFSET = settings.value("IMG_SIZE_OFFSET", 100).toInt();
    int IMG_QUALAITY = settings.value("IMG_QUALAITY", 90).toInt();
    QString IMG_NAME = settings.value("IMG_NAME", "cover").toString();

    CCover cover;

    for (auto iter = files.begin(); iter != files.end(); ++iter){
        QImage img;
        QFileInfo info(*iter);

        wchar_t filenameW[MAX_FILENAME_SIZE];
        int length = info.filePath().replace("/","\\").left(MAX_FILENAME_SIZE - 1).toWCharArray(filenameW);
        filenameW[length] = '\0';

        TagLib::FileRef file(filenameW);

        if (file.isNull()){
            img.load(*iter);
        }else{
            if (!cover.GetEmbedded(file, img)){
                img.load(*iter);
            }
        }

        qDebug() << img;

        if (!img.isNull()){
            if (img.width()>MAX_IMG_SIZE+IMG_SIZE_OFFSET || img.height()>MAX_IMG_SIZE+IMG_SIZE_OFFSET){
                img = img.scaled(MAX_IMG_SIZE, MAX_IMG_SIZE, Qt::AspectRatioMode::KeepAspectRatio, Qt::SmoothTransformation);
            }
            qDebug() << "saved:" << img.save(info.path()+"/"+IMG_NAME+".jpg", "JPG", IMG_QUALAITY);
        }
    }

    return 0;

    //return a.exec();
}
