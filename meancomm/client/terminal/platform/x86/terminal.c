#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <stdio.h>
#include <linux/in.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
//#include <arpa/inet.h>  
//#include <netinet/in.h>  
#include "cJSON.h"
 
#define MAXLINE 1024  
  
int cjson_post(char *ip,int port,char *page,char *msg)
{  
    int sockfd,n;  
    char recvline[MAXLINE];  
    struct sockaddr_in servaddr;  
    char content[4096];  
    char content_page[50];  
    sprintf(content_page,"POST /%s HTTP/1.1\r\n",page);  
    char content_host[50];  
    sprintf(content_host,"HOST: %s:%d\r\n",ip,port);  
    char content_type[] = "Content-Type: application/json\r\n";  
    char content_len[50];  
    sprintf(content_len,"Content-Length: %d\r\n\r\n",strlen(msg));  
    sprintf(content,"%s%s%s%s%s",content_page,content_host,content_type,content_len,msg);  

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)  
        printf("socket error\n");  
    bzero(&servaddr,sizeof(servaddr));  
    servaddr.sin_family = AF_INET;  
    servaddr.sin_port = htons(port);  
    if(inet_pton(AF_INET,ip,&servaddr.sin_addr) <= 0)  
        printf("inet_pton error\n");  
    if(connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)  
        printf("connect error\n");  
    write(sockfd,content,strlen(content)); 

    while((n = read(sockfd,recvline,MAXLINE)) > 0)  
    {  
        recvline[n] = 0;  
    }  
    if(n < 0)  
        printf("read error\n");  
	
    printf("rev:\n%s\n", recvline);
  
}  
  
int main(int argc, char **argv) 
{  
    cJSON * json = NULL;
    char * sjson = NULL;
	
	printf("cJSON Version: %s\n", cJSON_Version());
	json = cJSON_CreateObject();
	cJSON_AddItemToObject(json, "name", cJSON_CreateString("Jack")); 
	cJSON_AddItemToObject(json, "id", cJSON_CreateString("12312")); 
	cJSON_AddItemToObject(json, "notes", cJSON_CreateString("notesmeanning"));
	sjson = cJSON_Print(json);
    cJSON_Delete(json);
	 
    cjson_post("139.159.162.170", 3006, "comm/comm_process", sjson);  
	
    exit(0);  
}  
