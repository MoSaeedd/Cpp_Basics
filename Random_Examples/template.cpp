// Online C compiler to run C program online
#include <iostream>
using namespace std;

template <class summable> 
inline summable sumd (const summable ar[],int size, summable sum=0)
{
    for(int i =0 ; i<size ;i ++)
        sum += ar[i];
    return sum;
}
int main() {
    // Write C code here
    double ar[2]= {3.2, 1.2};
    float sum=0;
    sum= sumd(ar,2);
    cout<<sum<<endl;
    
    return 0;
}













#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    int least =s;
    int finished =0;
    vector <vector <int>> graph (n,vector <int> (n,0));
    fill(graph.begin(), graph.end(), vector<int>(10, 2147483647));
    vector <int> visited (n,0);

    vector<int> AR (n,2147483647);
    // for(int i=0 ; i< n ; i++)
    // {   for(int j=0 ; j< n ; i++)
    //     {graph[i][j]=
    //     }
    // }  
    // vector<vector<int>> sP;
    for(int i=0 ; i< n ; i++)
    {
        if(  edges[i][2] < graph[edges[i][0]][edges[i][1]])
            graph[edges[i][0]][edges[i][1]]= edges[i][2];
    }
    while(1)
    {   visited[least]=1;
        for(int i=0 ; i< n ; i++)
        {        
            int length= AR[i]+ graph[least][i];
            if (length < AR[i] 
        }    
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
