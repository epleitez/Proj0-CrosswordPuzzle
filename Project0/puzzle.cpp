// UMBC - CMSC 341 - Spring 2024 - Proj0
// Emely Pleitez
// emelyp1@umbc.edu

#include "puzzle.h"


Puzzle::Puzzle(int rows, int cols){
    //constructor
    // It initializes all member variables & it allocates required memory
    if (rows <=0 || cols <= 0){
        //If the user passes invalid parameters
        //the constructor creates an empty object
        m_puzzle = nullptr;
        m_numRows = 0;
        m_numCols = 0;
    }//end if
    else{
        m_numRows = rows;
        m_numCols = cols;
        m_puzzle = new char *[m_numRows];
        for(int i = 0; i < m_numRows; i++){
            m_puzzle[i] = new char[m_numCols];
        }//end for
    }//end else
}//end Puzzle(int rows, int cols)

Puzzle::~Puzzle(){
    //destructor and it deallocates the memory.
    clear();
}//end ~Puzzle()

void Puzzle::clear(){
    //deallocates all memory and re-initializes all member variables to default values
    //clears current object to an empty object
    if (m_puzzle != nullptr){
        for(int i=0; i < m_numRows; i++){
            delete [] m_puzzle[i];
        }//end for
        delete [] m_puzzle;
    }//end if

    m_puzzle = nullptr;
    m_numRows = 0;
    m_numCols = 0;
}//end Puzzle::clear()


bool Puzzle::reCreate(int rows, int cols, int seed){
    //function re-creates a Puzzle object and fills it with random information
    //If the current object is already created this function clears the object and creates a new object

    if( rows < 10 && cols < 10){
        //cout << "Cannot re-create puzzle, parameters invalid" << endl;
        return false;
    }//end if
    else{
        m_numRows = rows;
        m_numCols = cols;
        fill(seed);
        int tempRows = rows;
        int tempCols = cols;
        char ** tempPuzzle = new char *[m_numRows];
        for(int i = 0; i < m_numRows; i++) {
            m_puzzle[i] = new char[m_numCols];
        }//end for

        //clear original object
        clear();
        m_puzzle = tempPuzzle;
        m_numRows = tempRows;
        m_numCols = tempCols;
        return true;
    }//end else

}//end Puzzle::reCreate(int rows, int cols, int seed)


void Puzzle::fill(int seed){
    //populates the table cells with random characters and proper number of separators
    // parameter seed used as the seed value for the random number generator
    Random randomObj(97,122);
    //randomly created puzzle
    randomObj.setSeed(seed);
    for(int i = 0; i < m_numRows; i++){
        for(int j = 0; j < m_numCols; j++){
            int randNum = randomObj.getRandNum();
            m_puzzle[i][j] = randNum;
        }//end inner for
    }//end outer for
}//end Puzzle::fill(int seed)


Puzzle::Puzzle(const Puzzle& rhs){
    //The copy constructor creates a deep copy of rhs
    m_numRows = rhs.m_numRows;
    m_numCols = rhs.m_numCols;
    m_puzzle = new char *[m_numRows];
    for (int i = 0; i < m_numRows; i++){
        m_puzzle[i] = new char[m_numCols];
    }//end for
    for(int i = 0; i < rhs.m_numRows; i++){
        for(int j = 0; j < rhs.m_numCols; j++){
            m_puzzle[i][j] = rhs.m_puzzle[i][j];
        }//end inner for
    }//end outer for
}//end Puzzle(const Puzzle& rhs)

const Puzzle& Puzzle::operator=(const Puzzle& rhs){
    //The assignment operator creates a deep copy of rhs.
    //assignment operator needs protection against self-assignment
    if(this != &rhs){ // check for self assignment
        clear();
        m_numRows = rhs.m_numRows;
        m_numCols = rhs.m_numCols;
        m_puzzle = new char*[m_numRows];
        for(int i = 0; i< m_numRows; i++){
            m_puzzle[i] = new char[m_numCols];
        }//end for
        for(int i = 0; i < rhs.m_numRows; i++){
            for(int j = 0; j < rhs.m_numCols; j++){
              m_puzzle[i][j] = rhs.m_puzzle[i][j];
            }//end inner for
        }//end outer for
    }//end if
    return *this;
}// end Puzzle::operator=(const Puzzle& rhs)

