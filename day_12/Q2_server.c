#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/un.h>


// server
#define SERV_PORT	2809
#define SERV_IP		"127.0.0.1"
int main() {
	int serv_fd, cli_fd, ret;
	struct sockaddr_un serv_addr, cli_addr;
	socklen_t socklen;
	int num1, num2, res;
	serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(serv_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sun_family = AF_UNIX;
	serv_addr.sun_path == "/tmp/desd_socket";
	ret = bind(serv_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("bind() failed");
		_exit(2);
	}

	listen(serv_fd, 5);

	socklen = sizeof(cli_addr);
	cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
	if(cli_fd < 0) {
		perror("accept() failed");
		_exit(3);
	}

//	while(1) {
		read(cli_fd, &num1, sizeof(num1));
		read(cli_fd, &num2, sizeof(num2));
		printf("client: %d %d\n", num1, num2);
        
		res = num1 + num2;
		printf("server: ");
		scanf("%d",&res);
		write(cli_fd, &res, sizeof(res));
    	close(cli_fd);

//	shutdown(serv_fd, SHUT_RDWR);
//    }
	shutdown(serv_fd, SHUT_RDWR);
return 0;
}

