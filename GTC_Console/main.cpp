#include <QtCore/QCoreApplication>
#include <QStringList>
#include <iostream>
#include <QTextStream>
#include <QProcess>

using namespace std;
/*!
\mainpage 
\brief Программа для автоматической генерации оглавления в виде якорных ссылок
*\author Кременецкая А.Д.

Программа выполняет следующие функции:
<ol>
<li>ищет в коде заголовочные теги;</li>
<li>на основании тегов организует вложенность ;</li>
<li>игнорирует непарные теги, т.к. при замене на маркированный список они утрачивают свои функции;</li>
<li>сообщает об ошибке в случае незакрытого или неоткрытого парного тега;</li>
</ol>
<p>Программа принимает на вход URL/путь к файлу, содержащему html-код</p>
<p>Программа возвращает html-разметку со сгенерированным оглавлением с соблюдением вложенности</p>
*/


/*!Главная функция проекта
*\param [in] argc - количество переданных параметров
*\param [in] argv - переданные параметры(пути к файлам)
*\return - 0 при завершении работы программы

*\brief Главная функция проекта

Функция организует ввод и вывод данных и вызов процесса, обрабатывающего данные
*/
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	setlocale(LC_ALL, "Russian");
	QTextStream cin(stdin); 

	cout << "--------GTC is responsible for formation table of contents based on html-code--------\n\n";

	cout << "Enter URL to website or filepath to html-code you want to analyze:\n";
	QString Path = cin.readLine();

	cout << "Enter filepath to the result file: \n";
	QString ResultHtmlDataFile = cin.readLine();

	//Если необходимые параметры указаны
	if(!Path.isEmpty() && !ResultHtmlDataFile.isEmpty()){

		//Создать процесс-обработчик
		QProcess GTC_GUI;

		GTC_GUI.start("C:\\GTC_GUI\\Win32\\Debug\\GTC_GUI.exe", QStringList() << Path << ResultHtmlDataFile);

		if (!GTC_GUI.waitForStarted()){
			cout << "Unable to create handler process. Termination" << endl;
			return 0;
		}

		QByteArray processOutput; ///> Отчет о выполнении процесса обработчика
		processOutput = GTC_GUI.readAllStandardOutput();//но как записать в стдаут?


		//QByteArray result = GTC_GUI.readAll();   //хз чем от readAllStandardOutput отличается
	}

	//Иначе
	else
		cout << "Needed arguments are not mentioned" << endl;

	return 0;
}
