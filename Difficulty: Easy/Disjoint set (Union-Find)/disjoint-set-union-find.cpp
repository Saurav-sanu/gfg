/*Complete the functions below*/

int find(int par[], int x) {
    if(x==par[x]){
        return x;
    }
    return par[x]=find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    ///by ra
    
    int x_parent=find(par,par[x]);
    int y_parent=find(par,par[z]);
    
    if(x_parent!=y_parent){
        par[x_parent]=y_parent;
        
    }
   
}


