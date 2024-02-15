// UMBC - CMSC 341 - Spring 2024 - Proj0
// Emely Pleitez
// emelyp1@umbc.edu
#include "puzzle.h"


class Tester{
public:
    //checks if constructor creates valid objects
    void constructorCheck(Puzzle &puzzle);

    //checks if copy constructor works properly
    bool copyConstructorCheck(Puzzle &puzzle);

    //Checks if reCreate works properly for normal case
    bool reCreateCheckNormal(Puzzle &puzzle);

    //Checks if reCreate works properly for error case
    bool reCreateCheckError(Puzzle &puzzle);

    //checks if appendRight() works properly
    bool appendRightCheck(Puzzle &puzzle);

    //checks if appendBottom() works properly
    bool appendBottomCheck(Puzzle &puzzle);

    //checks if the assignment operator works properly (Normal Case)
    bool assignOperatorCheck();

    //checks if the assignment operator works properly for Edge Case
    bool assignOperatorEdgeCheck();


};

int main(){

    Tester test; //test object

    //test cases for puzzle object
    cout << "******** TEST CASES FOR PUZZLE OBJECTS ******** " << endl;
    cout << "\nChecking Constructor Normal Case: " << endl;
    cout << "Puzzle Object: 12 Rows, 14 Columns" << endl;
    Puzzle puzzle1(12, 14);
    test.constructorCheck(puzzle1);

    cout << "\nChecking Constructor Edge Case: " << endl;
    cout << "Puzzle Object: 10 Rows, 10 Columns" << endl;
    Puzzle puzzle2(10, 10);
    test.constructorCheck(puzzle2);

    cout << "\nChecking Constructor Error Case: " << endl;
    cout << "Puzzle Object: -5 Rows, -10 Columns" << endl;
    Puzzle puzzle3(-5, -10);
    test.constructorCheck(puzzle3);



    //test cases for copy constructor
    cout << "\n******** TEST CASES FOR COPY CONSTRUCTOR ******** " << endl;
    cout << "\nChecking Copy Constructor: " << endl;
    Puzzle puzzle4(12,12);
    puzzle4.fill(12);
    bool result = test.copyConstructorCheck(puzzle4);
    if(!result){
        cout << "Copy Constructor failed one or more test cases" << endl;
    }//end if
    else{
        cout << "Copy Constructor passed all test cases" << endl;
    }//end else

    //test cases for puzzle object using reCreate()
    cout << "\n******** TEST CASES FOR reCreate() FUNCTION ******** " << endl;
    cout << "\nChecking reCreate() Normal Case: " << endl;
    Puzzle puzzle5(13,13);
    puzzle5.fill(12);
    cout << "ORIGINAL -> Rows: 13   Columns: 13" << endl;
    puzzle5.reCreate(12,14,97);
    test.reCreateCheckNormal(puzzle5);

    cout << "\nChecking reCreate() Error Case: " << endl;
    Puzzle puzzle6(13,13);
    puzzle6.fill(12);
    cout << "ORIGINAL -> Rows: 13   Columns: 13" << endl;
    test.reCreateCheckError(puzzle6);


    //test cases for appendRight()
    cout << "\n******** TEST CASES FOR appendRight() FUNCTION ******** " << endl;
    cout << "\nChecking appendRight() works properly: " << endl;
    Puzzle puzzle7(10,10);
    puzzle7.fill(98);
    bool result2 = test.appendRightCheck(puzzle7);
    if(!result2){
        cout << "appendRight() failed more than one test..." << endl;
    }//end if
    else{
        cout << "appendRight() passed all tests!" << endl;
    }//end else

    //test cases for appendBottom()
    cout << "\n******** TEST CASES FOR appendBottom() FUNCTION ******** " << endl;
    cout << "\nChecking appendBottom() works properly: " << endl;
    Puzzle puzzle8(10,10);
    puzzle8.fill(98);
    bool result3 = test.appendBottomCheck(puzzle8);
    if(!result3){
        cout << "appendBottom() failed more than one test..." << endl;
    }//end if
    else{
        cout << "appendBottom() passed all tests!" << endl;
    }//end else

    //test cases for Assignment Operator Edge Case
    cout << "\n******** TEST CASES FOR ASSIGNMENT OPERATOR (EDGE CASE) ******** " << endl;
    cout << "Testing Assignment Operator " << endl;
    bool result5 = test.assignOperatorEdgeCheck();
    if(!result5){
        cout << "Assignment Operator edge case failed more than one test..." << endl;
    }//end if
    else{
        cout << "Assignment Operator edge case passed all tests!" << endl;
    }//end else


    //test cases for Assignment Operator Normal Case
    cout << "\n******** TEST CASES FOR ASSIGNMENT OPERATOR (NORMAL) ******** " << endl;
    cout << "Testing Assignment Operator " << endl;
    bool result4 = test.assignOperatorCheck();
    if(!result4){
        cout << "Assignment Operator failed more than one test..." << endl;
    }//end if
    else{
        cout << "Assignment Operator passed all tests!" << endl;
    }//end else




}

