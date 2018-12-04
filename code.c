
/* 
 * File:   code.c
 * Author: Viktitors
 *
 * 
 */
#include <stdio.h>
#include <stdlib.h>
int feasibility(int packet, int total);
//for the quicksort algorithm:
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char** argv) {
    int totalWeight=4000;   //maximum weight of the truck=4000kg
    int weight=0;   //cummulative weight of the packets loaded
    int numberOfPackets; 
    int i,j=0;
    int cash=0;//amount of packets that we have loaded in the truck
    
    
    
    //INTRODUCING VALUES FOR THE ALGORITHM:
    
    printf("Enter the number of packets:\n");
    scanf("%d", &numberOfPackets);
    
    int packetWeight[numberOfPackets];
    int packets[numberOfPackets];//to print the loaded packets with their weight
    
    //CANDIDATES: ----->	O(n)	
    for(i=0;i<numberOfPackets;i++){
        printf("Introduce weight for packet number: %d\n",i+1);
        scanf("%d",&packetWeight[i]);
    }
    
    
    //QUICK SORTING:--->O(n·log(n))
  qsort(packetWeight, numberOfPackets, sizeof(int), compare);

    //CANDIDATES ORDERED PRINT:---->O(n)
  printf("Total of packets ordered:\n");
    for(i=0;i<numberOfPackets;i++){
        printf("packet: %d\n",packetWeight[i]);   
    }
  
    j=0;
    i=0;
    
    //O(n):
    while (i<numberOfPackets) {
        if(packetWeight[i]+weight<=totalWeight){//if the selected packet fits in the lorry-->add it to the lorry packets
            weight=feasibility(packetWeight[i],weight);    //feasibility       
            cash++; //and add 1 to the number of packets added
           
            packets[j]=packetWeight[i];//add the packet to the array of added packets
            j++;                      
        }
        i++;        
    }
    
    printf("Number of packets selected for the service: %d\n\n",cash);
    printf("Total amount of money to pay for the service: %d euros\n",cash*10);//multiply the number of packets loaded by 10 to get the money cost
    
    //PRINT PACKETS:---->O(n)
    printf("Packets selected for the transport:\n");
    for(i=0;i<cash;i++){
        printf("Packet: %d\n",packets[i]);
    }
    printf("Weight left: %d\n",totalWeight-weight);
    
    system("pause");
}
//return the sum of the selected packet plus the weight of the already added packets ONLY IF THE CONDITION IS FULFILLED IN THE WHILE
int feasibility(int packet, int total) {
    return packet+total;
}