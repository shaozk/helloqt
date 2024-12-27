#pragma once

#include <QString>
#include <QSettings>
#include <QFile>
#include <QSharedPointer>

class ISetting
{
public:
	static const QString sConfigName;
	static const QSettings::Format sConfigFormat;

	explicit ISetting(const QString& name, const QString& confgiName = "Config.ini");
	virtual ~ISetting() {};

	ISetting() = delete;
	//ISetting(const ISetting& setting) = delete;
	//ISetting(ISetting&& setting) = delete;
	//ISetting& operator=(const ISetting& setting) = delete;
	//ISetting& operator=(ISetting&& setting) = delete;

	virtual void save() = 0;
	virtual void clean() = 0;

	inline void reload();
	inline QString name() const;
	inline void setName(const QString& name);

protected:
	virtual void load() = 0;
	
	QSharedPointer<QSettings> mSettings;
	QString mName;
};


