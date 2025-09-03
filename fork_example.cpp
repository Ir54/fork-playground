#include <iostream>
#include <unistd.h>     // for fork(), getpid()
#include <sys/types.h>  // for pid_t

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed!\n";
        return 1;
    } 
    else if (pid == 0) {
        cout << "[Child ] PID=" << getpid() << " (parent=" << getppid() << ")\n";
    } 
    else {
        cout << "[Parent] PID=" << getpid() << " created child PID=" << pid << "\n";
    }

    return 0;
}
