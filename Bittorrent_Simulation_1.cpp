//This program simulates a bittorrent client. It simulates seeds and peers. Data to be trasnferred is decided by the user.
//The initial number of systems in the network is decided by the user.
//Subsequent rounds provide the choice of adding peers or removing seeds from the network
//The implementation of the tracker is realised using dijkstra's algorithm which generates random weights for all systems in the
//network and returns the value of the seed which is closest to the peer


#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

int delay(long seconds);
int dijkstra(int G[21][21], int n, int startnode, int num, int seed[21]);

int main()
{
    //Intialising all variables and arrays to be used in the program
    srand(time(NULL));
    int arr[21][11], tracker[21][21], seed[21], remarray[21], data[11];
    int n, s, num;
    int oldrems=0, nrems=0, ch=0, newp=0, v=0, c=0, x=0, thisflag=0, count=0, oldnum=0, a=1, w=1,  m=1;
    long sec=2, seconds=3;


    cout<<"Enter the number of systems=\n";          //Accepting number of systems
    cin>>n;


    cout<<"Enter the data file="<<endl;              //Accepting data file from user
    for(int i=1; i<11; i++)
        {
            cin>>data[i];
    }

    cout<<endl;


    cout<<"Enter the number of systems with full data file"<<endl;               //Accepting number of seeds
    cin>>num;


    cout<<"Enter the seeds="<<endl;                //Accepting seeds

    //do_while LOOP THAT RUNS THAT SIMULATES BITTORRENT CLIENT

    do
        {
            for(int i=oldnum; i<num; i++)
            {
                if(ch==1)
                {
                    for(int e=w; e<=num; e++)                         //Adding previous peers as new seeds to the seed[] array
                        {
                            c=0;
                    for(int j=0; j<oldnum; j++)
                        {
                            if(e!=seed[j])
                            {
                                c++;
                    }
                    }
                    if(c==oldnum)
                        {
                            seed[i]=e;
                    {
                        w=e+1;
                        break;
                    }
                        }
                        }
                }
                else
                    cin>>seed[i];                                        //In case of round 1, accept seeds from user
            }


            int temp=0;

            for(int i=0; i<(num-1); i++)                                 //Sorting the seed[] array in ascending order using bubble sort
                {
                    for(int j=0; j<(num-i-1); j++)
                    {
                        if(seed[j]>seed[j+1])
                        {
                            temp=seed[j];
                            seed[j]=seed[j+1];
                            seed[j+1]=temp;
                        }
                    }
                }


                if(ch==1)                                          //If user wants to continue using the network
                    {
                        for(int i=0; i<oldrems+nrems; i++)         //Ensuring that no seeds are repeated in the seed[] array
                        {
                            for(int j=0; j<num; j++)
                            {
                                if(remarray[i]==seed[j])
                                {
                                    for(int k=j; k<num-1; k++)
                                    {
                                        seed[k]=seed[k+1];
                                    }
                                    num=num-1;
                                    break;
                                }
                            }
                        }
                    }


                    delay(sec);           //Calling delay function of 2 seconds


                    cout<<"Seeds in this round are="<<endl;     //Displaying seeds available in this round
                    for(int i=0; i<num; i++)
                        cout<<seed[i]<<"\t";

                    cout<<endl;


                    delay(sec);                //Calling delay function of 2 seconds


                    for(int k=0; k<num; k++)
                        {
                            for(int i=1; i<11; i++)
                            {
                                arr[seed[k]][i]=data[i];         //Filling designated seeds with required data
                            }
                        }
                                            /*for(int k=0; k<num; k++)
                                                  {
                                                     for(int j=1; j<11; j++)
                                                     {
                                                        cout<<arr[seed[k]][j]<<"\t";
                                                     }
                                                     cout<<endl;
                                                  } */
                    cout<<endl;


                                            //int a=1, x=0, count=0, thisflag=0;
                    for(int i=1; i<=n; i++)
                        {
                            count=0;
                            a=1;

                            for(int k=0; k<num; k++)
                                {
                                    if(i!=seed[k])         //To ensure that seeds do not transfer data to other seeds
                                    {
                                        if(ch==0)
                                        count++;

                                        else if(ch==1)
                                            {
                                                thisflag=0;
                                        for(int q=0; q<oldrems+nrems; q++)
                                            {
                                                if(i==remarray[q])     //To ensure that seeds do not transfer data to removed seeds
                                                {
                                                    thisflag=1;
                                                    break;
                                                }
                                            }
                                            if(thisflag==0)
                                                count++;
                                            }
                                    }
                                }


                                if(count==num)              //If count is less than number of seeds, it is peer and is sent to tracker
                                    {
                                        cout<<endl;
                                cout<<"Data transfer in progress..."<<endl;


                                delay(sec);                 //Calling delay function of 2 seconds


                                cout<<"PEER "<<i<<"=> ";


                                while(a<11)
                                    {
                                        for(int i=0; i<n; i++)
                                    {
                                        for(int j=0; j<n; j++)
                                        {
                                            tracker[i][j]=rand() % (9+1-0)+0 ;    //Generating random weights to store in tracker
                                        }
                                    }
                                s=dijkstra(tracker, n, i, num, seed);            //Using tracker information to deduce shortest path
                                cout<<endl;
                                cout<<"from seed "<<s<<"= ";
                                x=0;

                                while(x!=2)                                 //Ensuring no more than 2 bits are transmitted between
                                    {                                       //a seed and a peer consecutively
                                        arr[i][a]=arr[s][a];
                                        cout<<arr[i][a]<<"\t";
                                        a++;
                                        x++;
                                    }

                                    if(a==11)
                                        cout<<endl;
                                    }
                                    }
                    }


                    cout<<"Do you wish to continue? Enter 1 to continue:"<<endl;           //Enquiring whether to coninue using the program
                    cin>>ch;

                    if(ch==1)
                        {
                            cout<<"Enter number of new peers to introduce to network= "<<endl;  //New peers to add to network
                            cin>>newp;



                                cout<<endl;

                                int reveal=0;
                                cout<<"Seeds at your disposal are= "<<endl;
                            for(int i=1; i<=n; i++)
                                {
                                    reveal=0;
                                    for(int j=0; j<oldrems+nrems; j++)
                                    {
                                        if(i==remarray[j])
                                            reveal=1;
                                    }
                                    if(reveal==0)
                                    cout<<i<<"\t";
                                }
                                cout<<endl;

                                cout<<"Enter the number of seeds to be removed from network="<<endl; //Seed to be removed from the network
                                cin>>nrems;


                                if(nrems!=0)
                                    {
                                        cout<<"Enter the seeds to be removed="<<endl;
                                        for(int i=oldrems; i<oldrems+nrems; i++)
                                            {
                                                cin>>remarray[i];
                                            }
                                    }

                                    for(int i=oldrems; i<oldrems+nrems; i++)      //Updating remarray to hold latest seeds to be removed
                                        {
                                            for(int j=0; j<oldrems; j++)
                                            {
                                                if(remarray[i]==remarray[j])
                                                {
                                                    for(int k=i; k<oldrems+nrems-1; k++)
                                                    {
                                                        remarray[k]=remarray[k+1];
                                                        i=oldrems;
                                                    }
                                                    nrems=nrems-1;
                                                }
                                            }
                                        }
                                       /*
                                        int tem=0;
                                    for(int i=0; i<(oldrems+newrems-1); i++)
                                        {
                                            for(int j=0; j<(oldrems+newrems-i-1); j++)
                                            {
                                                if(remarray[j]>remarray[j+1])
                                                {
                                                    tem=remarray[j];
                                                    remarray[j]=remarray[j+1];
                                                    remarray[j+1]=tem;
                                                }
                                            }
                                        } */

                                      cout<<endl;

                                      delay(seconds);

                                      cout<<"Seeds that have been removed from the network= "<<endl;
                                      if(nrems==0)
                                      cout<<"None"<<endl;
                                      else
                                        {
                                            for(int i=0; i<oldrems+nrems; i++)
                                            {
                                                cout<<remarray[i]<<"\t";
                                            }
                                        }


                                      oldrems=oldrems+nrems;       //Setting up values for next round of transfer
                                      m=1;
                                      oldnum=num;
                                      num=n;
                                      n=n+newp;
                                      c=0;
                                      w=1;
                           }

                           cout<<endl;

                           delay(seconds);                //Calling delay function of 3 seconds

                           }while(ch==1);
}

 /*int y=0;
for(int t=0; t<5; t++)
{
    for(int i=0; i<n; i++)
              {
                 for(int j=0; j<n; j++)
                 {
                    tracker[i][j]=rand() % (9+1-0)+0 ;
                 }
                 }
                 y=dijkstra(tracker, n, t, num, seed);
                 cout<<"y= "<<y<<endl;
}
*/


