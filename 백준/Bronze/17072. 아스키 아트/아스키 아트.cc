#include <iostream>
using namespace std;

class RGB {
public:
    long long R;
    long long G;
    long long B;
    long long intensity = 0;

    void IntensityFunc() {
        intensity = static_cast<long long>(2126) * R + static_cast <long long>(7152) * G + static_cast <long long>(722) * B;
    }

    void AsciiArt() const {
        if (intensity>= 0 && intensity< 510000)
        {
            cout << "#";
        }
        else if (intensity >= 510000 && intensity < 1020000)
        {
            cout << "o";
        }
        else if (intensity >= 1020000 && intensity < 1530000)
        {
            cout << "+";
        }
        else if (intensity >= 1530000 && intensity < 2040000)
        {
            cout << "-";
        }
        else if (intensity >= 2040000 )
        {
            cout << ".";
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    RGB** arr = new RGB*[n];
    for (int i = 0; i < n; i++) 
    {

        arr[i] = new RGB[m];

        for (int j = 0; j < m; j++)
        {
            arr[i][j].R = 0;
            arr[i][j].G = 0;
            arr[i][j].B = 0;
            arr[i][j].intensity = 0;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j].R;
            cin >> arr[i][j].G;
            cin >> arr[i][j].B;

            arr[i][j].IntensityFunc();
        }
    }




    

    ////출력 잘돼
    //cout << "\n\n출력:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //cout << arr[i][j].R << " ";
            //cout << arr[i][j].G << " ";
            //cout << arr[i][j].B << " ";
            //cout << arr[i][j].intensity << " ";
            arr[i][j].AsciiArt();

        }cout << "\n";
    }







    for (int i = 0; i < n; i++) 
    {
        delete arr[i];
    }

    delete[] arr;
    return 0;
}
