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
    phonebook = new Trie;
    phonebook->Load_Directory();
    update_homepage();
    ui->login_pswd->setEchoMode(QLineEdit::Password);
    ui->login_pswd_new->setEchoMode(QLineEdit::Password);
    login_id = "suraj2439";
    login_password = "smyerkal";
}

MainWindow::~MainWindow()
{
    phonebook->Load_Data_in_file();
    delete ui;
}



void MainWindow::update_login_details(std::string id, std::string password) {
       login_id = id;
       login_password = password;
       return;
}

std::string MainWindow::get_login_id() {
    return login_id;
}
std::string MainWindow::get_login_password() {
    return login_password;
}

Trie MainWindow::get_phonebook() {
	return *(this->phonebook);
}

History MainWindow::get_history() {
	return phonebook->get_history();
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
    ui->msg->setText(QString::fromStdString("You need to login for this action."));
    ui->login_userId->clear();
    ui->login_pswd->clear();
    log_intoPage = 4;
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_delno_clicked()
{
    ui->msg->setText(QString::fromStdString("You need to login for this action."));
    ui->login_userId->clear();
    ui->login_pswd->clear();
    log_intoPage = 1;
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_history_clicked()
{
    ui->msg->setText(QString::fromStdString("You need to login for this action."));
    ui->login_userId->clear();
    ui->login_pswd->clear();
    log_intoPage = 5;
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    update_homepage();
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    update_homepage();
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    update_homepage();
}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    update_homepage();
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    update_homepage();
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    update_homepage();
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    update_homepage();
}

void MainWindow::on_addNoSubmit_clicked()
{
    // init generator and validator
	Generator g;
    Validator v;

    // code number i.e. country or area code
    std::string codeNo = ui->code->toPlainText().toStdString();
    // validate code
    if(! v.isNumber(codeNo)) {
        ui->msg->setText(QString::fromStdString("Invalid Code"));
        return;
    }

    std::string countryName = ui->code_Name->toPlainText().toStdString();
    if(countryName == "") {
        ui->msg->setText(QString::fromStdString("Code Name is required."));
        return;
    }
    phonebook->set_code_info(codeNo, countryName);

    // convert to int
    int code = phonebook->get_code_key(codeNo);

    info *inf = new info;
    inf->country_code = code;

    std::string vip = ui->vipDigits->toPlainText().toStdString();
    std::string number;
    // number type
    int type = ui->noType->currentIndex();
    if(! v.isNumber(vip))
        number = g.generate_number(type, stoi(codeNo));
    else
        number = g.generate_number(type, stoi(codeNo), vip.size(), vip);

    inf->company = ui->company->toPlainText().toStdString();
    if(inf->company == "") {
        ui->msg->setText(QString::fromStdString("Company Name is required."));
        return;
    }
    inf->name = ui->name->toPlainText().toStdString();
    if(! v.isName(inf->name)) {
        ui->msg->setText(QString::fromStdString("Invalid Name."));
        return;
    }
    inf->aadharNo = ui->aadharNo->toPlainText().toStdString();
    if(! v.isAadhar(inf->aadharNo)) {
        ui->msg->setText(QString::fromStdString("Invalid Aadhar Number."));
        return;
    }
    inf->address = ui->address->toPlainText().toStdString();

    phonebook->insert_number(number, inf);
    ui->msg->setText(QString::fromStdString("Your Number " + number + " is successfully added."));
    return;
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
    if(ui->retriveType->currentIndex() == 0) {
        time_t lower = std::stoi(str1);
        int N = std::stoi(str2);
        hst = hstr.retrive(lower, N);
    }
    else if(ui->retriveType->currentIndex() == 1) {
        time_t lower = std::stoi(str1);
        time_t upper = std::stoi(str2);
        hst = hstr.retrive(lower, upper);
    }
    else
        hst = hstr.retrive();

    ui->label_totalEntries->setText(QString::number(hst.size()));

    QTableWidgetItem *itm;
    int i, h_indx = get_historyPageNo() * ui->historyTable->rowCount();
    if(h_indx < (int)hst.size() || h_indx == 0)
        ui->historyTable->clearContents();
    else {
        set_historyPageNo(get_historyPageNo()-1);
        ui->label_pageNo->setText(QString::number(get_historyPageNo()+1));
        return;
    }
    for(i = 0; i < ui->historyTable->rowCount() && i+h_indx < (int)hst.size() ; i++) {
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
    if(no)
        set_historyPageNo(no-1);
    else
        return;
    printHistoryTable();
}

void MainWindow::on_noType_currentIndexChanged(int index)
{
    if(index == 0) {
        ui->label_code->setText(QString::fromStdString("Country Code"));
        ui->label_codeName->setText(QString::fromStdString("Country Name"));
    }
    else {
        ui->label_code->setText(QString::fromStdString("Area Code"));
        ui->label_codeName->setText(QString::fromStdString("Area Name"));
    }
}


void MainWindow::print_homeTable() {
    ui->homePageNo->setText(QString::number(phonebook->get_homeTablePageNo()+1));

    std::vector<std::string> numbers;
    numbers = phonebook->traverse_directory();

    ui->totContacts->setText(QString::number(numbers.size()));

    QTableWidgetItem *itm;
    int i, h_indx = phonebook->get_homeTablePageNo() * ui->main_table->rowCount();
    if(h_indx < (int)numbers.size() || h_indx == 0)
        ui->main_table->clearContents();
    else {
        phonebook->set_homeTablePageNo(phonebook->get_homeTablePageNo()-1);
        ui->homePageNo->setText(QString::number(phonebook->get_homeTablePageNo()+1));
        return;
    }

    for(i = 0; i < ui->main_table->rowCount() && i+h_indx < (int)numbers.size() ; i++) {
        itm = new QTableWidgetItem;
        char code_key = numbers[i+h_indx][0];
        numbers[i+h_indx].erase(0, 1);
        std::string number = phonebook->get_code_key(code_key) + " " + numbers[i+h_indx];
        itm->setText(QString::fromStdString(number));
        ui->main_table->setItem(i, 0, itm);
    }
}


void MainWindow::on_btn_HomeNext_clicked()
{
    int no = phonebook->get_homeTablePageNo();
    phonebook->set_homeTablePageNo(no+1);
    print_homeTable();
}

void MainWindow::on_btn_HomePrev_clicked()
{
    int no = phonebook->get_homeTablePageNo();
    if(no)
        phonebook->set_homeTablePageNo(no-1);
    else
        return;
    print_homeTable();
}

void MainWindow::update_homepage()
{
    ui->contactNo->clear();
    ui->countryHome->clear();
    ui->nameHome->clear();
    ui->companyHome->clear();
    ui->aadharHome->clear();
    ui->addressHome->clear();
    phonebook->set_homeTablePageNo(0);
    print_homeTable();
}

void MainWindow::on_delNumber_textChanged(const QString &num)
{
    Validator v;
    std::string number = (num).toStdString();
    std::string code = (ui->delNoCode->text()).toStdString();
    char code_key = phonebook->get_code_key(code);
    if(! v.isPhoneNumber(number)) {
        ui->delNoStatus->setText(QString::fromStdString("Not Available."));
        return;
    }
    else if(! phonebook->is_present(number, code_key)){
        ui->delNoStatus->setText(QString::fromStdString("Not Available."));
        return;
    }
    else {
        ui->delNoStatus->setText(QString::fromStdString("Available."));
        return;
    }
}

void MainWindow::on_delNoCode_textChanged(const QString &code_inp)
{
    Validator v;
    std::string code = (code_inp).toStdString();
    std::string number = (ui->delNumber->text()).toStdString();
    char code_key = phonebook->get_code_key(code);
    if(! v.isPhoneNumber(number)) {
        ui->delNoStatus->setText(QString::fromStdString("Not Available."));
        return;
    }
    else if(! phonebook->is_present(number, code_key)){
        ui->delNoStatus->setText(QString::fromStdString("Not Available."));
        return;
    }
    else {
        ui->delNoStatus->setText(QString::fromStdString("Available."));
        return;
    }
}

void MainWindow::on_btn_delSubmit_clicked()
{
    if(ui->delNoStatus->toPlainText().toStdString() == "Not Available.") {
        ui->msg->setText(QString::fromStdString("Number Not Available."));
        return;
    }
    else if(ui->delNumber->text() != ui->reconfirmNo->text() || ui->delNoCode->text() != ui->reconfirmCode->text()) {
        ui->msg->setText(QString::fromStdString("Please Check Number Once Again."));
        return;
    }
    std::string code = (ui->delNoCode->text()).toStdString();
    std::string number = (ui->delNumber->text()).toStdString();
    short int code_key = phonebook->get_code_key(code);
    phonebook->delete_number(number, code_key);
    ui->msg->setText(QString::fromStdString("Your Number is successfully Deleted."));
    return;
}


void MainWindow::on_main_table_cellClicked(int row, int column)
{
    QTableWidgetItem *itm = new QTableWidgetItem;
    itm = ui->main_table->item(row, column);
    if(itm == NULL) {
        ui->contactNo->clear();
        ui->countryHome->clear();
        ui->nameHome->clear();
        ui->companyHome->clear();
        ui->aadharHome->clear();
        ui->addressHome->clear();
        return;
    }
    std::string number = itm->text().toStdString();
    if(number.size() == 0)
        return;
    std::string code;
    int i;
    for(i = 0; i < (int)number.size() && number[i] != ' '; i++) {
        code.push_back(number[i]);
    }
    number = number.substr(i+1, number.size()-1);
    short int code_key = phonebook->get_code_key(code);

    //if( phonebook->is_present(number, code_key))
     //   return;
    info *inf = phonebook->get_info(number, code_key);
     //           return;
    ui->contactNo->setText(QString::fromStdString(number));
    ui->countryHome->setText(QString::fromStdString(phonebook->get_code_info(code)));
    ui->nameHome->setText(QString::fromStdString(inf->name));
    ui->companyHome->setText(QString::fromStdString(inf->company));
    ui->aadharHome->setText(QString::fromStdString(inf->aadharNo));
    ui->addressHome->setText(QString::fromStdString(inf->address));
    //ui->msg->setText(QString::fromStdString(code + " " + number));
}


void MainWindow::print_getInfoTable() {
    ui->getInfoPageNo->setText(QString::number(phonebook->get_infoTablePageNo()+1));

    std::string to_check = ui->infoSearch->text().toStdString();
    std::vector<std::string> numbers;
    numbers = phonebook->display_number_via_substring(to_check);

    ui->totContacts_get->setText(QString::number(numbers.size()));

    QTableWidgetItem *itm;
    int i, h_indx = phonebook->get_infoTablePageNo() * ui->getInfo_table->rowCount();
    if(h_indx < (int)numbers.size() || h_indx == 0)
        ui->getInfo_table->clearContents();
    else {
        phonebook->set_getInfoTablePageNo(phonebook->get_infoTablePageNo()-1);
        ui->getInfoPageNo->setText(QString::number(phonebook->get_infoTablePageNo()+1));
        return;
    }

    for(i = 0; i < ui->getInfo_table->rowCount() && i+h_indx < (int)numbers.size() ; i++) {
        itm = new QTableWidgetItem;
        char code_key = numbers[i+h_indx][0];
        numbers[i+h_indx].erase(0, 1);
        std::string number = phonebook->get_code_key(code_key) + " " + numbers[i+h_indx];
        //std::cout<<"key "<<phonebook->get_code_key(code_key)<<" no: "<<
        itm->setText(QString::fromStdString(number));
        ui->getInfo_table->setItem(i, 0, itm);
    }
}


void MainWindow::on_infoSearch_textChanged(const QString &num)
{
    ui->contactNo_get->clear();
    ui->country_get->clear();
    ui->name_get->clear();
    ui->company_get->clear();
    ui->aadhar_get->clear();
    ui->address_get->clear();
    phonebook->set_getInfoTablePageNo(0);
    print_getInfoTable();
}

void MainWindow::on_btn_getInfoPrev_clicked()
{
    int no = phonebook->get_infoTablePageNo();
    if(no)
        phonebook->set_getInfoTablePageNo(no-1);
    else
        return;
    print_getInfoTable();
}

void MainWindow::on_btn_getInfoNext_clicked()
{
    int no = phonebook->get_infoTablePageNo();
    phonebook->set_getInfoTablePageNo(no+1);
    print_getInfoTable();
}

void MainWindow::on_getInfo_table_cellClicked(int row, int column)
{
    QTableWidgetItem *itm = new QTableWidgetItem;
    itm = ui->getInfo_table->item(row, column);
    if(itm == NULL) {
        ui->contactNo_get->clear();
        ui->country_get->clear();
        ui->name_get->clear();
        ui->company_get->clear();
        ui->aadhar_get->clear();
        ui->address_get->clear();
        return;
    }
    std::string number = itm->text().toStdString();
    if(number.size() == 0)
        return;
    std::string code;
    int i;
    for(i = 0; i < (int)number.size() && number[i] != ' '; i++) {
        code.push_back(number[i]);
    }
    number = number.substr(i+1, number.size()-1);
    short int code_key = phonebook->get_code_key(code);

    info *inf = phonebook->get_info(number, code_key);

    ui->contactNo_get->setText(QString::fromStdString(number));
    ui->country_get->setText(QString::fromStdString(phonebook->get_code_info(code)));
    ui->name_get->setText(QString::fromStdString(inf->name));
    ui->company_get->setText(QString::fromStdString(inf->company));
    ui->aadhar_get->setText(QString::fromStdString(inf->aadharNo));
    ui->address_get->setText(QString::fromStdString(inf->address));
}


void MainWindow::on_searchNo_update_textChanged(const QString &num)
{
    ui->country_update->clear();
    ui->name_update->clear();
    ui->company_update->clear();
    ui->aadhar_update->clear();
    ui->address_update->clear();

    Validator v;
    std::string number = (num).toStdString();
    std::string code = (ui->searchCode_update->text()).toStdString();
    short int code_key = phonebook->get_code_key(code);
    if(! v.isPhoneNumber(number)) {
        ui->status_update->setText(QString::fromStdString("Not Available."));
        return;
    }
    else if(! phonebook->is_present(number, code_key)){
        //std::cout<<"hello";
        ui->status_update->setText(QString::fromStdString("Not Available."));
        return;
    }
    else {
        ui->status_update->setText(QString::fromStdString("Available."));

        info *inf = phonebook->get_info(number, code_key);
        ui->country_update->setText(QString::fromStdString(phonebook->get_code_info(code)));
        ui->name_update->setText(QString::fromStdString(inf->name));
        ui->company_update->setText(QString::fromStdString(inf->company));
        ui->aadhar_update->setText(QString::fromStdString(inf->aadharNo));
        ui->address_update->setText(QString::fromStdString(inf->address));
        return;
    }
}

void MainWindow::on_searchCode_update_textChanged(const QString &country_code)
{
    ui->country_update->clear();
    ui->name_update->clear();
    ui->company_update->clear();
    ui->aadhar_update->clear();
    ui->address_update->clear();

    Validator v;
    std::string number = (ui->searchNo_update->text()).toStdString();
    std::string code = (country_code).toStdString();
    short int code_key = phonebook->get_code_key(code);
    if(! v.isPhoneNumber(number)) {
        ui->status_update->setText(QString::fromStdString("Not Available."));
        return;
    }
    else if(! phonebook->is_present(number, code_key)){
        //std::cout<<"hello";
        ui->status_update->setText(QString::fromStdString("Not Available."));
        return;
    }
    else {
        ui->status_update->setText(QString::fromStdString("Available."));

        info *inf = phonebook->get_info(number, code_key);
        ui->country_update->setText(QString::fromStdString(phonebook->get_code_info(code)));
        ui->name_update->setText(QString::fromStdString(inf->name));
        ui->company_update->setText(QString::fromStdString(inf->company));
        ui->aadhar_update->setText(QString::fromStdString(inf->aadharNo));
        ui->address_update->setText(QString::fromStdString(inf->address));
        return;
    }
}

void MainWindow::on_submit_update_clicked()
{
    if((ui->status_update->toPlainText()).toStdString() == "Available.") {
        Validator v;
        info *inf = new info;

        std::string code = (ui->searchCode_update->text()).toStdString();
        short int code_key = phonebook->get_code_key(code);
        inf->country_code = code_key;

        std::string number = (ui->searchNo_update->text()).toStdString();

        inf->company = ui->company_update->text().toStdString();
        if(inf->company == "") {
            ui->msg->setText(QString::fromStdString("Company Name is required."));
            return;
        }
        inf->name = ui->name_update->text().toStdString();
        if(! v.isName(inf->name)) {
            ui->msg->setText(QString::fromStdString("Invalid Name."));
            return;
        }
        inf->aadharNo = ui->aadhar_update->text().toStdString();
        if(! v.isAadhar(inf->aadharNo)) {
            ui->msg->setText(QString::fromStdString("Invalid Aadhar Number."));
            return;
        }
        inf->address = ui->address_update->toPlainText().toStdString();

        phonebook->update_info(number, inf);
        ui->msg->setText(QString::fromStdString("Your Number " + number + " is successfully updated."));
        return;

    }
}

void MainWindow::on_login_submit_clicked()
{
    if(get_login_id() == ui->login_userId->text().toStdString() && get_login_password() == ui->login_pswd->text().toStdString()) {
        ui->msg->setText(QString::fromStdString("You are successfully logged in."));
        ui->stackedWidget->setCurrentIndex(log_intoPage);
    }
    else{
        ui->msg->setText(QString::fromStdString("Invalid login id or password, try again..."));
    }
}


void MainWindow::on_loginUpdate_submit_clicked()
{
    if(ui->login_userId_new->text().toStdString() == "") {
        ui->msg->setText(QString::fromStdString("User Id is required."));
        return;
    }
    else if(ui->login_pswd_new->text().toStdString() == "") {
        ui->msg->setText(QString::fromStdString("Password is required."));
        return;
    }
    update_login_details(ui->login_userId_new->text().toStdString(),
                         ui->login_pswd_new->text().toStdString());
    ui->msg->setText(QString::fromStdString("You have successfully updated your login information."));
    return;
}

void MainWindow::on_loginInfo_update_clicked()
{
    if(get_login_id() == ui->login_userId->text().toStdString() && get_login_password() ==
            ui->login_pswd->text().toStdString()) {
        ui->stackedWidget->setCurrentIndex(7);
        ui->login_userId_new->clear();
        ui->login_pswd_new->clear();
    }
    else{
        ui->msg->setText(QString::fromStdString("Invalid login id or password, try again..."));
    }
}


