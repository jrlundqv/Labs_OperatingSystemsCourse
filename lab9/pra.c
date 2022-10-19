#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PageFrame
{
	int Id; /* Page ID */
	int ArrivalTime; /* Time that the page arrives */
	int LastRefTime; /* the Last time that the page was refered in the past */
	int Rbit; /* Referenced(R) bit */
	int Mbit; /* Modified(M) bit */
};


struct PageFrame page[100];


void first_in_first_out(int n)
{
	int i;
	struct PageFrame P = page[0];
	for (i = 0; i < n; i++)
	{
		if (page[i].ArrivalTime < P.ArrivalTime) P = page[i];
	}
	printf("Page selected: Page %d, Loaded at time %d, Last Refered at time %d, Rbit %d, Mbit %d\n", P.Id, P.ArrivalTime, P.LastRefTime, P.Rbit, P.Mbit);
}


void least_recently_used(int n)
{
	int i;
	struct PageFrame P = page[0];
	for (i = 0; i < n; i++)
	{
		if (page[i].LastRefTime < P.LastRefTime) P = page[i];
	}
	printf("Page selected: Page %d, Loaded at time %d, Last Refered at time %d, Rbit %d, Mbit %d\n", P.Id, P.ArrivalTime, P.LastRefTime, P.Rbit, P.Mbit);
}


void second_chance(int n)
{
	int i;
	struct PageFrame P = page[0];
	for (i = 0; i < n; i++)
	{
		if (page[i].ArrivalTime < P.ArrivalTime) P = page[i];
	}
	for (i = 0; i < n; i++)
	{
		if (!page[i].Rbit) P = page[i];
	}
	for (i = 0; i < n; i++)
	{
		if (page[i].ArrivalTime < P.ArrivalTime && !page[i].Rbit) P = page[i];
	}
	printf("Page selected: Page %d, Loaded at time %d, Last Refered at time %d, Rbit %d, Mbit %d\n", P.Id, P.ArrivalTime, P.LastRefTime, P.Rbit, P.Mbit);
}


int main()
{
	FILE *pFile= fopen("Testcase0.txt", "r");
	if (pFile == NULL)
	{
		printf("Error! Could not open file\n");
		exit(-1);
	}

	int i = 0;
	printf("Page\tArrival\tLastRef\tRbit\tMbit\n");

	while (fscanf(pFile, "%d%d%d%d%d", &page[i].Id, &page[i].ArrivalTime, &page[i].LastRefTime, &page[i].Rbit, &page[i].Mbit) != EOF)
	{
		printf("%d\t%d\t%d\t%d\t%d\n", page[i].Id, page[i].ArrivalTime, page[i].LastRefTime, page[i].Rbit, page[i].Mbit);
		i++;
	}

	/* Run page replacement algorithms */
	printf("First-in-First-out...\n");
	first_in_first_out(i);

	printf("Least-Recently-Used...\n");
	least_recently_used(i);

	printf("Second-Chance...\n");
	second_chance(i);

	return 0;
}
