#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "backend.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public History {
	Q_OBJECT

	public:
		MainWindow(QWidget *parent = nullptr);

		//void init_phonebook(Trie T, History H);
		Trie get_phonebook();

		History get_history();
	
		~MainWindow();

	private slots:

        void on_tableWidget_cellClicked(int row, int column);

        void on_addno_clicked();

        void on_getinfo_clicked();

        void on_update_clicked();

        void on_delno_clicked();

        void on_history_clicked();

        void on_pushButton_15_clicked();

        void on_pushButton_16_clicked();

        void on_pushButton_18_clicked();

        void on_pushButton_17_clicked();

        void on_pushButton_14_clicked();

        void on_addNoSubmit_clicked();

        void on_noType_activated(const QString &arg1);

        void on_retriveType_currentIndexChanged(int index);

        void on_BtnHistorySubmit_clicked();

        void on_BtnNextHistory_clicked();

        void on_BtnPrevHistory_clicked();

private:
        void printHistoryTable();
		Trie *phonebook;
		Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
