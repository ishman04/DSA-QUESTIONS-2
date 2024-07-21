
    while(n>=0){
        int x=k%10;
        v.push_back(x);
        k=k/10;
    }
    for(int i=0;i<v.size()-1;i++){
        return 1+min(f(n-v[i]),f(n-v[i+1]));
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    cout<<f(n);
}