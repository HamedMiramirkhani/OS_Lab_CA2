#include "types.h"
#include "user.h"


int main(int argc, char* argv[]) {
    int most = find_most_caller();
    printf(1, "%d\n", most);
    exit();
}