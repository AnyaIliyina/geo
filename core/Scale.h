#pragma once

#include <QObject>
#include <QString>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QUrl>
#include <QDateTime>

/*!
*  \brief Представляет сущность Масштаб
		(таблица scales)
*  \author Козырева О.
*  \date 10 марта 2016
*/

class Scale: public QObject {
	Q_OBJECT
private:
	int m_scale_id;
	QString m_description;

public:
	QString description();
	
	/*!
	Конструирует объект класса Scale из параметров
	*/
	Scale(QString description);
	
	/*!
	Конструирует объект класса Scale из данных в базе
	\param int id - id сайта в базе
	*/
	Scale(int id);
	
	~Scale();
	
	int scale_id();
	
	/*!
	Записывает информацию о масштабе в базу данных.
	\return true - если запись в БД успешно добавлена
	*/
	bool insertIntoDatabase();
	
	/*!
	Создает таблицу "scales" в базе данных.
	\return true - если таблица успешно создана
	*/
	static bool createTable();
	
	
	/*!
	Заполняет таблицу "scales" в БД начальными значениями.
	\return true - если таблица успешно заполнена
	*/
	static bool completeTable();
	static QString coded(QByteArray encodedStr);

	static QStringList getDescription();

	/*!
	Записывает в базу данных список масштабов
	\param QStringList descriptions - список названий масштабов
	\return true - масштабы записаны в БД
	\return false - возникли ошибки*/
	static bool insert(QStringList descriptions);
};

