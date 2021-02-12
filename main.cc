#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <climits>
using namespace std;


void emit(vector<string> stringV){
// print out each string in the vector with format "Word is "word"\n
        for (long unsigned int i = 0; i < stringV.size(); i++){
                cout << "Word is \"" << stringV[i] << "\"\n";
}
}

int wordMax(vector<string> v){
// return the maximum size length for the strings in the given vector
        long unsigned int max = 0;
        for (long unsigned int i = 0; i < v.size(); i++){
                if (v[i].size() > max) max = v[i].size();
}
        return max;
}

int wordMin(vector<string> v){
// return the minimum size length for the strings in the given vector
        long unsigned int min = INT_MAX;
        for (long unsigned int  i = 0; i < v.size(); i++){
                if (v[i].size() < min) min = v[i].size();
}
        return min;
}
void lineParse(string line, vector<string> &stringV){
        while (line.size() >  0){
        //cout << "inside while loop\n";
        // find the first occurence of the " \f\n\r\t\v()"
        int firstChar = line.find_first_of(" \f\n\r\t\v ()");
        string temp;
        // if the firstChar is not at index zero create a string of the chars
        //  up to that index, add to vector, then delete those characters from
        //   the string. if the first char is a () then also add those
        //   parenthesis to the vector and delete the characters
        if (firstChar > 0){
                // if the firstchar == () then add the previous characters to the
                // vector, erase the characters you added from the string
                // add the parenthesis to the vector and then delete the ()
                // from the string
                if(line[firstChar] == '(' || line[firstChar] == ')'){
                        stringV.push_back(line.substr(0,firstChar));
                        //cout << "added a string to vector\n";
                        line.erase(0,firstChar);
                        stringV.push_back(line.substr(0,1));
                        line.erase(0,1);
}
                else{
                        // if its one of the other spaces then add the previous
                        // characters to the vector and delete them from the string
                        stringV.push_back(line.substr(0,firstChar));
                        line.erase(0,firstChar);
}
}
        else{
                // the firstChar is at index 0 so if it is a () add it to
                // the vector and then delete it from the string
                if (line[firstChar] == '(' || line[firstChar] == ')'){
                        stringV.push_back(line.substr(0,1));
                        line.erase(0,1);
}               // if it is not a () then dont add it to the vector
                // and just delete the char from the string
                else{
                        line.erase(0,1);
}
}
}
}

int main(int /* argc*/, char *argv[]){
        string line;
        vector<string> v;
// iterate through and get every line in the text document
        while(getline(cin, line)){
                line.append("\n");
                lineParse(line , v);
}
        // determine if there are any words in the given file
        // if there is not send a message to error output
        if (v.size() == 0){
                cerr << argv[0] << ": no words were encountered\n";
                return 0;
}
        emit(v);
        cout << "Words: " << v.size() << "\n";
        cout << "Word range: " << wordMin(v) << "-" << wordMax(v) << "\n";
        return 0;

}
