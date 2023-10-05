/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in
adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n,
return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and
false otherwise.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

*/
#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int count = 0, temp = n;

    if (flowerbed.size() == 1)
    {
        if (flowerbed[0] == 0 && n == 1)
            return true;

        if (flowerbed[0] == 1)
        {
            if (n == 0)
                return true;
            else
                return false;
        }
    }

    else
    {
        if (flowerbed[0] == 0 && flowerbed[1] == 0 && n != 0)
        {
            flowerbed[0] = 1;
            count++;
            n--;
        }

        for (int i = 1; i < flowerbed.size() - 1; i++)
        {
            if (n != 0)
            {
                if (flowerbed[i] == 1)
                {
                    i++;
                    continue;
                }

                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    flowerbed[i] = 1;
                    count++;
                    n--;
                    i++;
                }
            }
            else
                break;
        }
        if (flowerbed[flowerbed.size() - 1] == 0 && flowerbed[flowerbed.size() - 2] == 0 && n != 0)
        {
            flowerbed[flowerbed.size() - 1] = 1;
            count++;
            n--;
        }
    }
    return (count == temp);
}

int main()
{
    // vector<int> flowerbed = {1, 0, 0, 0, 1, 0, 0};
    // int n = 2;

    vector<int> flowerbed = {0,0,0,1} ;
    int n = 1  ;

    cout << "\nBefore Flowerbed : ";
    for (int i = 0; i < flowerbed.size(); i++)
        cout << flowerbed[i] << " ";

    cout << "\nCan We Place : " ;
    cout << canPlaceFlowers(flowerbed, n);

    cout << "\nAfter Flowerbed : ";
    for (int i = 0; i < flowerbed.size(); i++)
        cout << flowerbed[i] << " ";
}