bool Puzzle::appendRight(const Puzzle& rhs){
    //function appends the rhs object to the right of the current object
    // If the operation is successful the function returns true otherwise it returns false

    //append operation only happens if both objects have the same number of rows or either object is empty.
    if (m_numRows == rhs.m_numRows || (m_puzzle == nullptr && rhs.m_puzzle == nullptr) ){
        //creates temp puzzle
        char ** temp = new char*[m_numRows];
        char tempRows = m_numRows;
        char tempCols = m_numCols + rhs.m_numCols;
        for (int i = 0; i < m_numRows; i++){
            temp[i] = new char[tempCols];
        }//end for


        //copies elements from original puzzle to temp puzzle
        for (int i = 0; i < m_numRows; i++){
            for (int j = 0; j < m_numCols; j++){
                temp[i][j] = m_puzzle[i][j];
            }//end inner for
        }//end outer for

        //copies elements from passed in puzzle to the right of the original puzzle
        for(int i = 0; i < m_numRows; i++){
            char counter = m_numCols;
            for (int j = 0; j < rhs.m_numCols; j++){
                temp[i][counter] = rhs.m_puzzle[i][j];
                counter++;
            }//end inner for
        }//end outer for

        //clears original puzzle and replaces it with the temp puzzle
        clear();
        m_numRows = tempRows;
        m_numCols = tempCols;
        m_puzzle = temp;

        //if successful, returns true
        return true;

    }//end if

    //otherwise, returns false (failed)
    return false;

}//end Puzzle::appendRight(const Puzzle& rhs)

bool Puzzle::appendBottom(const Puzzle& bottom){
    //function appends the bottom object to the bottom of the current object
    //If the operation is successful the function returns true otherwise it returns false

    //The append operation only happens if both objects have the same number of columns or either object is empty
    if (m_numRows == bottom.m_numCols || (m_puzzle == nullptr && bottom.m_puzzle == nullptr) ){
        //creates temp puzzle
        char tempRows = m_numRows + bottom.m_numRows;
        char **temp = new char*[tempRows];
        char tempCols = m_numCols;
        for (int i = 0; i< tempRows; i++){
            temp[i] = new char[tempCols];
        }

        //copies elements from original puzzle to temp puzzle
        for (int i = 0; i < m_numRows; i++){
            for (int j = 0; j < m_numCols; j++){
                temp[i][j] = m_puzzle[i][j];
            }//end inner for
        }//end outer for

        //copies elements from passed in puzzle to the bottom of the original puzzle
        int counter = m_numRows;
        for(int i = 0; i < m_numRows; i++){
            for(int j = 0; j < bottom.m_numCols; j++){
                temp[counter][j] = bottom.m_puzzle[i][j];
            }//end inner for
        }//end outer for

        //clears original puzzle and replaces it with the temp puzzle
        clear();
        m_numRows = tempRows;
        m_numCols = tempCols;
        m_puzzle = temp;

        //if successful, returns true
        return true;

    }//end if

    //otherwise, returns false (failed)
    return false;

}

void Puzzle::dump(){
    int i=0;
    int j=0;
    cout << "   ";
    for (int k=0;k<m_numCols;k++){
        if ((k+1) < 10) cout << "0";
        cout << (k+1) << " ";
    }
    cout << endl;
    while(i<m_numRows){
        if ((i+1) < 10) cout << "0";
        cout << (i+1) << " ";
        while(j<m_numCols){
            if (m_puzzle[i][j] == '#')
                cout << "\033[1;31m\u2731\033[0m" << "  ";   // this prints HEAVY ASTERISK as separators
            else
                cout << m_puzzle[i][j] << "  ";
            j++;
        }
        cout << endl;
        j=0;
        i++;
    }
    cout << endl;
}
