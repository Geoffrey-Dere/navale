#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QStringList>
#include <Map/caseMap.h>
#include <QAbstractListModel>
#include <QTime>
#include <QDebug>



class LoggerItem : public ListItem
{
    Q_OBJECT

public:
    enum Roles {
        DateRole = Qt::UserRole+1,
        MessageRole,
        CouleurRole
    };

public:
    explicit LoggerItem(QObject *parent = 0);
    explicit LoggerItem(QString message, QString couleur, QObject *parent = 0);
    QVariant data(int role) const;
    QHash<int, QByteArray> roleNames() const;
    virtual bool setData(const QVariant & value, int role);

    inline QString id() const { return m_date; }
    inline QString message() const { return m_message; }
    inline QString date() const { return m_date; }
    inline QString couleur() const {return m_couleur;}

private:
    QString m_date, m_message, m_couleur;

};



class Logger : public QAbstractListModel
{
    Q_OBJECT
public:

    static Logger* getInstance();
    ~Logger();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    void appendRow(ListItem* item);
    void appendRows(const QList<ListItem *> &items);
    QHash<int, QByteArray> roleNames() const;


    void ajouterMessage(QString message, QString couleur = "black");

    inline void clean(){
        m_list.clear();
    }


signals:

public slots:


protected:
    explicit Logger(QObject *parent = 0);
    static Logger* m_instance  ;

    ListItem* m_prototype;
    QList<ListItem*> m_list;

};

#endif // LOGGER_H

