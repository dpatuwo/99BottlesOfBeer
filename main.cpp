// Yeah, I did this out of sheer boredom.  Don't judge me.
// David Patuwo
// 03/17/2015

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>

void sprint(std::string);
std::string words(int);
std::string upper(std::string);

int main(){

	int bottles;
	std::cout << "How many bottles of beer do you have on the wall? (0 (quit) - and 99) ";
	std::cin >> bottles;
	
	if (bottles == 0){
		std::cout << std::endl;
	}

	else{
		for(bottles; bottles >= 0; --bottles){
			if(bottles == 1){
				sprint(upper(words(bottles)) + "bottle of beer on the wall,");
				std::this_thread::sleep_for (std::chrono::milliseconds(250));
				sprint(upper(words(bottles)) + "bottle of beer.");
				std::this_thread::sleep_for (std::chrono::milliseconds(600));
			}
			else{
				sprint(upper(words(bottles)) + "bottles of beer on the wall,");
				std::this_thread::sleep_for (std::chrono::milliseconds(250));
				sprint(upper(words(bottles)) + "bottles of beer.");
				std::this_thread::sleep_for (std::chrono::milliseconds(600));
			}
			if(bottles == 0){
				sprint("Go to the store and buy some more,");
				std::this_thread::sleep_for (std::chrono::milliseconds(250));
				std::cout << "*psst* how many bottles of beer did you buy?  (0-99) ";
				std::cin >> bottles;
				if(bottles == 0)
					sprint("You were thrown in jail for the night.");
				else{
					if(bottles == 1)
						sprint(upper(words(bottles)) + "bottle of beer on the wall.");
					else
						sprint(upper(words(bottles)) + "bottles of beer on the wall.");
					++bottles;
				}
			}
			else{
				if(0 == rand() % 100){
					sprint("If one of those bottles should happen to fall,");
					std::this_thread::sleep_for (std::chrono::milliseconds(250));
					if(bottles - 1 == 1)
						sprint(upper(words(bottles - 1)) + "bottle of beer on the wall.");
					else
						sprint(upper(words(bottles - 1)) + "bottles of beer on the wall.");
				}
				else{
					sprint("Take one down, pass it around,");
					std::this_thread::sleep_for (std::chrono::milliseconds(250));
					if(bottles - 1 == 1)
						sprint(upper(words(bottles - 1)) + "bottle of beer on the wall.");
					else
						sprint(upper(words(bottles - 1)) + "bottles of beer on the wall.");
				}
			}
			std::this_thread::sleep_for (std::chrono::milliseconds(600));
			std::cout << std::endl;
		}
	}
}

void sprint(std::string input){
	for(unsigned int i = 0; i < input.size(); ++i){
		std::cout << input[i];
		std::this_thread::sleep_for (std::chrono::milliseconds(30));
	}
	std::cout << std::endl;
}

std::string words(int in){
	int ones = in % 10;
	int tens;
	if(in < 10)
		tens = 0;
	else
		tens = (in - ones) / 10;
	std::string word;
	if (tens == 1){
		switch(ones){
		case 0:
			word = "ten ";
			break;
		case 1:
			word = "eleven ";
			break;
		case 2:
			word = "twelve ";
			break;
		case 3:
			word = "thirteen ";
			break;
		case 4:
			word = "fourteen ";
			break;
		case 5:
			word = "fifteen ";
			break;
		case 6:
			word = "sixteen ";
			break;
		case 7:
			word = "seventeen ";
			break;
		case 8:
			word = "eighteen ";
			break;
		case 9:
			word = "nineteen ";
			break;
		}
	}
	else{
		switch(tens){
		case 9:
			word = "ninety ";
			break;
		case 8:
			word = "eighty ";
			break;
		case 7:
			word = "seventy ";
			break;
		case 6:
			word = "sixty ";
			break;
		case 5:
			word = "fifty ";
			break;
		case 4:
			word = "forty ";
			break;
		case 3:
			word = "thirty ";
			break;
		case 2:
			word = "twenty ";
			break;
		default:
			break;
		};
		switch(ones){
		case 9:
			word = word + "nine ";
			break;
		case 8:
			word = word + "eight ";
			break;
		case 7:
			word = word + "seven ";
			break;
		case 6:
			word = word + "six ";
			break;
		case 5:
			word = word + "five ";
			break;
		case 4:
			word = word + "four ";
			break;
		case 3:
			word = word + "three ";
			break;
		case 2:
			word = word + "two ";
			break;
		case 1:
			word = word + "one ";
			break;
		default:
			break;
		}
	}
	if(in == 0)
		word = "no more ";
	return word;
}

std::string upper(std::string lower){
	lower[0] = toupper(lower[0]);
	return lower;
}