#include <stdio.h>
#include <sys/resource.h>

int main()
{
	struct rlimit r ;
	getrlimit(RLIMIT_MSGQUEUE,&r);
	printf("soft limit : %ld\n",r.rlim_cur);
	printf("Hard limit : %ld\n",r.rlim_max);
	r.rlim_cur = 819000;
	setrlimit(RLIMIT_MSGQUEUE,&r);
	getrlimit(RLIMIT_MSGQUEUE,&r);
	printf("soft limit : %ld\n",r.rlim_cur);
}
