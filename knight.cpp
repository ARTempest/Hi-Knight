#include <iostream>
#include <string>
#include <fstream>
#include <random>

using namespace std;

const int lineLength = 42;

string quote = "Btw I'm a knight that prints randomly pre-generated messages.I'm gonna serve you for making your day a better thing";

int stringLength = quote.length();


string line1 = "                                          ";
string line2 = "                                          ";
string line3 = "                                          ";
string line4 = "                                          ";
string line5 = "                                          ";

string line[5] {line1,line2,line3,line4,line5};

int calculateRest(int a, int b){
	if ((a - b) < 0){
		return 0;
	}

	return (a - b);
}

string fixQuote(){
	string newQuote = quote;
	for (int i=0; i < (stringLength / lineLength); i++){
		int start = lineLength * (i+1);

		if (newQuote[start] != ' '){
			while (newQuote[start - 1] != ' '){
				start--;
			}

			string rest(lineLength*(i+1) - start,' ');
	
			newQuote = newQuote.substr(0,start)+rest+newQuote.substr(start,stringLength);
		} 
		else{
			newQuote = newQuote.substr(0,start)+newQuote.substr(start + 1,stringLength);
		}
		

	}
	stringLength = newQuote.length();
	return newQuote;

}

void createLines(){
	int restChar = stringLength;

	for (int i = 0; i <= (stringLength / lineLength); i++){

		string rest(calculateRest(lineLength, restChar),' '); // calculate the amount of ' ' needed for this line
	
		line[i] = quote.substr((stringLength - restChar), lineLength)+rest;

		restChar = calculateRest(restChar,lineLength); // substract the length of a line from the restant characters returning the actual rest of characters that haven't been procceseated 
	}
}

string selectQuote(){
	int amountLines = 0;

	string line;
	ifstream myQuotes1 ("quotes.txt");
		if (myQuotes1.is_open()){
			while (getline(myQuotes1,line)){
				amountLines++;
			}
			myQuotes1.close();
		}


	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1,amountLines);




	ifstream myQuotes ("quotes.txt");

	if (myQuotes.is_open()){
	


		for (int i=0; i < distr(gen); i++){
			getline(myQuotes,line);
		}
		myQuotes.close();
	}
	return line;
}



int main(){
quote = selectQuote();
selectQuote();
quote = fixQuote();
createLines();

cout << "                          ____________________________________________" << '\n';
cout << "                          |" << line[0] << "|" << '\n';
cout << "                          |" << line[1] << "|" << '\n';
cout << "                          |" << line[2] << "|" << '\n';
cout << "                          |" << line[3] << "|" << '\n';
cout << "      A           {}      |" << line[4] << "|" << '\n';
cout << " / \\, | ,        .--.     | _________________________________________|" << '\n';
cout << "|    =|= >      /.--.\\   /_/" << '\n';
cout << " \\ /` | `       |====|" << '\n';
cout << "  `   |         |`::`| "  << '\n';
cout << "      |     .-;`\\..../`;_.-^-._" << '\n';
cout << "     /\\\\/  /  |...::..|`   :   `|" << '\n';
cout << "     |:'\\ |   /'''::''|   .:.   |" << '\n';
cout << "      \\ /\\;-,/\\   ::  |..:::::..|" << '\n';
cout << "      |\\ <` >  >._::_.| ':::::' |" << '\n';
cout << "      |   `""`  /   ^^  |   ':'   |" << '\n';
cout << "      |       |       \\    :    /" << '\n';
cout << "      |       |        \\   :   /"  << '\n';
cout << "      |       |___/\\___|`-.:.-`" << '\n';
cout << "      |        \\_ || _/"     << '\n';
cout << "      |        <_ >< _>" << '\n';
cout << "      |        |  ||  |" << '\n';
cout << "      |        |  ||  |" << '\n';
cout << "      |       _\\.:||:./_" << '\n';
cout << "      |      /____/\\____\\" << '\n';


return 0;
}
