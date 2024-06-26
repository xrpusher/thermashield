#pragma once

#include "lwip/tcp.h"
#include "sensors.h"
#include "string.h"

extern int16_t temp_bme280;
extern int16_t temp_bmp280;

static struct tcp_pcb *testpcb;
err_t error;

uint32_t length;
char id[32];
char string[256] = "\0";
char string_content[128] = "\0";

uint32_t data = 0xdeadbeef;
ip_addr_t ip;

uint32_t tcp_send_packet(void)
{
    // char *string = "GET / HTTP/1.0\r\nHost: ya.ru\r\n\r\n ";
    // char *string = "GET /api/ HTTP/1.1\r\nHost: thermashield.duckdns.org\r\n\r\n ";
    // char *string = "POST /api/update/ HTTP/1.0\r\nHost:thermashield.duckdns.org\r\n\r\n ";
    // char *string = "POST /api/update/ HTTP/1.1\r\nHost: thermashield.duckdns.org\r\nContent-Type: application/json\r\nAccept: */*\r\nContent-Length: 40\r\n\r\n{\"sensor_id\": \"222\",\"temperature\": 12.2}";
    strcpy(id,"device rack 1");
    length = sprintf(string_content, "%s%s%s%d%c%d%c", "{\"sensor_id\":\"", id, "\",\"temperature\":", temp_bmp280 / 100, '.', ((uint16_t)temp_bmp280 % 100) / 10, '}');
    uint32_t len = sprintf(string, "%s%d%s%s%s", "POST /api/update/ HTTP/1.1\r\nHost: thermashield.duckdns.org\r\nContent-Type: application/json\r\nAccept: */*\r\nContent-Length: ", length, "\r\n\r\n", string_content, "\r\n");
    printf("string_content: %s  %d\n\n\n", string_content, length);
    printf("request:\n%s\n\n", string);

    // uint32_t len = strlen(string);
    err_t error;

    /* push to buffer */    
    error = tcp_write(testpcb, string, len, TCP_WRITE_FLAG_COPY);

    if (error) {
        printf("ERROR: Code: %d (tcp_send_packet :: tcp_write)\n", error);
        return 1;
    }

    /* now send */
    error = tcp_output(testpcb);
    if (error) {
        printf("ERROR: Code: %d (tcp_send_packet :: tcp_output)\n", error);
        return 1;
    }

    memset(string_content,'\0',sizeof(string_content));
    memset(string,'\0',sizeof(string));
    //*string_content = '\0';
    //*string = '\0';

    return 0;
}

/* connection established callback, err is unused and only return 0 */
err_t connectCallback(void *arg, struct tcp_pcb *tpcb, err_t err)
{
    printf("Connection Established.\n");
    printf("Now sending a packet\n");
    tcp_send_packet();
    return 0;
}

err_t tcpRecvCallback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
    printf("Data recieved.\n");
    if (p == NULL) {
        // printf("The remote host closed the connection.\n");
        // printf("Now I'm closing the connection.\n\n");
        // pbuf_free(p);
        // tcp_close(tpcb);
        // return ERR_CLSD;
        // return ERR_ABRT;
    } else {
        printf("Number of pbufs %d\n", pbuf_clen(p));
        printf("Contents of pbuf: \n%s\n\n", (char *)p->payload);

        printf("The remote host closed the connection.\n");
        printf("Now I'm closing the connection.\n\n");
        error = tcp_close(tpcb);
        printf("TCP CLOSE status: %d\n", error);
        pbuf_free(p);
        return ERR_CLSD;
    }

    return 0;
}

void tcpErrorHandler (void *arg, err_t err){
    (void)arg;
    printf("TCP Error: %d\n", err);
}

void tcp_setup(void)
{
    //uint32_t data = 0xdeadbeef;

    /* create an ip */
    IP_ADDR4(&ip, 45,14,247,122);    //IP of my PHP server  45.14.247.122

    /* create the control block */
    testpcb = tcp_new();    //testpcb is a global struct tcp_pcb
                            // as defined by lwIP

    /* dummy data to pass to callbacks*/
    tcp_arg(testpcb, &data);

    error = tcp_bind(testpcb, IP_ANY_TYPE, 1234); // get local ip
    printf("TCP BIND status: %d\n", error);
    xtimer_sleep(2);
    

    /* register callbacks with the pcb */
    tcp_err(testpcb, tcpErrorHandler);
    tcp_recv(testpcb, tcpRecvCallback);
    //tcp_sent(testpcb, tcpSendCallback);

    /* now connect */
    error = tcp_connect(testpcb, &ip, 80, connectCallback);
    printf("TCP Connect status: %d\n", error);

    if (error) {

    }

}
