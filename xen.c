/* Program that implements, basic libvirt functionalities */

#include <stdio.h>
#include <stdlib.h>
#include <libvirt/libvirt.h>

int main(int argc, char *argv[])
{
    virConnectPtr connt;
    virDomainPtr vdptr;
    int val=-1;
    int ch;	
    connt = virConnectOpen("xen:///");
    if (connt == NULL) {
        fprintf(stderr, "Failed to open connection\n");
        return 1;
    }

while(1)
{

printf("\nEnter your choice....");
printf("\n1.Suspend Instance\n2.Resume Instance\n3.Stop Instance\n4.Start Instance\n5.Exit from program");
scanf("%d",&ch);

vdptr=virDomainLookupById(connt,1);

switch(ch){

case 1 : val=virDomainSuspend(vdptr); //Suspending an instance
	if(val==0)
	{
	   printf("\nSuccessfully suspended");
	}else{
	   printf("\nFailed to suspend");	
	}
	break;

case 2 : val=virDomainResume(vdptr); //Resume an instance
	 if(val==0)
	 {
	     printf("Successfully resumed");
	 }else{
	     printf("Failed to resume");	
	 }
	 break;

case 3 : val=virDomainDestroy(vdptr); // Stops an instance
	 if(val==0)
	 {
	   printf("Successfully destroyed");
	 }else{
	   printf("Failed to destroy");	
	 }
	 break;

case 4 : val=virDomainCreate(vdptr); //Starts an instance
	 if(val==0)
	 {
	   printf("Successfully created ");
	 }else{
	   printf("Failed to create");	
	 }
	 break;

case 5 : virConnectClose(connt); // Close connection and exit
	 exit(0);
	 break;

default : exit(0);
	  break;
}  
}
return (0);
}
