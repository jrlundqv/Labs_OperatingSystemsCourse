#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct process
{
	/* Values initialized for each process */
	int id;
	int arrivaltime;  /* Time process arrives and wishes to start */
	int runtime;      /* Time process requires to complete job */

	/* Values algorithm may use to track processes */
	int starttime;
	int endtime;
};


struct process proc[100];


int read_file(char fileName[14])
{
	FILE *pFile;
	pFile = fopen(fileName, "r");

	if (pFile == NULL)
	{
		printf("Error! Could not open file\n");
		exit(-1);
	}
	int i = 0;
	while (fscanf(pFile, "%d%d%d", &proc[i].id, &proc[i].arrivaltime, &proc[i].runtime) != EOF)
	{
		proc[i].starttime = 0;
		proc[i].endtime = 0;
		i++;
	}
	fclose(pFile);
	return i;
}


void first_come_first_served(char argv[14], int n)
{
	int i = 0;
	char readFileName[14]= "";
	strcat(readFileName, argv);

	char writeFileName[] = "FCFS";
	strcat(writeFileName, readFileName);

	FILE *FCFSfile;

	FCFSfile = fopen(writeFileName, "w");

	int index, time = 0;
	struct process nextProcess = proc[0], lastProcess = proc[0];
	for (i = 0; i < n; i++)
	{
		if (proc[i].arrivaltime > lastProcess.arrivaltime) lastProcess = proc[i];
		else if ((proc[i].arrivaltime == lastProcess.arrivaltime) && (proc[i].runtime > lastProcess.runtime)) lastProcess = proc[i];
	}
	for (int j = 0; j < n; j++)
	{
		nextProcess = lastProcess;
		for (i = 0; i < n; i++)
		{
			if (proc[i].endtime == 0)
			{
				if (proc[i].arrivaltime < nextProcess.arrivaltime)
				{
					nextProcess = proc[i];
					index = i;
				}
				else if (proc[i].arrivaltime == nextProcess.arrivaltime)
				{
					if (proc[i].id == lastProcess.id)
					{
						nextProcess = proc[i];
						index = i;
					}
					if (proc[i].runtime < nextProcess.runtime)
					{
						nextProcess = proc[i];
						index = i;
					}
				}
			}
		}
		while (proc[index].arrivaltime > time)
		{
			time += 1;
		}
		proc[index].starttime = time;
		time += proc[index].runtime;
		proc[index].endtime = time;
		fprintf(FCFSfile, "Process %d started at time %d and finished at time %d\n", proc[index].id, proc[index].starttime, proc[index].endtime);
	}
	fclose(FCFSfile);
}


void shortest_remaining_time(char argv[14])
{
	char readFileName[14]= "";
	strcat(readFileName, argv);

	char writeFileName[] = "STRN";
	strcat(writeFileName, readFileName);

	FILE *STRNfile;

	STRNfile = fopen(writeFileName, "w");

	// while (processes left to run)
		// check if process has arrived yet
			// run the process with shortest time remaining
		//
/*	int index, time = 0, total_time = 0;
	struct process nextProcess = proc[0], lastProcess = proc[0];
	for (i = 0; i < n; i++)
	{
		total_time += proc[i].runtime;
		if (proc[i].arrivaltime > lastProcess.arrivaltime) lastProcess = proc[i];
		else if ((proc[i].arrivaltime == lastProcess.arrivaltime) && (proc[i].runtime > lastProcess.runtime)) lastProcess = proc[i];
	}
	for (i = 0; i < n; i++)
	{
		nextProcess = lastProcess;
		for (int j = 0; j < n; j++)
		{
			if (proc[i].endtime == 0)
			{
				if (proc[i].runtime < nextProcess.runtime)
				{
					nextProcess = proc[i];
					index = i;
				}
				else if (proc[i].arrivaltime == nextProcess.arrivaltime)
				{
					if (proc[i].id == lastProcess.id)
					{
						nextProcess = proc[i];
						index = i;
					}
					if (proc[i].runtime < nextProcess.runtime)
					{
						nextProcess = proc[i];
						index = i;
					}
				}
			}
		}
		proc[index].starttime = time;
		time += proc[index].runtime;
		proc[index].endtime = time;
//		printf("Process %d: arrivaltime %d, starttime %d, runtime %d, endtime %d\n", proc[index].id, proc[index].arrivaltime, proc[index].starttime, proc[index].runtime, proc[index].endtime);
		fprintf(STRNfile, "Process %d: arrivaltime %d, starttime %d, runtime %d, endtime %d\n", proc[index].id, proc[index].arrivaltime, proc[index].starttime, proc[index].runtime, proc[index].endtime);
	}
*/	fclose(STRNfile);
}


int main(int argc, char *argv[])
{
	char readFileName0[14];

	int n = read_file(argv[1]);

	/* Run scheduling algorithms */

	// how the output is supposed to look
	// printf("Process %d started at time %d and finished at time %d\n", proc[i].id, proc[i].starttime, proc[i].endtime);

	first_come_first_served(argv[1], n);

	shortest_remaining_time(argv[1]);

	return 0;
}
