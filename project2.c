
/* Panagiotis Leonis
    AM: 2022202000123
    dit20123@go.uop.gr
   --------------------
   Ervis Gjata
    AM: 2022202000043
    dit20043@go.uop.gr
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "header.h"	//ka8olikes metablhtes,dhlwseis sunarthsewn included

/////////////////////////////////////////////////////////////////////////////////////
                                //MAIN function///
////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	post *t;

	int i,wrong,j,reps;		// reps is for the function print/printR

	char len;

	system("clear");

	do
	{
	  for(i=0; i<15; i++)
		array[i]=NULL;

	  printf("\n$TraSH> ");
	  fgets(text, sizeof(text),stdin);


	  array[0] = strtok(text, " \n");

          if (array[0] == NULL)
          {
                printf("No text to search!!\n");
		continue;
          }

          len=strlen(array[0]);

//case sensitive fixed for the 1st command
          for(i=0; i<len; i++)
          {
               array[0][i]=tolower(array[0][i]);
          }

//case newpost
	  if( (array[0][0]=='n') && (array[0][1]=='e') && (array[0][2]=='w') && (array[0][3]=='p') && (array[0][4]=='o') && (array[0][5]=='s') && (array[0][6]=='t') && (array[0][7]=='\0'))
	  {
		for (i=1; i<100; i++)
    		{
        	  array[i] = strtok(NULL, ";");

        	  if (array[i] == NULL)
            		break;
    		}

                i=ONPostCheck();	//ginontai ola ta checks pou xreiazetai wste to newpost na einai valid

                if(i == 1)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

		lentext=strlen(array[1]);
		leninfo=strlen(array[2]);
		lentype=strlen(array[3]);
		lenlink=strlen(array[4]);

		PostSave = 0;		//to put the ' kbrd ' in the learnedfrom in list and no the ' list '

		NewPost();

		printf("\n1 post added successfully!!!\n");
	  }

//case oldpost for bonus 10%
          else if( (array[0][0]=='o') && (array[0][1]=='l') && (array[0][2]=='d') && (array[0][3]=='p') && (array[0][4]=='o') && (array[0][5]=='s') && (array[0][6]=='t') && (array[0][7]=='\0'))
          {
                for (i=1; i<100; i++)
                {
                  array[i] = strtok(NULL, ";");

                  if (array[i] == NULL)
                        break;
                }

                i=ONPostCheck();	//ginontai ola ta checks pou xreiazetai wste to oldpost na einai valid

                if(i == 1)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

		lentext=strlen(array[1]);
		leninfo=strlen(array[2]);
		lentype=strlen(array[3]);
		lenlink=strlen(array[4]);

		PostSave = 0;		//to put the ' kbrd ' in the learnedfrom in list and no the ' list '

		OldPost();

		printf("\n1 post added successfully!!!\n");

	  }

//case count ...
	  else if( (array[0][0]=='c') && (array[0][1]=='o') && (array[0][2]=='u') && (array[0][3]=='n') && (array[0][4]=='t') && (array[0][5]=='\0') )
	  {

		array[1] = strtok(NULL, "\n");

		if(array[1]==NULL)
		{
		  printf("\nINCERT ERROR!!\n");
                  continue;
		}

		len=strlen(array[1]);

		for(i=0; i<len; i++)
          	{
                   array[1][i]=tolower(array[1][i]);
          	}

	//check if there is a normal insert for the count and then calls Count();

		if( i=strcmp(array[1],"reactions") == 0)
		{
                	Count(1);
                }

		else if( i=strcmp(array[1],"comments") == 0)
                {
	                Count(2);
                }

		else if( i=strcmp(array[1],"shares") == 0)
                {
	                Count(3);
                }

		else if( i=strcmp(array[1],"likes") == 0)
                {
	                Count(4);
                }

		else if( i=strcmp(array[1],"loves") == 0)
                {
	                Count(5);
                }

		else if( i=strcmp(array[1],"wows") == 0)
                {
	                Count(6);
                }

		else if( i=strcmp(array[1],"hahas") == 0)
                {
	                Count(7);
                }

		else if( i=strcmp(array[1],"sads") == 0)
                {
	                Count(8);
                }

		else if( i=strcmp(array[1],"angrys") == 0)
                {
	                Count(9);
                }

		else
		{
		  printf("\nINCERT ERROR!!\n");
                  continue;
		}

	  }

//case typecount ....
	  else if( (array[0][0]=='t') && (array[0][1]=='y') && (array[0][2]=='p') && (array[0][3]=='e') && (array[0][4]=='c') && (array[0][5]=='o') && (array[0][6]=='u') && (array[0][7]=='n') && (array[0][8]=='t') && (array[0][9]=='\0'))
	  {
		array[1] = strtok(NULL, "\n");

                if(array[1]==NULL)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

                len=strlen(array[1]);

                for(i=0; i<len; i++)
                {
                   array[1][i]=tolower(array[1][i]);
                }

	//check if there is a normal insert for the typecount and then calls TypeCount();

                if( i=strcmp(array[1],"status") == 0)
                {
	                TypeCount(1);
                }

                else if( i=strcmp(array[1],"photo") == 0)
                {
	                TypeCount(2);
                }

                else if( i=strcmp(array[1],"video") == 0)
                {
	                TypeCount(3);
                }

                else if( i=strcmp(array[1],"link") == 0)
                {
	                TypeCount(4);
                }

		else
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }
	  }

//case findT/findI/findL ....
	  else if( (array[0][0]=='f') && (array[0][1]=='i') && (array[0][2]=='n') && (array[0][3]=='d') && ( (array[0][4]=='t') || (array[0][4]=='i') || (array[0][4]=='l') ) && (array[0][5]=='\0') )
	  {
		array[1] = strtok(NULL, "\n");

                if(array[1]==NULL)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

		FindTIL();
	  }

//case printA/printB ....
	  else if( (array[0][0]=='p') && (array[0][1]=='r') && (array[0][2]=='i') && (array[0][3]=='n') && (array[0][4]=='t') && ((array[0][5]=='a') || (array[0][5]=='b')) && (array[0][6]=='\0') )
	  {
		array[1] = strtok(NULL, "\n");

                if(array[1]==NULL)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

	//diaxorismos twn mm,dd,yyyy
                DateTime[0]= strtok(array[1],"/");
                DateTime[1]=strtok(NULL,"/");
                DateTime[2]=strtok(NULL," ");

		wrong=0;

		for(i=0; i<3; i++)
		{
		  if(DateTime[i] == NULL)
		  {
                    wrong++;
                  }
		}

		if(wrong != 0)
		{
		  printf("\nINCERT ERROR!!\n");
                  continue;
		}


	//elenxos twn time kai date gia alfa
                wrong=0;

                for(i=0; i<3; i++)
                {
                  for(j=0; j<2; j++)
                  {
                        if(DateTime[i][j]=='\0')
                          break;

                        else if( ( DateTime[i][j] < '0') || ( DateTime[i][j] > '9') )
                        {
                                wrong++;
                                break;
                        }
                  }
                }

                if(wrong!=0)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

	//metatroph twn date se int
                for(i=0; i<3; i++)
                {
                  dtime[i]=atoi(DateTime[i]);
                }

	//check if 1<=month<=12
                if( (dtime[0] < 1) || (dtime[0] > 12) )
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

	//check if 1<=day<=31
                if( (dtime[1] < 1) || (dtime[1] > 31) )
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

	//check if 1950<=year<=2025 || 0<=year<=25 || 50<=year<=99
                wrong=0;

                if( (dtime[2] >= 0/*2000*/) && (dtime[2] <= 25/*2025*/) )
                {
                  wrong++;
                }

                if( (dtime[2] >= 50/*1950*/) && (dtime[2] <= 99/*1999*/) )
                {
                  wrong++;
                }

                if( (dtime[2] >= 1950) && (dtime[2] <= 2025) )
                {
                  wrong++;
                }

                if(wrong==0)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

		PrintAB();

	  }

