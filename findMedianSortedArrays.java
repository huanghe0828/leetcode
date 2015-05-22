public class Solution {
    public double findMedianSortedArrays(int[] A, int[] B) {
        int total = A.length + B.length;
        if (total%2 == 1) return findKth(A, B, 0, A.length, 0, B.length, total/2+1);
        else return (findKth(A, B, 0, A.length, 0, B.length, total/2)+findKth(A, B, 0, A.length, 0, B.length, total/2+1))/2;
    }
    private double findKth(int[] A, int[] B, int s1, int m, int s2, int n, int k) {
        if (m > n) return findKth(B, A, s2, n, s1, m, k);
        if (m == 0) return (double) B[k-1];
        int m1 = Math.min(m, k/2);
        int m2 = k - m1;
        if (n == 0) return (double) A[k-1];
        if (k == 1) return (double) Math.min(A[s1], B[s2]);
        if (A[s1+m1-1] <= B[s2+m2-1]) return findKth(A, B, s1+m1, m-m1, s2, n, k-m1);
        else return findKth(A, B, s1, m, s2+m2, n-m2, k-m2);
    }
}
