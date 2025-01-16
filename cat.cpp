#include <iostream>
#include <string>
#include <random>
#include <fstream>

using namespace std;

string quote = "Yo, can you please put a txt file for my phrases please ?"; 

const int amountLines = 5;
const int minimunLineLength = 42;

int quoteLength = quote.length();
int lineLength = minimunLineLength;

const int amountCharactersLimit = minimunLineLength * amountLines; 

string line[amountLines];

void organizeQuote(){
	int position = 0;
	int beforeSpace = 0;
	int nextEdge = lineLength;


	for (int i=0; i < quoteLength; i++){
		if (quote[i] == ' '){
			beforeSpace = i;
		}

		
		if (beforeSpace < i && i == nextEdge){
			
			string spaces (i - beforeSpace - 1,' ');

			quote = quote.substr(position, beforeSpace - position) + spaces + quote.substr(beforeSpace, 1000);

		}		
		
			
		if (i == nextEdge && quote[i] == ' ') {
			
			quote = quote.substr(0, i) + quote.substr(i+1,1000);
		}

		if (i > nextEdge){
			nextEdge += lineLength;
		}


	}
	
	quoteLength = quote.length();
	string extraSpaces (lineLength * amountLines - quoteLength, ' ');
	quote = quote + extraSpaces;
}

void distributeQuote(){
	int from = 0;
	int to = lineLength;

	for (int i=0; i < amountLines; i++){
		line[i] = quote.substr(from, to);
		from += lineLength;
	}
}

int calculateAmountQuotes(){
	string line = " ";
	ifstream quotes ("quotes.txt");
	int amountQuotes = 0;

	if (quotes.is_open()){
		while (getline(quotes,line)){
			amountQuotes += 1;
		}
	}

	quotes.close();

	return amountQuotes;

}

int generateNumber(int amountQuotes){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, amountQuotes);
	int number = distr(gen);

	return number;
}

string selectQuote(int position){
	string line = " ";
	ifstream quotes ("quotes.txt");


	if (quotes.is_open()){
		while (position > 0){
			getline(quotes,line);
			position --;
		}
	}

	quotes.close();

	return line;
}

void printCat(){
	cout << "                                               __________________________________________" << '\n';
    cout << "                                              |"<< line[0] <<"|" <<'\n';  
    cout << "           ⣤⣤⣤                 ⣤⣤           |"<< line[1] <<"|" <<'\n';
    cout << "          ⣾⣿⣿⣿               ⣼⣿⣿⣿          |"<< line[2] <<"|" <<'\n';  
    cout << "         ⣾⣿⣿⣿⣿⣷             ⣾⣿⣿⣿⣷         |"<< line[3] <<"|" <<'\n'; 
    cout << "        ⣾⣿⣿⣿⣿⣿⣷            ⣼⣿⣿⣿⣿⣿        |"<< line[4] <<"|" <<'\n';
    cout << "        ⣾⣿⣿⣿⣿⣿⣿⣧          ⢰⣿⣿⣿⣿⣿⣿⣧      |  ________________________________________|" << '\n';
    cout << "       ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣇         ⣿⣿⣿⣿⣿⣿⣿⣿⡆   /_/" << '\n';
    cout << "      ⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄      ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣷        " << '\n';
    cout << "     ⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧     ⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       " << '\n';
    cout << "     ⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄   ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇       " << '\n';
    cout << "     ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿       " << '\n';
    cout << "    ⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿       " << '\n';
    cout << "    ⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿       " << '\n';
    cout << "    ⠈⣿⣿⣿⣿⣿⣿⠟⠉   ⠙⢿⣿⣿⣿⣿⣿⣿⣿⡿⠋   ⠙⢻⣿⣿⣿⣿       " << '\n';
    cout << "     ⣿⣿⣿⣿⣿⠃    ⣠⣄  ⢻⣿⣿⣿⣿⣿⡿ ⣠⣄     ⢻⣿⣿⣏       " << '\n';
    cout << "     ⣾⣿⣿⣿⣿    ⠰⣿⣿  ⢸⣿⣿⣿⣿⣿⡇ ⣿⣿⡇    ⢸⣿⣿⣿       " << '\n';
    cout << "     ⣿⣿⣿⣿⣿⣄    ⠙⠃  ⣼⣿⣿⣿⣿⣿⣇ ⠙⠛⠁    ⣼⣿⣿⣿⡇      " << '\n';
    cout << "     ⣿⣿⣿⣿⣿⣿⣷⣤⣄⣀⣠⣤⣾⣿⣿⣿⣿⣽⣿⣿⣦⣄⣀⣀⣤⣾⣿⣿⣿⣿⠃  ⢀⣀  " << '\n';
    cout << "⠰⡶⠶⠶⠶⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠛⠉⠉⠙⠛⠋ " << '\n';
    cout << "  ⢀⣀⣠⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠷⠶⠶⠶⢤⣤⣀ " << '\n';
    cout << " ⠛⠋⠉⠁ ⣀⣴⡿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣤⣀⡀    ⠘⠃" << '\n';
    cout << "  ⢀⣤⡶⠟⠉⠁  ⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠟⠉   ⠉⠙⠳⠶⣄⡀  " << '\n';
    cout << "  ⠙⠁        ⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏           ⠉⠁  " << '\n';
    cout << "           ⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷               " << '\n';
    cout << "          ⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀              " << '\n';
    cout << "          ⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇              " << '\n';
    cout << "         ⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷              " << '\n';
    cout << "        ⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆             " << '\n';
    cout << "       ⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇             " << '\n';
    cout << "      ⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆            " << '\n';
    cout << "     ⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷            " << '\n';
    cout << "    ⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇           " << '\n';
    cout << "    ⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷           " << '\n';
}




int main(){
	quote = selectQuote(generateNumber(calculateAmountQuotes()));
	quoteLength = quote.length();
	
	if (quoteLength > amountCharactersLimit - 15){
		lineLength = quoteLength / amountLines + 10;
	}

	organizeQuote();

	distributeQuote();

	printCat();

	return 0;
}

