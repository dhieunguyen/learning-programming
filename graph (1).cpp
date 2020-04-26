#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

struct Edge
{
    int firstPoint;
    int endPoint;
};

void readMatrix(string filePath, vector<vector<int> > &matrix)
{
    int size;
    int delimiter;
    fstream input;
    input.open(filePath, ios::in);
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

vector<vector<int> > convertToDirectedGraph(vector<vector<int> > matrix)
{
    int size = matrix.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                matrix[j][i] = 1;
            }
        }
    }
    return matrix;
}

vector<vector<int> > multiply(vector<vector<int> > matrixA, vector<vector<int> > matrixB)
{
    int rowA = matrixA.size();
    int rowB = matrixB.size();
    int columnA = matrixA[0].size();
    int columnB = matrixB[0].size();
    vector<vector<int> > res;

    if (columnA != rowB)
        cout << "Invalid params" << endl;
    else
    {
        for (int i = 0; i < rowA; i++)
        {
            vector<int> tempv;
            for (int j = 0; j < columnB; j++)
            {
                int temp = 0;
                for (int k = 0; k < columnA; k++)
                {
                    temp += matrixA[i][k] * matrixB[k][j];
                }
                tempv.push_back(temp);
            }
            res.push_back(tempv);
        }
    }
    return res;
}

vector<vector<int> > power(vector<vector<int> > matrix, int times)
{
    vector<vector<int> > res = matrix;
    while (times - 1 > 0)
    {
        res = multiply(res, matrix);
        times--;
    }
    return res;
}

vector<Edge> getListEdge(vector<vector<int> > matrix)
{
    vector<Edge> listEdge;
    int size = matrix.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Edge temp;
            if (matrix[i][j] == 1)
            {
                temp.firstPoint = i;
                temp.endPoint = j;
                listEdge.push_back(temp);
            }
        }
    }
    return listEdge;
}

vector<vector<string> > convertToIncidenceMatrix(vector<vector<int> > matrix)
{
    vector<vector<string> > incidenceMatrix;
    int size = matrix.size();
    vector<Edge> listEdge;
    listEdge = getListEdge(matrix);

    for (int i = 0; i < size; i++)
    {
        vector<string> tempv;
        for (int j = 0; j < listEdge.size(); j++)
        {
            string value = i == listEdge[j].firstPoint ? " 1" : i == listEdge[j].endPoint ? "-1" : " 0";
            tempv.push_back(value);
        }
        incidenceMatrix.push_back(tempv);
    }

    return incidenceMatrix;
}

vector<vector<int> > getListAdjacentPoint(vector<vector<int> > matrix)
{
    vector<vector<int> > listAdjacentPoint, directedGraph;
    int size = matrix.size();

    directedGraph = convertToDirectedGraph(matrix);

    for (int i = 0; i < size; i++)
    {
        vector<int> tempv;
        for (int j = 0; j < size; j++)
        {
            if (directedGraph[i][j] == 1)
            {
                tempv.push_back(j + 1);
            }
        }
        listAdjacentPoint.push_back(tempv);
    }
    return listAdjacentPoint;
}

void printMatrix(vector<vector<int> > matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void printIncidenceMatrix(vector<vector<string> > incidenceMatrix)
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

void printPoint(vector<Edge> listPoint)
{
    cout << "FirstPoint EndPoint" << endl;
    for (int i = 0; i < listPoint.size(); i++)
    {
        cout << listPoint[i].firstPoint + 1 << "          " << listPoint[i].endPoint + 1 << endl;
    }
    cout << endl;
}

int main()
{
    vector<vector<int> > matrix, listAdjacentPoint, res;
    vector<vector<string> > incidenceMatrix;
    vector<Edge> listEdge;
    int p = 3;

    readMatrix("matrix.dat", matrix);

    cout << "Adjacency matrix" << endl
         << endl;

    printMatrix(matrix);

    incidenceMatrix = convertToIncidenceMatrix(matrix);

    cout << "Incidence matrix" << endl
         << endl;

    printIncidenceMatrix(incidenceMatrix);

    listEdge = getListEdge(matrix);

    cout << "List edge" << endl
         << endl;

    printPoint(listEdge);

    listAdjacentPoint = getListAdjacentPoint(matrix);

    cout << "List Adjacent Point" << endl
         << endl;

    printListAdjacentPoint(listAdjacentPoint);

    res= power(matrix, p);

    cout << "Multiphy matrix " << p << " times" << endl
         << endl;

    printMatrix(res);

    return 0;
}