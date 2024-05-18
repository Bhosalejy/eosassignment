#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/un.h>


// client
#define SERV_PORT	2809
#define SERV_IP		"127.0.0.1"

int main() {
	int cli_fd, ret;
	struct sockaddr_un serv_addr;
	int num1, num2, res;
	cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(cli_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

	serv_addr.sun_family = AF_UNIX;
	serv_addr.sun_path == "/tmp/desd_socket";
	ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	if(ret < 0) {
		perror("connect() failed");
		_exit(2);
	}

//	while(1) {
		printf("client: ");
		printf("Enter two numbers :");
		scanf("%d %d", &num1, &num2);

		write(cli_fd, &num1, sizeof(num1));
		write(cli_fd, &num1, sizeof(num1));
		

		read(cli_fd, &res, sizeof(res));
		printf("server: %d\n", res);

	close(cli_fd);
//   }	
	return 0;
}
