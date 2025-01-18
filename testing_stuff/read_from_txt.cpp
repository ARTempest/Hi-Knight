#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;
string file_name = "test.txt"; // This is the name for the art file, you can change it to other art file


int counting_lines (const string& file_name){
    int number_of_lines = 0;
    string line;
    ifstream file (file_name);

    if (!file){
        cerr << "Error: File not found" << endl; // Debugging
    }

    while (getline(file, line)){ // Count each line of the art text file
        number_of_lines++;
    }

    file.close(); // Close the file and return the value
    return number_of_lines;

}


vector<string> getting_strings (const string& file_name){
    int number_of_lines = counting_lines(file_name); // Get the number of lines in the art
    vector<string> text(number_of_lines); // Array list, each array have a different line of the art
    int i = 0; // i is used to determine which line is being written

    ifstream file (file_name);
    if (!file ){
        cerr << "Error: File not found" << endl; // Debugging
    }


    while (getline(file, text[i])){
        i++; // Store a line in text array and increment i to write the next line
    }

    file.close(); 
    return text; // Close the file and return the ptr to the array

}


void print_art (const vector<string>& text){    

    for (const string& line : text){ // Loop through the array of strings
        cout << line << endl; // Print each line of the art
    }

}


int validating_file (const string& file_name){
    ifstream file (file_name);

    if (!file){
        cerr << "Error: File not found" << endl; // Debugging
        return 1; // Return 1 if the file is not found
    }
    
    int number_of_lines = counting_lines(file_name);
    if (number_of_lines <= 5){
        cerr << "Error: File is empty" << endl; // Debugging
        return 1; // Return 1 if the file is empty
    }
    
    return 0; // Return 0 if the file is found
}


void creating_formattedArt_file (const string& file_name){
    ofstream file ("formattedArt.txt");
    vector<string> text = getting_strings(file_name); // Get the text from the file

    for (const string& line : text){
        file << line << endl; // Write each line of the art in the new file
    }

    file.close(); // Close the file

}


int main (){


    vector<string> text = getting_strings(file_name); // Get the text from the file
    print_art(text); // Print the art
    cout << "The art has " << counting_lines(file_name) << " lines" << endl; // Print the amount of lines in the art



    return 0;
}