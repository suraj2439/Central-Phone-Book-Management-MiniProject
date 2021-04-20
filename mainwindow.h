#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "backend.h"
#include <cstdio>
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

        void update_login_details(std::string id, std::string password);
	
		~MainWindow();

	private slots:

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

        void on_retriveType_currentIndexChanged(int index);

        void on_BtnHistorySubmit_clicked();

        void on_BtnNextHistory_clicked();

        void on_BtnPrevHistory_clicked();


        void on_noType_currentIndexChanged(int index);

        void on_btn_HomeNext_clicked();

        void on_btn_HomePrev_clicked();

        void update_homepage();


        void on_delNumber_textChanged(const QString &arg1);

        void on_delNoCode_textChanged(const QString &arg1);

        void on_btn_delSubmit_clicked();

        void on_main_table_cellClicked(int row, int column);

        void on_infoSearch_textChanged(const QString &arg1);


        void on_btn_getInfoPrev_clicked();

        void on_btn_getInfoNext_clicked();

        void on_getInfo_table_cellClicked(int row, int column);

        void on_searchNo_update_textChanged(const QString &arg1);

        void on_searchCode_update_textChanged(const QString &arg1);

        void on_submit_update_clicked();

        void on_login_submit_clicked();


        void on_pushButton_19_clicked();

        void on_loginUpdate_submit_clicked();

        void on_loginInfo_update_clicked();

        std::string get_login_id();
        std::string get_login_password();

        void on_pushButton_20_clicked();

private:
        int log_intoPage;
        std::string login_id;
        std::string login_password;
        void printHistoryTable();
        void print_homeTable();
        void print_getInfoTable();
		Trie *phonebook;
		Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
