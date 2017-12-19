#include "pipe_networking.h"
#include <signal.h>

void process(char *s);
void subserver(int from_client);

static void sighandler(int signo) {
  if (signo == SIGINT) {
    remove("luigi");
    exit(0);
  }
}

int main() {
  while(1){
    int from_cliente = server_setup();
    char * client_message[BUFFER_SIZE];

    if(!fork()){
      while(read(from_cliente, client_message, sizeof(client_message))){
        printf("Received Message: [%s] from client!\n", client_message);
        //process(buffer);
        
      }
    }
  }
}

void subserver(int from_client) {
}

void process(char * s) {
}
