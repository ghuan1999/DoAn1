#pragma once
#include<iostream>

using namespace std;

class Matrix
{
private:
	float matrix[100][100];
	int n;

public:
	void nhapmat(float a[][100], int n);
	void xuatmat(float a[][100], int n);
	float det(float a[][100], int n);
	void nghichdao(float a[][100], int n);
	float con(float a[][100], int n, int h, int c);
	int hang();
	void nhanMT_MT(float b[100][100], int soHang);
	//tìm hệ số tuyến tính
	/*Nhap ma tran he so tu do*/
	void Nhap(float B[100], int n);
	/*Xuat ma tran he so tu do*/
	void Xuat(float B[100], int n);
	//xuất nghiêm ma trận
	void XuatNghiem(float X[], int n, char* s);
	char HeTamGiacDuoi(float A[100][100], float X[100], float B[100], int n);
	char HeTamGiacTren(float A[100][100], float X[100], float B[100], int n);
	void PhanRaLU(float A[100][100], float L[100][100], float U[100][100], int n);
	void GiaiHePTTT(float A[100][100], float X[100], float B[100], int n);
};

