#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include<cstdlib>
#include<sstream>


using namespace std ;

#define a 100 //to chande the size of the matrix


string print (float am[a][a],int count1,int count2) //am is any matrix
	{int i,j;
	//Printing the matrix
	string str;
	ostringstream s;
    s<<"[";
	for(i=0;i<count2;i++)
	{
		for(j=0;j<count1;j++)
			{
			s <<am[i][j];
			if(j==count1-1) break;
			s<<" ";
		}
		if(i==count2-1) break;
		s<<";";

	}
	    s<<"]";
	str = s.str(); // to put the matrix un string
	
	return str; //the fn neads cout to print the result
	}




int main ()  
{

	//THE FIRST MATRIX
	string m1;  //m1 is matrix 1

	//cout<<"Enter The First Matrix"<<endl;
	getline (cin,m1);  //take matrix 1 from user into a string

	
	char ch1='[';
	char ch2=']';
	if(m1[0]!=ch1){ cout <<"ERROR"<<endl; exit(0);} //matrices must start and end with []
	if(m1[m1.length()-1]!=ch2){ cout <<"ERROR"<<endl;  exit(0);}
	
	
	string m11=m1.erase(0,1);         
	string m12=m1.erase(m1.length()-1,1); //m11 ,m12 are matrix 1 without []

	/*cout<<m11<<endl<<m12<<endl<<"without []"<<endl;*/

	
    float am1[a][a];  //am1 is the array of matrix 1
	float am2[a][a];  //am2 is the array of matrix 2

	int i,j,k,h=0,count1=1,count2=1,count11=0; //count11 to see if the input can be a matrix or not
    int count1a=1,count2a=1,count11a=0; //count1a ,count2a ,count11a of the second matrix ,count11a to see if the input can be a matrix or not
	
	string m123=m12; // m123 to erase no. till space to put the new one in the array
	
	for(i=0;i<count2;i++) // i for row
	{
		int v=0;
		int count11=0; //to count spaces from start each time

	   for(j=0;j<count1;j++) //j for column
	  {
	
		  for(k=0;k<m123.length();k++) //loop to find space & ;
		  { 
		     if(m123[k]==';')
			    {v=1; break;}//find ';'
		     if(m123[k]==' ')  //find space 
			    {   
					count11++; // count spaces to prevent error of getting input that can not be a matrix 
					break;
			    }   

		  }
		  
		  if (v==0)
		  {
		  // convert from string to float and put it into array of matrix 1 */
	
              if(m123.length()>0) 
			  { if(i==0){ count1++;} //to take no. of column one time without adding 1 on it in the new row
		   am1[i][j]= atof(m123.substr(0,(k)).c_str());
		   m123=m123.erase(0,k+1);
			  }
		  }

		  if(v==1)
		  {
		  if(m123.length()>0) 
		      {   count2++;
		  am1[i][j]=atof(m123.substr(0,k).c_str());
		  m123=m123.erase(0,k+1);
		  break;
		      }
		  }
	  }
	if(i!=0)
	{
	if(count1!=(count11+1)){cout <<"ERROR"<<endl; exit(0); } //printing ERROR for wrong matrix
	}
	}
	//cout<<print(am1,count1,count2)<<endl; //to print the result
	// if one row mat. printed value will be like in =,-

	
	
	
	int power;
	string operat; //operat is the operator
	//cout<<"Enter operator"<<endl;
	getline (cin,operat);  //getting the operator
	if((operat=="+")||(operat=="-")||(operat=="*")||(operat=="^")||(operat=="T")||(operat=="D")||(operat=="I")||(operat=="/")) //check the operator 
	{ 
	if(operat=="^")
	   {  // cout<<"Enter The Power"<<endl; 
		   cin>>power;
	if(power<0) { cout <<"ERROR"<<endl; exit(0); }
	    }





	//THE SECOND MATRIX
	if(operat=="/")
	{
	string m2;  //m2 is matrix 2

	//cout<<"Enter The Second Matrix"<<endl;
	getline (cin,m2);  //take matrix 2 from user into a string

	if(m2[0]!=ch1){ cout <<"ERROR"<<endl; exit(0);} //matrices must start and end with []
	if(m2[m2.length()-1]!=ch2){ cout <<"ERROR"<<endl;  exit(0);}
	
	string m21=m2.erase(0,1);         
	string m22=m2.erase(m2.length()-1,1); //m21 ,m22 are matrix 2 without []

	/*cout<<m21<<endl<<m22<<endl<<"without []"<<endl;*/

	//am2 is the array of matrix 2
    
	
    string m223=m22; /* m223 to erase no. till space to put the new one in the array*/
	

	for(i=0;i<count2a;i++) // i for row
	{
		int v=0;
		int count11a=0; //to count spaces from start each time

	   for(j=0;j<count1a;j++) //j for column
	  {
	
		  for(k=0;k<m223.length();k++) //loop to find space & ;
		  { 
		     if(m223[k]==';')
			    {v=1; break;}//find ';'
		     if(m223[k]==' ')  //find space 
			    {   
					count11a++; // count spaces to prevent error of getting input that can not be a matrix 
					break;
			    }   

		  }
		  
		  if (v==0)
		  {
		  /* convert from string to float and put it into array of matrix 1 */
	
              if(m223.length()>0) 
			  { if(i==0){ count1a++;} //to take no. of column one time without adding 1 on it in the new row
		   am2[i][j]= atof(m223.substr(0,(k)).c_str());
		   m223=m223.erase(0,k+1);
			  }
		  }

		  if(v==1)
		  {
		  if(m223.length()>0) 
		      {   count2a++;
		  am2[i][j]=atof(m223.substr(0,k).c_str());
		  m223=m223.erase(0,k+1);
		  break;
		      }
		  }
	  }
	if(i!=0)
	{
	if(count1a!=(count11a+1)){cout <<"ERROR"<<endl; exit(0); } //printing ERROR for wrong matrix
	}
	}

	//cout<<print(am2,count1a,count2a)<<endl; //to print the result
	// if one row mat. printed value will be like in =,-
	
	}






	float r[a][a];
	float r1[a][a];


	 if(operat=="^")
 {  
	 

	 for(i=0;i<count2;i++)
        {
			for(j=0;j<count1;j++)
	       { 
			   r1[i][j]=0;
			   r1[i][j]=am1[i][j]; //put am1 in r1
			   r[i][j]=0;
			}
	    }


	if(power==0){ cout<<"1"<<endl; }
	else if(power==1) { cout <<print(am1,count1,count2)<<endl;  }//printing the mat. power 1  
	


	while(power>1)
	{
	//power of matrix
if(count1==count2)//to check if we can * the matrix
	 {

	   for(i=0;i<count2;i++)
        {
	  
	      for(j=0;j<count1;j++)
	       { float sum =0; //to start from 0 each time
			   for(k=0;k<count1;k++) //count1==count2 
			   {
			   sum+=r1[i][k]*am1[k][j];
			   r[i][j]=sum; 
			 
			   // cout<<i<<"\t"<<j<<"\t"<<k<<"\t"<<power<<"\t"<<endl;
				
			  // cout<<r[i][j]<<"\t";

			   //cout<<r[i][j]<<endl;
			   
			   }    
		  }
	   }        
	
	    //cout <<print(r,count1,count2)<<endl<<endl<<endl;

	   for(i=0;i<count2;i++)
        {
			for(j=0;j<count1;j++)
	       { 
			   r1[i][j]=r[i][j]; //put r in r1 
			   r[i][j]=0;
			    //cout<<r[i][j]<<" ";
			}
	    }

		
		//cout <<print(r1,count1,count2)<<"GGGHHHH"<<endl<<endl<<endl;

   }

	 else { cout <<"ERROR"<<endl; exit(0); }
	power--; //To get out of while loop
	}
	 cout <<print(r1,count1,count2)<<endl; //printing the mult. using fn print
 }






 else if(operat=="T")
 {  
	 
 for(i=0;i<count2;i++)
        {
	  
	      for(j=0;j<count1;j++)
	       { 
			   
			   r[j][i]=am1[i][j];
			        
		  }
	   }        

 cout <<print (r,count2,count1)<<endl;

 }



 else if(operat=="D")
 { float dev=0,res=0,det=1;
   int b=0;

   if(count1==count2)//for square matrix
	 {
		 for(j=0;j<count1;j++) 
		 {
			

			 for(i=j+1;i<=count2;i++) // deviding In/I(n-1)
			 {
				 
				 
		
			dev=am1[i][j]/am1[j][j];


			for(k=0;k<count1;k++)
			  {
			 res=am1[j][k]*dev;    
			 am1[i][k]-=res;
			
			}
			 
			 } 
			 
		 
			 
		 }

		
	


		 for(i=0;i<count2;i++)
		  {det*=am1[i][i];}

		 cout <<det<<endl;
		
     

 }


 else { cout <<"ERROR"<<endl;   exit(0); }
 
 
 }






  else if(operat=="I")
 {
	 float fact=1;  //fact is the factor
	 float I[a][a],r2[a][a] ;
  
 if(count1==count2)//for square matrix
	 {	 
	 
 for(i=0;i<count2;i++) //Define matrix I
  {
    for(j=0;j<count1;j++)
     {
    if(i==j)
	  { I[i][j]=1;  }
	else 
      { I[i][j]=0;  }
    r[i][j]=am1[i][j];
	
	}
  }
 
 


 for(i=0;i<count2;i++) 
	 {
			r2[i][i]=r[i][i];	 
	   for(j=0;j<count1;j++)  // deviding rows by the main dia.  
		
	     { 
			 if(r2[i][i]==0) { cout<<"ERROR"<<endl; exit(0); }
	 I[i][j]=I[i][j]/r2[i][i]; 
	 r[i][j]=r[i][j]/r2[i][i];
	 
	   
         } 
			
		 

	   for(k=0;k<count2;k++)
	   {
	      fact=r[k][i];
		 
		  if(k==i) { continue; }

		   for(j=0;j<count1;j++)
		   {
		   
		  
		   
		   r[k][j]-=(fact*r[i][j]);
		   I[k][j]-=(fact*I[i][j]);
		   

		      
		   }
	   }	   
	 }

   cout <<print (I,count2,count1)<<endl;

 }
 
 
else { cout <<"ERROR"<<endl;   exit(0); } 
}



else if(operat=="/")
 {


   float fact=1;  //fact is the factor
	 float I[a][a],r2[a][a] ;
  
 if(count1a==count2a)//for square matrix
	 {	 
	 
 for(i=0;i<count2a;i++) //Define matrix I
  {
    for(j=0;j<count1a;j++)
     {
    if(i==j)
	  { I[i][j]=1;  }
	else 
      { I[i][j]=0;  }
    r[i][j]=am2[i][j];
	
	}
  }
 
 


 for(i=0;i<count2a;i++) 
	 {

		 // Finding the inverse
			r2[i][i]=r[i][i];	 
	   for(j=0;j<count1a;j++)  // dividing rows by the main dia.  
		
	     { 
			 if(r2[i][i]==0) //incase ofdividing by zero
			 { 
			 for(int i1=0;i1<count1;i1++)
			 {   
			 r[i][i1]+=r[i+1][i1];  r2[i][i]=r[i][i];
			 I[i][i1]+=I[i+1][i1];
			 }
			 
			 }
	 I[i][j]=I[i][j]/r2[i][i]; 
	 r[i][j]=r[i][j]/r2[i][i];
	 
	   
         } 
			
		 

	   for(k=0;k<count2a;k++)
	   {
	      fact=r[k][i];
		 
		  if(k==i) { continue; }

		   for(j=0;j<count1a;j++)
		   {
		   
		   r[k][j]-=(fact*r[i][j]);
		   I[k][j]-=(fact*I[i][j]);
		   

		      
		   }
	   }	   
	 }

   

 }
 
 
else { cout <<"ERROR"<<endl;   exit(0); }
  
  
  
  float r3[a][a];




 //mult. of two matrices
	if(count1==1) //like case j of 1st mat. =1 ,one column (3*1),(1*2)
	    { count1a--; }
	if(count2==1) //like case i of 1st mat. =1 ,one row (1*3),(3*2)
	    { count1--; }
	 if(count1==count2a)//to check if we can * the 2 matrices
	 {
     
	   for(i=0;i<count2;i++)
        {
	  
	      for(j=0;j<count1a;j++)
	       { float sum =0; //to start from 0 each time
			   for(k=0;k<count1;k++) //count1==count2a  
			   {
			   sum+=am1[i][k]*I[k][j];
			   r3[i][j]=sum; 
			  // cout<<i<<"\t"<<j<<endl;
			   // cout<<r[i][j]<<endl;
			   
			   }
			    
		  }

	   }
	   
     cout <<print(r3,count1a,count2)<<endl; //printing the mult. using fn print
	           
	 }
	
	 
	 else { cout <<"ERROR"<<endl; exit(0); }
 
  
 }



}
else { cout <<"ERROR"<<endl; exit(0);} 


	return 0;
	}






















//	[0 2 0 1;2 2 3 2;4 -3 0 1;6 1 -6 -5]
//	[0;-2;-7;6]
