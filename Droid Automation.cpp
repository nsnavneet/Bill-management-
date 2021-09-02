#include<iostream>
#include<string>
#include<conio.h>
#include<vector>
#include<map>
#include<fstream>
#include<cstdlib>
using namespace std;
void Display()
{
	int k = 0, j = 0;
	string name = "D R O I D       A U T O M A T I O N ";
	for (int i = 0; i < name.size(); i++)
	{
		while (j < 42)
		{
			cout << " ";
			j++;
		}
		cout << name[i];
	}
	cout << endl;
	for (int i = 0; i < 120; i++)
	{
		cout << "~";
	}

}


class Bill
{
public:
	string item_name;
	int qty;
	double long price;
	string date;
	double long amt;
	long bill_no;
	long long Accno;
	long get_billno() { return bill_no; }

};
class Account
{
private:
	string company_name;
	string gst_no;
	long long int E_way_no;
	long long Accno;
	static long long generateAccno;

public:
	vector<Bill> b;
	map<long long, vector<Bill>>mp;
	Account() {  }
	Account(string c_n, string g_n, long long int E_n);
	string get_cname()
	{
		return company_name;
	}
	string getgstno()
	{
		return gst_no;
	}
	long  getEno()
	{
		return E_way_no;
	}
	long long getAccno()
	{
		return Accno;
	}
	void set_bills(int size, long long Accno)
	{
		b.resize(size);
		long long  b_no;
		string Date;
		cout << "Enter the Date : " << endl;
		cin >> Date;
		cout << "Enter the bill no : ";
		cin >> b_no;
		for (int i = 0; i < size; i++)
		{
			cout << "\nEnter the Discription : ";
			cin >> b[i].item_name;
			cout << "\nEnter the Qty. : ";
			cin >> b[i].qty;
			cout << "\nEnter the price : ";
			cin >> b[i].price;
			b[i].Accno = Accno;
			b[i].date = Date;
			b[i].bill_no = b_no;
			b[i].amt = b[i].qty * b[i].price;
		}
		mp.insert(pair<long, vector<Bill>>(b_no, b));
	}


	void get_bill(long bill_no, long long Accno)
	{
		system("CLS");

		auto it = mp.find(bill_no);
		if (it == mp.end())
		{
			cout << "\t\t\t\tSorry Bill does not generated or create the bills :) " << endl;
			return;
		}
		else
		{
			vector<vector<Bill>> b;
			b.push_back(it->second);
			int x = 1;
			cout << "\t\t\tBill No. :" << it->second.begin()->bill_no << "\t\tAccount :" << it->second.begin()->Accno << "\t\tDATE :" << it->second.begin()->date << endl;
			cout << "\tDiscription:\t\t" << "\t\tQty. :" << "\t\tPrice:" << "\t\tAmount: " << endl;
			{
				for (auto i = b.begin(); i != b.end(); i++)
				{
					for (auto j = i->begin(); j != i->end(); j++)
					{
						cout << x+1<< ")\t" << j->item_name << "\t\t" << "\t\t\t" << j->qty << "\t\t" << j->price << "\t\t" << j->amt << endl;
						x++;
					}
				}
			}
		}
		for (int i = 0; i < 120; i++)
		{
			cout << "_";
		}
	}

	void getAllbill(long long Accno)
	{
		auto it = mp.begin();
		if(it==mp.end())
		{
		  cout << "\t\t\t\tSorry Bills does not generated or create the bills :) " << endl;
         }
		else
		{
			for (it; it != mp.end(); it++)
			{
				cout << "\tBill No. :" << it->second.begin()->bill_no << "\tAccount :" << it->second.begin()->Accno << "\tDATE :" << it->second.begin()->date << endl;
				int x = 0;
				cout << endl << "\tDiscription:\t\t" << "\t\tQty. :" << "\t\tPrice:" << "\t\tAmount: " << endl;
				for (auto i = it->second.begin(); i != it->second.end(); i++)
				{
					cout << x + 1 << ")\t" << i->item_name << "\t\t" << "\t\t\t" << i->qty << "\t\t" << i->price << "\t\t" << i->amt << endl;
					x++;
				}
				cout << "____________________________________________________________________________________________" << endl;
			}
		}
	}


