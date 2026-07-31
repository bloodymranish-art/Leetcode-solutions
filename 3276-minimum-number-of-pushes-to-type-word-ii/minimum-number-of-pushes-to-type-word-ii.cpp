class Solution {
public:
    int minimumPushes(string word) {
        int f[26] = {0};
        for (auto& w : word)
            f[(w & 31) - 1]++;

        int res = 0, x = 26;
        for (int n = 1; n <= 1 << 2; n++) {
            for (int i = 0; i < 1 << 3; i++) {
                int m = 0, k = 0;

                for (int j = 0; j < x; j++)
                    if (f[j] > m) {
                        m = f[j];
                        k = j;
                    }

                if (!m) break;

                f[k] = exchange(f[--x], 0);
                res += m * n;
            }
        }

        return res;
    }
};