//case print/pritR ....
	  else if( (array[0][0]=='p') && (array[0][1]=='r') && (array[0][2]=='i') && (array[0][3]=='n') && (array[0][4]=='t') && ((array[0][5]=='\0') || (array[0][5]=='r')))
	  {
		array[1] = strtok(NULL, "\n");

                if(array[1]==NULL)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

	//elenxos gia ton ari8mo na mhn exei xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[1][i]=='\0')
                  {
                        break;
                  }

                  if( (array[1][i] < '0') || (array[1][i] > '9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

		reps=atoi(array[1]);

		Print_R(reps);
	  }

//case deleteN/deleteO
	  else if( (array[0][0]=='d') && (array[0][1]=='e') && (array[0][2]=='l') && (array[0][3]=='e') && (array[0][4]=='t') && (array[0][5]=='e') && ((array[0][6]=='n') || (array[0][6]=='o')) && (array[0][7]=='\0') )
	  {

		DeleteNO();

		if( ((i=strcmp(array[0],"deleten")) == 0) && (head != NULL))        //deleteN = diagrafh apo to telos ths listas
		{
		  printf("\nThe newest post has been deleted!!!\n");
		}
		else if( ((i=strcmp(array[0],"deleteo")) == 0) && (head != NULL))
		{
		  printf("\nThe oldest post has been deleted!!!\n");
		}
	  }

//case save ....
	  else if( (array[0][0]=='s') && (array[0][1]=='a') && (array[0][2]=='v') && (array[0][3]=='e') && (array[0][4]=='\0') )
	  {
		array[1] = strtok(NULL, "\n");

                if(array[1]==NULL)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

		fp = fopen(array[1],"w");

		if (fp == NULL)
		{
	   	  printf("Error opening file \"%s\"\n", array[1]);
	   	  continue;
   		}

		Save();

		fclose(fp);

	  }
//case load ...
	  else if( (array[0][0]=='l') && (array[0][1]=='o') && (array[0][2]=='a') && (array[0][3]=='d') && (array[0][4]=='\0') )
	  {
		array[1] = strtok(NULL, "\n");

                if(array[1]==NULL)
                {
                  printf("\nINCERT ERROR!!\n");
                  continue;
                }

		fp = fopen(array[1],"r");

		if (fp == NULL)
                {
                  printf("\nError opening file \"%s\"\n", array[1]);
                  continue;
                }

		Load();

		fclose(fp);
	  }

//case exit
	  else if( (array[0][0]=='e') && (array[0][1]=='x') && (array[0][2]=='i') && (array[0][3]=='t') && (array[0][4]=='\0') )
	  {
		if(head != NULL)		//free twn stoixeiwn pou den diegrapse o xrhsths kai paramenoun sth mnhmh
		{
		  while(head != NULL)
		  {
			t=head->next;
			free(head);
			head=t;
		  }
		}

		printf("\nEnd of insert\n\nBye Bye!!");
		exit(0);
	  }

//case clear (for a little bonus)
	  else if( (array[0][0]=='c') && (array[0][1]=='l') && (array[0][2]=='e') && (array[0][3]=='a') && (array[0][4]=='r') && (array[0][5]=='\0'))
	  {
		system("clear");
	  }

//case help (for a little bonus)
	  else if( (array[0][0]=='h') && (array[0][1]=='e') && (array[0][2]=='l') && (array[0][3]=='p') && (array[0][4]=='\0') )
	  {
		printf("\n1) newpost text;info;type;link;mm/dd/yyyy hh:mm:ss;reactions;comments;shares;likes;loves;wows;hahas;sads;angrys\n\n");
		printf("2) count <reactions/likes/loves/wows/hahas/sads/angrys/comments/shares>\n\n");
		printf("3) TypeCount <status/photo/video/link>\n\n");
		printf("4) findT/FindI/FindL <aSs or iva or (*) or etc.>\n\n");
		printf("5) printA/printB <date>\n\n");
		printf("6) print/printR <number>\n\n");
		printf("7) deleteN/deleteO\n\n");
		printf("8) save <name of file>\n\n");
		printf("9) load <name of file>\n\n");
		printf("10) exit\n\n11) clear\n\n");
	  }

//case den einai tipota apo ta panw
	  else
	  {
	    printf("\nINCERT ERROR!!\n");
	  }


	}while(1);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
				//functions bodys///
////////////////////////////////////////////////////////////////////////////////////

//Newpost Function
void NewPost(void)
{
	post *tmp=head,*n;

//malloc for the new insert in the list
	n=(post *) malloc(sizeof(post));

	if(n == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

//malloc for the text,info,type,link
	n->text=(char*)malloc((lentext+1)*sizeof(char));

	if(n->text == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

	n->info=(char*)malloc((leninfo+1)*sizeof(char));

	if(n->info == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

	n->type=(char*)malloc((lentype+1)*sizeof(char));

	if(n->type == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

	n->link=(char*)malloc((lenlink+1)*sizeof(char));

	if(n->link == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

//string copy from array[i] (1<=i<=4) to the list
	n->text=strcpy(n->text,array[1]);
	n->info=strcpy(n->info,array[2]);
	n->type=strcpy(n->type,array[3]);
	n->link=strcpy(n->link,array[4]);

//month,day,year,hour,minute,second added in list
	n->posted.month=dtime[0];
	n->posted.day=dtime[1];
	n->posted.year=dtime[2];
	n->posted.hour=dtime[3];
	n->posted.minute=dtime[4];
	n->posted.second=dtime[5];

//likes,loves,wows,hahas,sads,angrys added in list
	n->feelings.like=likes;
	n->feelings.love=loves;
	n->feelings.wow=wows;
	n->feelings.haha=hahas;
	n->feelings.sad=sads;
	n->feelings.angry=angrys;

//rections,comments,shares added in list
	n->react=reaction;
	n->comment=comments;
	n->share=shares;

//kbrd or file added in list (learnedFrom)
	if(PostSave == 0)
	{
	  n->learnedFrom[0]='k';
	  n->learnedFrom[1]='b';
	  n->learnedFrom[2]='r';
	  n->learnedFrom[3]='d';
	  n->learnedFrom[4]='\0';
	}
	else
	{
	  n->learnedFrom[0]='f';
          n->learnedFrom[1]='i';
          n->learnedFrom[2]='l';
          n->learnedFrom[3]='e';
          n->learnedFrom[4]='\0';
	}

	n->next=NULL;	//topo8ethsh tou NULL sto teleytaio stoixeio ths listas
	tail=n;		//tail=to kainourio stoixeio to opoio einai to telutaio ths listas

//ean h lista einai adeia
	if(head==NULL)
	{
	  head=n;
	  n->prev=NULL;
	  return ;
	}
	else //ean h lista exei toulaxiston ena stoixeio
	{
	  while(tmp->next != NULL)
	  {
		tmp=tmp->next;
	  }
	  tmp->next=n;
	  n->prev=tmp;
	  return ;
	}

}

//Oldpost Function
void OldPost(void)
{
	post *tmp,*n;

//malloc for the new insert in the list
        n=(post *) malloc(sizeof(post));

        if(n == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

//malloc for the text,info,type,link
        n->text=(char*)malloc((lentext+1)*sizeof(char));

        if(n->text == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

        n->info=(char*)malloc((leninfo+1)*sizeof(char));

        if(n->info == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

        n->type=(char*)malloc((lentype+1)*sizeof(char));

        if(n->type == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

        n->link=(char*)malloc((lenlink+1)*sizeof(char));

        if(n->link == NULL)
        {
          printf("\nERROR in memory allocation!!!Not enough memory!!\n");
          exit(1);
        }

//string copy from array[i] (1<=i<=4) to the list
        n->text=strcpy(n->text,array[1]);
        n->info=strcpy(n->info,array[2]);
        n->type=strcpy(n->type,array[3]);
        n->link=strcpy(n->link,array[4]);

//month,day,year,hour,minute,second added in list
        n->posted.month=dtime[0];
        n->posted.day=dtime[1];
        n->posted.year=dtime[2];
        n->posted.hour=dtime[3];
        n->posted.minute=dtime[4];
        n->posted.second=dtime[5];

//likes,loves,wows,hahas,sads,angrys added in list
        n->feelings.like=likes;
        n->feelings.love=loves;
        n->feelings.wow=wows;
        n->feelings.haha=hahas;
        n->feelings.sad=sads;
        n->feelings.angry=angrys;

//rections,comments,shares added in list
        n->react=reaction;
        n->comment=comments;
        n->share=shares;

//kbrd added in list (learnedFrom)
        n->learnedFrom[0]='k';
        n->learnedFrom[1]='b';
        n->learnedFrom[2]='r';
        n->learnedFrom[3]='d';
        n->learnedFrom[4]='\0';

//ean h lista einai adeia
        if(head==NULL)
        {
          head=n;
          n->prev=NULL;
	  tail=n;
          return ;
        }
	else
	{
	  tmp=head;
	  head=n;
	  head->next=tmp;
	  head->prev=NULL;
	}

}

//Count function
void Count(int c)
{
	int sum=0;
	post *tmp=head;

	if(tmp == NULL)
	{
	  printf("\nThe list is empty!!\n");
          return ;
	}

	switch(c)
	{
	  case 1:

	    while((tmp != NULL))
	    {
		sum += tmp->react;

		tmp = tmp->next;
	    }

	    printf("\n%d reactions are stored in Trumps posts!\n",sum);
            break;

	  case 2:

            while((tmp != NULL))
	    {
		sum += tmp->comment;

		tmp = tmp->next;
	    }

	    printf("\n%d comments are stored in Trumps posts!\n",sum);
            break;

	  case 3:

	    while((tmp != NULL))
	    {
		sum += tmp->share;

		tmp = tmp->next;
    	    }

	    printf("\n%d shares are stored in Trumps posts!\n",sum);
            break;

	  case 4:

            while((tmp != NULL))
            {
                sum += tmp->feelings.like;

                tmp = tmp->next;
            }

            printf("\n%d likes are stored in Trumps posts!\n",sum);
            break;

	  case 5:

            while((tmp != NULL))
            {
                sum += tmp->feelings.love;

                tmp = tmp->next;
            }

            printf("\n%d loves are stored in Trumps posts!\n",sum);
            break;

	  case 6:

            while((tmp != NULL))
            {
                sum += tmp->feelings.wow;

                tmp = tmp->next;
            }

            printf("\n%d wows are stored in Trumps posts!\n",sum);
            break;

	  case 7:

            while((tmp != NULL))
            {
                sum += tmp->feelings.haha;

                tmp = tmp->next;
            }

            printf("\n%d hahas are stored in Trumps posts!\n",sum);
            break;

	  case 8:

            while((tmp != NULL))
            {
                sum += tmp->feelings.sad;

                tmp = tmp->next;
            }

            printf("\n%d sads are stored in Trumps posts!\n",sum);
            break;

	  case 9:

            while((tmp != NULL))
            {
                sum += tmp->feelings.angry;

                tmp = tmp->next;
            }

            printf("\n%d angrys are stored in Trumps posts!\n",sum);
            break;

	}
}

//TypeCount function
void TypeCount(char c)
{
  post *tmp=head;

  int Tsum=0;

  char *p;

  switch(c)
  {

    case 1:  //status
      while( tmp != NULL )
      {
           if((p=strstr(tmp->type,array[1])) != NULL)
	   {
             Tsum++;
           }

           tmp = tmp->next;
      }

      if(Tsum != 0)
      {
	 printf("\n%d status are stored in list!!!\n",Tsum);
      }
      else
      {
	 printf("\nNo status are stored in list!!!\n");
      }

      break;

    case 2: //photo
      while( tmp != NULL )
      {
      	if((p=strstr(tmp->type,array[1])) != NULL)
	{
          Tsum++;
        }

        tmp = tmp->next;
      }

      if(Tsum != 0)
      {
         printf("\n%d photos are stored in list!!!\n",Tsum);
      }
      else
      {
         printf("\nNo photos are stored in list!!!\n");
      }

      break;

    case 3: //video
      while( tmp != NULL )
      {
        if((p=strstr(tmp->type,array[1])) != NULL)
	{
          Tsum++;
	}

        tmp = tmp->next;
      }

      if(Tsum != 0)
      {
         printf("\n%d videos are stored in list!!!\n",Tsum);
      }
      else
      {
         printf("\nNo videos are stored in list!!!\n");
      }

      break;

    case 4://link
      while((tmp != NULL))
      {
        if((p=strstr(tmp->type,array[1])) != NULL)
	{
          Tsum++;
        }

        tmp = tmp->next;
      }

      if(Tsum != 0)
      {
         printf("\n%d links are stored in list!!!\n",Tsum);
      }
      else
      {
         printf("\nNo links are stored in list!!!\n");
      }

      break;
  }

}

//printA/printB function
void PrintAB(void)
{
	post *tmp=head;

	int pl=0,j,i=0;

	if(tmp==NULL)
	{
	  printf("\nThe list is empty!!\n");
	}
	else if((j=strcmp(array[0],"printa")) == 0) {
    while( tmp != NULL){

      if(tmp->posted.year>dtime[2]){
          printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",i+1,tmp->text,tmp->info,tmp->type,tmp->link);

		    printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

		     printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

		    printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);

		    printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

		    printf("%s\n",tmp->learnedFrom);

          tmp = tmp->next;
          i++;
        pl++;
      }else if(tmp->posted.year==dtime[2] ){
        if(tmp->posted.month>dtime[0]){

        printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",i+1,tmp->text,tmp->info,tmp->type,tmp->link);

		    printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

		     printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

		    printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);

		    printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

		    printf("%s\n",tmp->learnedFrom);

          tmp = tmp->next;
          i++;
        pl++;


        }else if(tmp->posted.month==dtime[0]){
          if(tmp->posted.day>=dtime[1]){



        printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",i+1,tmp->text,tmp->info,tmp->type,tmp->link);

		    printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

		     printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

		    printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);

		    printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

		    printf("%s\n",tmp->learnedFrom);

          tmp = tmp->next;
          i++;
          pl++;

          }else{
        tmp = tmp->next;
         }


        }else{
        tmp = tmp->next;
      }


      }else{
        tmp = tmp->next;
      }


    }
    if(pl==0){
        printf("\nNo post where found after the time period: %d/%d/%d\n",dtime[0],dtime[1],dtime[2]);

    }


  }else if((j=strcmp(array[0],"printb")) == 0){

    while( tmp != NULL){

      if(tmp->posted.year<dtime[2]){
          printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",i+1,tmp->text,tmp->info,tmp->type,tmp->link);

		    printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

		     printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

		    printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);

		    printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

		    printf("%s\n",tmp->learnedFrom);

          tmp = tmp->next;
          i++;
        pl++;
      }else if(tmp->posted.year==dtime[2] ){
        if(tmp->posted.month<dtime[0]){

        printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",i+1,tmp->text,tmp->info,tmp->type,tmp->link);

		    printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

		     printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

		    printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);

		    printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

		    printf("%s\n",tmp->learnedFrom);

          tmp = tmp->next;
          i++;
        pl++;


        }else if(tmp->posted.month==dtime[0]){
          if(tmp->posted.day<=dtime[1]){



        printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",i+1,tmp->text,tmp->info,tmp->type,tmp->link);

		    printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

		     printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

		    printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);

		    printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

		    printf("%s\n",tmp->learnedFrom);

          tmp = tmp->next;
          i++;
          pl++;

          }else{
        tmp = tmp->next;
         }


        }else{
        tmp = tmp->next;
      }

      }else{
        tmp = tmp->next;
      }




    }
    if(pl==0){
        printf("\nNo post where found before the time period: %d/%d/%d\n",dtime[0],dtime[1],dtime[2]);

    }


  }

}

//findI/findL/findT function
void FindTIL(void)
{
	post *tmp=head;

	char *a3,*c;

	int i,j,k,n;

	if( (array[1][0]=='*') && (array[1][1]=='\0') ) //periptosh findt * or findi * or findl *
	{
	  if(tmp != NULL)
	  {
	    j=0;

	    while(tmp != NULL)
	    {
	  	printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",j+1,tmp->text,tmp->info,tmp->type,tmp->link);
          	printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);
            	printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);
            	printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);
            	printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);
            	printf("%s\n",tmp->learnedFrom);

		tmp=tmp->next;
	    }

	    return ;
	  }
	  else
	  {
	    printf("\nThe list is empty!!\n");
	    return ;
	  }

	}


	if( (i=strcmp(array[0],"findt")) == 0)	//periptosh findt
        {
	  if(tmp==NULL)
	  {
		printf("\nThe list is empty!!\n");
		return ;
	  }
	  else
	  {
	 	j=0;	//gia ektupwsh tou #1,2,3,4....
		k=0;	//flag me skopo na doume an vre8hke auto pou zhtaei o xrhsths

		while(tmp != NULL)
		{
		  for(i=0; i<5000; i++)
                  {
                    if(tmp->text[i] == '\0')
                    {
                        break;
                    }

                    a3[i]=tolower((tmp->text)[i]);

                  }

		  if( (c=strstr(a3,array[1])) != NULL)
		  {
			k++;

			printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",j+1,tmp->text,tmp->info,tmp->type,tmp->link);
                  	printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);
                  	printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);
                  	printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);
                  	printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);
                  	printf("%s\n",tmp->learnedFrom);

			j++;

		  }

		  tmp =tmp->next;
		}

		if(k == 0)
		{
		  printf("\n''%s'' is not found in any text in list!!!\n",array[1]);
		}
	  }


	}

	else if( (i=strcmp(array[0],"findi")) == 0)
	{
		if(tmp==NULL)
          	{
                  printf("\nThe list is empty!!\n");
		  return ;
          	}

		j=0;    //gia ektupwsh tou #1,2,3,4....
                k=0;    //flag me skopo na doume an vre8hke auto pou zhtaei o xrhsths

                while(tmp != NULL)
		{
		    for(i=0; i<5000; i++)
                    {
                      if(tmp->info[i] == '\0')
                      {
                        break;
                      }

                      a3[i]=tolower((tmp->info)[i]);

                    }

                  if( (c=strstr(a3,array[1])) != NULL)
                  {
                        k++;	//metrhths gia to an vre8hke to alfa sth lista

                        printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",j+1,tmp->text,tmp->info,tmp->type,tmp->link);
                        printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);
                        printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);
                        printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);
                        printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);
                        printf("%s\n",tmp->learnedFrom);

			j++;

                  }

                  tmp =tmp->next;
		}

                if(k == 0)
                {
                  printf("\n''%s'' is not found in any information in list!!!\n",array[1]);
                }
          }

	else if( (i=strcmp(array[0],"findl")) == 0)
	{
	  if(tmp==NULL)
          {
                printf("\nThe list is empty!!\n");
          }
          else
	  {
		j=0;    //gia ektupwsh tou #1,2,3,4....
                k=0;    //flag me skopo na doume an vre8hke auto pou zhtaei o xrhsths

                while(tmp != NULL)
                {
		    for(i=0; i<5000; i++)
                    {
                      if(tmp->link[i] == '\0')
                      {
                        break;
                      }

                      a3[i]=tolower((tmp->link)[i]);

		    }

                  if( (c=strstr(a3,array[1])) != NULL)
                  {
                        k++;    //metrhths gia to an vre8hke to alfa sth lista

                        printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",j+1,tmp->text,tmp->info,tmp->type,tmp->link);
                        printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);
                        printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);
                        printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);
                        printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);
                        printf("%s\n",tmp->learnedFrom);

                        j++;

                  }

                  tmp =tmp->next;
		}

                if(k == 0)
                {
                  printf("\n''%s'' is not found in any link in list!!!\n",array[1]);
                }
          }

	}
}