	static void set_generateAccno(long long Acc_no);
	static long long get_generateAccno();
	friend ostream& operator<<(ostream& os, Account& a);
	friend ofstream& operator<<(ofstream& of, Account& a);
	friend ifstream& operator>>(ifstream& ifs, Account& a);
	friend ifstream& getline(ifstream& ifs, Account& a);
	friend ofstream& operator<<(ofstream& of, Bill& b);
	friend ifstream& operator>>(ifstream& ifs, Bill& b);
};

long long Account::generateAccno = 0;

class Droid_Automation
{
private:
	map<long long, Account>m;
public:
	Droid_Automation();
	Account OpenAccount(string cname, string gst, long long int Ewno);
	void showBill(long long Accno);
	void showAllAccount();
	Account create_bill(long long Accno);
	void get_Allbill(long long Accno);
	~Droid_Automation();
};

Account::Account(string c_n, string g_n, long long int  E_n)
{
	generateAccno++;

	this->company_name = c_n;
	this->gst_no = g_n;
	this->E_way_no = E_n;
	this->Accno = generateAccno;
}
void Account::set_generateAccno(long long Acc_no)
{
	generateAccno = Acc_no;
}
long long Account::get_generateAccno()
{
	return generateAccno;
}

ostream& operator<<(ostream& os, Account& a)
{
	os << "\n\n\t\t\t\tCompany Name   : " << a.get_cname() << endl;
	os << "\t\t\t\tE-way Number   : " << a.getEno() << endl;
	os << "\t\t\t\tGST Number     : " << a.getgstno() << endl;
	os << "\t\t\t\tAccount Number : " << a.getAccno() << endl;
	//os << "Bill           : " << a.get_bill() << endl;
	return os;
}

ofstream& operator<<(ofstream& ofs, Account& a)
{
	ofs << a.company_name << endl;
	ofs << a.gst_no << endl;
	ofs << a.E_way_no << endl;
	ofs << a.Accno << endl;
	return ofs;
}

ifstream& operator>>(ifstream& ifs, Account& a)
{
	ifs >> a.company_name;
	ifs >> a.gst_no;
	ifs >> a.E_way_no;
	ifs >> a.Accno;
	return ifs;
}


ifstream& getline(ifstream& ifs, Account& a)
{
	ifs >> a.company_name;
	ifs >> a.gst_no;
	ifs >> a.E_way_no;
	ifs >> a.Accno;
	return ifs;
}

ofstream& operator<<(ofstream& of, Bill& b)
{
	of << b.Accno << endl;
	of << b.bill_no << endl;
	of << b.date << endl;
	of << b.item_name << endl;
	of << b.qty << endl;
	of << b.price << endl;
	of << b.amt << endl;
	return of;
}


ifstream& operator>>(ifstream& ifs, Bill& b)
{
	ifs >> b.Accno;
	ifs >> b.bill_no;
	ifs >> b.date;
	ifs >> b.item_name;
	ifs >> b.qty;
	ifs >> b.price;
	ifs >> b.amt;
	return ifs;
}

