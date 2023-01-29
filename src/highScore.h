#pragma once

#include <QString>
#include <QDataStream>
#include <QDateTime>

class HighScoreModel;

class HighScore : public QObject
{
	Q_OBJECT

public:

	enum Difficulty
	{
		beginner,
		intermediate,
		expert,
		custom,
	};
	Q_ENUM(Difficulty);

public:

	HighScore() = default;
	HighScore(QString name, Difficulty difficulty, quint32 score, QDateTime date);
	HighScore(const HighScore& other);
	HighScore& operator=(const HighScore& other);

	QString name() const;
	Difficulty difficulty() const;
	quint32 score() const;
	QDateTime date() const;

	void setName(QString name);
	void setDifficultty(Difficulty difficulty);
	void setScore(quint32 score);
	void setDate(QDateTime date);

	bool operator<(const HighScore& rhs) const;
	bool operator==(const HighScore& rhs) const;

	friend HighScoreModel;

private:

	QString	m_name;
	Difficulty	m_difficulty;
	quint32	m_score;
	QDateTime m_date;
};

Q_DECLARE_METATYPE(HighScore);

QDataStream &operator<<(QDataStream &out, const HighScore&);
QDataStream &operator>>(QDataStream &in, HighScore&);