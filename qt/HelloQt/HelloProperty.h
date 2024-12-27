/**
 * @copyright	Copyright (c) Huizhou Desay SV Automotive Co., Ltd.
 * @file 		HelloProperty.h
 * @author 		uidq5675
 * @date		2024/06/07
 * @brief 	    转台控制工具
 * @details
 */

#pragma once

#include <QObject>

class HelloProperty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)

public:

    explicit HelloProperty(QObject* parent = nullptr);
    ~HelloProperty();

    void helloProperty();

    int id() const;
    void setId(int id);
    QString name() const;
    void setName(const QString& name);

signals:
    void idChanged();
    void nameChanged();

private:
    int mId;
    QString mName;

};

