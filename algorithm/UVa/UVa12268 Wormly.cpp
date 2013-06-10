#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

int L, b, n;
char bridge[MAXN];
int sum[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d%s", &L, &b, &n, bridge + 1);
        for (int i = 1; i <= n; ++i)
        {
            sum[i] = sum[i - 1] + (bridge[i] == '1');
        }
        int left = 1, right = L, head = b;
        long long ans = 0;
        bool possible = false;
        if (n == L && n == b)
        {
            possible = true;
        }
        while (true)
        {
            if (right == head)
            {
                break;
            }
            for (right = head; bridge[right] == '0'; --right);
            if (sum[right] - sum[left - 1] <= L)
            {
                break;
            }
            int count = 0;
            for (; sum[right] - sum[left - 1] > L || bridge[left] == '0'; ++left, ++count);
            if (head + count < n)
            {
                ans += L + count;
                head += count;
            }
            else
            {
                possible = true;
                ans += L + n - head;
                head = n;
            }
        }
        if (possible)
        {
            printf("%lld\n", ans);
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
