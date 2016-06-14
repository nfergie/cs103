#include <string>

using namespace std;


/**
 * opens the text file indicated by filename,
 * reads an integer, n, from the beginning of the file
 * then reads n strings from the file (separated by 
 * whitespace).  Returns a pointer to the array of
 * strings containing the words and copies n to the 
 * integer pointed to by size.  If the file is 
 * unable to be opened or an integer is unable to be
 * read from the beginning of the file, returns NULL;
 * and sets the integer to 0 that is pointed to by size 
 */
std::string* read_words(char* filename, int* size);

/**
 * Checks whether two strings are a DNA match
 * A DNA-match is defined as two strings such that:
 *  1. Both strings are the same length
 *  2. An 'A' or 'T' at a given location in one string
 *     should have a 'T' or 'A' (respectively) in the
 *     same location in the other string  ...OR...
 *     A 'C' or 'G' at a given location in one string
 *     should have a 'G' or 'C' (respectively) in the
 *     same location in the other string
 * You may assume all strings are made of upper case letters.
 */ 
bool dna_match(std::string s1, std::string s2);

