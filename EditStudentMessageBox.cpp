//
// Created by 菜鸟大声笑 on 2021/11/4.
//


#include "EditStudentMessageBox.h"

EditStudentMessageBox::EditStudentMessageBox() {
  setWindowIcon(QIcon("./image/loco.ico"));
  setWindowTitle("添加学生信息");
  QVBoxLayout *VBox = new QVBoxLayout;
  QFormLayout *formLayout = new QFormLayout;
  ID_ = new QLineEdit;
  name_ = new QLineEdit;
  sex_ = new QLineEdit;
  age_ = new QLineEdit;
  chineseScore_ = new QLineEdit;
  mathScore_ = new QLineEdit;
  englishScore_ = new QLineEdit;
  formLayout->addRow("学号：", ID_);
  formLayout->addRow("姓名：", name_);
  formLayout->addRow("年龄：", age_);
  formLayout->addRow("性别：", sex_);
  formLayout->addRow("语文成绩：", chineseScore_);
  formLayout->addRow("数学成绩：", mathScore_);
  formLayout->addRow("英语成绩：", englishScore_);
  formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);

  QHBoxLayout *HBox = new QHBoxLayout;
  submit_ = new QPushButton("提交");
  cancel_ = new QPushButton("取消");
  HBox->addWidget(submit_);
  HBox->addWidget(cancel_);

  VBox->addLayout(formLayout, 4);
  VBox->addLayout(HBox, 2);
  this->setLayout(VBox);

  QObject::connect(submit_, &QPushButton::clicked, this, &EditStudentMessageBox::saveStuMess);
  QObject::connect(cancel_, &QPushButton::clicked, this, &EditStudentMessageBox::close);
}

void EditStudentMessageBox::saveStuMess() {
  if (this->ID_->text() != "" && this->name_->text() != "" && this->age_->text() != "" && this->sex_->text() != "" &&
      this->chineseScore_->text() != "" && this->mathScore_->text() != "" && this->englishScore_->text() != "") {
    Student stu;
    stu.setID(this->ID_->text());
    stu.setName(this->name_->text());
    stu.setAge(this->age_->text());
    stu.setSex(this->sex_->text());
    stu.setChineseSorce(this->chineseScore_->text());
    stu.setMathSorce(this->mathScore_->text());
    stu.setEnglishSorce(this->englishScore_->text());

    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QDataStream dataStr(&file);
    dataStr << stu.getID() << stu.getName() << stu.getAge() << stu.getSex() << stu.getChineseSorce()
            << stu.getMathSorce() << stu.getEnglishSorce();
    file.close();
    this->close();
    emitCloseBox();
  } else {
    QMessageBox::warning(this, "提示", "请将信息填写完整", QMessageBox::Ok);
  }
}

void EditStudentMessageBox::emitCloseBox() {
  emit closeBox();
}