#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct MBlock{

	char block[32];
	char *tag;
	char *set;
	char *offset;
	int hit;
};




	
	struct MBlock;
	int memoryread=0;
	int memorywrite=0;
	int cachemiss = 0;
	int cachehit = 0;
	int numsets;
	int count2 = 0;


void FACache(struct MBlock *block, struct MBlock *Cache, int numsets, char *RorW){
	int n=0;
	char rorw = RorW[0];
	int leasthits;
	int leastindex;
	int p = 0;

	while(n<numsets){
		if(Cache[n].tag==NULL){
			Cache[n]=*block;
			cachemiss++;
			if(rorw=='W'){
				memoryread++;
				memorywrite++;
				}
			else{
				memoryread++;
				}
			break;
			}
		else if(strcmp(Cache[n].tag,block->tag)==0){
			
			Cache[n].hit++;
			cachehit++;
			if(rorw=='W'){
				memorywrite++;
				}
			
			
			}
		n++;
		}

		leasthits = Cache[0].hit;
		
		while(p<numsets){
			if(Cache[p].hit<=leasthits){
				leasthits = Cache[p].hit;
				leastindex = p;
				}
				p++;
			}
		Cache[p] = *block;
			
	
	}
void PuttoCache(char *index, int numset ,struct MBlock *block, char *MorW, struct MBlock *Cache){
	int x=0;
	int count = -1;
	int p = 0;
	int ind = 0;
	int power;
	char mOrW = MorW[0];
	
	
		
	
	
	while(block->set[x]!='\0'){
		
		count++;
		x++;
		}
		
		
	while(count>=0){	
		if(block->set[p]=='1'){
			power = pow(2,count);
			ind = ind + power;
			}
		count--;
		p++;
		}
		
		
		ind = ind%numset;
		
		
		count2++;
		
		
		
		if(Cache[ind].set==NULL){
			
			
			cachemiss++;
			
			if(mOrW=='R'){
				
				memoryread++;
				}
			else{
				
				memoryread++;
				memorywrite++;
				}
				Cache[ind] = *block;
			}
			
		else if(Cache[ind].set!=NULL) {
				
			if(strcmp(Cache[ind].set,block->set)==0){
				
				if(strcmp(Cache[ind].tag,block->tag)==0){
					cachehit++;
					
					if(mOrW=='W'){						
						memorywrite++;
						}
					
						}
					
				else{
					/*printf("set match, but tags not\n");*/
					/*printf("cach[ind] tag was %s\n",Cache[ind].tag);*/
					Cache[ind].tag = block->tag;
					/*printf("cach[ind] tag is now %s\n",Cache[ind].tag);*/
					cachemiss++;
					if(mOrW=='R'){
						/*cachemiss++;*/
						memoryread++;
						}
					else{
						/*cachemiss++;*/
						memoryread++;
						memorywrite++;
							}

						
						}
					}
				}
			
				
			}

void BinaryConvert(char *memWorR, char *address, int cachesize,struct MBlock *Cache, int blocksize, char *type){
	int startofindex;
	int cbits;
	char *tag;
	char *index;
	int p = 2;
	char c;
	int i = 0;
	char *BinC; 
	int offsize;
	struct MBlock *x;
	int ii;
	char *add;
	int size;
	
	
	numsets = cachesize/blocksize;
	offsize = log(blocksize)/log(2);
	cbits = log(numsets)/log(2);
	
	

	tag = malloc(sizeof(char)*40);
	index = malloc(sizeof(char)*40);
	
	
	
	


	
	x = malloc(sizeof(struct MBlock));
	
	while(address[p]!='\0'){
		
		
		c = address[p];
		
		switch(c){

		case '0':
			BinC = "0000";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
				else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '1':
			BinC = "0001";

			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '2':
			BinC = "0010";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
			else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '3':
			BinC = "0011";

			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '4':
			BinC = "0100";

			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '5':
			BinC = "0101";

			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '6':
			BinC = "0110";

			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '7':
			BinC = "0111";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '8':
			BinC = "1000";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case '9':
			BinC = "1001";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case 'a':
			BinC = "1010";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case 'b':
			BinC = "1011";
				if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			
			break;
		case 'c':
			BinC = "1100";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case 'd':
			BinC = "1101";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;
		case 'e':
			BinC= "1110";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);

				
				
			}
			break;
		case 'f':
			BinC ="1111";
			if(i==0){
			
			strcpy(x->block,BinC);
			
			}
		else{
			
				strcat(x->block,BinC);
				
				
			}
			break;

		default:
			
			break;
		}
		
		
		
			
			p++;
			i=1;
			}
			x->block[32] = '\0';
			if(strlen(x->block)<32){
				
				size = 32 - strlen(x->block);
				
				add = malloc((sizeof(char)*size) + strlen(x->block));

				for(ii=0;ii<size;ii++){
					
					add[ii] = '0';
					
					}
				
				strcat(add,x->block);
				strncpy(x->block,add,32);
				x->block[32] = '\0';
				
				
				
				}
			startofindex = strlen(x->block)-cbits-offsize;
		
			strncpy(index,x->block+startofindex,cbits);
			
			index[cbits] = '\0';
			
			x->set = index;
			
			strncpy(tag,x->block,22);
			
			tag[startofindex]='\0';
			x->tag = tag;

			
			
			x->hit = 0;
			
			if(strcmp(type,"direct")==0){
			PuttoCache(x->set,numsets,x,memWorR,Cache);
				}
			else{
				FACache(x,Cache,numsets,memWorR);
				}
			
			
		}
	
		
	

void getMemAdd(FILE *tracefile, int cachesize, struct MBlock *Cache, int blocksize, char *type){
	
	int csize = cachesize;
	char str[40];
	char *div;
	char *WR;
	char *MemAdd;
	
	
	while(fgets(str,40,tracefile)!=NULL){
		
		
		if(str[0]!='0'){
			break;
			}
		div = strtok(str," :");
		
		div = strtok(NULL," :");
		WR = div;
		
		div = strtok(NULL," :");
		MemAdd = div;
		
		
		BinaryConvert(WR, MemAdd,csize,Cache,blocksize,type);
}
}





int main(int argc, char *arg[]){
	
	if(strcmp(arg[1],"-h")==0){
		printf("1st arg: program name\n");
		printf("2nd arg: size of cache\n");
		printf("3rd arg: associativity\n");
		printf("4th arg: size of memory block\n");
		printf("5th arg: file name\n");
		}
	else if(argc==5){
	FILE *fp = fopen(arg[4],"r");
	int cachesize = atoi(arg[1]);
	char *type = arg[2];
	int blocksize = atoi(arg[3]);
	struct MBlock *Cache = malloc(sizeof(struct MBlock)*cachesize);
	getMemAdd(fp,cachesize,Cache,blocksize,type);
	
	printf("Memory reads: %d\n", memoryread);
	printf("Memory Writes %d\n", memorywrite);
	printf("Cache hits: %d\n", cachehit);
	printf("Cache miss: %d", cachemiss);
	}
	else{
		printf("too few or many arguments try again");
		}
	
	return 0;
}
	
