/* The functions which
builds the segment tree */
void build(int l,int r,int i,int segment[],int arr[]){
    //base case
    if(l==r){
        segment[i]=arr[l];
        return ;
    }
    
    int mid=l+(r-l)/2;
    
    build(l,mid,2*i+1,segment,arr);
    build(mid+1,r,2*i+2,segment,arr);
    segment[i]=min(segment[2*i+1],segment[2*i+2]);
    
    
}
int *constructST(int arr[], int n) {
    int *segment=new int[4*n];
    
    build(0,n-1,0,segment,arr);
    
    return segment;
    
}

int query(int start,int end,int i,int l,int r,int segment[]){
    if(l>end || r<start){
        return INT_MAX;
    }
    if(l>=start && r<=end){
        return segment[i];
    }
    
    int mid=l+(r-l)/2;
    
    return min(query(start,end,2*i+1,l,mid,segment),query(start,end,2*i+2,mid+1,r,segment));
}

/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b) {
    
    return query(a,b,0,0,n-1,st);
}