class CMyVector{
public:
    //...
    CMyVector& operator=(const CMyVector&){
        //...
        //- Make a clone to what m_pArr refers to
        //- Destruct the resource that m_pArr refers to
        //- Attach the cloned resource to m_pArr
        //...
    }
private:
    int* m_pArr;
};

CMyVector foo(){
    return CMyVector();
}

int main(){
    CMyVector x;
    //... do some stuff with x
    x = foo();
    //...
}