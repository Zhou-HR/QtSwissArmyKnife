﻿/*
 * Copyright 2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project(https://www.qsak.pro). The project is an open source project. You can
 * get the source of the project from: "https://github.com/qsak/QtSwissArmyKnife"
 * or "https://gitee.com/qsak/QtSwissArmyKnife". Also, you can join in the QQ
 * group which number is 952218522 to have a communication.
 */
#ifndef SAKSINGLETONCONTROLLER_HH
#define SAKSINGLETONCONTROLLER_HH

#include <QObject>

/// @brief 单实例控制类
class SAKSingletonController:public QObject
{
    Q_OBJECT
public:
    SAKSingletonController(QObject *parent = Q_NULLPTR);
    ~SAKSingletonController();
};

#endif
