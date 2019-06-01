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
#ifndef QTAPPSTYLEAPI_HH
#define QTAPPSTYLEAPI_HH

#include <QList>
#include <QObject>
#include <QAction>

class QtAppStyleApi:public QObject
{
    Q_OBJECT
public:
    /**
     * @brief instance  -- 实例化接口，该类必须通过该接口来实例化
     * @return          -- 实例指针（对象指针）
     */
    static QtAppStyleApi *instance();

    /**
     * @brief actions   -- 获取用于软件风格的action列表
     * @return          -- action列表
     */
    QList<QAction *> actions();
signals:
    /// 软件风格发生改变时发射该信号
    void appStyleChanged(QString appStyleName);
private:
    static QtAppStyleApi *_this;
    QList<QAction *> appStyleActions;
private:
    QtAppStyleApi(QObject *parent = Q_NULLPTR);
    void changeAppStyle();
};

#endif
