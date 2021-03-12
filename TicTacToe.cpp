
#include <iostream>
#include <string>

using namespace std;
int point(char *khune)
{
        for(int i = 0; i < 3; i++) 
        {
            if(khune[i] == 'x' && khune[i + 3] == 'x' && khune[i + 6] == 'x')
            {
                return -10;
            }
            else if(khune[i] == 'o' && khune[i + 3] == 'o' && khune[i + 6] == 'o')
            {
                return 10;
            }
        }
        if((khune[0] == 'x' && khune[4] == 'x' && khune[8] == 'x') || (khune[2] == 'x' && khune[4] == 'x' && khune[6] == 'x'))
        {
                return -10;
        }
        else if((khune[0] == 'o' && khune[4] == 'o' && khune[8] == 'o') || (khune[2] == 'o' && khune[4] == 'o' && khune[6] == 'o'))
        {
                return 10;
        }
        for(int i = 0; i < 9; i += 3)
        {
            if(khune[i] == 'x' && khune[i + 1] == 'x' && khune[i + 2] == 'x')
            {
                return -10;
            }
            else if(khune[i] == 'o' && khune[i + 1] == 'o' && khune[i + 2] == 'o')
            {
                return 10;
            }
        }
        return 0;
}
void xo(int *a, char *home, int j, int counter, int moves)
{
    cout<<moves;
    static int max_point[9]={0};
    static int shit[9];
    static char khune[9];
    /*static int moves = 0;
    if(j == 0 && counter == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            khune[i] = home[i];
            if(a[i] < 1000)
            moves ++;
        }
    }*/
    if(j == 0 && counter == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            if(khune[i] != 'b')
            {
                max_point[i] = -10000;
            }
        }
    }
    for(int k = j; k < 9; k ++)
    {
        if(khune[k] != 'o' && khune[k] != 'x' && counter % 2 == 1)
        {
            khune[k] = 'o';
            shit[counter] = k;
            break;
        }
        else if(khune[k] != 'o' && khune[k] != 'x' && counter % 2 == 0)
        {
            khune[k] = 'x';
            shit[counter] = k;            
            break;      
        }
    }
    //cout<<moves;
    int score = point(khune);
    if(score == 0 && counter != 8-moves)
    {
        cout<<"khali mosavi";
        counter ++;
        return xo(a, home, 0, counter, moves);
    }
    else if(counter == 8-moves)
    {
        int x = 1000;
        for (int i = counter; i > 0; i--)
        {
            //cout<<shit[i];
            if(shit[i] > shit[i-1])
            {
                x = i-1;
                break;
            }
        }
        if(x != 1000)
        {
            for (int i = x; i <= counter; i++)
            {
                khune[shit[i]] = 'b';            
            }
            max_point[shit[0]] += score;
            cout<<"por1";
            return xo(a, home, shit[x]++, x, moves);
        }
        else
        {
            int z = 0;
            int min = -10000;
            for (int i = 0; i < 9; ++i)
            {
                //cout<<max_point[i] << "\n";
                if(max_point[i] > min)
                {
                    min = max_point[i];
                    z = i;
                }
            }
            moves = 0;
            cout<<"por2";
            //return z;
        }
    }
    else if(score != 0 && counter != 8 - moves)
    {
        int x = 0;
        for(int i = counter; i >= 0 ; i--)
        {
            if(khune[shit[i]+1] != 0)
            {
                x = i;
                break;
            }
        }
        for (int i = x; i <= counter; i++)
        {
            khune[shit[i]] = 'b';            
        }
        max_point[shit[0]] += score;
        cout<<"bord khali";
        return xo(a, home, shit[x]++, x, moves);
    }
}
int main()
{
    char khune[9];
    for(int i = 0; i < 9; i++)
    {
        khune[i] = 'b';
    }
    int a[9];
    fill_n(a, 9, 1000);
    for(int i = 0; i < 9; i++)
    {
        if(i%2 == 0)
        {
            cin >> a[i];
            khune[a[i]] = 'x';
        }
        else
        {
            xo(a, khune, 0, 0, i);
            /*int z = xo(a, khune, 0, 0);
            cout << z;
            a[i+1] = z;
            khune[z] = 'o';*/
        }
    }  
    return 0;
}

