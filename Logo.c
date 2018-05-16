#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void logo();

void main() {
	logo();
}

void logo() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	printf("        ,,,,,   ,,,,,      ,,,,,,        ,,,,,,     ,,,,,,,,,    ,,,,,  ,,,,,,,,,,,,,     ,,,,,      ,,,,,\n");
	printf("        MMMMF   JMMMM   ,aMMMMMMMMb,   JMMMM@MMMW,  MMMMMMMMMMb  JMMMM  MMMMMMMMMMMMF    JMMMMM      JMMMM\n");
	printf("        MMMMF   JMMMM  JMMMMM99NMMMM, JMMMM` 9MMMM  MMMMP!?NMMMF JMMMM  @@@@MMMMM@@@E   JMMMMMMI     JMMMM\n");
	printf("        MMMMWmmmdMMMM  MMMMP    YMMMW JMMMMMMmJ,    MMMMF  JMMMF JMMMM      MMMMF       MMMMJMMMJ    JMMMM\n");
	printf("        MMMMMMMMMMMMM  MMMMF    JMMMM  J@MMMMMMMMp  MMMMMMMMMMM+ JMMMM      MMMMF      JMMME,MMMM    JMMMM\n");
	printf("        MMMMP!!!YMMMM  MMMMF    JMMMM   ,,,7?@MMMML MMMMM@@@9!   JMMMM      MMMMF     JMMMMJJdMMMF   JMMMM\n");
	printf("        MMMMF   JMMMM  JMMMMp,,JMMMMW JMMMh, ,MMMME MMMMF        JMMMM      MMMMF     MMMMMMMMMMMMJ  JMMMMJJJJJJ\n");
	printf("        MMMMF   JMMMM   JNMMMMMMMMMW   @MMMMMMMMME  MMMMF        JMMMM      MMMMF    JMMMP^^^^JMMMM  JMMMMMMMMMMF\n");
	printf("        99999   J9999     ?9@@99`      Q?9@@@9!     MMMMF        JMMMM      MMMMF    9999+     99999 J9999999999T\n");
	printf(" \n\n\n");
	SetConsoleTextAttribute(hConsole, 12);
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"),
	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("                                   JMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("                                   J@@@@@@@@@@@@@@@@NMMMMMMMMMMMMMMM@@@@@@@@@@@@@@@@@\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    JMMMMMMMMMMMMMMM\n");
	printf("                                                    J@@@@@@@@@@@@@@9\n\n\n\n");

	SetConsoleTextAttribute(hConsole, 15);
	system("PAUSE");
	system("cls");
	system("color 07");
}
}
