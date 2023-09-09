/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int accumlator = 0;
    int dfs(vector<Employee*> employees, int id, map<int, int>& indexing, vector<int>& visited){
        visited[id] = 1;
        accumlator += employees[indexing[id]]->importance;
        for(auto i : employees[indexing[id]]->subordinates){
            if(!visited[i]){
                dfs(employees, i, indexing, visited);
            }
        }
        return accumlator;
    }
    int getImportance(vector<Employee*> employees, int id) {
        int index;
        vector<int>visited(2001, 0);
        map<int, int>indexing;
        for(int i = 0; employees.size()>i; i++)
            indexing[employees[i]->id] = i;
        
        return dfs(employees, id, indexing, visited);
    }
};