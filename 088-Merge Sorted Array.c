void merge(int* nums1, int m, int* nums2, int n) {
    int* aux = (int*)malloc(sizeof(int) * m);
    int i, j, k;
    for(i = 0; i < m; i++){
        aux[i] = nums1[i];
    }
    i = j = k = 0;
    while(k < m + n){
            if(i < m && j < n){
                if(aux[i] <= nums2[j]) {
                    nums1[k] = aux[i];
                    i++;
            }
            else{
                nums1[k] = nums2[j];
                j++;
            }
        }
        else if(i >= m){
            nums1[k] = nums2[j];
            j++;
        }
        else {
            nums1[k] = aux[i];
            i++;
        }
        k++;
    }
    free(aux);
    return;
}
