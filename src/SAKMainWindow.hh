﻿/*
 * Copyright 2018-2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project(https://www.qsak.pro). The project is an open source project. You can
 * get the source of the project from: "https://github.com/qsak/QtSwissArmyKnife"
 * or "https://gitee.com/qsak/QtSwissArmyKnife". Also, you can join in the QQ
 * group which number is 952218522 to have a communication.
 */
#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QMetaEnum>
#include <QTabWidget>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QTranslator>

class SAKQRCodeDialog;
class SAKUpdateManager;
class SAKMoreInformation;

namespace Ui {
    class SAKMainWindow;
}
/// @brief 程序主窗口
class SAKMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SAKMainWindow(QWidget *parent = Q_NULLPTR);
    ~SAKMainWindow();
private:
    QTranslator qtTranslator;
    QTranslator qtBaeTranslator;
    QTranslator sakTranslator;

    QMenu *toolsMenu;
    QAction *defaultStyleSheetAction;
    SAKUpdateManager *updateManager;
    SAKMoreInformation *moreInformation;
    SAKQRCodeDialog *qrCodeDialog;
private: 
    void initMenuBar();
    void initFileMenu();
    void initToolMenu();
    void initOptionMenu();
    void initLanguageMenu();
    void initHelpMenu();
    void initLinksMenu();

    void changeStylesheet(QString styleSheetName);
    void changeAppStyle(QString appStyle);

    /// @brief 显示关于软件弹窗
    void about();
    /// @brief 切换软件显示语言
    void installLanguage();
    /// @brief 追加页面
    void appendRemovablePage();
    /// @brief 移除页面
    void removeRemovableDebugPage(int index);
    /// @brief 打开调试页面窗口
    void openDebugPageWidget();
    /// @brief 生成调试页面
    QWidget *debugPageFromType(int type);
private slots:
    /// @brief 显示工具窗口
    void showToolWidget();
private:
    Ui::SAKMainWindow *ui;
    QTabWidget *tabWidget;
};

#endif // MAINWINDOW_H
