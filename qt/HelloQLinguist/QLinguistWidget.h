/**
 * @copyright	Copyright (c) Huizhou Desay SV Automotive Co., Ltd.
 * @file 		QLinguistWidget.h
 * @author 		uidq5675
 * @date		2024/09/13
 * @brief 		数据列表
 * @details     多语言示例
 */


#pragma once

#include <QWidget>

namespace Ui {
    class QLinguistWidget;
}

class QLinguistWidget : public QWidget
{
    Q_OBJECT

public:

    explicit QLinguistWidget(QWidget* parent = nullptr);
    ~QLinguistWidget();

protected:
    void changeEvent(QEvent* event);

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::QLinguistWidget* ui;

};


