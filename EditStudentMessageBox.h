//
// Created by 菜鸟大声笑 on 2021/11/4.
//

#ifndef QTSTUDY_EDITSTUDENTMESSAGEBOX_H
#define QTSTUDY_EDITSTUDENTMESSAGEBOX_H

#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QFile>
#include "config.h"
#include "student.h"

class EditStudentMessageBox : public QDialog {
private:
  Q_OBJECT

  QLineEdit* ID_;
  QLineEdit* name_;
  QLineEdit* sex_;
  QLineEdit* age_;
  QLineEdit* chineseScore_;
  QLineEdit* mathScore_;
  QLineEdit* englishScore_;
  QPushButton* submit_;
  QPushButton* cancel_;

signals:
  void closeBox();

public:
  EditStudentMessageBox();

  void saveStuMess();
  void emitCloseBox();
};


#endif //QTSTUDY_EDITSTUDENTMESSAGEBOX_H
