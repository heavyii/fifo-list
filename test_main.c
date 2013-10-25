#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "fifo_list.h"

int main(int argc, char **argv) {
	int i;
	int num;
	char *data = NULL;
	struct fifo_node *head = NULL;
	
	if (argc != 2) {
		printf("test fifo_list: %s [n]\n", argv[0]);
		exit(0);
	}
	num = atoi(argv[1]);
	for (i = 0; i < num; i++) {
		data = (char *)malloc(16384);
		if (!data) {
			perror("malloc");
			break;
		}
		snprintf(data, 1024, "%d-test-data", i);
		if (fifo_in(&head, data) < 0) {
			free(data);
			data = NULL;
			break;
		}
		printf("IN: %s\n", data);
	}

	while ((data = fifo_out(&head)) != NULL) {
		printf("OUT: %s\n", (char*)data);
		free(data);
		data = NULL;
	}

	return 0;
}

