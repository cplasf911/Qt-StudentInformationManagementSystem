//
// Created by 菜鸟大声笑 on 2021/11/4.
//

#ifndef QTSTUDY_MAINWIDGET_H
#define QTSTUDY_MAINWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QLineEdit>
#include <QTableWidget>
#include <QGroupBox>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include "config.h"
#include "EditStudentMessageBox.h"

class MainWidget : public QWidget {
private:
  Q_OBJECT

  QGroupBox* createStuMess();
  QGroupBox* createMenu();

  QTableWidget* tableWidget_;
  QListWidget* listWidget_;
  QPushButton* AddStuBtn_;
  QPushButton* DelStuBtn_;
  QLineEdit* FindStuEdit_;
  QPushButton* SaveBtn_;
  QPushButton* ExitBtn_;
  EditStudentMessageBox* messBox_;
public:
  MainWidget();
  void addStuBox();
  void flushTable();
  void flushListWidget(int row);
  void delStuFun();
  void findStuMess();
  void changeStuMess(int row);
  void saveStuMess();
};

#endif //QTSTUDY_MAINWIDGET_H
