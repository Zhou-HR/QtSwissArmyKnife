﻿/*
 * Copyright (C) 2018-2019 wuuhii. All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project. The project is a open source project, you can get the source from:
 *     https://github.com/wuuhii/QtSwissArmyKnife
 *     https://gitee.com/wuuhii/QtSwissArmyKnife
 *
 * If you want to know more about the project, please join our QQ group(952218522).
 * In addition, the email address of the project author is wuuhii@outlook.com.
 * Welcome to bother.
 *
 * I write the comment in English, it's not because that I'm good at English,
 * but for "installing B".
 */
#include <QDebug>
#include <QApplication>
#include "SAKSerialportAssistant.hh"
#include "SAKTabPageSerialportAssistant.hh"

SAKSerialportAssistant::SAKSerialportAssistant(const QString name,
                                               const qint32 baudRate,
                                               const QSerialPort::DataBits dataBits,
                                               const QSerialPort::StopBits stopBits,
                                               const QSerialPort::Parity parity, SAKTabPageSerialportAssistant *debugPage,
                                               QObject *parent)
    :QThread (parent)
    ,_name (name)
    ,_baudRate (baudRate)
    ,_dataBits (dataBits)
    ,_stopBits (stopBits)
    ,_parity (parity)
    ,debugPage (debugPage)
{
    moveToThread(this);
}

void SAKSerialportAssistant::run()
{
    serialPort = new QSerialPort(this);
    serialPort->setPortName(_name);
    serialPort->setBaudRate(_baudRate);
    serialPort->setDataBits(_dataBits);
    serialPort->setStopBits(_stopBits);
    serialPort->setParity(_parity);


    connect(serialPort, &QSerialPort::readyRead, this, &SAKSerialportAssistant::readBytes);
    connect(qApp, &QApplication::lastWindowClosed, this, &SAKSerialportAssistant::terminate);

    if (serialPort->open(QSerialPort::ReadWrite)){
#ifdef QT_DEBUG
        qDebug() << serialPort->portName() << serialPort->baudRate() << serialPort->dataBits() << serialPort->stopBits() << serialPort->parity();
#endif
        emit deviceStatuChanged(true);
        exec();
    }else{
        emit deviceStatuChanged(false);
        emit messageChanged(tr("串口打开失败：") + serialPort->errorString(), false);
    }
}

void SAKSerialportAssistant::readBytes()
{    
    serialPort->waitForReadyRead(debugPage->readWriteParameters().waitForReadyReadTime);
    QByteArray data = serialPort->readAll();    
    if (data.isEmpty()){
        return;
    }
    emit bytesRead(data);
}

void SAKSerialportAssistant::writeBytes(QByteArray data)
{    
    qint64 ret = serialPort->write(data);
    serialPort->waitForBytesWritten(debugPage->readWriteParameters().waitForBytesWrittenTime);
    if (ret == -1){
        emit messageChanged(tr("串口发送数据失败：") + serialPort->errorString(), false);
    }else{
        emit bytesWriten(data);
    }
}