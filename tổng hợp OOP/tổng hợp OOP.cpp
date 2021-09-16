#include <iostream>
#include<string>
#include<vector>
using namespace std;

class nhanvien {
protected:
	string hoten;
	string manv;
	string namsinh;
public:
	virtual void nhapthongtin();
	virtual void xuatthongtin();
	virtual double tienluong()=0;
};

void nhanvien::nhapthongtin() {
	cout << "\nNhap ho ten nhan vien:";
	getline(cin, hoten);
	cout << "\nNhap ma nhan vien:";
	getline(cin, manv);
	cout << "\nNhap ngay thang nam sinh:";
	getline(cin, namsinh);
}

void nhanvien::xuatthongtin() {
	cout << "\nHo ten nhan vien:" << hoten;
	cout << "\nMa so nhan vien:" << manv;
	cout << "\nNgay thang nam sinh:" << namsinh;
}

class nhanviensuaongnuoc : public nhanvien {
private:
	float sohsua;
public:
	void nhapthongtin();
	void xuatthongtin();
	double tienluong();
};

void nhanviensuaongnuoc::nhapthongtin() {
	cin.ignore();
	nhanvien::nhapthongtin();
	cout << "\nNhap so gio da sua trong thang vua qua:";
	cin >> sohsua;
}

double nhanviensuaongnuoc::tienluong() {
	return sohsua * 50000;
}

void nhanviensuaongnuoc::xuatthongtin() {
	cout << "\n\n\t\tNHAN VIEN SUA ONG NUOC\n";
	nhanvien::xuatthongtin();
	cout << "\n So gio da sua trong thang vua qua:" << sohsua;
	cout << "\nTien luong trong thang vua qua:" << (size_t)tienluong();
}
 
class nhanviengiaohang :public nhanvien {
private:
	int sohanggiao;
public:
	void nhapthongtin();
	void xuatthongtin();
	double tienluong();
};

void nhanviengiaohang::nhapthongtin() {
	cin.ignore();
	nhanvien::nhapthongtin();
	cout << "\nSo hang da giao trong thang vua qua:";
	cin >> sohanggiao;
}

double nhanviengiaohang::tienluong() {
	return sohanggiao * 33500;
}
void nhanviengiaohang::xuatthongtin() {
	cout << "\n\n\t\tNHAN VIEN GIAO HANG\n";
	nhanvien::xuatthongtin();
	cout << "\nSo hang da giao trong thang vua qua:" << sohanggiao;
	cout << "\nTien luong trong thang vua qua:" << (size_t)tienluong();
}

class nhanvienxeom :public nhanvien {
private:
	float sokm;
public:
	void nhapthongtin();
	void xuatthongtin();
	double tienluong();
};

void nhanvienxeom::nhapthongtin() {
	cin.ignore();
	nhanvien::nhapthongtin();
	cout << "\nNhap so km da chay trong thang vua qua:";
	cin >> sokm;
}

double nhanvienxeom::tienluong() {
	return sokm * 23500;
}

void nhanvienxeom::xuatthongtin() {
	cout << "\n\n\t\tNHAN VIEN XE OM\n";
	nhanvien::xuatthongtin();
	cout << "\nSo km da chay trong thang vua qua:" << sokm;
	cout << "\nTien luong trong thang vua qua:" << (size_t)tienluong();
}

class congty {
private:
	vector<nhanvien*>dsnhanvien;
public:
	void nhapthongtin();
	void xuatthongtin();	
	vector<nhanvien*> getterdanhsach() {
		return dsnhanvien;
	}
};

void congty::nhapthongtin() {
	int luachon;
	while (69) {
		system("cls");
		cout << "\n\n\t\t=========PHAN MEM QUAN LY NHAN VIEN=========";
		cout << "\n1.Nhap thong tin nhan vien sua ong nuoc:";
		cout << "\n2.Nhap thong tin nhan vien giao hang:";
		cout << "\n3.Nhap thong tin nhan vien xe om";
		cout << "\n0.Ket thuc";
		cout << "\n\n\t\t===================END======================";
		cout << "\nNhap lua chon cua ban:";
		cin >> luachon;
		nhanvien* x;
		if (luachon == 0) {
			break;
		}
		else if (luachon == 1) {
			x=new nhanviensuaongnuoc;
			x->nhapthongtin();
			dsnhanvien.push_back(x);
		}
		else if (luachon == 2) {
			x = new nhanviengiaohang;
			x->nhapthongtin();
			dsnhanvien.push_back(x);
		}
		else if (luachon == 3) {
			x = new nhanvienxeom;
			x->nhapthongtin();
			dsnhanvien.push_back(x);
		}
		else {
			cout << "\nLua chon khong hop le!";
			system("pause");
		}
	}
}

double tienluongcongty(vector<nhanvien*>dsnhanvien) {
	double sum = 0;
	for (int i = 0; i < dsnhanvien.size(); i++) {
		sum += dsnhanvien[i]->tienluong();
	}
	return sum;
}

void xuatdanhsachluongtangdan(vector<nhanvien*> dsnhanvien) {
	for (int i = 0; i < dsnhanvien.size()-1; i++)
	{
		for(int j=i+1;j<dsnhanvien.size();j++)
		{		if (dsnhanvien[i]->tienluong() > dsnhanvien[j]->tienluong()) 
			{
				swap(dsnhanvien[i],dsnhanvien[j]);
			}
		}
	}
	for (int i = 0; i < dsnhanvien.size(); i++) {
		dsnhanvien[i]->xuatthongtin();
	}
}

void xuatdanhsachnhanvien(vector<nhanvien*> ds) {
	for (int i = 0; i < ds.size(); i++) {
		ds[i]->xuatthongtin();
	}
}

void congty::xuatthongtin() {
	int luachon;
	while (69) {
		system("cls");
		cout << "\n\t1.Xuat danh sach nhan vien:";
		cout << "\n\t2.Xuat danh sach nhan vien theo luong tang dan:";
		cout << "\n\t3.Xuat tong tien luong cong ty:";
		cout << "\n\t0.Ket thuc";
		cout << "\nLua chon cua ban la gi?";
		cin >> luachon;

		if (luachon == 1) {
			xuatdanhsachnhanvien(getterdanhsach());
			system("pause");
		}

		else if (luachon == 2) {
			xuatdanhsachluongtangdan(getterdanhsach());
			
			system("pause");
		}

		else if (luachon == 3) {
			cout << "\n\n\t\tTIEN LUONG PHAI TRA CHO NHAN VIEN\n";
			tienluongcongty(getterdanhsach());
			system("pause");
		}

		else if (luachon == 0) {
			break;
		}

	}
}

int main()
{
	congty* x=new congty;
	x->nhapthongtin();
	x->xuatthongtin();
	delete x;
   
}

