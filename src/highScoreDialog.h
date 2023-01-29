#pragma once

#include <QDialog>
#include <QTabWidget>

#include "highScoreModel.h" 

class HighScoreDialog : public QDialog
{
public:

	HighScoreDialog(QMap<HighScore::Difficulty, HighScoreModel*> models, QWidget* parent = nullptr);

	void setActiveTab(const QString& difficulty);

private:

	QTabWidget* tabWidget;
};