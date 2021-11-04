//
// Created by 菜鸟大声笑 on 2021/11/4.
//

#include <QString>
#include "student.h"

QString Student::getID() const {
  return ID_;
}

void Student::setID(const QString &value) {
  ID_ = value;
}

QString Student::getName() const {
  return name_;
}

void Student::setName(const QString &value) {
  name_ = value;
}

QString Student::getSex() const {
  return sex_;
}

void Student::setSex(const QString &value) {
  sex_ = value;
}

QString Student::getAge() const {
  return age_;
}

void Student::setAge(const QString &value) {
  age_ = value;
}

QString Student::getChineseSorce() const {
  return chineseSorce_;
}

void Student::setChineseSorce(const QString &value) {
  chineseSorce_ = value;
}

QString Student::getMathSorce() const {
  return mathSorce_;
}

void Student::setMathSorce(const QString &value) {
  mathSorce_ = value;
}

QString Student::getEnglishSorce() const {
  return englishSorce_;
}

void Student::setEnglishSorce(const QString &value) {
  englishSorce_ = value;
}
