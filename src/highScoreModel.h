#pragma once

#include <QAbstractItemModel>
#include <QDataStream>
#include <QVector>

#include "highScore.h"

class HighScoreModel : public QAbstractItemModel
{
public:

	enum Column
	{
		Name	= 0,
		Score	= 1,
		Date	= 2,
	};
	Q_ENUM(Column);

public:

	HighScoreModel() = default;
	HighScoreModel(HighScore::Difficulty difficulty, QObject* parent = nullptr);
	HighScoreModel(const HighScoreModel& other);
	HighScoreModel& operator=(const HighScoreModel& other);

	void addHighScore(HighScore score);
	HighScore::Difficulty difficulty() const;
	void setDifficulty(HighScore::Difficulty difficulty);

	virtual QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	virtual QModelIndex parent(const QModelIndex &child) const override;
	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	virtual Qt::ItemFlags flags(const QModelIndex& index) const override;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

	const QVector<HighScore>& highScores() const;
	void setHighScores(QVector<HighScore> scores);
	bool isHighScore(int time) const;

private:

	HighScore::Difficulty m_difficulty;
	QVector<HighScore> m_highScores;
};

Q_DECLARE_METATYPE(HighScoreModel);

QDataStream &operator<<(QDataStream &out, const HighScoreModel&);
QDataStream &operator>>(QDataStream &in, HighScoreModel&);