#ifndef THEMEMANAGER_H
#define THEMEMANAGER_H

#include <QObject>
#include <QQmlFileSelector>
#include<QDebug>
#include <assert.h>

class ThemeManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString theme READ theme WRITE setTheme NOTIFY themeChanged)
private:
    explicit ThemeManager(QQmlEngine* engine,QObject *parent = 0);
    ~ThemeManager();
    static ThemeManager* m_instance  ;
    QString m_theme;
    QQmlEngine* m_engine;

signals:
    void themeChanged();

public slots:
   inline QString theme(){
       return m_theme;
   }

    void setTheme(QString const& theme);

public :
   static ThemeManager* getInstance(QQmlEngine* engine = nullptr);

  QQmlEngine* getEngine(){
      return m_engine;
  }

};




#endif // THEMEMANAGER_H
