//
// Created by 菜鸟大声笑 on 2021/11/4.
//


#include "MainWidget.h"

MainWidget::MainWidget() {
  setWindowIcon(QIcon("./image/logo.ico"));
  setWindowTitle("学生信息管理系统");
  this->resize(1920, 1280);
  QHBoxLayout *HBoxLayout = new QHBoxLayout(this);
  QGroupBox *LeftTableBox = createStuMess();
  QGroupBox *RightTableBox = createMenu();

  HBoxLayout->addWidget(LeftTableBox, 4);
  HBoxLayout->addWidget(RightTableBox, 2);
}

QGroupBox *MainWidget::createStuMess() {
  QGroupBox *box = new QGroupBox("学生信息");
  tableWidget_ = new QTableWidget;
  tableWidget_->setSelectionBehavior(QAbstractItemView::SelectRows);
  tableWidget_->setColumnCount(7);
  tableWidget_->setHorizontalHeaderLabels(QStringList() << "学号" << "姓名" << "年龄" << "性别" << "语文成绩" << "数学成绩" << "英语成绩");
  flushTable();
  QHBoxLayout *AutoHBoxLayout = new QHBoxLayout;
  AutoHBoxLayout->addWidget(tableWidget_);
  box->setLayout(AutoHBoxLayout);

  connect(tableWidget_, &QTableWidget::cellClicked, this, &MainWidget::flushListWidget);
  connect(tableWidget_, &QTableWidget::cellChanged, this, &MainWidget::changeStuMess);
  connect(tableWidget_, &QTableWidget::cellChanged, this, &MainWidget::flushListWidget);
  return box;
}

QGroupBox *MainWidget::createMenu() {
  QGroupBox *box = new QGroupBox("功能面板");
  QVBoxLayout *VBoxLayout = new QVBoxLayout;
  QGridLayout *but = new QGridLayout;

  listWidget_ = new QListWidget;
  AddStuBtn_ = new QPushButton("添加");
  DelStuBtn_ = new QPushButton("删除");
  SaveBtn_ = new QPushButton("保存");
  ExitBtn_ = new QPushButton("退出");
  FindStuEdit_ = new QLineEdit;
  FindStuEdit_->setPlaceholderText("请输入学生姓名...");
  FindStuEdit_->setClearButtonEnabled(true);
  FindStuEdit_->setStyleSheet("QLineEdit{padding: 3, 3, 3, 3;}");
  but->addWidget(AddStuBtn_, 0, 0);
  but->addWidget(DelStuBtn_, 0, 1);
  but->addWidget(FindStuEdit_, 1, 0, 1, 0);
  but->addWidget(SaveBtn_, 2, 0);
  but->addWidget(ExitBtn_, 2, 1);

  VBoxLayout->addWidget(listWidget_, 4);
  VBoxLayout->addLayout(but, 2);

  box->setLayout(VBoxLayout);

  connect(AddStuBtn_, &QPushButton::clicked, this, &MainWidget::addStuBox);
  connect(DelStuBtn_, &QPushButton::clicked, this, &MainWidget::delStuFun);
  connect(FindStuEdit_, &QLineEdit::returnPressed, this, &MainWidget::findStuMess);
  connect(SaveBtn_, &QPushButton::clicked, this, &MainWidget::saveStuMess);
  connect(ExitBtn_, &QPushButton::clicked, this, &MainWidget::close);
  return box;
}

void MainWidget::addStuBox() {
  messBox_ = new EditStudentMessageBox;
  QObject::connect(messBox_, &EditStudentMessageBox::closeBox, this, &MainWidget::flushTable);
  QObject::connect(messBox_, &EditStudentMessageBox::closeBox, listWidget_, &QListWidget::clear);
  messBox_->exec();
}

void MainWidget::flushTable() {
  disconnect(tableWidget_, &QTableWidget::cellChanged, 0, 0);
  QFile file(fileName);
  file.open(QIODevice::ReadOnly);
  QDataStream dataStr(&file);
  QString id, name, age, sex, chineseScore, mathScore, englishScore;
  tableWidget_->setRowCount(0);
  while (!dataStr.atEnd()) {
    tableWidget_->setRowCount(tableWidget_->rowCount() + 1);
    dataStr >> id >> name >> age >> sex >> chineseScore >> mathScore >> englishScore;
    tableWidget_->setItem(tableWidget_->rowCount() - 1, 0, new QTableWidgetItem(id));
    tableWidget_->setItem(tableWidget_->rowCount() - 1, 1, new QTableWidgetItem(name));
    tableWidget_->setItem(tableWidget_->rowCount() - 1, 2, new QTableWidgetItem(age));
    tableWidget_->setItem(tableWidget_->rowCount() - 1, 3, new QTableWidgetItem(sex));
    tableWidget_->setItem(tableWidget_->rowCount() - 1, 4, new QTableWidgetItem(chineseScore));
    tableWidget_->setItem(tableWidget_->rowCount() - 1, 5, new QTableWidgetItem(mathScore));
    tableWidget_->setItem(tableWidget_->rowCount() - 1, 6, new QTableWidgetItem(englishScore));
  }
  file.close();
  connect(tableWidget_, &QTableWidget::cellChanged, this, &MainWidget::changeStuMess);
  connect(tableWidget_, &QTableWidget::cellChanged, this, &MainWidget::flushListWidget);
}

