#include <iostream>
using namespace std;

void func_0(int **arr, int row, int col)
{
    cout << "Enter the Test Score in Test Field or if you want to ( Skip any Test enter -1 ). \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the Test score in TEST no  " << j + 1 << " of field no  " << i + 1 << " : ";
            cin >> arr[i][j];
        }
        cout << endl;
    }
}

void func_9(int **arr, int row, int col)
{
    cout << " The complete Test result of All Field is Shown Below : \n";
    cout << endl;
    cout << endl;
    cout << "         ";
    for (int i = 0; i < col; i++)
    {
        cout << "Test  " << i + 1 << "   ";
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        cout << "FIELD " << i + 1 << "    ";
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << "         ";
        }
        cout << endl;
    }
}

void func_2(int **arr, int row, int col)
{
    int fill_locat = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != -1)
            {
                fill_locat++;
            }
        }
    }
    cout << "The Total " << fill_locat << "  locations are filled ." << endl;
}

void func_3(int **arr, int row, int col)
{
    int F = 0;
    int T = 0;
    cout << " Enter the Field from which you want to delete Test : ";
    cin >> F;
    cout << " Enter the Test from that you want to delete  : ";
    cin >> T;

    // Check for valid input
    if (F >= 1 && F <= row && T >= 1 && T <= col)
    {
        arr[F - 1][T - 1] = -1;
        cout << " The Test has deleted. \n";
    }
    else
    {
        cout << "Invalid field or test number.\n";
    }
    cout << endl;
}

void func_4(int **arr, int row, int col)
{
    int mfrq = 0;
    int smfrq = 0;
    int n_mfrq = 0;
    int n_smfrq = 0;
    int count = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == -1)
            {
                break;
            }
            if (arr[i][j] == n_mfrq || arr[i][j] == n_smfrq)
            {
                break;
            }
            else
            {
                count = 0;

                for (int k = 0; k < row; k++)
                {
                    for (int l = 0; l < col; l++)
                    {
                        if (arr[i][j] == arr[k][l])
                        {
                            count = count + 1;
                        }
                    }
                }

                if (count > mfrq)
                {
                    n_smfrq = n_mfrq;
                    n_mfrq = arr[i][j];
                    smfrq = mfrq;
                    mfrq = count;
                }
                else if (count > smfrq && count < mfrq)
                {
                    n_smfrq = arr[i][j];
                    smfrq = count;
                }
            }
        }
    }
    cout << " The number " << n_mfrq << "   has maximum occurrence of " << mfrq << "  times. " << endl;
    cout << " The number " << n_smfrq << "   has second maximum occurrence of " << smfrq << "  times. " << endl;
}

void func_1(int **arr, int row, int col)
{
    int nfield = 0;
    int nint = 0;
    bool check = false;
    cout << "Enter the Field no in which you want to insert new result (1 to " << row << "):  ";
    cin >> nfield;

    // Check for valid input
    if (nfield < 1 || nfield > row)
    {
        cout << "Invalid field number.\n";
        return;
    }

    cout << "Enter the result that you want to insert : ";
    cin >> nint;
    int i = 0;
    for (i = 0; i < col; i++)
    {
        if (arr[nfield - 1][i] == -1)
        {
            arr[nfield - 1][i] = nint;
            check = true;
            break;
        }
    }
    if (check == true)
    {
        cout << " The result " << nint << "  is inserted in Test no   " << i + 1 << "   .\n";
    }
    if (check == false)
    {
        cout << " There is no place left for this Test result. \n";
    }
}

void func_5(int **arr, int row, int col)
{
    int *sum = new int[row];
    int *div = new int[row];

    for (int i = 0; i < row; i++)
    {
        sum[i] = 0;
        div[i] = 0;
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != -1)
            {
                sum[i] += arr[i][j];
                div[i]++;
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        if (div[i] > 0)
        { // Check for division by zero
            cout << "The average of Field no " << i + 1 << ": " << float(sum[i]) / div[i] << endl;
        }
        else
        {
            cout << "No valid scores for Field no " << i + 1 << ".\n";
        }
    }

    delete[] sum;
    delete[] div;
}

void func_6(int **arr, int row, int col)
{
    int *m_sum = new int[row];
    int max = 0;
    int index = 0;

    for (int i = 0; i < row; i++)
    {
        m_sum[i] = 0;
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != -1)
            {
                m_sum[i] += arr[i][j];
            }
        }

        if (m_sum[i] > max)
        {
            max = m_sum[i];
            index = i;
        }
    }

    cout << "The Field " << index + 1 << " has the maximum success value, which is " << max << endl;

    delete[] m_sum;
}

int main()
{
    cout << "           --------   PESTCOUTS     --------             \n";
    cout << endl;
    cout << "   Aiming at Producing Environmental Friendly Pesticides  \n";
    cout << endl;
    cout << endl;
    //  Code Starts from here
    int field = 0;
    int test = 0;
    int exit = 0;
    int opt = 0;

    cout << " Enter the number of fields : \n ";
    cin >> field;
    cout << " Enter the number of test you want to take :  \n ";
    cin >> test;
    cout << endl;

    int **record = new int *[field];
    for (int i = 0; i < field; i++)
    {
        record[i] = new int[test];
    }
    func_0(record, field, test);
    func_9(record, field, test);

    cout << endl;
    cout << endl;
    while (exit != 1)
    {
        cout << endl;
        cout << endl;
        cout << " Enter 0 to view the record. " << endl;
        cout << " Enter 1 to add a record. " << endl;
        cout << " Enter 2 to delete a record. " << endl;
        cout << " Enter 3 to see the total filled location. " << endl;
        cout << " Enter 4 to see the frequent number. " << endl;
        cout << " Enter 5 to see the average. " << endl;
        cout << " Enter 6 to see the maximum success value. " << endl;
        cout << " Enter 7 to exit. " << endl;
        cin >> opt;

        switch (opt)
        {
        case 0:
            func_9(record, field, test);
            break;
        case 1:
            func_1(record, field, test);
            break;
        case 2:
            func_3(record, field, test);
            break;
        case 3:
            func_2(record, field, test);
            break;
        case 4:
            func_4(record, field, test);
            break;
        case 5:
            func_5(record, field, test);
            break;
        case 6:
            func_6(record, field, test);
            break;
        case 7:
            exit = 1;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }

    // Memory cleanup
    for (int i = 0; i < field; i++)
    {
        delete[] record[i];
    }
    delete[] record;

    return 0;
}