//Print and printr function
void Print_R(int reps)
{
	post *tmp;

	int i=0,j;

	if( (j=strcmp(array[0],"print")) == 0)
	{
	  tmp=head;

          if(tmp==NULL)
          {
        	printf("\nThe list is empty!!\n");
          }
          else
          {
		printf("\nThe list is:\n\n");

		while((tmp != NULL) && (i<reps))
		{

		  printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",i+1,tmp->text,tmp->info,tmp->type,tmp->link);

		  printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

		  printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

		  printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);

		  printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

		  printf("%s\n",tmp->learnedFrom);

		  tmp = tmp->next;
		  i++;
		}

		if(i<reps)
		{
		  printf("\nThere are only %d inserts in list!!!\n",i);
		}

	  }

	}
	else
	{
	  tmp=tail;

          if(tmp==NULL)
          {
                printf("\nThe list is empty!!\n");
          }
          else
          {
                printf("\nThe list in reverse is:\n");

                while((tmp != NULL) && (i<reps))
                {
                  printf("#%d: %.30s;    %.30s;    %s;    %.30s;    ",i+1,tmp->text,tmp->info,tmp->type,tmp->link);

                  printf("%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

                  printf("%d:%d:%d;    ",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

                  printf("%d;    %d;    %d;    ",tmp->react,tmp->comment,tmp->share);

                  printf("%d;    %d;    %d;    %d;    %d;    %d;    ",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

                  printf("%s\n",tmp->learnedFrom);

                  tmp = tmp->prev;
                  i++;
                }

		if(i<reps)
                {
                  printf("\nThere are only %d inserts in list!!!\n",i);
                }

          }
	}

}

//Delete New or Old post function
void DeleteNO(void)
{
	post *tmp;

	int i;

	if( (i=strcmp(array[0],"deleten")) == 0)	//deleteN = diagrafh apo to telos ths listas
	{
	  tmp=head;

	  if(tmp == NULL)		//kenh lista
	  {
		printf("\nThere isn't element to delete\n");
	  }
	  else if(tmp->next == NULL)	//mono 1 stoixeio sth lista
	  {
		free(tmp);
		head=NULL;
		tail=NULL;

		printf("\nThe newest post has been deleted!!!\n");

	  }
	  else				//toulaxiston duo stoixeia sth lista
	  {
		while(tmp->next->next != NULL)
		{
		  tmp = tmp->next;
		}

		free(tmp->next);
		tmp->next=NULL;
		tail=tmp;
	  }
	}

	else	//deleteO = diagrafh apo thn arxh ths listas
	{
	  if(head == NULL)	//kenh lista
          {
                printf("\nThere isn't element to delete\n");
          }
	  else			//toulaxiston 1 stoixeio sth lista
	  {
		tmp = head->next;
		free(head);

		if(tmp == NULL)	//ean h lista exei mono ena stoixeio tote prepei na enhmero8ei kai to tail pou exo balei
		{
		  printf("\nThe oldest post has been deleted!!!\n");

		  tail=	NULL;
		}

		head=tmp;
	  }

	}

}

//Save function
void Save(void)
{
	post *tmp=head;

	int i=0;

	if ( tmp == NULL )
	{
	  printf( "\nList is empty.\n" );
	}
	else
	{
	  while(tmp != NULL)
	  {
		i++;

		fprintf(fp,"%s;%s;%s;%s;",tmp->text,tmp->info,tmp->type,tmp->link);

                fprintf(fp,"%d/%d/%d ", tmp->posted.month,tmp->posted.day,tmp->posted.year);

                fprintf(fp,"%d:%d:%d;",tmp->posted.hour,tmp->posted.minute,tmp->posted.second);

                fprintf(fp,"%d;%d;%d;",tmp->react,tmp->comment,tmp->share);

                fprintf(fp,"%d;%d;%d;%d;%d;%d;",tmp->feelings.like,tmp->feelings.love,tmp->feelings.wow,tmp->feelings.haha,tmp->feelings.sad,tmp->feelings.angry);

                fprintf(fp,"%s\n",tmp->learnedFrom);

		tmp = tmp->next;
	  }

	  printf("\n%d posts written to file %s\n",i,array[1]);

	}


}

//Load function
void Load(void)
{
	int pl=0,i=0;

	while( !feof(fp) )
	{
	  fgets(text,sizeof(text),fp);

	  pl++;

	  array[1] = strtok(text, ";");

          if (array[1] == NULL)
          {
                printf("\nNo text to search!!\n");
                exit(0);
          }

	  for (i=2; i<100; i++)
          {
              array[i] = strtok(NULL, ";");

              if (array[i] == NULL)
	      {
                  break;
	      }

          }

          if( (i=ONPostCheck()) == 1)	//ginontai ola ta checks pou xreiazetai wste to newpost na einai valid
          {
		pl--;
                continue;
          }

          lentext=strlen(array[1]);
          leninfo=strlen(array[2]);
          lentype=strlen(array[3]);
          lenlink=strlen(array[4]);

	  PostSave = 1;

          NewPost();

	}

	if(pl != 0)
	{
	  printf("\n%d posts loaded succssefully!!!\n",pl);
	}
	else
	{
	  printf("\nError. No posts loaded !!!\n");
	}
}


//OLD & NEW post check function
int ONPostCheck(void)
{
                int wrong,i,j;

                char *check;

//see if all elements needed, added with stdin or file
                wrong=0;

                for(i=1; i<15; i++)
                {
                  if(array[i]==NULL)
                  {                       //no elements added
                    wrong++;
                  }
                }

                if(wrong != 0)
                {
                  return 1;
                }

                wrong=0;

//elenxos tou type ean exei ari8mous
                wrong=0;

                for(i=0; i<500; i++)
                {
                  if(array[3][i]=='\0')
                  {
                        break;
                  }

                  if( (array[3][i] >= '0') && (array[3][i] <= '9') )
                  {
                        wrong++;
                  }

                }

                if(wrong != 0)
                {
                  return 1;
                }

//elnxos gia or8o type
                wrong=0;

//elenxos ean to type einai keno to opoio einai dekto
                if(i=strcmp(array[3]," ") == 0)
                {
                  wrong++;
                }

//elenxos ean to type periexei toulaxiston ena apo ta status,photo,video,link
                if( (check=strstr(array[3],"status")) != NULL)
                {
                  wrong++;
                }

                if( (check=strstr(array[3],"photo")) != NULL)
                {
                  wrong++;
                }

                if( (check=strstr(array[3],"video")) != NULL)
                {
                  wrong++;
                }

                if( (check=strstr(array[3],"link")) != NULL)
                {
                  wrong++;
                }

                if(wrong == 0)
                {
                  return 1;
                }

//elnxos gia or8o link
                wrong=0;

//elenxos ean to link einai keno to opoio einai dekto
                if( (i=strcmp(array[4]," ")) == 0)
                {
                  wrong++;
                  i=0;
                }

//elenxos gia or8o link me to protokolo mprosta
                if( (check=strstr(array[4],"http:/")) != NULL)  //den evala http:// giati ta kanei sxolia XD
                {
                  wrong++;
                }

                if( (check=strstr(array[4],"https:/")) != NULL) //den evala https:// giati ta kanei sxolia epishs
                {
                  wrong++;
                }

                if(wrong == 0)
                {
                  return 1;
                }

//elenxos gia or8o link me domain suffix pou einai upoxreotiko
                wrong=0;

                if(i != 0)      //to kano giati ean to link 8a einai keno 8a exo 8ema edo pou ksanakano to wrong=0
                {
                  if( (check=strstr(array[4],".gr")) != NULL)
                  {
                    wrong++;
                  }

                  if( (check=strstr(array[4],".com")) != NULL)
                  {
                    wrong++;
                  }

                  if( (check=strstr(array[4],".info")) != NULL)
                  {
                    wrong++;
                  }

                  if(wrong == 0)
                  {
                    return 1;
                  }

                }

//diaxorismos twn mm,dd,yyyy and hh,mm,ss
                DateTime[0]= strtok(array[5],"/");
                DateTime[1]=strtok(NULL,"/");
                DateTime[2]=strtok(NULL," ");
                DateTime[3]=strtok(NULL,":");
                DateTime[4]=strtok(NULL,":");
                DateTime[5]=strtok(NULL,";");

		wrong=0;

                for(i=0; i<6; i++)
                {
                  if(DateTime[i] == NULL)
                  {
                        wrong++;
                  }
                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn time kai date ean exoun xarakthres
                wrong=0;

                for(i=0; i<6; i++)
                {
                  for(j=0; j<2; j++)
                  {
                        if(DateTime[i][j]=='\0')
                          break;

                        else if( ( DateTime[i][j] < '0') || ( DateTime[i][j] > '9') )
                        {
                                wrong++;
                                break;
                        }
                  }
                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn reactions ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[6][i]=='\0')
                  {
                        break;
                  }

                  if( (array[6][i] < '0') || (array[6][i] > '9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn comments ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[7][i]=='\0')
                  {
                        break;
                  }

                  if( (array[7][i]<'0') || (array[7][i]>'9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn shares ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[8][i]=='\0')
                  {
                        break;
                  }

                  if( (array[8][i]<'0') || (array[8][i]>'9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn likes ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[9][i]=='\0')
                  {
                        break;
                  }

                  if( (array[9][i]<'0') || (array[9][i]>'9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn loves ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[10][i]=='\0')
                  {
                        break;
                  }

                  if( (array[10][i]<'0') || (array[10][i]>'9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn wows ean exoun xarakthres
                //elenxos twn wows ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[11][i]=='\0')
                  {
                        break;
                  }

                  if( (array[11][i]<'0') || (array[11][i]>'9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn hahas ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[12][i]=='\0')
                  {
                        break;
                  }

                  if( (array[12][i]<'0') || (array[12][i]>'9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn sads ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[13][i]=='\0')
                  {
                        break;
                  }

                  if( (array[13][i]<'0') || (array[13][i]>'9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//elenxos twn angrys ean exoun xarakthres
                wrong=0;

                for(i=0; i<50; i++)
                {
                  if(array[14][i]=='\n')
                  {
                        break;
                  }

                  if( (array[14][i]<'0') || (array[14][i]>'9') )
                  {
                        wrong++;
                  }

                }

                if(wrong!=0)
                {
                  return 1;
                }

//metatroph twn date kai time se int
                for(i=0; i<6; i++)
                {
                  dtime[i]=atoi(DateTime[i]);
                }

//metatroph twn reaction se int
                reaction=atoi(array[6]);

//metatroph twn comments se int
                comments=atoi(array[7]);

//metatroph twn shares se int
                shares=atoi(array[8]);

//metatroph twn likes se int
                likes=atoi(array[9]);

//metatroph twn loves se int
                loves=atoi(array[10]);

//metatroph twn wows se int
                wows=atoi(array[11]);

//metatroph twn hahas se int
                hahas=atoi(array[12]);

//metatroph twn sads se int
                sads=atoi(array[13]);

//metatroph twn angrys se int
                angrys=atoi(array[14]);


//check if 1<=month<=12
                if( (dtime[0] < 1) || (dtime[0] > 12) )
                {
                  return 1;
                }

//check if 1<=day<=31
                if( (dtime[1] < 1) || (dtime[1] > 31) )
                {
                  return 1;
                }

//check if 1950<=year<=2025 || 0<=year<=25 || 50<=year<=99
                wrong=0;

                if( (dtime[2] >= 0/*2000*/) && (dtime[2] <= 25/*2025*/) )
                {
                  wrong++;
                }

                if( (dtime[2] >= 50/*1950*/) && (dtime[2] <= 99/*1999*/) )
                {
                  wrong++;
                }

                if( (dtime[2] >= 1950) && (dtime[2] <= 2025) )
                {
                  wrong++;
                }

                if(wrong==0)
                {
                  return 1;
                }

//check if 0<=hour<=24
                if( (dtime[3] < 0) || (dtime[3] > 24) )
                {
                  return 1;
                }

//check if 0<=minute<=60
                if( (dtime[4] < 0) || (dtime[4] > 60) )
                {
                  return 1;
                }

//check if 0<=second<=60
                if( (dtime[5] < 0) || (dtime[5] > 60) )
                {
                  return 1;
                }

//check if reactions>=0
                if(reaction<0)
                {
                  return 1;
                }

//check if comments>=0
                if(comments<0)
                {
                  return 1;
                }

//check if shares>=0
                if(shares<0)
                {
                  return 1;
                }

//check if likes>=0
                if(likes<0)
                {
                  return 1;
                }

//check if loves>=0
                if(loves<0)
                {
                  return 1;
                }

//check if wows>=0
                if(wows<0)
                {
                  return 1;
                }

//check if hahas>=0
                if(hahas<0)
                {
                  return 1;
                }

//check if sads>=0
                if(sads<0)
                {
                  return 1;
                }

//check if angrys>=0
                if(angrys<0)
                {
                  return 1;
                }

                return 0;	// 0 means everything allright

}
