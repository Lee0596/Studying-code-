int Bsearch(int *p, int n, int x){
  int low,high,mid;
  low=0,high=n-1;
  while(low<=high){
    mid=(low+high)/2;
    if(x==*(p+mid)){
      break;
    }else{
      if(x>*(p+mid)){
        low=mid+1;
      }else{
        high=mid-1;
      }
    }
  }
  if(low<=high){
    return mid;
  }else{
    return -1;
  }
}
