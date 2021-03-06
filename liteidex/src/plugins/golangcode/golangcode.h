/**************************************************************************
** This file is part of LiteIDE
**
** Copyright (c) 2011-2014 LiteIDE Team. All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** In addition, as a special exception,  that plugins developed for LiteIDE,
** are allowed to remain closed sourced and can be distributed under any license .
** These rights are included in the file LGPL_EXCEPTION.txt in this package.
**
**************************************************************************/
// Module: golangcode.h
// Creator: visualfc <visualfc@gmail.com>

#ifndef GOLANGCODE_H
#define GOLANGCODE_H

#include "liteapi/liteapi.h"
#include "liteeditorapi/liteeditorapi.h"
#include "liteenvapi/liteenvapi.h"
#include "golangastapi/golangastapi.h"

class QProcess;

class GolangCode : public QObject
{
    Q_OBJECT
public:
    explicit GolangCode(LiteApi::IApplication *app, QObject *parent = 0);
    ~GolangCode();
    void setCompleter(LiteApi::ICompleter *completer);
    void resetGocode();
    void cgoComplete();
public slots:
    void currentEditorChanged(LiteApi::IEditor*);
    void currentEnvChanged(LiteApi::IEnv*);
    void prefixChanged(QTextCursor,QString,bool froce);
    void wordCompleted(QString,QString,QString);
    void started();
    void finished(int,QProcess::ExitStatus);
    void broadcast(QString,QString,QString);
    void applyOption(QString);
protected:
    static  int g_gocodeInstCount;
    LiteApi::IApplication *m_liteApp;
    LiteApi::ICompleter   *m_completer;
    QString     m_gobinCmd;
    QString     m_preWord;
    QString     m_prefix;
    QString     m_lastPrefix;
    QFileInfo   m_fileInfo;
    bool        m_breset;
    QProcess   *m_gocodeProcess;
    QProcess   *m_updatePkgProcess;
    QByteArray  m_writeData;
    LiteApi::IEnvManager *m_envManager;
    LiteApi::IGolangAst *m_golangAst;
    QString     m_gocodeCmd;
    bool        m_closeOnExit;
    bool        m_autoUpdatePkg;
};

#endif // GOLANGCODE_H
