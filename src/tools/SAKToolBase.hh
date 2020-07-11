﻿/*
 * Copyright 2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project(https://www.qsak.pro). The project is an open source project. You can
 * get the source of the project from: "https://github.com/qsak/QtSwissArmyKnife"
 * or "https://gitee.com/qsak/QtSwissArmyKnife". Also, you can join in the QQ
 * group which number is 952218522 to have a communication.
 */
#ifndef SAKTOOLBASE
#define SAKTOOLBASE

#include <QWidget>

/// @brief 瑞士军刀实用工具基类
class SAKToolBase : public QWidget
{
    Q_OBJECT
public:
    SAKToolBase(QWidget *parent = Q_NULLPTR);
    ~SAKToolBase();
};

#endif
