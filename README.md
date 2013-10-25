
# FIFO LIST

fifo list

##usage:

	struct fifo_node *head = NULL;
	...
	char *data = (char *)malloc(16384);
	if (!data) {
		perror("malloc");
		break;
	}
	...
	if (fifo_in(&head, data) < 0) {
		free(data);
		data = NULL;
		fprintf(stderr, "fifo_in failed\n");
	}
	...
	while ((data = fifo_out(&head)) != NULL) {
		printf("OUT: %s\n", (char*)data);
		free(data);
		data = NULL;
	}
