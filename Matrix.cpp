#include "Matrix.h"

void Matrix:: nhapmat(float a[][100], int n) {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << i + 1 << j + 1 << endl;
		     cin>>a[i][j];
		}
}
void  Matrix::xuatmat(float a[][100], int n) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cout << a[i][j] << endl;;
	
	}

}
float  Matrix::det(float a[][100], int n) {
	int i, j, k, dem = 0, kt;
	float b[100], h, det = 1, c[100];
	for (i = 0; i < n - 1; i++)
	{
		if (a[i][i] == 0)
		{
			kt = 0;
			for (j = 0; j < n; j++)
				if (a[i][j] != 0)
				{
					for (k = 0; k < n; k++)
					{// Doi cot j voi cot i
						c[k] = a[k][i];
						a[k][i] = a[k][j];
						a[k][j] = c[k];
					}
					dem++;// dem so lan doi cot
					kt++;// Kiem tra xem co so 0 o dong i cot j
					break;
				}
		}
		if (kt == 0) return 0;
		b[i] = a[i][i];
		for (j = 0; j < n; j++) a[i][j] = a[i][j] / b[i];//tao so 1 o dong i,cot i
		for (j = i + 1; j < n; j++)
		{
			h = a[j][i];
			for (k = 0; k < n; k++) a[j][k] = a[j][k] - h * a[i][k];//lay dong thu j-h*dong i
		}
	}
	b[n - 1] = a[n - 1][n - 1];
	for (i = 0; i < n; i++) det = det * b[i];// Nhan cac so da lay ra ngoai dinh thuc
	if (dem % 2 == 0) return det;
	else return -det;
}
void Matrix::nghichdao(float a[][100], int n) {

	float b[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			b[i][j] = con(a, n, i, j);
		}
	}
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			float t = b[i][j];
			b[i][j] = b[j][i];
			b[j][i] = t;
		}
	float k = det(a, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			b[i][j] /= k;
	if (k == 0) cout << "\nkhong co ma tran nghich dao!";
	else xuatmat(b, n);
}

float Matrix::con(float a[][100], int n, int h, int c)
{
	float b[100][100];
	int i, j, x = -1, y;
	for (i = 0; i < n; i++)
	{
		if (i == h) continue;
		x++; y = -1;
		for (j = 0; j < n; j++)
		{
			if (j == c)continue;
			y++;
			b[x][y] = a[i][j];
		}
	}
	if ((h + c) % 2 == 0) return det(b, n - 1);
	return -det(b, n - 1);
}
int Matrix::hang() {
	//Dua ma tran ve ma tran tam giac tren
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (matrix[i][j] == 0)
				for (int k = i + 1; k < n; k++)
					if (matrix[k][j] != 0) {
						for (int u = 0; u < n; u++) {
							float t = matrix[i][u];
							matrix[i][u] = matrix[k][u];
							matrix[k][u] = t;
						}
						break;
					}
			if (matrix[i][j] != 0) {
				for (int k = i + 1; k < n; k++) {
					double tl = (double)matrix[k][j] / matrix[i][j];
					for (int u = 0; u < n; u++) {
						matrix[k][u] -= matrix[i][u] * tl;
					}
				}
				break;
			}
		}
	}
	//Tim hang (dem hang chua phan tu != 0 co chi so lon nhat, chi so do chinh la hang cua ma tran
	int r = 0;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++)
			if (abs(matrix[i][j]) != 0) {
				r = i + 1;
				break;
			}
		if (r > 0) break;
	}
	return r;
}

void Matrix::nhanMT_MT(float b[100][100],int soHang) {
	

	cout << "nhập ma trận cần tính tích: " << endl;
	nhapmat(b, n);
	cout << "Ma tran ban vua nhap la:";
	xuatmat(b, n);
	float tong[100][100];
	for (int i = 0; i < soHang; i++)
		for (int j = 0; j < soHang; j++) {
			for (int k = 0; k < n; k++)
				tong[i][j] += matrix[i][k] * b[k][j];
		}
	cout << "Tich cua ma tran A va ma tran B la:";
	xuatmat(tong, n);
}

// Giair hệ phương trình
/*Nhap ma tran he so tu do*/
void Matrix:: Nhap(float B[100], int n) {
	for (int i = 0; i < n; i++) {
		cout << "b[" << i << "] = ";
		cin >> B[i];
	}
}
/*Xuat ma tran he so tu do*/
void Matrix:: Xuat(float B[100], int n) {
	cout << "(";
	for (int i = 0; i < n - 1; i++)
		cout << B[i] << ",";
	cout << B[n - 1] << ")";
}
/*Xuat nghiem*/
void Matrix::XuatNghiem(float X[], int n, char* s) {
	cout << "\nNghiem cua he A.X = B\n";
	for (int i = 0; i < n; i++)
		cout << s << i + 1 << " = " << X[i] << endl;
}

char Matrix:: HeTamGiacDuoi(float A[100][100], float X[100], float B[100], int n) {
	for (int i = 0; i < n; i++) {
		if (A[i][i] != 0) {
			if (i == 0)
				X[i] = B[i] / A[i][i];
			else {
				X[i] = B[i];
				for (int j = 0; j < i; j++)
					X[i] = X[i] - A[i][j] * X[j];
				X[i] = X[i] / A[i][i];
			}
		}
		else
			return 0;
	}
	return 1;
}

char Matrix::HeTamGiacTren(float A[100][100], float X[100], float B[100], int n) {
	for (int i = n - 1; i >= 0; i--) {
		if (A[i][i] != 0) {
			if (i == n - 1)
				X[i] = B[i] / A[i][i];
			else {
				X[i] = B[i];
				for (int j = i + 1; j < n; j++)
					X[i] = X[i] - A[i][j] * X[j];
				X[i] = X[i] / A[i][i];
			}
		}
		else
			return 0;
	}
	return 1;
}

void Matrix::PhanRaLU(float A[100][100], float L[100][100], float U[100][100], int n) {
	for (int k = 0; k < n; k++) {
		U[k][k] = A[k][k];
		L[k][k] = 1;
		for (int i = k + 1; i < n; i++) {
			L[i][k] = A[i][k] / U[k][k];
			U[k][i] = A[k][i];
			U[i][k] = 0;
			L[k][i] = 0;
		}
		for (int i = k + 1; i < n; i++)
			for (int j = k + 1; j < n; j++)
				A[i][j] = A[i][j] - L[i][k] * U[k][j];
	}
}

/*Giai he phuong trinh tong quat LUX=B*/
void Matrix::GiaiHePTTT(float A[100][100], float X[100], float B[100], int n) {
	float L[100][100], U[100][100], Y[100];
	cout << "Phan ra A = L.U\n";
	PhanRaLU(A, L, U, n);
	cout << "Ma tran L";
	xuatmat(L, n);
	cout << "\nMa tran U";
	xuatmat(U, n);
	cout << "\nGiai LY = B. Nghiem Y";
	if (HeTamGiacDuoi(L, Y, B, n)) {
		XuatNghiem(Y, n, "\ny");
		cout << "\nGiai UX = Y. Nghiem X";
		if (HeTamGiacTren(U, X, Y, n))
			XuatNghiem(X, n, "\nx");
		else
			cout << "\nHe pttt k co nghiem duy nhat";
	}
	else
		cout << "\nHe pttt k co nghiem duy nhat";
}