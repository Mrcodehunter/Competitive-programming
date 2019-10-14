struct matrix
{

    int r;
    int c;
    vector< vector <int> >mat;

    matrix(vector< vector <int > > A): mat(A),r(A.size()),c(A[0].size()) {}

    static matrix idmat(int n)
    {
      vector<vector<int> > I (n,vector<int>(n,0));
      for(int i=0;i<n;i++)I[i][i]=1;
      return matrix(I);
    }

    matrix operator * (matrix P)
    {
      int rw=r;
      int cl=P.c;
      int x=c;
      vector< vector < int > > temp(rw,vector<int> (cl,0));

      for(int i=0;i<rw;i++)
      {
        for(int j=0;j<cl;j++)
        {
          for(int k=0;k<x;k++)

            temp[i][j]=((temp[i][j]+mat[i][k]*P.mat[k][j])%mod+mod)%mod;
        }
      }
      return matrix(temp);

    }

  friend  ostream&  operator << (ostream &out, matrix X);




};

ostream& operator << (ostream &out, matrix X)
{
  for(int i=0;i<X.r;i++)
  {
    if(i)cout<<"\n";
    for(int j=0;j<X.c;j++)cout<<X.mat[i][j]<<" ";
  }
}


matrix matrix_expo(int p,matrix R,int d)
{
  matrix ret=R.idmat(d);
  while(p)
  {
    if(p&1)
    {
      ret= ret* R;
    }
    p/=2;
    R=R * R;
  }
  return ret;
}

int32_t main()
{

    matrix X(
             {
               {0,1,1,1},
               {1,0,1,1},
               {1,1,0,1},
               {1,1,1,0}

             }
             );


             int n;
             cin>>n;
             cout<<matrix_expo(n,X).mat[0][0]<<endl;

    return 0;
}

