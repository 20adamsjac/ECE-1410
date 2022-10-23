#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
using namespace std;

/******************************************************************************
* Function Title: openFile
*
* Summary: The function of this program is to open a file so that it can be written onto
*
* Inputs: string filename, ofstream file
* Outputs: bool
* *****************************************************************************
* Pseudocode
*
* BEGIN
* open file for writing
* if the file does not open
*   print error
*   return failure
* else
*   return success
* END
******************************************************************************/
bool openFile(ofstream& o, string o1)
{
    o.open(o1, ios::out);//opens output file for writing
    if (o.fail())
    {
        cout << "Unable to open output file: " << o1;//check to make sure it opened
        return 0; //return failure
    }
    else
        return 1; //return success
}


/******************************************************************************
* Function Title: openFile
* 
* Summary: The function of this program is to open any input file so that it can be read.
* 
* Inputs: string file name, ifstream file
* Outputs: bool
* *****************************************************************************
* Pseudocode
* 
* BEGIN
* open file for reading
* if the file does not open
*   print error
*   return failure
* else
*   return success
* END
******************************************************************************/

bool openFile(ifstream& i, string i1)
{
    i.open(i1, ios::in); //opens input file for reading
    if (i.fail())
    {
        cout << "Unable to open input file: " << i1;//check to make sure it opened
        return 0; //return failure
    }
    else
        return 1; //return success
}