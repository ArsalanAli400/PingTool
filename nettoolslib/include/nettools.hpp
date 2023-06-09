#ifndef NETTOOLS_NETTOOLS_HPP
#define NETTOOLS_NETTOOLS_HPP

#ifndef CMode
#define CMode "NO SYSTEM NAME"
#endif

// C++ program to Implement Ping
// compile as -o ping
// run as sudo ./ping <hostname>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

// Define the Packet Constants
// ping packet size
#define PING_PKT_S 64

// Automatic port number
#define PORT_NO 0

// Automatic port number
#define PING_SLEEP_RATE 1000000

// Gives the timeout delay for receiving packets
// in seconds
#define RECV_TIMEOUT 1


static int pingloop=1;
static int pingloop10=10;

// ping packet structure
struct ping_pkt
{
    struct icmphdr hdr;
    char msg[PING_PKT_S-sizeof(struct icmphdr)];
};

// nettools class: defines all the utilities for network tools
class nettools{
private:
    /*******************************************************************
            * Nettools variables
    ******************************************************************/
    unsigned short *buf, result;
    unsigned int sum=0;
    int ttl_val=64, msg_count=0, i, flag=1,
            msg_received_count=0;

    char *ip=(char*)malloc(NI_MAXHOST*sizeof(char)), buf_host[NI_MAXHOST], *ret_buf;

    struct hostent *host_entity;
    struct sockaddr_in temp_addr;

    socklen_t len;
    socklen_t addr_len;

protected:

public:

    /*******************************************************************
            * Nettools methods
    ******************************************************************/
    static void intHandler(int);                                // Interrupt handler
    unsigned short checksum(ping_pkt*, int);                    //Calculating the Check Sum
    char *dns_lookup(char*, struct sockaddr_in*);               // Performs a DNS lookup
    char* reverse_dns_lookup(char*);                            // Resolves the reverse lookup of the hostname
    void send_ping(int, struct sockaddr_in *,                   // make a ping request
                   char*, char*, char*);
    void ping(int, char*[]);                                    // Infinite ping test
    float ping10(int, char*[]);                        // 10 seconds ping test and return success packets
    float send_ping10(int, struct sockaddr_in *,      // make a ping request
    char*, char*, char*);
};

#endif //NETTOOLS_NETTOOLS_HPP