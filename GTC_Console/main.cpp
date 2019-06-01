#include <QtCore/QCoreApplication>
#include <QStringList>
#include <iostream>
#include <QTextStream>
#include <QProcess>

using namespace std;
/*!
\mainpage 
\brief ��������� ��� �������������� ��������� ���������� � ���� ������� ������
*\author ����������� �.�.

��������� ��������� ��������� �������:
<ol>
<li>���� � ���� ������������ ����;</li>
<li>�� ��������� ����� ���������� ����������� ;</li>
<li>���������� �������� ����, �.�. ��� ������ �� ������������� ������ ��� ���������� ���� �������;</li>
<li>�������� �� ������ � ������ ����������� ��� ����������� ������� ����;</li>
</ol>
<p>��������� ��������� �� ���� URL/���� � �����, ����������� html-���</p>
<p>��������� ���������� html-�������� �� ��������������� ����������� � ����������� �����������</p>
*/


/*!������� ������� �������
*\param [in] argc - ���������� ���������� ����������
*\param [in] argv - ���������� ���������(���� � ������)
*\return - 0 ��� ���������� ������ ���������

*\brief ������� ������� �������

������� ���������� ���� � ����� ������ � ����� ��������, ��������������� ������
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

	//���� ����������� ��������� �������
	if(!Path.isEmpty() && !ResultHtmlDataFile.isEmpty()){

		//������� �������-����������
		QProcess GTC_GUI;

		GTC_GUI.start("C:\\GTC_GUI\\Win32\\Debug\\GTC_GUI.exe", QStringList() << Path << ResultHtmlDataFile);

		if (!GTC_GUI.waitForStarted()){
			cout << "Unable to create handler process. Termination" << endl;
			return 0;
		}

		QByteArray processOutput; ///> ����� � ���������� �������� �����������
		processOutput = GTC_GUI.readAllStandardOutput();//�� ��� �������� � ������?


		//QByteArray result = GTC_GUI.readAll();   //�� ��� �� readAllStandardOutput ����������
	}

	//�����
	else
		cout << "Needed arguments are not mentioned" << endl;

	return 0;
}
