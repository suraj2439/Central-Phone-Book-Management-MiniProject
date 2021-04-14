#include "backend.h"
#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;

	//.init_phonebook(trie, history);

	w.show();
	//Trie t = w.get_phonebook();
	//History h = w.get_history();

	a.exec();

	std::vector<hstry> hst;
	History hstr = w.get_history();
	hst = hstr.retrive();

	
	std::cout<<hst.size()<<"end";
	for(int i = 0; i < hst.size(); i++) 
		std::cout<<hst[i].num<<std::endl;
	
	return 0;
}
