#include <iostream>

using namespace std;

class DiagonalMatrix
{
private:
    int *A;
    int n;
public:
    DiagonalMatrix()
    {
        A = new int[2];
        int n=2;
    }
    DiagonalMatrix(int n)
    {
        this->n=n;
        A = new int[n];
    }
    ~DiagonalMatrix()
    {
        delete []A;
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    int GetDimension();
};
class LowerTriangularMatrix
{
private:
    int *A;
    int n;
public:
     LowerTriangularMatrix(int n)
     {
         this->n=n;
         int Size=(n*(n+1))/2;
         A = new int[Size];
     }
     ~LowerTriangularMatrix()
     {
         delete []A;
     }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};
class UpperTriangularMatrix
{
private:
    int *A;
    int n;
public:
     UpperTriangularMatrix(int n)
     {
         this->n=n;
         int Size=(n*(n+1))/2;
         A = new int[Size];
     }
     ~UpperTriangularMatrix()
     {
         delete []A;
     }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};
class SymmetricMatrix
{
private:
    int *A;
    int n;
public:
     SymmetricMatrix(int n)
     {
         this->n=n;
         int Size=(n*(n+1))/2;
         A = new int[Size];
     }
     ~SymmetricMatrix()
     {
         delete []A;
     }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};
class TriDiagonalMatrix
{
private:
    int *A;
    int n;
public:
     TriDiagonalMatrix(int n)
     {
         this->n=n;
         int Size=((3*n)-2);
         A = new int[Size];
     }
     ~TriDiagonalMatrix()
     {
         delete []A;
     }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};
class ToeplitzMatrix
{
private:
    int *A;
    int n;
public:
     ToeplitzMatrix(int n)
     {
         this->n=n;
         int Size=(2*n)-1;
         A = new int[Size];
     }
     ~ToeplitzMatrix()
     {
         delete []A;
     }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
};
int main()
{

    DiagonalMatrix dm(5);
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            dm.Set(i, j, i+1);
        }
    }
    dm.Display();
    cout << endl;

    LowerTriangularMatrix ltm(5);
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++)
        {
            ltm.Set(i, j, (i+j));
        }
    }
    ltm.Display();
    cout << endl;

    UpperTriangularMatrix utm(5);
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++)
        {
            utm.Set(i, j, (i+j));
        }
    }
    utm.Display();
    cout << endl;

    SymmetricMatrix sm(5);
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++)
        {
            sm.Set(i, j, std::min(i, j));
        }
    }
    sm.Display();
    cout << endl;

    TriDiagonalMatrix tdm(5);
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            tdm.Set(i, j, 5);
        }
    }
    tdm.Display();
    cout << endl;

    ToeplitzMatrix tm(5);
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=5;j++)
        {
            tm.Set(i, j, i-j+5);
        }
    }
    tm.Display();
    cout << endl;

    return 0;
}

void ToeplitzMatrix::Set(int i, int j, int x)
{
    int loc=(i-j+n-1);A[loc]=x;
}
int ToeplitzMatrix::Get(int i, int j)
{
    int loc=(i-j+n-1); return A[loc];
}
void ToeplitzMatrix::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int loc=(i-j+n-1);cout << A[loc] << " ";
        }
        cout << endl;
    }
}


void TriDiagonalMatrix::Set(int i, int j, int x)
{
    if((i-j)==1){int loc=i-2;A[loc]=x;}
    else if(i==j){int loc=n+i-2;A[loc]=x;}
    else if((i-j)==(-1)){int loc=((2*n)+i-2);A[loc]=x;}
}
int TriDiagonalMatrix::Get(int i, int j)
{
    if((i-j)==1){int loc=i-2; return A[loc];}
    else if(i==j){int loc=n+i-2; return A[loc];}
    else if((i-j)==-1){int loc=((2*n)+i-2);return A[loc];}
    else{return 0;}
}
void TriDiagonalMatrix::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i-j)==1){int loc=i-2;cout << A[loc] << " ";}
    else if(i==j){int loc=n+i-2;cout << A[loc] << " ";}
    else if((i-j)==-1){int loc=((2*n)+i-2);cout << A[loc] << " ";}
    else{cout << "0 ";}
        }
        cout << endl;
    }
}



void SymmetricMatrix::Set(int i, int j, int x)
{
    if(i>=j){int loc=( (((i-1)*i)/2) + (j-1) );A[loc]=x;}
}
int SymmetricMatrix::Get(int i, int j)
{
    if(i>=j){int loc=( (((i-1)*i)/2) + (j-1) );return A[loc];}
    else{int loc=( (((j-1)*j)/2) + (i-1) );return A[loc];}
}
void SymmetricMatrix::Display()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){int loc=( (((i-1)*i)/2) + (j-1) );cout << A[loc] << " ";}
    else{int loc=( (((j-1)*j)/2) + (i-1) );cout << A[loc] << " ";}
        }
        cout << endl;
    }
}


void UpperTriangularMatrix::Set(int i, int j, int x)
{
    if(j>=i){int loc=( (((j-1)*j)/2) + (i-1) );A[loc]=x;}
}
int UpperTriangularMatrix::Get(int i, int j)
{
    if(j>=i){int loc=( (((j-1)*j)/2) + (i-1) );return A[loc];}
    else{return 0;}
}
void UpperTriangularMatrix::Display()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>=i){int loc=( (((j-1)*j)/2) + (i-1) );cout << A[loc] << " ";}
    else{cout << "0 ";}
        }
        cout << endl;
    }
}



void DiagonalMatrix::Set(int i, int j, int x)
{
    if(i==j){A[i]=x;}
}
int DiagonalMatrix::Get(int i, int j)
{
    if(i==j){return A[i];}
    else{return 0;}
}
void DiagonalMatrix::Display()
{
    int i, j;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j){cout << A[i] << " ";}
            else{cout << "0 ";}
        }
        cout << endl;
    }
}
int DiagonalMatrix::GetDimension()
{
    return n;
}



void LowerTriangularMatrix::Set(int i, int j, int x)
{
    if(i>=j){int loc=( (((i-1)*i)/2) + (j-1) );A[loc]=x;}
}
int LowerTriangularMatrix::Get(int i, int j)
{
    if(i>=j){int loc=( (((i-1)*i)/2) + (j-1) );return A[loc];}
    else{return 0;}
}
void LowerTriangularMatrix::Display()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j){int loc=( (((i-1)*i)/2) + (j-1) );cout << A[loc] << " ";}
    else{cout << "0 ";}
        }
        cout << endl;
    }
}
