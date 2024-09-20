#include <stdio.h>
#include <sys/resource.h>

int main()
{
	struct rlimit p;
	int i = getrlimit(RLIMIT_MSGQUEUE,&p);
	if (!i)
		perror("");
	if (p.rlim_cur == RLIM_INFINITY)
		printf("RLIM_INFINITY\n");
	printf("message queue limits..\n");
	printf("Soft limit : %ld\n",p.rlim_cur);
	printf("Hard limit : %ld\n",p.rlim_max);

	getrlimit(RLIMIT_AS ,&p);
	if (p.rlim_cur == RLIM_INFINITY)
		printf("No limit on maximum size of the process's virtual memory\n");
	else {
	printf("Soft limit : %ld\n",p.rlim_cur);
	printf("Hard Limit : %ld \n",p.rlim_max);}
	
	getrlimit(RLIMIT_CORE, &p);
	if (p.rlim_cur == RLIM_INFINITY)
		printf("No limit on maximum size of core file.\n");
	else {
		printf("limit on maximum size of core file...\n");
		printf("Soft limit : %ld\n",p.rlim_cur);
        	printf("Hard Limit : %ld \n",p.rlim_max);
	}

	getrlimit(RLIMIT_CPU, &p);
	if (p.rlim_cur == RLIM_INFINITY)
	{
		printf("no limit on the amount of cpu time that the process can consume\n");
	}
	else{
	printf("Softlimit : %ld\n",p.rlim_cur);
	printf("Hardlimit : %ld\n",p.rlim_cur);}
	
	getrlimit(RLIMIT_FSIZE,&p);
	if(p.rlim_cur == RLIM_INFINITY){
		printf("no limit on maximum size of files that the process may create\n");
	}

	getrlimit(RLIMIT_DATA,&p);
	if (p.rlim_cur == RLIM_INFINITY)
	{
		printf("no limit on the size of the process data segment\n");
	}
	
}
