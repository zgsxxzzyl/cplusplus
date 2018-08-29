#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip> 
#include <fstream>
using namespace std;

//����ģ�������BMPͼ��(��ɫͼ����24bit RGB��8bit)�����ػ�ȡ���������ļ���Ϊxiang_su_zhi.txt��

unsigned char *pBmpBuf;//����ͼ�����ݵ�ָ��

int bmpWidth;//ͼ��Ŀ�
int bmpHeight;//ͼ��ĸ�
RGBQUAD *pColorTable;//��ɫ��ָ��

int biBitCount;//ͼ�����ͣ�ÿ����λ��

			   //��ͼ���λͼ���ݡ����ߡ���ɫ��ÿ����λ�������ݽ��ڴ棬�������Ӧ��ȫ�ֱ�����
bool readBmp(char *bmpName)
{
	FILE *fp = fopen(bmpName, "rb");//�����ƶ���ʽ��ָ����ͼ���ļ�

	if (fp == 0)
		return 0;

	//����λͼ�ļ�ͷ�ṹBITMAPFILEHEADER
	fseek(fp, sizeof(BITMAPFILEHEADER), 0);

	//����λͼ��Ϣͷ�ṹ��������ȡλͼ��Ϣͷ���ڴ棬����ڱ���head��
	BITMAPINFOHEADER head;

	fread(&head, sizeof(BITMAPINFOHEADER), 1, fp); //��ȡͼ����ߡ�ÿ������ռλ������Ϣ

	bmpWidth = head.biWidth;
	bmpHeight = head.biHeight;
	biBitCount = head.biBitCount;//�������������ͼ��ÿ��������ռ���ֽ�����������4�ı�����

	int lineByte = (bmpWidth * biBitCount / 8 + 3) / 4 * 4;//�Ҷ�ͼ������ɫ������ɫ�����Ϊ256

	if (biBitCount == 8)
	{
		//������ɫ������Ҫ�Ŀռ䣬����ɫ����ڴ�
		pColorTable = new RGBQUAD[256];
		fread(pColorTable, sizeof(RGBQUAD), 256, fp);
	}

	//����λͼ��������Ҫ�Ŀռ䣬��λͼ���ݽ��ڴ�
	pBmpBuf = new unsigned char[lineByte * bmpHeight];
	fread(pBmpBuf, 1, lineByte * bmpHeight, fp);

	fclose(fp);//�ر��ļ�

	return 1;//��ȡ�ļ��ɹ�
}


//����һ��ͼ��λͼ���ݡ����ߡ���ɫ��ָ�뼰ÿ������ռ��λ������Ϣ,����д��ָ���ļ���
bool saveBmp(char *bmpName, unsigned char *imgBuf, int width, int height, int biBitCount, RGBQUAD *pColorTable)
{
	//���λͼ����ָ��Ϊ0����û�����ݴ��룬��������
	if (!imgBuf)
		return 0;

	//��ɫ���С�����ֽ�Ϊ��λ���Ҷ�ͼ����ɫ��Ϊ1024�ֽڣ���ɫͼ����ɫ���СΪ0
	int colorTablesize = 0;

	if (biBitCount == 8)
		colorTablesize = 1024;

	//���洢ͼ������ÿ���ֽ���Ϊ4�ı���
	int lineByte = (width * biBitCount / 8 + 3) / 4 * 4;

	//�Զ�����д�ķ�ʽ���ļ�
	FILE *fp = fopen(bmpName, "wb");

	if (fp == 0)
		return 0;

	//����λͼ�ļ�ͷ�ṹ��������д�ļ�ͷ��Ϣ
	BITMAPFILEHEADER fileHead;

	fileHead.bfType = 0x4D42;//bmp����

							 //bfSize��ͼ���ļ�4����ɲ���֮��
	fileHead.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + colorTablesize + lineByte*height;

	fileHead.bfReserved1 = 0;
	fileHead.bfReserved2 = 0;

	//bfOffBits��ͼ���ļ�ǰ3����������ռ�֮��
	fileHead.bfOffBits = 54 + colorTablesize;

	//д�ļ�ͷ���ļ�
	fwrite(&fileHead, sizeof(BITMAPFILEHEADER), 1, fp);
	//����λͼ��Ϣͷ�ṹ��������д��Ϣͷ��Ϣ
	BITMAPINFOHEADER head;

	head.biBitCount = biBitCount;
	head.biClrImportant = 0;
	head.biClrUsed = 0;
	head.biCompression = 0;
	head.biHeight = height;
	head.biPlanes = 1;
	head.biSize = 40;
	head.biSizeImage = lineByte*height;
	head.biWidth = width;
	head.biXPelsPerMeter = 0;
	head.biYPelsPerMeter = 0;

	//дλͼ��Ϣͷ���ڴ�
	fwrite(&head, sizeof(BITMAPINFOHEADER), 1, fp);

	//����Ҷ�ͼ������ɫ��д���ļ� 
	if (biBitCount == 8)
		fwrite(pColorTable, sizeof(RGBQUAD), 256, fp);

	//дλͼ���ݽ��ļ�
	fwrite(imgBuf, height*lineByte, 1, fp);

	//�ر��ļ�
	fclose(fp);

	return 1;

}


