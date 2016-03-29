/* 成段更新
 *   设一个flags-tree,路过某个点的时候:
 *       1.如果这个点,有flag把它的信息更新到child
 *       2.到达你想到的点的时候,给flags-tree加上相应的信息
 *
 * */
/*
 *  10
 *  1 2 3 4 5 6 7 8 9 10
 *  4
 *  add 2 3 2
 *  q 1 10
 *  add 1 3 2
 *  q 1 6
 * */
#include <cstdio>
#include <cstring>

#define lson(rt) (rt<<1)
#define rson(rt) (rt<<1|1)

#define maxn 100
int tree[maxn << 2];
int flag[maxn << 2];

void pushup(int rt)
{
        tree[rt] = tree[lson(rt)] + tree[rson(rt)];
}
void pushdown(int rt)  //把m分给child,m是每个点都要加下的值
{
        if (flag[rt])
        {
                flag[lson(rt)] += flag[rt];
                flag[rson(rt)] += flag[rt];//把信息给child
                flag[rt] = 0;
        }
}

void build(int l, int r, int rt)
{
        if ( l == r)
        {
                scanf("%d", &tree[rt]);
                flag[rt] = 0;
                return ;
        }
        flag[rt] = 0;
        int m = (l + r) >> 1;
        build(l, m, lson(rt));
        build(m + 1, r, rson(rt));
        pushup(rt);
}

/* update 更新一段区间内值都加上一个数 */
void update(int L, int R, int c, int l, int r, int rt)
{
        if (L <= l && r <= R) // 在内部
        {
                flag[rt] += c;
                tree[rt] += (r - l + 1) * flag[rt];
                return ;
        }
        pushdown(rt);
        int m = (l + r) >> 1;
        if ( L <= m) update(L, R, c, l, m, lson(rt));
        if ( R > m ) update(L, R, c, m + 1, r, rson(rt));
        pushup(rt);
}

int query(int L, int R, int l, int r, int rt)
{
        if (L <= l && r <= R)
        {
                return tree[rt];
        }
        int ans = 0;
        int m = (l + r) >> 1;
        if (L <= m)
        {
                ans += query(L, R, l, m, lson(rt));
        }
        if (R > m)
        {
                ans += query(L, R, m+1, r, rson(rt));
        }
        return ans;
}

char str[100] = {0};
int main()
{
        freopen("1.in", "r", stdin);
        int n;
        scanf("%d", &n);
        build(1, n, 1);
        int m;
        int i;
        int j, k, l;
        scanf("%d", &m);
        for (i = 1; i <= m; i++)
        {
                scanf("%s", str);

                if (strcmp(str, "add") == 0)
                {
                    scanf("%d%d%d", &j, &k, &l);
                    update(j, k, l, 1, n, 1);
                }
                else if (strcmp(str, "q") == 0)
                {
                    scanf("%d%d", &j, &k);
                    int tmp = query(j, k, 1, n, 1);
                    printf("%d\n", tmp);
                }
        }
        return 0;
}
