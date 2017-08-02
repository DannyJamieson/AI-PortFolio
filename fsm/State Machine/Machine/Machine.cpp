// Machine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

int State=0;
int Money=10;
int Excitement=10;
int Food=10;
bool True = true;

void Work(){
	Money = Money + 2;
	Excitement = Excitement - 1;
	Food = Food - 1;
}

void Home() {
	Excitement = Excitement + 3;
	Food = Food - 1;
	Money = Money - 1;
}

void Resturant() {
	Food = Food + 3;
	Money = Money - 1;
}

void DoStuff() {

	if (Money <= Excitement && Money <= Food) {
		State = 0;
	}
	else if (Excitement <= Money && Excitement <= Food) {
		State = 1;
	}
	else if (Food <= Money && Food <= Excitement) {
		State = 2;
	}



	switch (State) {
		case 0: {
			Work();
			printf("Been to work       . Money = %u. Excitement = %u Food = %u \n\r", Money, Excitement, Food);
			break;
		}
		case 1: {
			Home();
			printf("Been Home          . Money = %u. Excitement = %u Food = %u \n\r", Money, Excitement, Food);
			break;
		}
		case 2: {
			Resturant();
			printf("Been to A Resturant. Money = %u. Excitement = %u Food = %u \n\r", Money, Excitement, Food);
			break;
		}
	}
}

int main() {
	while (True = true) {
		DoStuff();
		if (Money >= 100) { Money -= 90; }
		if (Excitement >= 100) { Excitement -= 90; }
		if (Food >= 100) { Food -= 90; }
		Sleep(100);
	}


			/*
				if (Money <= Excitement && Money <= Food) {
					State = 0;
				}
				else if (Excitement <= Money && Excitement <= Food) {
					State = 1;
				}
				else if (Food <= Money && Food <= Excitement) {
					State = 2;
				}



			switch (State) {
				case 0: {
					Work();
					printf("Been to work. Money = %u. Excitement = %u Food = %u \n\r", Money, Excitement, Food);
					break;
				}
				case 1: {
					Home();
					printf("Been Home. Money = %u. Excitement = %u Food = %u \n\r", Money, Excitement, Food);
					break;
				}
				case 2: {
					Resturant();
					printf("Been to A Resturant. Money = %u. Excitement = %u Food = %u \n\r", Money, Excitement, Food);
					break;
				}
			}

			//printf("money %u excitement %u food %u \n\r", Money, Excitement, Food);
			//Sleep(1000);
		*/




		//while (True = false) { Money + 2; }

}