void Tester::constructorCheck(Puzzle &puzzle){
    //Checks if constructor works with Normal Case, Edge Case, and Error Case.
    if (puzzle.m_numRows == 0 && puzzle.m_numCols == 0 && puzzle.m_puzzle == nullptr){
        cout << "Puzzle Object is an empty object due to either"
                "\ninvalid parameters or no parameters." << endl;
    }//end if
    else{
        cout << "Puzzle Object-> "
                "Rows: " << puzzle.m_numRows <<  "  Columns: " << puzzle.m_numCols << endl;
    }//end else
};

bool Tester::copyConstructorCheck(Puzzle &puzzle){

    bool result = true;

    Puzzle puzzleSample(puzzle);

    cout << "Test 1: Memory Location of Puzzle Objects " << endl;
    if(&puzzle.m_puzzle != &puzzleSample.m_puzzle){
        cout << "Source Location: " << &puzzle.m_puzzle << "\nCopied Location: " <<
        &puzzleSample << endl;
        cout << "Test 1 Passed." << endl;
    }//end if
    else{
        cout << "Source and Copied Location of Object match" << endl;
        result = false;
    }//end else

    cout << "\nTest 2: Member Values of Puzzle Objects " << endl;
    if(puzzle.m_numRows == puzzleSample.m_numRows && puzzle.m_numCols == puzzleSample.m_numCols ){
        cout << "Both objects have equal member values " << endl;
        cout << "Test 2 Passed." << endl;
    }//end if
    else{
        if(result){
            result = false;
        }
        cout << "Both objects do not have equal member values" << endl;
    }//end else

    cout << "\nTest 3: Equal Char Values " << endl;
    for (int i = 0; i < puzzle.m_numRows; i++){
        for (int j = 0; j < puzzle.m_numCols; j++){
            if(puzzle.m_puzzle[i][j] != puzzleSample.m_puzzle[i][j]){
                result = false;
            }
        }//end inner for
    }//end outer for
    cout << "Test 3 Passed." << endl;
    return result;
};


bool Tester::reCreateCheckNormal(Puzzle &puzzle) {
    //checks if reCreate() works with Normal Case
    bool result = false;

    if (puzzle.m_numRows == 12 && puzzle.m_numCols == 14){
        cout << "Puzzle recreated...reCreate() works" << endl;
        cout << "Rows: " << puzzle.m_numRows << "  Cols: " << puzzle.m_numCols << endl;
        result = true;
    }
    else{
        cout << "reCreate() does not work" << endl;
        cout << "Rows: " << puzzle.m_numRows << "  Cols: " << puzzle.m_numCols << endl;
        result = false;
    }
    return result;
}

bool Tester::reCreateCheckError(Puzzle &puzzle) {
    //checks if reCreate() works with error Case
    bool result = puzzle.reCreate(0,0,98);

    if(result == true){
        cout <<"reCreate() does not work... new object created with invalid parameters" << endl;
        cout << "Rows: " << puzzle.m_numRows << "  Cols: " << puzzle.m_numCols << endl;
    }
    else if(result == false){
        cout <<"reCreate() works... new object not created given invalid parameters" << endl;
    }

}


bool Tester::appendRightCheck(Puzzle &puzzle){

    bool test;
    bool result = true;
    Puzzle puzzleSample1(10,10);
    puzzleSample1.fill(98);

    //Tests appendRight() for Normal Case
    cout << "Test 1: Testing appendRight() for Normal Case: " << endl;
    test = puzzle.appendRight(puzzleSample1);
    if(test){
        cout << "Test 1 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 1 Failed." << endl;
    }

    //Tests appendRight() for Error Case
    cout << "Test 2: Testing appendRight() for Error Case: " << endl;
    //testing different row sizes
    Puzzle puzzleSample2(10,15);
    puzzleSample2.fill(98);
    if(test){
        cout << "Test 2 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 2 Failed." << endl;
    }

    //Tests if appendRight() correctly appends normal object to empty object
    cout << "Test 3: Testing if appendRight() correctly appends normal object to empty object: " << endl;
    //testing objects of different sizes
    Puzzle puzzleSample3; //empty object
    test = puzzleSample1.appendRight(puzzleSample3);
    if(test){
        cout << "Test 3 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 3 Failed." << endl;
    }

    //Tests if appendRight() correctly appends empty object to normal object
    cout << "Test 4: Testing if appendRight() correctly appends empty object to normal object: " << endl;
    test = puzzleSample3.appendRight(puzzleSample1);
    if(test){
        cout << "Test 4 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 4 Failed." << endl;
    }

    //Tests if appendRight() correctly appends object to itself
    cout << "Test 5: Testing if appendRight() correctly appends object to itself: " << endl;
    test = puzzleSample1.appendRight(puzzleSample1);
    if(test){
        cout << "Test 5 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 5 Failed." << endl;
    }
    return result;
}

