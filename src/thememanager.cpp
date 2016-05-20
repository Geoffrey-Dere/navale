

#include "thememanager.h"

ThemeManager *ThemeManager::m_instance = nullptr;

ThemeManager::ThemeManager(QQmlEngine* engine, QObject *parent)
    : QObject(parent), m_engine(engine)
{

}

ThemeManager::~ThemeManager(){
    if(m_instance!=nullptr)
        delete(m_instance);
}

ThemeManager* ThemeManager::getInstance(QQmlEngine* engine){
    if(m_instance==nullptr)
        m_instance= new ThemeManager(engine);

    return m_instance;
}


void ThemeManager::setTheme(const QString& theme){

    assert(m_engine != nullptr);

    if(m_theme == theme)
        return ;

    m_theme = theme ;
    QStringList xsel ;
    if(m_theme=="sombre"){
        xsel << m_theme;
    }

    QQmlFileSelector::get(m_engine)->setExtraSelectors(xsel);

    emit themeChanged();

}
