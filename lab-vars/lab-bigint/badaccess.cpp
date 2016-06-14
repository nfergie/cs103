#include <string>
#include <vector>
#include "bigint.h"

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

int main(){

	BigInt bgint("45");
	vector<int> myvec = bgint.data;

	return 0;
}