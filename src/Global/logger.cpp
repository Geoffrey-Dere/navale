#include "logger.h"


LoggerItem:: LoggerItem( QObject *parent)
    : ListItem(parent)
{
}

LoggerItem:: LoggerItem(QString message, QString couleur, QObject *parent)
    : m_message(message),m_couleur(couleur), ListItem(parent)
{
    m_date = QTime::currentTime().toString("hh:mm:ss");
}


QHash<int, QByteArray>  LoggerItem::roleNames() const
{
    QHash<int, QByteArray> names;
    names[DateRole] = "date";
    names[MessageRole] = "message";
    names[CouleurRole] = "couleur";
    return names;
}

QVariant  LoggerItem::data(int role) const
{
    switch(role) {
    case DateRole:
        return date();
    case MessageRole:
        return message();
    case CouleurRole:
        return couleur();
    default:
        return QVariant();
    }
}

bool LoggerItem::setData(const QVariant & value, int role){
    Q_UNUSED(value);
    Q_UNUSED(role);

    return false;
}



/********/



Logger* Logger::m_instance = new Logger;


Logger* Logger::getInstance(){

    if(m_instance==nullptr)
        m_instance = new Logger;
    return m_instance;

}

Logger::Logger(QObject *parent) : QAbstractListModel(parent)
{
    m_prototype = new LoggerItem(this);
}


 int Logger::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

QVariant Logger::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_list.size())
        return QVariant();
    return m_list.at(index.row())->data(role);
}


/* ajouter données dans le modèle */
void Logger::appendRow(ListItem *item)
{
    appendRows(QList<ListItem*>() << item);
}

void Logger::appendRows(const QList<ListItem *> &items)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount()+items.size()-1);
    foreach(ListItem *item, items) {
        m_list.append(item);
    }
    endInsertRows();
}


QHash<int, QByteArray> Logger::roleNames() const{
    return m_prototype->roleNames();
}

void Logger::ajouterMessage(QString message, QString couleur){

    appendRow(new LoggerItem(message,couleur,this));
}


Logger::~Logger(){
    qDeleteAll(m_list);
    m_list.clear();
    delete(m_prototype);
}

