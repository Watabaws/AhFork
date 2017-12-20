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

    if(!fork()){
      subserver(from_cliente);
    }
  }
}

void subserver(int from_client) {
  char client_message[BUFFER_SIZE];
  while(read(from_client, client_message, sizeof(client_message))){
    printf("Received Message: [%s] from client!\n", client_message);
    //process(client_message);
    int to_cliente = server_connect(from_client);
    write(to_cliente, client_message, sizeof(client_message));
  }
}

void process(char * s) {
}