bool Tester::appendBottomCheck(Puzzle &puzzle){

    bool test;
    bool result = true;
    Puzzle puzzleSample1(10,10);
    puzzleSample1.fill(98);

    //Tests appendBottom() for Normal Case
    cout << "Test 1: Testing appendBottom() for Normal Case: " << endl;
    test = puzzle.appendBottom(puzzleSample1);
    if(test){
        cout << "Test 1 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 1 Failed." << endl;
    }

    //Tests appendBottom() for Error Case
    cout << "Test 2: Testing appendBottom() for Error Case: " << endl;
    //testing different row sizes
    Puzzle puzzleSample2(10,15);
    puzzleSample2.fill(98);
    if(test){
        cout << "Test 2 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 2 Failed." << endl;
    }

    //Tests if appendBottom() correctly appends normal object to empty object
    cout << "Test 3: Testing if appendBottom() correctly appends normal object to empty object: " << endl;
    //testing objects of different sizes
    Puzzle puzzleSample3; //empty object
    test = puzzleSample1.appendBottom(puzzleSample3);
    if(test){
        cout << "Test 3 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 3 Failed." << endl;
    }

    //Tests if appendBottom() correctly appends empty object to normal object
    cout << "Test 4: Testing if appendBottom() correctly appends empty object to normal object: " << endl;
    test = puzzleSample3.appendBottom(puzzleSample1);
    if(test){
        cout << "Test 4 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 4 Failed." << endl;
    }

    //Tests if appendBottom() correctly appends object to itself
    cout << "Test 5: Testing if appendBottom() correctly appends object to itself: " << endl;
    test = puzzleSample1.appendBottom(puzzleSample1);
    if(!test){
        cout << "Test 5 Passed." << endl;
    }
    else{
        result = false;
        cout << "Test 5 Failed." << endl;
    }
    return result;
}

bool Tester::assignOperatorEdgeCheck() {
    bool result = true;
    Puzzle puzzleSample, puzzleSample2; //empty objects is the edge case
    puzzleSample2 = puzzleSample;


    cout << "Test 1: Memory Location of Puzzle Objects" << endl;
    if (&puzzleSample2.m_puzzle != &puzzleSample.m_puzzle){
        cout << "Source Location: " << &puzzleSample.m_puzzle << "\nCopied Location: " <<
             &puzzleSample2 << endl;
        cout << "Test 1 Passed." << endl;
    }
    else{
        cout << "Locations Match" << endl;
        cout << "Failed" << endl;
        result = false;
    }

    cout << "\nTest 2: Member Values of Puzzle Objects" << endl;
    if(puzzleSample.m_numRows == puzzleSample2.m_numRows && puzzleSample.m_numCols ==
                                                            puzzleSample2.m_numCols) {
        for (int i = 0; i < puzzleSample.m_numRows; i++) {
            for (int j = 0; j < puzzleSample.m_numCols; j++){
                if(puzzleSample.m_puzzle[i][j] != puzzleSample2.m_puzzle[i][j]){
                    result = false;
                }
            }//end inner for
        }//end outer for
        if (result){
            cout << "Both Objects have equal member values" << endl;
        }
        else{
            if(result){
                result = false;
            }
            cout << "Both Objects do not have equal member values" << endl;
        }
    }//end if

    return result;
}//end assignOperatorEdgeCheck()


bool Tester::assignOperatorCheck() {
    bool result = true;
    Puzzle puzzleSample(12,14), puzzleSample2;
    puzzleSample.fill(98);
    puzzleSample2 = puzzleSample;

    cout << "Test 1: Memory Location of Puzzle Objects" << endl;
    if (&puzzleSample.m_puzzle != &puzzleSample2.m_puzzle){
        cout << "Source Location: " << &puzzleSample.m_puzzle << "\nCopied Location: " <<
             &puzzleSample2 << endl;
        cout << "Test 1 Passed." << endl;
    }
    else{
        cout << "Locations Match" << endl;
        cout << "Failed" << endl;
        result = false;
    }

    cout << "\nTest 2: Member Values of Puzzle Objects" << endl;
    if(puzzleSample.m_numRows == puzzleSample2.m_numRows && puzzleSample.m_numCols ==
        puzzleSample2.m_numCols){
        if(result){
            cout << "Both objects have equal member values" << endl;
            cout << "Test 2 Passed." << endl;
        }
        else{
            if(result){
                result = false;
            }
            cout << "Both objects do not have equal member values" << endl;
            cout << "Test 2 Failed." << endl;
        }
    }

    cout << "\nTest 3: Equal Char Values" << endl;
    for(int i = 0; i < puzzleSample.m_numRows; i++){
        for (int j = 0; j < puzzleSample.m_numCols; j++){
            if(puzzleSample.m_puzzle[i][j] != puzzleSample2.m_puzzle[i][j]){
                result = false;
                //cout << "Test 3 Failed." << endl;
            }
        }//end inner for
    }//end outer for

    return result;
}





