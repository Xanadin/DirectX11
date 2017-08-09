#include <Windows.h> // for FLOAT definition
#include <iostream>
#include <DirectXMath.h>
using namespace std;
using namespace DirectX;

ostream& operator<< (ostream& os, FXMVECTOR v)
{
	XMFLOAT3 dest;
	XMStoreFloat3(&dest, v);
	os << "(" << dest.x << "," << dest.y << "," << dest.z << ")";
	return os;
}

void callTestDirectXMath()
{
	cout << "Chapter 1 example 1" << endl;
	XMVECTOR p = XMVectorZero();
	XMVECTOR q = XMVectorSplatOne();
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorReplicate(-2.0f);
	XMVECTOR w = XMVectorSplatZ(u);

	cout << "p=" << p << endl;
	cout << "q=" << q << endl;
	cout << "u=" << u << endl;
	cout << "v=" << v << endl;
	cout << "w=" << w << endl;
	cout << "-------------------------" << endl;
}

void callTestDirectXMath2()
{
	cout << "Chapter 1 example 2" << endl;
	XMVECTOR n = XMVectorSet(1.0f, 0.0f, 0.0f, 0.0f);
	XMVECTOR u = XMVectorSet(1.0f, 2.0f, 3.0f, 0.0f);
	XMVECTOR v = XMVectorSet(-2.0f, 1.0f, -3.0f, 0.0f);
	XMVECTOR w = XMVectorSet(0.707f, 0.707f, 0.0f, 0.0f);

	// Vector addition: XMVECTOR operator +
	XMVECTOR a = u + v;
	// Vector subtraction: XMVECTOR operator -
	XMVECTOR b = u - v;
	// Scalar multiplication: XMVECTOR operator *
	XMVECTOR c = 10.0f * u;
	// ||u|| modulo
	XMVECTOR L = XMVector3Length(u);
	// d = u / ||u|| normalizzazione
	XMVECTOR d = XMVector3Normalize(u);
	// s = u * v prodotto scalare
	XMVECTOR s = XMVector3Dot(u, v);
	// e = u x v prodotto vettoriale
	XMVECTOR e = XMVector3Cross(u, v);
	//Finf proj_n(w) and perp_n(w)
	XMVECTOR projW;
	XMVECTOR perpW;
	XMVector3ComponentsFromNormal(&projW, &perpW, w, n);
	// Does projW + perpW == w ?
	bool equ = XMVector3Equal(projW + perpW, w) != 0;
	bool notEqual = XMVector3NotEqual(projW + perpW, w) != 0;

	// The angle between projW and perpW should be 90 degrees
	XMVECTOR angleVec = XMVector3AngleBetweenVectors(projW, perpW);
	float angleRadians = XMVectorGetX(angleVec);
	float angleDegrees = XMConvertToDegrees(angleRadians);

	cout << "u                  = " << u << endl;
	cout << "v                  = " << v << endl;
	cout << "w                  = " << w << endl;
	cout << "n                  = " << n << endl;
	cout << "a = u + v          = " << a << endl;
	cout << "b = u - v          = " << b << endl;
	cout << "c = 10 * u         = " << c << endl;
	cout << "d = u / ||u||      = " << d << endl;
	cout << "e = u x v          = " << e << endl;
	cout << "L = ||u||          = " << L << endl;
	cout << "s = u * v          = " << s << endl;
	cout << "projW              = " << projW << endl;
	cout << "perpW              = " << perpW << endl;
	cout << "projW + perpW == w = " << equ << endl;
	cout << "projW + perpW != w = " << notEqual << endl;
	cout << "angle              = " << angleDegrees << endl;
	cout << "-------------------------" << endl;
}

int main()
{
	cout.setf(ios_base::boolalpha);
	//Check support for SSE2 (Pentium4, AMD K8, and above)
	if (!XMVerifyCPUSupport())
	{
		cout << "DirectX Math not supported" << endl;
		return 0;
	}

	callTestDirectXMath();
	callTestDirectXMath2();
	
	system("pause");
	return 0;
}