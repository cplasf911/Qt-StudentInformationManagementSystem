//
// Created by 菜鸟大声笑 on 2021/11/4.
//

#ifndef QTSTUDY_STUDENT_H
#define QTSTUDY_STUDENT_H

class Student {
private:
  QString ID_;
  QString name_;
  QString sex_;
  QString age_;
  QString chineseSorce_;
  QString mathSorce_;
  QString englishSorce_;
public:
  QString getID() const;
  void setID(const QString& value);

  QString getName() const;
  void setName(const QString& value);

  QString getSex() const;
  void setSex(const QString& value);

  QString getAge() const;
  void setAge(const QString& value);

  QString getChineseSorce() const;
  void setChineseSorce(const QString& value);

  QString getMathSorce() const;
  void setMathSorce(const QString& value);

  QString getEnglishSorce() const;
  void setEnglishSorce(const QString& value);
};

#endif //QTSTUDY_STUDENT_H
