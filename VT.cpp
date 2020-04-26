#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

struct Point
{
    int firstPoint;
    int endPoint;
};

void readMatrix(string fileName, vector<vector<int> > &matrix)
{
    int size;
    int delimiter;
    fstream input;
    input.open(fileName, ios::in);
    input >> size;
    for (int i = 0; i < size; i++)
    {
        vector<int> tempv;
        for (int j = 0; j < size; j++)
        {
            input >> delimiter;
            tempv.push_back(delimiter);
        }
        matrix.push_back(tempv);
    }
}

vector<Point> getListEdge(vector<vector<int> > matrix)
{
    vector<Point> listEdge;
    int size = matrix.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            Point temp;
            if (matrix[i][j] == 1)
            {
                temp.firstPoint = i + 1;
                temp.endPoint = j + 1;
                listEdge.push_back(temp);
            }
        }
    }
    return listEdge;
}

vector<vector<int> > convertToIncidenceMatrix(vector<vector<int> > matrix)
{
    vector<vector<int> > incidenceMatrix;
    int size = matrix.size();
    vector<Point> listEdge;
    listEdge = getListEdge(matrix);

    for (int i = 0; i < size; i++)
    {
        vector<int> tempv;
        for (int j = 0; j < listEdge.size(); j++)
        {
            if(i == listEdge[j].firstPoint - 1 || i == listEdge[j].endPoint - 1)
                tempv.push_back(1);
            else    
                tempv.push_back(0);
        }
        incidenceMatrix.push_back(tempv);
    }

    return incidenceMatrix;
}

vector<vector<int> > getListAdjacentPoint(vector<vector<int> > matrix)
{
    vector<vector<int> > listAdjacentPoint;
    int size = matrix.size();

    for (int i = 0; i < size; i++)
    {
        vector<int> tempv;
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                 if (matrix[i][j] == 1)
                    tempv.push_back(j + 1);
            }
        }
        listAdjacentPoint.push_back(tempv);
    }
    return listAdjacentPoint;
}

void printMatrix(vector<vector<int> > incidenceMatrix)
{
    for (int i = 0; i < incidenceMatrix.size(); i++)
    {
        for (int j = 0; j < incidenceMatrix[i].size(); j++)
            cout << incidenceMatrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printListAdjacentPoint(vector<vector<int> > listAdjacentPoint)
{
    for (int i = 0; i < listAdjacentPoint.size(); i++)
    {
        cout << "Ker(" << i + 1 << ") = ";
        for (int j = 0; j < listAdjacentPoint[i].size(); j++)
            cout << listAdjacentPoint[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printPoint(vector<Point> listPoint)
{
    cout << "FirstPoint EndPoint" << endl;
    for (int i = 0; i < listPoint.size(); i++)
    {
        cout << listPoint[i].firstPoint << "          " << listPoint[i].endPoint << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int> > matrix, incidenceMatrix, listAdjacentPoint;
    vector<Point> listEdge;

    readMatrix("matrix2.dat", matrix);

    cout << "Adjacency matrix" << endl
         << endl;

    printMatrix(matrix);

    incidenceMatrix = convertToIncidenceMatrix(matrix);

    cout << "Incidence matrix" << endl
         << endl;

    printMatrix(incidenceMatrix);

    listEdge = getListEdge(matrix);

    cout << "List edge" << endl
         << endl;

    printPoint(listEdge);

    listAdjacentPoint = getListAdjacentPoint(matrix);

    cout << "List Adjacent Point" << endl
         << endl;

    printListAdjacentPoint(listAdjacentPoint);

    return 0;
}