void MainWidget::flushListWidget(int row) {
  if (listWidget_->count() > 0) {
    listWidget_->item(0)->setText("学    号：" + tableWidget_->item(row, 0)->text());
    listWidget_->item(1)->setText("姓    名：" + tableWidget_->item(row, 1)->text());
    listWidget_->item(2)->setText("年    龄：" + tableWidget_->item(row, 2)->text());
    listWidget_->item(3)->setText("性    别：" + tableWidget_->item(row, 3)->text());
    listWidget_->item(4)->setText("语文成绩：" + tableWidget_->item(row, 4)->text());
    listWidget_->item(5)->setText("数学成绩：" + tableWidget_->item(row, 5)->text());
    listWidget_->item(6)->setText("英语成绩：" + tableWidget_->item(row, 6)->text());
  } else {
    listWidget_->addItem("学    号：" + tableWidget_->item(row, 0)->text());
    listWidget_->addItem("姓    名：" + tableWidget_->item(row, 1)->text());
    listWidget_->addItem("年    龄：" + tableWidget_->item(row, 2)->text());
    listWidget_->addItem("性    别：" + tableWidget_->item(row, 3)->text());
    listWidget_->addItem("语文成绩：" + tableWidget_->item(row, 4)->text());
    listWidget_->addItem("数学成绩：" + tableWidget_->item(row, 5)->text());
    listWidget_->addItem("英语成绩：" + tableWidget_->item(row, 6)->text());
  }
}

void MainWidget::delStuFun() {
  QList<QTableWidgetItem *> items = tableWidget_->selectedItems();
  if (items.count() > 0) {
    QMessageBox::StandardButton result = QMessageBox::question(this, "删除", "确定要删除" + items.at(1)->text() + " " +
                                                                           items.at(0)->text() + "?");
    if (result == QMessageBox::Yes) {
      QString id, name, age, sex, chineseScore, mathScore, englishScore;
      QFile file(fileName);
      file.open(QIODevice::ReadOnly);
      QDataStream readDataStr(&file);

      QFile tempFile(tempFileName);
      tempFile.open(QIODevice::WriteOnly);
      QDataStream writeDataStr(&tempFile);

      while (!readDataStr.atEnd()) {
        readDataStr >> id >> name >> age >> sex >> chineseScore >> mathScore >> englishScore;
        if (id != items.at(0)->text()) {
          writeDataStr << id << name << age << sex << chineseScore << mathScore << englishScore;
        }
      }
      tempFile.close();
      file.close();
      file.remove();
      tempFile.rename(tempFileName);
      flushTable();
      listWidget_->clear();
    }
  } else {
    QMessageBox::warning(this, "提示", "请选择要删除的学生");
  }
}

void MainWidget::findStuMess() {
  qint32 count = tableWidget_->rowCount();
  bool findSuccess = false;
  if (count > 0) {
    for (qint32 i = 0; i < count; i++) {
      QString name = tableWidget_->item(i, 1)->text();
      if (name == FindStuEdit_->text()) {
        findSuccess = true;
        tableWidget_->selectRow(i);
        flushListWidget(i);
        break;
      }
    }
    if (!findSuccess) {
      QMessageBox::information(this, "查找失败", "当前表格中没有【" + FindStuEdit_->text() + "】同学");
    }
  }
}

void MainWidget::changeStuMess(int row) {
  QString id, name, age, sex, chineseScore, mathScore, englishScore;
  QString stuName = tableWidget_->item(row, 1)->text();
  QFile file(fileName);
  file.open(QIODevice::ReadOnly);
  QDataStream readDataStr(&file);

  QFile tempFile(tempFileName);
  tempFile.open(QIODevice::WriteOnly);
  QDataStream writeDataStr(&tempFile);

  while (!readDataStr.atEnd()) {
    readDataStr >> id >> name >> age >> sex >> chineseScore >> mathScore >> englishScore;
    if (name != stuName) {
      writeDataStr >> id >> name >> age >> sex >> chineseScore >> mathScore >> englishScore;
    } else {
      for (int i = 0; i < tableWidget_->rowCount(); i++) {
        writeDataStr << tableWidget_->item(row, i)->text();
      }
    }
  }
  tempFile.close();
  file.close();
  file.remove();
  tempFile.rename(fileName);
}

void MainWidget::saveStuMess() {
  QFile file(fileName);
  file.open(QIODevice::WriteOnly);
  QDataStream dataStr(&file);

  for (int i = 0; i < tableWidget_->rowCount(); i++) {
    for (int j = 0; j < tableWidget_->columnCount(); j++) {
      dataStr << tableWidget_->item(i, j)->text();
    }
  }
  file.close();
  QMessageBox::information(this, "保存", "保存成功!");
}
