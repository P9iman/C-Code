#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// #include <sys/neutrino.h>

int chid = -1; // Keine Race Condition, da kein Read Modify Write Zugriff
void *client(void *not_used)
{
    int node_id = 0; // 0 : my node
    pid_t pid = 0;   // 0 : my process
    int coid;        // coid = ConnectionId
    char *s_msg = "My first message";
    char r_msg[512];
    do
    { // connect to channel
        coid = ConnectAttach(node_id, pid, chid, 0, 0);
        if (coid == -1)
            fprintf(stderr, "Client: ConnectAttach failed\n");
    } while (coid == -1); // infinite retry only for this example
    // send message
    if (-1 == MsgSend(coid, s_msg, strlen(s_msg) + 1, r_msg, sizeof(r_msg)))
    {
        fprintf(stderr, "Error during MsgSend\n");
        exit(EXIT_FAILURE);
    }
    printf("Client: Reply from Server: %s \n", r_msg);
    return NULL;
}

void *server(void *not_used) // Server
{
    int rcvid;               // receive id
    char msg[256];           // message buffer
    chid = ChannelCreate(0); // chid = ChannelId
    while (1)
    { // Server usually works in infinite loop
        // Waiting for a message
        rcvid = MsgReceive(chid, msg, sizeof(msg), NULL);
        // handle the message
        printf("Server: got the message: %s \n", msg);
        strcpy(msg, "Got the message");
        // send reply
        MsgReply(rcvid, 0, msg, sizeof(msg));
    }
    // you'll never get here
    return NULL;
}
int main(int argc, char *argv[])
{
    printf("create server and client thread\n");
    pthread_create(NULL, NULL, server, NULL);
    pthread_create(NULL, NULL, client, NULL);
    sleep(20);
    return (EXIT_SUCCESS);
}