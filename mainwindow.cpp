#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : History(), QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("logo.jpg");
    int w = ui->label_img->width();
    int h = ui->label_img->height();
    ui->label_img->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    ui->stackedWidget->setCurrentIndex(0);
    this->phonebook = new Trie;

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*
void MainWindow::init_phonebook() {
	this->phonebook = T;
	this->history = H;
}*/

Trie MainWindow::get_phonebook() {
	return *(this->phonebook);
}

History MainWindow::get_history() {
	return phonebook->get_history();
}

void MainWindow::on_tableWidget_cellClicked(int row, int column)
{

}

void MainWindow::on_addno_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_getinfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_update_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_delno_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_history_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_addNoSubmit_clicked()
{
	Generator g;
	int type = ui->noType->currentIndex();
	// TODO validate
	int code = std::stoi(ui->code->toPlainText().toStdString());
	std::string st = g.generate_number(type, code);
	phonebook->insert_number(st);
}

void MainWindow::on_noType_activated(const QString &arg1)
{

}

void MainWindow::on_retriveType_currentIndexChanged(int index)
{
    if(index == 1) {
        ui->labelTime->setText(QString::fromStdString("Enter Lower Time"));
        ui->label_N->setText(QString::fromStdString("Enter Upper Time"));
    }
    return;
}

void MainWindow::printHistoryTable() {
    ui->label_pageNo->setText(QString::number(get_historyPageNo()+1));

    std::vector<hstry> hst;
    History hstr = get_history();
    std::string str1 = ui->lowerTime->text().toStdString();
    std::string str2 = ui->upperTimeOrN->text().toStdString();
    //TODO validate str1 and str2
    if(ui->retriveType->currentIndex() == 0) {
        time_t lower = std::stoi(str1);
        int N = std::stoi(str2);
        hst = hstr.retrive(lower, N);
    }
    else if(ui->retriveType->currentIndex() == 1) {
        std::cout<<hstr.retrive().size();
        time_t lower = std::stoi(str1);
        time_t upper = std::stoi(str2);
        //std::cout<<lower<<" af "<<upper<<"end";
        hst = hstr.retrive(lower, upper);
    }
    else
        hst = hstr.retrive();

    ui->label_totalEntries->setText(QString::number(hst.size()));

    QTableWidgetItem *itm;
    int i, h_indx = get_historyPageNo() * ui->historyTable->rowCount();
    if(h_indx < hst.size() || h_indx == 0)
        ui->historyTable->clearContents();
    else {
        set_historyPageNo(get_historyPageNo()-1);
        ui->label_pageNo->setText(QString::number(get_historyPageNo()+1));
        return;
    }
    for(i = 0; i < ui->historyTable->rowCount() && i+h_indx < hst.size() ; i++) {
        for(int j = 0; j < ui->historyTable->columnCount(); j++) {
            itm = new QTableWidgetItem;
            if(j == 0)
                itm->setText(QString::fromStdString(hst[i+h_indx].num));
            else if(j == 1) {
                switch(hst[i+h_indx].operation) {
                    case INSERT_NO:
                        itm->setText(QString::fromStdString("Insert Number"));
                        break;
                    case DEL_NO:
                        itm->setText(QString::fromStdString("Delete Number"));
                        break;
                    case UPDATE_INFO:
                        itm->setText(QString::fromStdString("Update Information"));
                        break;
                    default:
                        itm->setText(QString::fromStdString("Unknown"));
                        break;
                }
            }
            else if(j == 2) {
                itm->setText(QString::number(hst[i+h_indx].time));
            }
            ui->historyTable->setItem(i, j, itm);
        }
    }
    //set_historyPageNo((i+h_indx) / ui->historyTable->rowCount());
}


void MainWindow::on_BtnHistorySubmit_clicked()
{
    set_historyPageNo(0);
    printHistoryTable();
}

void MainWindow::on_BtnNextHistory_clicked()
{
    int no = get_historyPageNo();
    set_historyPageNo(no+1);
    printHistoryTable();
}

void MainWindow::on_BtnPrevHistory_clicked()
{
    int no = get_historyPageNo();
    std::cout<< "n "<< no<<std::endl;
    if(no)
        set_historyPageNo(no-1);
    else
        return;
    printHistoryTable();
}
