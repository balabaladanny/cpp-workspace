const int mod = 10007;
Matrix::Matrix(int r, int c)
{
    row = r;
    col = c;
    memset(mat, 0, sizeof(mat));
}

int *Matrix::operator[] (const int &x)
{
    return mat[x];
}

Matrix Matrix:: operator+ (const Matrix &x) const{
    Matrix res(row,col);
    for(int i = 0 ; i < row ; i++) for(int j = 0 ; j < col ; j++)
        res[i][j] = (((mat[i][j]+x[i][j])%mod)+mod)%mod;
    return res;
}

Matrix operator* (const Matrix &x, const Matrix &y){
    Matrix res(x.row,y.col);
    for(int i = 0 ; i < x.row ; i++) for(int j = 0 ; j < x.col ; j++) for(int k=0 ; k < y.col ; k++){
        res[i][k] += ((x[i][j]*y[j][k])%mod + mod)%mod;
        res[i][k] = (res[i][k]%mod +mod)%mod;
    }
    return res;
}