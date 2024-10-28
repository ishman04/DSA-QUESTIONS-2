#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */
 
int find(vector<int> &parent,int x){
    if(parent[x]!=x){
        parent[x]=find(parent,parent[x]);
    }
    return parent[x];
}
 
void Union(vector<int> &parent,vector<int> &rank,int i,int j){
    int pari = find(parent,i);
    int parj = find(parent,j);
    if(pari != parj){
        if(rank[pari]>rank[parj]){
            parent[parj] = pari;
        }
        else if(rank[parj]>rank[pari]){
            parent[pari]=parj;
        }
        else{
            parent[parj]=pari;
            rank[pari]++;
        }
    }
    
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<int> rank(n,0);
    vector<int> parent(n);
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<astronaut.size();i++){
        Union(parent,rank,astronaut[i][0],astronaut[i][1]);
    }
    vector<long long> groupSizes;
    unordered_map<int, long long> sizeCounts;
    
    for (int i = 0; i < n; i++) {
        int leader = find(parent, i);
        sizeCounts[leader]++;
    }
    
    for (const auto& pair : sizeCounts) {
        groupSizes.push_back(pair.second);
    }
    
    long long total = (long long)n * (n - 1) / 2;
    
    for (long long size : groupSizes) {
        total -= (size * (size - 1)) / 2;
    }
    
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