int main()
{
	Droid_Automation d;
	Account acc;
	int choice;
	long long Accno;
	string cname, gst;
	long long int Eno;
	do
	{
		system("CLS");
		//Display();
		cout << endl << "\n\n\n\t\t\t\tSelect One option below : " << endl;
		cout << endl << "\t\t\t\t1 Open An Account                    press 1" << endl;
		cout << endl << "\t\t\t\t2 Show All Account                   press 2" << endl;
		cout << endl << "\t\t\t\t3 Create bill                        press 3" << endl;
		cout << endl << "\t\t\t\t4 Get Bill                           press 4" << endl;
		cout << endl << "\t\t\t\t5 Show All the bill of Account       press 5" << endl;
		cout << endl << "\t\t\t\t6 Quit                               press 6" << endl;

		cout << endl << flush<<"\t\t\t\tEnter your choice : ";
		cin >> choice;
		system("CLS");
		switch (choice)
		{
		case 1:
			//Display();
			cout << flush << "\n\n\t\t\t\tEnter the Company Eame : " << flush;
			cin.ignore();
			getline(cin, cname);//cin>> cname;
			cout << endl;
			cout << flush<< "\t\t\t\tEnter the GST number : ";
			cin >> gst;
			cout << endl;
			cout << "\t\t\t\tEnter the E-way Number : ";
			cin >> Eno;
			cout << endl;
			acc = d.OpenAccount(cname, gst, Eno);
			system("CLS");
			cout << "\n\n\n\t\t\t\tcongratulation Your Account is created :) " << endl;
			cout<< acc;
			cout << "\n\n\n\t\t\t\tpress any key to go to menu ";
			//_getch();
			break;
		case 2:
			Display();
			d.showAllAccount();
			cout << "\n\n\n\t\t\t\tpress any key to go to menu ";
			_getch();
			break;
		case 3:
			Display();
			cout << "Enter the Account Number : ";
			cin >> Accno;
			acc = d.create_bill(Accno);
			cout << acc;
			break;
		case 4:
			Display();
			cout << "\n\n\n\t\t\t\tEnter the Account Number : ";
			cin >> Accno;
			d.showBill(Accno);
			cout << "\n\n\n\t\t\t\tpress any key to go to menu ";
			_getch();
			break;
		case 5:
			Display();
			cout << "\n\n\n\t\t\t\tEnter the Account Number : ";
			cin >> Accno;
			d.get_Allbill(Accno);
			cout << "\n\n\n\t\t\t\tpress any key to go to menu ";
			_getch();
			break;
		case 6:
			Display();
			break;
		default:
			Display();
			cout << "\t\t\t\tEnter the correct choice :)";
			exit(0);
		}
	} while (choice != 6);
	cout << "\n\n\n\n\n\t\t\t\tThanks for your, visit again :)"<<endl;
	_getch();
	return 0;
}


Droid_Automation::Droid_Automation()
{
	Account ac;
	ifstream infile("DroidAutomation.data");
	if (!infile)
	{
		//cout << "Error file not found in can't open file  " << endl;
		return;
	}
	while (!infile.eof())
	{
		infile >> ac;
		m.insert(pair<long long, Account>(ac.getAccno(), ac));
	}
	Account::set_generateAccno(ac.getAccno());
	infile.close();

	Bill bee;
	vector<Bill> bie;
	ifstream inf("DroidBill.csv");
	if(!inf)
	{
		return;
	}
	for (int n; inf >>bee; )  //we can't use while(!inf.eof())bus it run extra;
	{
		inf >> bee;
		bie.push_back(bee);
	}
	inf.close();
	auto itert = m.begin();
	vector<Bill> bi;
	auto i = bie.begin();
	bee.Accno = i->Accno;
	bee.bill_no = i->bill_no;
	while(i!= bie.end())// iterating bie vector to end.
	{
		if(bee.Accno==i->Accno)
		{
			if (bee.bill_no == i->bill_no)
			{
				bee.amt = i->amt;
				bee.bill_no = i->bill_no;
				bee.date = i->date;
				bee.item_name = i->item_name;
				bee.price = i->price;
				bee.qty = i->qty;
				bi.push_back(bee);
				i++;
			}
			else
			{
				itert = m.find(bi.begin()->Accno);
				itert->second.mp.insert(pair<long, vector<Bill>>(bee.bill_no, bi));
				bee.Accno = i->Accno;
				bee.bill_no = i->bill_no;
				bi.clear();
			}
		}
		
		else
		{
			itert = m.find(bi.begin()->Accno);
			itert->second.mp.insert(pair<long, vector<Bill>>(bee.bill_no, bi));
			bee.Accno = i->Accno;
			bee.bill_no = i->bill_no;
			bi.clear();
		}

	}

	 //if()
	 itert = m.find(bi.begin()->Accno);
     itert->second.mp.insert(pair<long, vector<Bill>>(bi.begin()->bill_no, bi));
	

	/*
	Bill bill;
	ifstream inf;
	inf.open("DroidBill.csv");
		if (!inf)
		{
		return;
		}

		for (auto itert = m.begin(); itert != m.end(); itert++)
		{
			if (itert->first)
			{
				inf >> bill;
				itert->second.mp.insert(pair<long, Bill>(bill.get_billno(), bill));
			}
		}
		inf.close();

		*/

		/*ifstream inf;
	inf.open("DroidBill.csv");
	if (!inf)
	{
		return;
	}

	for (auto itert = m.begin(); itert != m.end(); itert++)
	{
		if (itert->first)
		{
			auto te = itert->second.mp.begin();   //this got faliur buz iterator reach at the mp.end() it means this is empty. it give runtime error.
			inf >> itert->second;
			itert->second.mp.insert(pair<long, Bill>(te->second.get_billno(), te->second));
		}
	}
	inf.close();*/


}