//����Ϊ���صĶ�ȡ����
void doIt()
{

	//����ָ��BMP�ļ����ڴ棬ע��Ҫ��"nv.BMP"�ļ��͡�Դ.cpp"�������ͬһ���ļ�����
	char readPath[] = "nv.BMP";
	readBmp(readPath);

	//���ͼ�����Ϣ
	cout << "width=" << bmpWidth << " height=" << bmpHeight << " biBitCount=" << biBitCount << endl;

	//ѭ��������ͼ�������
	//ÿ���ֽ���

	int lineByte = (bmpWidth*biBitCount / 8 + 3) / 4 * 4;

	//ѭ����������Բ�ɫͼ�񣬱���ÿ���ص���������
	int m = 0, n = 0, count_xiang_su = 0;

	//��ͼ�����½�1/4�����óɺ�ɫ
	ofstream outfile("ͼ������.txt", ios::in | ios::trunc);

	if (biBitCount == 8) //���ڻҶ�ͼ��
	{
		//�������ͼ��ķָ��8*8С��Ԫ����������ֵ�洢��ָ���ı��С�����BMPͼ������������Ǵ�
		//���½ǣ��������ң�������������ɨ���
		int L1 = 0;
		int hang = 63;
		int lie = 0;
		//int L2=0;
		//int fen_ge=8;
		for (int fen_ge_hang = 0; fen_ge_hang<8; fen_ge_hang++)//64*64������ѭ��
		{
			for (int fen_ge_lie = 0; fen_ge_lie<8; fen_ge_lie++)//64*64�о���ѭ��
			{
				for (L1 = hang; L1>hang - 8; L1--)//8*8������
				{
					for (int L2 = lie; L2<lie + 8; L2++)//8*8������
					{
						m = *(pBmpBuf + L1*lineByte + L2);
						outfile << m << " ";
						count_xiang_su++;
						if (count_xiang_su % 8 == 0)//ÿ8*8��������ı��ļ�
						{
							outfile << endl;
						}
					}
				}

				hang = 63 - fen_ge_hang * 8;//64*64�����б任
				lie += 8;//64*64�����б任,��һ�У�64����8��8*8����������
			}
			hang -= 8;//64*64������б任
			lie = 0;//64*64juzhen
		}
	}

	//double xiang_su[2048];
	//ofstream outfile("xiang_su_zhi.txt",ios::in|ios::trunc);
	if (!outfile)
	{
		cout << "open error!" << endl;
		exit(1);
	}
	else if (biBitCount == 24)
	{   //��ɫͼ��
		for (int i = 0; i<bmpHeight; i++)
		{
			for (int j = 0; j<bmpWidth; j++)
			{
				for (int k = 0; k<3; k++)//ÿ����RGB���������ֱ���0�ű�ɺ�ɫ
				{
					//*(pBmpBuf+i*lineByte+j*3+k)-=40;
					m = *(pBmpBuf + i*lineByte + j * 3 + k);
					outfile << m << " ";
					count_xiang_su++;
					if (count_xiang_su % 8 == 0)
					{
						outfile << endl;
					}

				}
				n++;
			}

		}
		cout << "�ܵ����ظ���Ϊ(����С):" << n << endl;

	}

	//��ͼ�����ݴ���
	char writePath[] = "nvcpy.BMP";//ͼƬ������ٴ洢
	saveBmp(writePath, pBmpBuf, bmpWidth, bmpHeight, biBitCount, pColorTable);

	//�����������pBmpBuf��pColorTable��ȫ�ֱ��������ļ�����ʱ����Ŀռ�
	delete[]pBmpBuf;

	if (biBitCount == 8)
		delete[]pColorTable;
}

//void main()
//{
//	doIt();
//	system("pause");
//}