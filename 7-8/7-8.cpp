#include <iostream>
#include <fstream>
#include <string>
#include <exception>


void write_file(const char* output_file, std::string text_line, int startIndex, int endIndex) {
	std::ofstream fout;
	fout.open(output_file, std::ios::app);
	try
	{
		if (fout.is_open())
		{
			for (int i = startIndex; i < endIndex+1; i++) {
				fout << text_line[i];
				//std::cout << text_line[i];
			}
			fout << '\n';
			//std::cout << '\n';

		}
		else {
			throw std::exception();
		}
	}
	catch (...)
	{
		std::cout << "Output.txt is not open";
	}
	fout.close();
}


void find_sequence(std::string text_line, char start_symbol, char end_symbol) {
	int  startIndex, endIndex;
	bool find = false;
	for (int i = 0; i < text_line.length(); i++) {
		if (!find) {
			if (text_line[i] == start_symbol) {
				startIndex = i;
				find = true;
				for (int j = startIndex; j < text_line.length(); j++) {
					if (text_line[j] == end_symbol) {
						endIndex = j;
					}
				}
			}
		}
	}

	if (start_symbol == '[')
		write_file("output.txt", text_line, startIndex, endIndex); 
	else
		write_file("output2.txt", text_line, startIndex, endIndex);
}

void read_file(const char* input_file) {
	std::ifstream fin;
	std::string text_line;
	fin.open(input_file/*, std::ios_base::in  | ios::out | ios::app | ios_base::in*/);
	try
	{
		if (fin) {
			while (!fin.eof()) {
				std::getline(fin, text_line, '\n');

				//std::cout << text_line << std::endl;

				find_sequence(text_line, '[', ']');
				find_sequence(text_line, '(', ')');
				
			}
		}
		else {
			throw std::exception();
		}
		
	}
	catch (...)
	{
		std::cout << "\nError : file dosn't open";
	}
	
	fin.close();

}


int main()
{

	 read_file("C:/Users/Иван/source/repos/ConsoleApplication27/ConsoleApplication27/7-8.txt");
	return 0;
	
}