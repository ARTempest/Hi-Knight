#include <iostream>
#include <string>

using namespace std;

string quote = "Remember doing a project ";

const int amountLines = 5;
const int minimunLineLength = 42;

int quoteLength = quote.length();
int lineLength = minimunLineLength;

const int amountCharactersLimit = minimunLineLength * amountLines; // This is the limit for the normal amount of characters with a limit of 42

string line[amountLines];

void organizeQuote(){
	int position = 0;
	int beforeSpace = 0;
	int nextEdge = lineLength;


	for (int i=0; i < quoteLength; i++){
		if (quote[i] == ' '){
			beforeSpace = i;
		}

		//cout << beforeSpace << " < " << i << " = " << quote[i] << '\n';

		if (beforeSpace < i && i == nextEdge){
			
			//cout << beforeSpace << '<' << i << '=' << quote[i] << '\n';
			string spaces (i - beforeSpace - 1,' ');

			//cout << spaces << '\n';
			//cout << i << ' ' << quote[i] << '\n';
			quote = quote.substr(position, beforeSpace - position) + spaces + quote.substr(beforeSpace, 1000);
			//cout << i << ' ' << quote[i] << '\n';

			//cout << quote[lineLength*2] << ' ' << lineLength*2 << '\n';
		}
		
		
			
		if (i == nextEdge && quote[i] == ' ') {
			
			quote = quote.substr(0, i) + quote.substr(i+1,1000);
		}

		if (i > nextEdge){
			nextEdge += lineLength;
		}


	}
	//cout << position << '\n';
	quoteLength = quote.length();
	string extraSpaces (lineLength * amountLines - quoteLength, ' ');
	quote = quote + extraSpaces;
	
}

void distributeQuote(){
	int from = 0;
	int to = lineLength;
	string extraSpaces (lineLength - quoteLength, ' ');


	for (int i=0; i < amountLines; i++){

		if (from <= quoteLength){
			if (quoteLength < lineLength){
				line[i] = quote.substr(from, to) + extraSpaces;
			} else{
				line[i] = quote.substr(from, to);
			}


			//+ extraSpaces;
			//cout << quote.substr(from, to) << '\n';
			from += lineLength;
		} else {
			string spaces (lineLength, ' ');
			line[i] = spaces;
		}
		
	}
}

void printKnight(){
cout << "                          ____________________________________________" << '\n';
//cout << "                          |" << line1 << "|" << '\n';
//cout << "                          |" << line2 << "|" << '\n';
//cout << "                          |" << line3 << "|" << '\n';
//cout << "                          |" << line4 << "|" << '\n';
//cout << "      A           {}      |" << line5 << "|" << '\n';
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
cout << "      |       \\_ || _/"     << '\n';
cout << "      |        <_ >< _>" << '\n';
cout << "      |        |  ||  |" << '\n';
cout << "      |        |  ||  |" << '\n';
cout << "      |       _\\.:||:./_" << '\n';
cout << "      |      /____/\\____\\" << '\n';
}

int main(){
	if (quoteLength > amountCharactersLimit - 15){
		lineLength = quoteLength / amountLines + 10;
	}

	if (quoteLength > minimunLineLength){
		organizeQuote();
	}

	distributeQuote();

	cout << line[0] << '\n';
	cout << line[1] << '\n';
	cout << line[2] << '\n';
	cout << line[3] << '\n';
	cout << line[4] << '\n';

	return 0;
}
