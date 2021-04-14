/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *MainPage;
    QTextBrowser *textBrowser_2;
    QPushButton *delno;
    QPushButton *pushButton_6;
    QLabel *label_6;
    QPushButton *update;
    QLabel *label_4;
    QTextBrowser *textBrowser_4;
    QLabel *label_5;
    QLabel *label;
    QTableView *tableView;
    QTableWidget *main_table;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *getinfo;
    QTextBrowser *textBrowser;
    QPushButton *addno;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser_3;
    QPushButton *history;
    QLabel *label_img;
    QWidget *PageDelNo;
    QLabel *label_32;
    QTableView *tableView_4;
    QPushButton *pushButton_10;
    QLineEdit *lineEdit_4;
    QLabel *label_31;
    QLineEdit *lineEdit_3;
    QTextBrowser *textBrowser_10;
    QLabel *label_30;
    QLabel *label_33;
    QPushButton *pushButton_15;
    QWidget *PageAddNo;
    QLabel *label_7;
    QComboBox *noType;
    QTextEdit *code;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_code;
    QLabel *label_10;
    QLabel *label_12;
    QPushButton *addNoSubmit;
    QPushButton *pushButton_16;
    QTextEdit *textEdit_10;
    QLabel *label_37;
    QWidget *PageGetInfo;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;
    QTableView *tableView_2;
    QTextBrowser *textBrowser_5;
    QLabel *label_15;
    QTextBrowser *textBrowser_6;
    QLabel *label_16;
    QTextBrowser *textBrowser_7;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QTextBrowser *textBrowser_8;
    QPushButton *pushButton_18;
    QWidget *PageUpdate;
    QLabel *label_20;
    QTableView *tableView_3;
    QLabel *label_21;
    QLabel *label_22;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_7;
    QComboBox *comboBox_2;
    QPushButton *pushButton_9;
    QLabel *label_23;
    QLabel *label_24;
    QTextEdit *textEdit_8;
    QLabel *label_25;
    QLabel *label_26;
    QLineEdit *lineEdit_2;
    QTextBrowser *textBrowser_9;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QTextEdit *textEdit_9;
    QPushButton *pushButton_17;
    QWidget *PageHistory;
    QLabel *label_34;
    QTableWidget *historyTable;
    QPushButton *BtnPrevHistory;
    QPushButton *BtnNextHistory;
    QComboBox *retriveType;
    QLabel *label_35;
    QLineEdit *lowerTime;
    QLineEdit *upperTimeOrN;
    QLabel *labelTime;
    QLabel *label_N;
    QPushButton *BtnHistorySubmit;
    QPushButton *pushButton_14;
    QLabel *label_pageNo;
    QLabel *label_9;
    QLabel *label_36;
    QLabel *label_totalEntries;
    QTextBrowser *msg;
    QLabel *label_38;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(799, 592);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(20, 20, 781, 571));
        MainPage = new QWidget();
        MainPage->setObjectName(QString::fromUtf8("MainPage"));
        textBrowser_2 = new QTextBrowser(MainPage);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(310, 220, 141, 31));
        delno = new QPushButton(MainPage);
        delno->setObjectName(QString::fromUtf8("delno"));
        delno->setGeometry(QRect(60, 370, 121, 31));
        pushButton_6 = new QPushButton(MainPage);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(590, 430, 89, 25));
        label_6 = new QLabel(MainPage);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(230, 310, 71, 17));
        update = new QPushButton(MainPage);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(60, 320, 121, 31));
        label_4 = new QLabel(MainPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 270, 67, 17));
        textBrowser_4 = new QTextBrowser(MainPage);
        textBrowser_4->setObjectName(QString::fromUtf8("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(310, 340, 141, 31));
        label_5 = new QLabel(MainPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(230, 350, 67, 17));
        label = new QLabel(MainPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 190, 67, 17));
        tableView = new QTableView(MainPage);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(210, 170, 271, 291));
        main_table = new QTableWidget(MainPage);
        if (main_table->columnCount() < 2)
            main_table->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        main_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        main_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (main_table->rowCount() < 8)
            main_table->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        main_table->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        main_table->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        main_table->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        main_table->setVerticalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        main_table->setVerticalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        main_table->setVerticalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        main_table->setVerticalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        main_table->setVerticalHeaderItem(7, __qtablewidgetitem9);
        main_table->setObjectName(QString::fromUtf8("main_table"));
        main_table->setGeometry(QRect(480, 170, 211, 291));
        label_2 = new QLabel(MainPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 190, 91, 17));
        label_3 = new QLabel(MainPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 230, 81, 17));
        getinfo = new QPushButton(MainPage);
        getinfo->setObjectName(QString::fromUtf8("getinfo"));
        getinfo->setGeometry(QRect(60, 270, 121, 31));
        textBrowser = new QTextBrowser(MainPage);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(310, 260, 141, 31));
        addno = new QPushButton(MainPage);
        addno->setObjectName(QString::fromUtf8("addno"));
        addno->setGeometry(QRect(60, 220, 121, 31));
        pushButton_5 = new QPushButton(MainPage);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(490, 430, 89, 25));
        textBrowser_3 = new QTextBrowser(MainPage);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(310, 300, 141, 31));
        history = new QPushButton(MainPage);
        history->setObjectName(QString::fromUtf8("history"));
        history->setGeometry(QRect(60, 420, 121, 31));
        label_img = new QLabel(MainPage);
        label_img->setObjectName(QString::fromUtf8("label_img"));
        label_img->setGeometry(QRect(310, 10, 141, 121));
        stackedWidget->addWidget(MainPage);
        main_table->raise();
        delno->raise();
        addno->raise();
        update->raise();
        pushButton_5->raise();
        label->raise();
        tableView->raise();
        pushButton_6->raise();
        label_2->raise();
        getinfo->raise();
        label_3->raise();
        textBrowser_3->raise();
        label_4->raise();
        label_6->raise();
        label_5->raise();
        textBrowser_2->raise();
        textBrowser_4->raise();
        textBrowser->raise();
        history->raise();
        label_img->raise();
        PageDelNo = new QWidget();
        PageDelNo->setObjectName(QString::fromUtf8("PageDelNo"));
        label_32 = new QLabel(PageDelNo);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(310, 70, 211, 41));
        QFont font;
        font.setPointSize(20);
        label_32->setFont(font);
        label_32->setAlignment(Qt::AlignCenter);
        tableView_4 = new QTableView(PageDelNo);
        tableView_4->setObjectName(QString::fromUtf8("tableView_4"));
        tableView_4->setGeometry(QRect(190, 130, 461, 321));
        pushButton_10 = new QPushButton(PageDelNo);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(370, 360, 89, 25));
        lineEdit_4 = new QLineEdit(PageDelNo);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(330, 290, 171, 31));
        label_31 = new QLabel(PageDelNo);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(500, 180, 67, 17));
        lineEdit_3 = new QLineEdit(PageDelNo);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(250, 210, 181, 31));
        textBrowser_10 = new QTextBrowser(PageDelNo);
        textBrowser_10->setObjectName(QString::fromUtf8("textBrowser_10"));
        textBrowser_10->setGeometry(QRect(470, 210, 131, 31));
        label_30 = new QLabel(PageDelNo);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(250, 180, 191, 21));
        QFont font1;
        font1.setPointSize(11);
        label_30->setFont(font1);
        label_33 = new QLabel(PageDelNo);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(350, 270, 151, 21));
        label_33->setFont(font1);
        pushButton_15 = new QPushButton(PageDelNo);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(330, 500, 141, 25));
        stackedWidget->addWidget(PageDelNo);
        PageAddNo = new QWidget();
        PageAddNo->setObjectName(QString::fromUtf8("PageAddNo"));
        label_7 = new QLabel(PageAddNo);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(310, 70, 211, 41));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        noType = new QComboBox(PageAddNo);
        noType->addItem(QString());
        noType->addItem(QString());
        noType->setObjectName(QString::fromUtf8("noType"));
        noType->setGeometry(QRect(430, 160, 151, 31));
        code = new QTextEdit(PageAddNo);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(430, 200, 151, 31));
        textEdit_2 = new QTextEdit(PageAddNo);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(430, 240, 151, 31));
        textEdit_3 = new QTextEdit(PageAddNo);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));
        textEdit_3->setGeometry(QRect(430, 280, 151, 31));
        textEdit_4 = new QTextEdit(PageAddNo);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));
        textEdit_4->setGeometry(QRect(430, 360, 151, 31));
        label_11 = new QLabel(PageAddNo);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(350, 290, 51, 17));
        label_8 = new QLabel(PageAddNo);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 160, 101, 31));
        label_code = new QLabel(PageAddNo);
        label_code->setObjectName(QString::fromUtf8("label_code"));
        label_code->setGeometry(QRect(350, 210, 51, 17));
        label_10 = new QLabel(PageAddNo);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(340, 330, 71, 17));
        label_12 = new QLabel(PageAddNo);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(350, 370, 67, 17));
        addNoSubmit = new QPushButton(PageAddNo);
        addNoSubmit->setObjectName(QString::fromUtf8("addNoSubmit"));
        addNoSubmit->setGeometry(QRect(460, 400, 89, 25));
        pushButton_16 = new QPushButton(PageAddNo);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(350, 470, 141, 25));
        textEdit_10 = new QTextEdit(PageAddNo);
        textEdit_10->setObjectName(QString::fromUtf8("textEdit_10"));
        textEdit_10->setGeometry(QRect(430, 320, 151, 31));
        label_37 = new QLabel(PageAddNo);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(310, 250, 111, 20));
        stackedWidget->addWidget(PageAddNo);
        PageGetInfo = new QWidget();
        PageGetInfo->setObjectName(QString::fromUtf8("PageGetInfo"));
        label_13 = new QLabel(PageGetInfo);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(300, 20, 241, 91));
        QFont font2;
        font2.setPointSize(17);
        label_13->setFont(font2);
        label_14 = new QLabel(PageGetInfo);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(320, 110, 141, 21));
        QFont font3;
        font3.setPointSize(12);
        label_14->setFont(font3);
        lineEdit = new QLineEdit(PageGetInfo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(260, 140, 261, 31));
        tableWidget = new QTableWidget(PageGetInfo);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        if (tableWidget->rowCount() < 10)
            tableWidget->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem20);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(480, 190, 161, 291));
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(150);
        tableWidget->verticalHeader()->setDefaultSectionSize(26);
        tableView_2 = new QTableView(PageGetInfo);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(190, 190, 291, 291));
        textBrowser_5 = new QTextBrowser(PageGetInfo);
        textBrowser_5->setObjectName(QString::fromUtf8("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(310, 260, 141, 31));
        label_15 = new QLabel(PageGetInfo);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(230, 310, 67, 17));
        textBrowser_6 = new QTextBrowser(PageGetInfo);
        textBrowser_6->setObjectName(QString::fromUtf8("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(310, 380, 141, 31));
        label_16 = new QLabel(PageGetInfo);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(230, 350, 71, 17));
        textBrowser_7 = new QTextBrowser(PageGetInfo);
        textBrowser_7->setObjectName(QString::fromUtf8("textBrowser_7"));
        textBrowser_7->setGeometry(QRect(310, 300, 141, 31));
        label_17 = new QLabel(PageGetInfo);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(230, 390, 67, 17));
        label_18 = new QLabel(PageGetInfo);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(300, 230, 91, 17));
        label_19 = new QLabel(PageGetInfo);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(230, 270, 81, 17));
        textBrowser_8 = new QTextBrowser(PageGetInfo);
        textBrowser_8->setObjectName(QString::fromUtf8("textBrowser_8"));
        textBrowser_8->setGeometry(QRect(310, 340, 141, 31));
        pushButton_18 = new QPushButton(PageGetInfo);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));
        pushButton_18->setGeometry(QRect(330, 500, 141, 25));
        stackedWidget->addWidget(PageGetInfo);
        PageUpdate = new QWidget();
        PageUpdate->setObjectName(QString::fromUtf8("PageUpdate"));
        label_20 = new QLabel(PageUpdate);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(290, 20, 211, 41));
        label_20->setFont(font);
        label_20->setAlignment(Qt::AlignCenter);
        tableView_3 = new QTableView(PageUpdate);
        tableView_3->setObjectName(QString::fromUtf8("tableView_3"));
        tableView_3->setGeometry(QRect(160, 150, 451, 351));
        label_21 = new QLabel(PageUpdate);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(250, 290, 67, 17));
        label_22 = new QLabel(PageUpdate);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(260, 410, 67, 17));
        textEdit_5 = new QTextEdit(PageUpdate);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));
        textEdit_5->setGeometry(QRect(360, 240, 151, 31));
        textEdit_6 = new QTextEdit(PageUpdate);
        textEdit_6->setObjectName(QString::fromUtf8("textEdit_6"));
        textEdit_6->setGeometry(QRect(360, 280, 151, 31));
        textEdit_7 = new QTextEdit(PageUpdate);
        textEdit_7->setObjectName(QString::fromUtf8("textEdit_7"));
        textEdit_7->setGeometry(QRect(360, 320, 151, 31));
        comboBox_2 = new QComboBox(PageUpdate);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(360, 200, 151, 31));
        pushButton_9 = new QPushButton(PageUpdate);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(390, 450, 89, 25));
        label_23 = new QLabel(PageUpdate);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(260, 250, 67, 17));
        label_24 = new QLabel(PageUpdate);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(260, 330, 67, 17));
        textEdit_8 = new QTextEdit(PageUpdate);
        textEdit_8->setObjectName(QString::fromUtf8("textEdit_8"));
        textEdit_8->setGeometry(QRect(360, 400, 151, 31));
        label_25 = new QLabel(PageUpdate);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(240, 200, 121, 31));
        label_26 = new QLabel(PageUpdate);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(240, 80, 141, 21));
        label_26->setFont(font3);
        lineEdit_2 = new QLineEdit(PageUpdate);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(210, 100, 211, 31));
        textBrowser_9 = new QTextBrowser(PageUpdate);
        textBrowser_9->setObjectName(QString::fromUtf8("textBrowser_9"));
        textBrowser_9->setGeometry(QRect(450, 100, 111, 31));
        label_27 = new QLabel(PageUpdate);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(480, 80, 67, 17));
        label_28 = new QLabel(PageUpdate);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(260, 160, 241, 20));
        label_29 = new QLabel(PageUpdate);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(250, 370, 81, 17));
        textEdit_9 = new QTextEdit(PageUpdate);
        textEdit_9->setObjectName(QString::fromUtf8("textEdit_9"));
        textEdit_9->setGeometry(QRect(360, 360, 151, 31));
        pushButton_17 = new QPushButton(PageUpdate);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));
        pushButton_17->setGeometry(QRect(300, 510, 141, 25));
        stackedWidget->addWidget(PageUpdate);
        PageHistory = new QWidget();
        PageHistory->setObjectName(QString::fromUtf8("PageHistory"));
        label_34 = new QLabel(PageHistory);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(260, 20, 211, 41));
        label_34->setFont(font);
        label_34->setAlignment(Qt::AlignCenter);
        historyTable = new QTableWidget(PageHistory);
        if (historyTable->columnCount() < 3)
            historyTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        historyTable->setHorizontalHeaderItem(0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        historyTable->setHorizontalHeaderItem(1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        historyTable->setHorizontalHeaderItem(2, __qtablewidgetitem23);
        if (historyTable->rowCount() < 10)
            historyTable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(5, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(6, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(7, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(8, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        historyTable->setVerticalHeaderItem(9, __qtablewidgetitem33);
        historyTable->setObjectName(QString::fromUtf8("historyTable"));
        historyTable->setGeometry(QRect(340, 100, 341, 371));
        historyTable->horizontalHeader()->setMinimumSectionSize(66);
        historyTable->horizontalHeader()->setDefaultSectionSize(112);
        historyTable->verticalHeader()->setDefaultSectionSize(30);
        BtnPrevHistory = new QPushButton(PageHistory);
        BtnPrevHistory->setObjectName(QString::fromUtf8("BtnPrevHistory"));
        BtnPrevHistory->setGeometry(QRect(350, 430, 89, 25));
        BtnNextHistory = new QPushButton(PageHistory);
        BtnNextHistory->setObjectName(QString::fromUtf8("BtnNextHistory"));
        BtnNextHistory->setGeometry(QRect(580, 430, 89, 25));
        retriveType = new QComboBox(PageHistory);
        retriveType->addItem(QString());
        retriveType->addItem(QString());
        retriveType->addItem(QString());
        retriveType->setObjectName(QString::fromUtf8("retriveType"));
        retriveType->setGeometry(QRect(190, 144, 131, 31));
        label_35 = new QLabel(PageHistory);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(60, 150, 101, 17));
        lowerTime = new QLineEdit(PageHistory);
        lowerTime->setObjectName(QString::fromUtf8("lowerTime"));
        lowerTime->setGeometry(QRect(190, 190, 131, 31));
        upperTimeOrN = new QLineEdit(PageHistory);
        upperTimeOrN->setObjectName(QString::fromUtf8("upperTimeOrN"));
        upperTimeOrN->setGeometry(QRect(190, 240, 131, 31));
        labelTime = new QLabel(PageHistory);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        labelTime->setGeometry(QRect(60, 200, 121, 20));
        label_N = new QLabel(PageHistory);
        label_N->setObjectName(QString::fromUtf8("label_N"));
        label_N->setGeometry(QRect(60, 250, 131, 17));
        BtnHistorySubmit = new QPushButton(PageHistory);
        BtnHistorySubmit->setObjectName(QString::fromUtf8("BtnHistorySubmit"));
        BtnHistorySubmit->setGeometry(QRect(140, 300, 89, 25));
        pushButton_14 = new QPushButton(PageHistory);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(280, 510, 141, 25));
        label_pageNo = new QLabel(PageHistory);
        label_pageNo->setObjectName(QString::fromUtf8("label_pageNo"));
        label_pageNo->setGeometry(QRect(490, 450, 41, 16));
        label_pageNo->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(PageHistory);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(480, 430, 61, 21));
        label_36 = new QLabel(PageHistory);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(540, 470, 91, 21));
        label_totalEntries = new QLabel(PageHistory);
        label_totalEntries->setObjectName(QString::fromUtf8("label_totalEntries"));
        label_totalEntries->setGeometry(QRect(640, 470, 41, 21));
        stackedWidget->addWidget(PageHistory);
        msg = new QTextBrowser(centralwidget);
        msg->setObjectName(QString::fromUtf8("msg"));
        msg->setGeometry(QRect(540, 0, 251, 31));
        label_38 = new QLabel(centralwidget);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(470, 0, 67, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 799, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        delno->setText(QApplication::translate("MainWindow", "Delete Number", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Next", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Aadhar No", nullptr));
        update->setText(QApplication::translate("MainWindow", "Update", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Address", nullptr));
        label->setText(QApplication::translate("MainWindow", "MENU", nullptr));
        QTableWidgetItem *___qtablewidgetitem = main_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Contact No", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = main_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Information", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Contact No", nullptr));
        getinfo->setText(QApplication::translate("MainWindow", "Get Info", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        addno->setText(QApplication::translate("MainWindow", "Add Number", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        history->setText(QApplication::translate("MainWindow", "History", nullptr));
        label_img->setText(QApplication::translate("MainWindow", "LOGO", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "DELETE NUMBER", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "Submit", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "Status", nullptr));
        textBrowser_10->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Not Available.</p></body></html>", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "Search Number For Delete", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "Reconfirm Number", nullptr));
        pushButton_15->setText(QApplication::translate("MainWindow", "GOTO MAIN MENU", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "ADD NUMBER", nullptr));
        noType->setItemText(0, QApplication::translate("MainWindow", "Mobile Number", nullptr));
        noType->setItemText(1, QApplication::translate("MainWindow", "Landline Number", nullptr));

        textEdit_2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Number Type", nullptr));
        label_code->setText(QApplication::translate("MainWindow", "Code", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Aadhar No", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Address", nullptr));
        addNoSubmit->setText(QApplication::translate("MainWindow", "Submit", nullptr));
        pushButton_16->setText(QApplication::translate("MainWindow", "GOTO MAIN MENU", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "VIP Digits If Any", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "GET INFORMATION", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Search For Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Matched Numbers", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Aadhar No", nullptr));
        textBrowser_7->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Address", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Information", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Contact No", nullptr));
        pushButton_18->setText(QApplication::translate("MainWindow", "GOTO MAIN MENU", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "UPDATE", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Number", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "Address", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("MainWindow", "Mobile Number", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "Landline Number", nullptr));

        pushButton_9->setText(QApplication::translate("MainWindow", "Submit", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "Code", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "Name", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "Number Type", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "Search For Number", nullptr));
        textBrowser_9->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Not Available.</p></body></html>", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "Status", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "UPDATE YOUR INFORMATION", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "Aadhar No", nullptr));
        pushButton_17->setText(QApplication::translate("MainWindow", "GOTO MAIN MENU", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "History", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = historyTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = historyTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Action", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = historyTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Time", nullptr));
        BtnPrevHistory->setText(QApplication::translate("MainWindow", "Previous", nullptr));
        BtnNextHistory->setText(QApplication::translate("MainWindow", "Next", nullptr));
        retriveType->setItemText(0, QApplication::translate("MainWindow", "Retrive N Units From Input Time", nullptr));
        retriveType->setItemText(1, QApplication::translate("MainWindow", "Retrive All Units Between Input Time Range", nullptr));
        retriveType->setItemText(2, QApplication::translate("MainWindow", "Retrive All History", nullptr));

        label_35->setText(QApplication::translate("MainWindow", "Retrive Type", nullptr));
        labelTime->setText(QApplication::translate("MainWindow", "Enter Time", nullptr));
        label_N->setText(QApplication::translate("MainWindow", "Enter Value Of 'N'", nullptr));
        BtnHistorySubmit->setText(QApplication::translate("MainWindow", "Submit", nullptr));
        pushButton_14->setText(QApplication::translate("MainWindow", "GOTO MAIN MENU", nullptr));
        label_pageNo->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Page No", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "Total Entries", nullptr));
        label_totalEntries->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "Message : ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