#define MAX 21
#define INFINITY 9

int dijkstra(int G[MAX][MAX], int n, int startnode, int num, int sd[MAX])     //Djikstra's algorithm to simulate behaviour of tracker
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(G[i][j]==0)
                cost[i][j]=INFINITY;
            else
                cost[i][j]=G[i][j];

    int flag=0, z=0, temp=0;
    int seeddist[num];


    for(int i=0; i<n; i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFINITY;
        for(int i=0; i<n; i++)
        {
            if(distance[i]<mindistance && !visited[i])
            {
                mindistance=distance[i];
                nextnode=i;
            }
        }
        visited[nextnode]=1;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                if(mindistance+cost[nextnode][i]<distance[i])
            {
                distance[i]=mindistance+cost[nextnode][i];
                pred[i]=nextnode;
            }
        }
        count++;
        }
        int i, j;

        for(i=0; i<n; i++)
        {
            cout<<".";
            flag=0;
            if(i!=startnode)
        {
            for(int p=0; p<num; p++)
            {
                if(i==sd[p]-1)
                    flag=1;
            }
            if(flag==1)
               {
                    seeddist[i]=distance[i];
                  /* // cout<<"Distance of "<<i+1<<"= "<<distance[i]<<endl;



            cout<<"Path= "<<i+1;
            j=i;
            do
            {
                j=pred[j];
               // cout<<"<-"<<j;
            }while(j!=startnode); */
               }
        }
        }

    int p=0;
	int small=seeddist[0];
	int pos=0;
	for(int i=0; i<n; i++)
    {
      while(i==sd[p]-1)
    {
        if(small>seeddist[i])
        {
            small=seeddist[i];
            pos=i;
        }
      p++;
    }
    }


	//cout<<endl;
	//cout<<"shortest path is to "<<pos+1<<endl;

     return (pos+1);
    }


int delay(long seconds)      //Delay function
{
   time_t t1;
   t1 = time(0) + seconds;
   while( time(0) < t1)
     ;
}
