class Solution {
    public long countCommas(long n) {
        long totalComma = 0;
        
        if (n >= 1000) {
            long count = Math.min(n, 999999L) - 1000L + 1;
            totalComma += count * 1;
        }
        if (n >= 1000000) {
            long count = Math.min(n, 999999999L) - 1000000L + 1;
            totalComma += count * 2;
        }
        if (n >= 1000000000) {
            long count = Math.min(n, 999999999999L) - 1000000000L + 1;
            totalComma += count * 3;
        }
        if (n >= 1000000000000L) {
            long count = Math.min(n, 999999999999999L) - 1000000000000L + 1;
            totalComma += count * 4;
        }
        if (n >= 1000000000000000L) {
            long count = Math.min(n, 99999999999999999L) - 1000000000000000L + 1;
            totalComma += count * 5;
        }
        return totalComma;
    }
}