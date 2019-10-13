#include<iostream>
#include<vector>
using namespace std;
class Matrix{
protected:
	vector<vector<int>>mat1;//�洢��ʼ������
	int row,col;
public:
	Matrix(){row=this->row;col=this->col;};//�޲ι��캯��
	Matrix(int a,int b):row(a),col(b){
		mat1.resize(row,vector<int>(col));
		cout<<"����������"<<row<<"*"<<col<<"��Ԫ��";
		for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>mat1[i][j];
	}
	friend Matrix operator*( const Matrix &x,const  Matrix &y);//��������غ���
	void show(){
		for(int i=0;i<this->row;i++){
		for(int j=0;j<this->col;j++){
			cout<<mat1[i][j]<<" ";
		}
		cout<<endl;
		}
	
	}
};
	Matrix operator*( const Matrix &x,const  Matrix &y){
	   Matrix m;//�����޲���Ĭ�Ϲ��캯��
	   m.row=x.row;//��ʼ���洢���ݵľ���������������һֱĬ��Ϊ���캯���е�ֵ
	   m.col=y.col;
	   m.mat1.resize(x.row,vector<int>(y.col));//���ô������ݵľ����С
	  
	   //����Ϊ����˷����㷨
	   for(int i=0;i<x.row;i++)
		   for(int j=0;j<y.col;j++){
			  m.mat1[i][j]=0;
			   for(int k=0;k<y.row;k++)//����������=�Ҿ��������
				   m.mat1[i][j]+=x.mat1[i][k]*y.mat1[k][j];
			   
	}
		  
			   return m;
	}
		   
	
void main(){
	Matrix m1(2,3);
	Matrix m2(3,2);
	(m1*m2).show();
	
}