Account Droid_Automation::OpenAccount(string cname, string gst, long long int Ewno)
{
	ofstream outfile;
	Account ac(cname, gst, Ewno); //bills is object of Bill class
	m.insert(pair<long long, Account>(ac.getAccno(), ac));// m.insert({ac.getAccno(),ac});
	outfile.open("DroidAutomation.data", ios::trunc);

	map<long long, Account>::iterator itr;// map<long, Account>::iterator itr = m.begin();
	for (itr = m.begin(); itr != m.end(); itr++)
	{
		outfile << itr->second;
	}
	outfile.close();
	return ac;
}




void Droid_Automation::showAllAccount()
{
	map<long long, Account>::iterator itr;
	for (itr = m.begin(); itr != m.end(); itr++)
	{
		cout << "\t\t\t\tAccouts : " << itr->first << "\n" << itr->second << endl;
		cout << "**************************************************************************************" << endl;
	}
}


Account Droid_Automation::create_bill(long long Accno)
{
	Account a;
	auto it = m.find(Accno);
	if (it == m.end())
	{
		cout << "Sorry can't find the account  First make Account of that Company " << endl;
	}
	else
	{
		int size;
		cout << "Account found" << endl << " Enter the numbers of items in bill : ";
		cin >> size;
		it->second.set_bills(size, Accno);
		return it->second;
	}
	return a;
}

void Droid_Automation::showBill(long long Accno)
{
	long bill_no;
	auto it = m.find(Accno);
	if (it == m.end())
	{
		cout << "\t\t\t\tSorry Account Not Found OR Create Account First  :) " << endl;
	}

	else
	{
		cout << "\t\t\t\tEnter the bill number you want to see : ";
		cin >> bill_no;
		cout << endl;
		it->second.get_bill(bill_no, Accno);
	}
}



void Droid_Automation::get_Allbill(long long Accno)
{
	auto it = m.find(Accno);
	if (it == m.end())
	{
		cout <<"\t\t\t\tSorry Account Not Found OR Create Account First :) " << endl;
	}
	else
	{
		it->second.getAllbill(Accno);
	}
}

Droid_Automation::~Droid_Automation()
{
	ofstream outfile;
	outfile.open("DroidAutomation.data", ios::trunc);
	map<long long, Account>::iterator itr;
	for (itr = m.begin(); itr != m.end(); itr++)
	{
		outfile << itr->second;
	}
	outfile.close();


	ofstream ofn;
	ofn.open("DroidBill.csv", ios::trunc);
	Bill b;
	vector<vector<Bill>> be;
	vector<Bill>bie;
	for (auto itert = m.begin(); itert != m.end(); itert++)
	{
		if (itert->first)
		{
			for (auto te = itert->second.mp.begin(); te != itert->second.mp.end(); te++)
			{
				be.push_back(te->second);
			}
		}
	}
	for (auto i = be.begin(); i != be.end(); i++)
	{
		for (auto j = i->begin(); j != i->end(); j++)
		{
			b.amt = j->amt;
			b.bill_no = j->bill_no;
			b.date = j->date;
			b.item_name = j->item_name;
			b.price = j->price;
			b.qty = j->qty;
			b.Accno = j->Accno;
			ofn << b;
		}
	}
	ofn.close();
}