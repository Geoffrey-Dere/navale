#ifndef CASEMAP_H
#define CASEMAP_H

#include <QObject>
#include <QHash>
#include <QVariant>

class ListItem: public QObject {
    Q_OBJECT

public:
    ListItem(QObject* parent = 0) : QObject(parent) {}
    virtual ~ListItem() {}
    virtual QString id() const = 0;
    virtual QVariant data(int role) const = 0;
    virtual QHash<int, QByteArray> roleNames() const = 0;
    virtual bool setData(const QVariant & value, int role)=0;

signals:
    void dataChanged();
};

class CaseMap : public ListItem
{
    Q_OBJECT

public:
    enum Roles {
        NumeroRole = Qt::UserRole+1,
        CouleurRole,
        PositionXRole,
        PositionYRole,
    };

public:
    CaseMap(QObject *parent = 0): ListItem(parent) {}
    explicit CaseMap(int name, const QString &couleur, QObject *parent = 0);
    QVariant data(int role) const;
    QHash<int, QByteArray> roleNames() const;
    virtual bool setData(const QVariant & value, int role);

    inline QString id() const { return QString(m_numero); }
    inline int numero() const { return m_numero; }
    inline QString couleur() const { return m_couleur; }

    inline int getX() const {return m_x;}
    inline int getY() const {return m_y;}

    bool setX(int x);
    bool setY(int y);
    bool setCouleur(QString couleur);

private:
    int m_numero;
    QString m_couleur;
    int m_x=0, m_y=0;
};

#endif // CASE_H
