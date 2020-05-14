#include <iostream>
#include "header.h"
#include <string>

int main(){

	std::string line;
    Playlist obj;

	while(getline(std::cin, line)){

		std::string command = line.substr(0, 1);
		std::string operand = line.substr(2);

		if (command == "m"){
			obj.set_max(std::stoi(operand));
		}

		else if (command == "i"){

			int pos = operand.find(";");

			std::string song_t = operand.substr(0, pos);
			std::string song_n = operand.substr(pos + 1);

			obj.insert(song_n, song_t);
		}

		else if (command == "p"){
			obj.play(std::stoi(operand));
		}

		else if (command == "e"){
			obj.erase(std::stoi(operand));
		}

	}
	return 0;
}
