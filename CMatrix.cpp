#include "CMatrix.h"

/////////////////////////////////////////////////////////////////////
//
//	Matrix functions
//
/////////////////////////////////////////////////////////////////////
//create an identity matrix
void CMatrix::Identity(size_t row, size_t col)
{
	m_Matrix._11 = 1; m_Matrix._12 = 0; m_Matrix._13 = 0;

	m_Matrix._21 = 0; m_Matrix._22 = 1; m_Matrix._23 = 0;

	m_Matrix._31 = 0; m_Matrix._32 = 0; m_Matrix._33 = 1;

	}

//create a transformation matrix
void CMatrix::Translate(double x, double y)
{
	SMatrix mat;
	
	mat._11 = 1; mat._12 = 0; mat._13 = 0;
	
	mat._21 = 0; mat._22 = 1; mat._23 = 0;
	
	mat._31 = x;    mat._32 = y;    mat._33 = 1;
	
	//and multiply
  SMatrixMultiply(mat);
}

//create a scale matrix
void CMatrix::Scale(double xScale, double yScale)
{
	SMatrix mat;
	
	mat._11 = xScale; mat._12 = 0; mat._13 = 0;
	
	mat._21 = 0; mat._22 = yScale; mat._23 = 0;
	
	mat._31 = 0; mat._32 = 0; mat._33 = 1;
	
	//and multiply
  SMatrixMultiply(mat);
}


//create a rotation matrix
void CMatrix::Rotate(double rot)
{
	SMatrix mat;

	double Sin = sin(rot);
	double Cos = cos(rot);
	
	mat._11 = Cos;  mat._12 = Sin; mat._13 = 0;
	
	mat._21 = -Sin; mat._22 = Cos; mat._23 = 0;
	
	mat._31 = 0; mat._32 = 0;mat._33 = 1;
	
	//and multiply
  SMatrixMultiply(mat);
}

