// File:	Student.c
// Author(S):	Sebastian Sopola
// Description:	functions for -> 2. Memory size is to be determined by the user. 
//              		 3. Fill student information according to user and check for uniqness of student ids. 
//              		 4. Feature update/modify functionality for student information. Calculate average of gpa of all students
//              		 5. Feature read from file 



#include "Student.h"


// initialize struct with variables we want to store about students
struct student {
	char name[NAMESIZE];
	int id;
	float gpa;

};

bool presentChoice() {

	// variable to keep asking for yes or no until it is given
	bool answer = false;

	// initialize choice which will be then passed to determine which path to take
	bool choice = false;
	printf("Would you like to read student information from file otherise you are directed to add new information to database? YES|NO \n");
	
	// read user input
	char input[ANSWERSIZE];
	
	// loop till user answers yes or no
	while ( answer == false ) {
		// check for user input as a string
		if ( fgets(input, ANSWERSIZE, stdin) != NULL ) {
		
			// take newline character out of string, IMPORTANT!
			input[strcspn(input, "\n")] = '\0';
			
			// if answer is yes, result of method is 0
			if ( strcmp(input,"yes") == 0 ) {
				choice = true;
				answer = true;
				
			// if answer is no, result of method is 0
			} else if ( strcmp(input,"no") == 0 ) {
				choice = false;
				answer = true;
				
			// if answer is not one of the given options
			} else {
				printf("You didn't answer yes or no. Please enter yes or no: \n");
				while ( getchar() != '\n' );
			}
			
		} else {
			printf("Error reading input. Please try again: \n");
			while ( getchar() != '\n' );
		}
	}
	

	return choice;
}

// function to ask for the number of students
int totalStudents(){

	int total = 0;
	
	// status to allow the number of students to be passed on when correctly given
	bool status = false;
	
	while ( status == false ) {
	
		// ask the number of students to be inserted
		printf("Enter the number of students: \n");
		if ( scanf("%d", &total) == 1 ) {
			status = true;
			while ( getchar() != '\n' );
			
		// when the amount is correctly given, this path is taken
		} else {
			printf("Traceback ( most recent call last):\n");
			printf("File: 'Student.c', line 76, in <module>\n");
			printf("   raise: The number of students wasn't inserted correctly\n\n");
			while ( getchar() != '\n' );
		}
	
	}
	
	return total;
}


// function to create array and return pointer to allocated memory array for further use
struct student* createArray( int totalStudents ) {

	// create struct memory pointer
	struct student *memoryPointer = NULL;
	
	// allocate memory for array of structs of fixed size of 20 students, later SIZE Will be asked from user !!!
	memoryPointer = ( struct student *) malloc(totalStudents * sizeof(struct student) );
	
	// check successfulity of memory allocation
	if ( memoryPointer == NULL ) {
		printf("\n\nTraceback ( most recent call last):\n");
		printf("File: 'Student.c', line 101, in <module>\n");
		printf("   raise: Memory allocation was unsuccessfull due to unkown error\n");
		return 0;
	}
	
	return memoryPointer;
}




// function to ask for student information, do error checking when name, id and gpa are given
int askInformation( struct student *memoryPointer, int totalStudents ) {

	// initialize help variables for testing newly added id to fit program requirements
	int testInteger = 0;
	int testIntegerCounter = 1;
	
	
	// initialize help variables for testing newly added id to fit uniqity of newly added id
	int idCheckCounter = totalStudents-1;
	char newID[IDSIZE];
	char previousID[IDSIZE];
	
	// initialize help variable for testing newly added gpa to fit program requirements
	double temporaryGpa = 0.0;
	
	
		
	// input student data and store it to struct 
	for ( int index = 0; index < totalStudents; index++) {
		printf("Enter student information: \n");
		
		
		// check that all information for particular student was given, limit string input to 30 charachters 
		if ( scanf("%30s %d %f", (*(memoryPointer + index)).name, 
                          &(memoryPointer + index)->id,
                          &(memoryPointer + index)->gpa ) != 3 ) {
			
			// error message when something goes wrong with allocating student information or student information is passed in
			// wrong format
			printf("Traceback ( most recent call last):\n");
			printf("File: 'Student.c', line 141, in <module>\n");
			printf("   raise: Student information wasn't inserted correctly. Could be one of these: \n          1. name, id or gpa not given \n          2. ID contained non-integer values\n\n");
			if ( index > 0 || index == 0 ) {
				index--;// delete current iteration so user information can be given again
			}
		}
		
		// assign newly given ID integer to test variable for checking it's validity
		testInteger = (memoryPointer + index)->id;
		sprintf(newID,"%d",(memoryPointer + index)->id);
		
		
		// devide ID integer by 10 until we reach 0 and so we have gone through whole integer
		while ( testInteger != 0 ) {
			testInteger = testInteger/10;
			testIntegerCounter++;
		}
		
		// check that ID is max 6 digits long, if not: raise error and delete newly added student and ask again
		if ( testIntegerCounter != IDSIZE ) {
			printf("Traceback ( most recent call last):\n");
			printf("File: 'Student.c', line 165, in <module>\n");
			printf("   raise: Student ID violated rules. ID must be 6 digits\n\n");
			if ( index > 0 || index == 0 ) {
				index--;// delete current iteration so user information can be given again
			}	
		}
		testIntegerCounter = 1;
		
		
		// check that id does not appear in the database yet
		if ( totalStudents > 1 ) {
		
			// loop through all previous student ids
			while ( idCheckCounter >= 0 ) {
			
				// make string of old id at currently comparing to newly given
				sprintf(previousID,"%d",(memoryPointer + idCheckCounter)->id);
				
				// compare old id in current loop cycle to newly given, if comparison method gives 0, id allready exists
				if ( strcmp(newID,previousID) == 0 ) {
					printf("Traceback ( most recent call last):\n");
					printf("File: 'Student.c', line 184, in <module>\n");
					printf("   raise: Student ID violated rules. ID allready exists\n\n");
					if ( index > 0 || index == 0 ) {
						index--;// delete current iteration so user information can be given again
					}
				}
				idCheckCounter--;// delete id counter till we have checked every id from database
			}
		}	
		
		
		// check that newly given gpa fits program requirements [ 0.00 - 5.00 ]
		temporaryGpa = (memoryPointer + index)->gpa;
		
		// in case gpa does not fit program requirements
		if ( (temporaryGpa < 0.00 || temporaryGpa > 5.00 ) ) {
			printf("Traceback ( most recent call last):\n");
			printf("File: 'Student.c', line 199, in <module>\n");
			printf("   raise: Student GPA violated rules. Must be between 0.00 - 5.00, formated [0.00]\n\n");
			if ( index > 0 || index == 0 ) {
				index--;// delete current iteration so user information can be given again
			}
		
		// in case gpa do fit program requirements
		} else if ( temporaryGpa >= 0.00 && temporaryGpa <= 5.00 ) {
			temporaryGpa = temporaryGpa * 100;
			temporaryGpa = round(temporaryGpa);
			temporaryGpa = temporaryGpa / 100;
			(memoryPointer + index)->gpa = temporaryGpa;

		}
		
		// Empties the command line of wrong user input, used with scanf upon invalid input
		// loops command line and takes character out of it until the end of string symbol is found
		// cuertesy of chatgpt
		while ( getchar() != '\n' );
		
		
	}

	// this will be activated if everything is fine till now
	printf("\n\nStudent information was added successfully !\n\n");


	return 0;
}

