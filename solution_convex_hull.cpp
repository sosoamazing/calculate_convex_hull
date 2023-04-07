#include<vector>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<algorithm>
#include"solution_convex_hull.h"

#define N 0xfffffffe

using namespace std;

solution_convex_hull::solution_convex_hull(int number) : n(number)
{
    a = get_array(a, n); 
    for (int i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
    get_convex_hull();
}

solution_convex_hull::solution_convex_hull()
{
    cin >> n;
    a = new Point[n];
    for (int i = 0; i < n; i++)cout << a[i] << " ";
    cout << endl;
    calculate_convex_hull(0, n - 1);
}

solution_convex_hull::~solution_convex_hull()
{
    delete[]a;
}

vector<int> solution_convex_hull::calculate_convex_hull(int l, int r)
{
    vector<int> v;
    if (r - l + 1 <= 3)
    {
        while (l <= r)
        {
            v.emplace_back(l);
            l++;
        }
        return v;
    }
    int mid = (l + r) / 2;
    vector<int> left = calculate_convex_hull(l, mid);
    vector<int> right = calculate_convex_hull(mid + 1, r);
    int m = left.size(), n = right.size();
    int i = m - 2, j = 1;
    int pl1 = m - 1, pr1 = 0;
    while (0 <= i || j < n)
    {//cout << i << " " << j << endl;
        while (i >= 0 && !a[left[i]].is_in_left(a[left[pl1]], a[right[pr1]]))i--;
        if (i >= 0)pl1 = i;
        while (j < n && !a[right[j]].is_in_left(a[left[pl1]], a[right[pr1]]))j++;
        if (j < n)pr1 = j;
    }
    int pl2 = m - 1, pr2 = 0;
    i = m - 2; j = 1; cout << "right" << endl;
    while (0 <= i || j < n)
    {//cout << i << " " << j << endl;
        while (j < n && !a[right[j]].is_in_left(a[right[pr2]], a[left[pl2]]))j++;
        if (j < n)pr2 = j;
        while (i >= 0 && !a[left[i]].is_in_left(a[right[pr2]], a[left[pl2]]))i--;
        if (i >= 0)pl2 = i;
    }
    for (auto& p : left)
    {
        if (a[p].is_in_left(a[left[pl2]], a[left[pl1]]))v.push_back(p);
    }
    for (auto& p : right)
    {
        if (a[p].is_in_left(a[right[pr1]], a[right[pr2]]))v.push_back(p);
    }
    return v;
}

void solution_convex_hull::get_convex_hull()
{
    sort(a, a + n);
    ans = calculate_convex_hull(0, n - 1);
}

void solution_convex_hull::print_convex_hull()
{
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[ans[i]] << " , ";
    }
    cout << a[ans.back()];
}