// function to show student information
void showStudentInformation( struct student *memoryPointer, int totalStudents ) {
	for ( int index = 0; index < totalStudents; index++) {
		printf("Name [%s] ID [%d] GPA [%.2f]\n",(memoryPointer + index)->name, 
							(memoryPointer + index)->id,
							(memoryPointer + index)->gpa);
	}
	printf("\n\n");
}



// function read information from file if user so chooses
void readFromFile() {
	FILE *readFilePointer = NULL;
	char string[NAMESIZE];
	readFilePointer = fopen("StudentInformation.txt", "a+");
	
	// check is file reading successfull
	if ( readFilePointer == NULL ) {
		printf("Traceback ( most recent call last):\n");
		printf("File: 'Student.c', line 245, in <module>\n");
		printf("   raise: Student information could not be read from file due to unknows issue\n\n");
	}
	
	// loop through file in 50 character cycles, while we don't meet end of file
	while ( fgets(string, NAMESIZE, readFilePointer ) != NULL ) {
		printf("%s", string);
	}
	
	// close file after it is read
	fclose(readFilePointer);
	
}


// function to update student information
int changeStudentInfo(struct student *memoryPointer, int totalStudents) {

    int studentID = 0;
    int index = 0;

    // loop to ask for student ID until a valid ID is entered
    while (true) {
        // ask user for the ID of the student to update
        printf("Enter the ID of the student to update: ");
        if (scanf("%d", &studentID) == 1) {
            // search for the student with the given ID
            for (index = 0; index < totalStudents; index++) {
                if ((memoryPointer + index)->id == studentID) {
                    // student found, exit the loop
                    break;
                }
            }
            if (index < totalStudents) {
                // student found, exit the loop
                break;
            } else {
                printf("Error: Student with ID %d not found.\n", studentID);
            }
        } else {
            // clear input buffer if invalid input is entered
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid student ID.\n");
        }
    }

    // ask user for the updated information
    printf("Enter the updated name of the student: ");
    scanf("%30s", (memoryPointer + index)->name);

    // ask user for the updated GPA of the student
    float updatedGPA = 0;
    while (true) {
        printf("Enter the updated GPA of the student (between 0.00 and 5.00): ");
        if (scanf("%f", &updatedGPA) == 1 && updatedGPA >= 0.00 && updatedGPA <= 5.00) {
            break;
        }
        // clear input buffer if invalid input is entered
        while (getchar() != '\n');
        printf("Invalid input. Please enter a valid GPA between 0.00 and 5.00.\n");
    }
    (memoryPointer + index)->gpa = updatedGPA;

    printf("Student information updated.\n");
    return 0;
}


float averageGpa( struct student *memoryPointer, int totalStudents ) {
	float average = 0.0;
	
	for ( int index = 0; index < totalStudents; index++) {
		average = average + (memoryPointer + index)->gpa;
	}

	average = average / totalStudents;
	
	return average;
}


void showAverage( float average ) {

	printf("Average of all GPAs is [%.2f]! Hurraa!\n\n",average);

}


void testFunction() {

	printf("Hi, I am going to get you !\n\n");


}















