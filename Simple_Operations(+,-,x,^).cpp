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

	cout<<"Enter The First Matrix"<<endl;
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
	cout<<"Enter operator"<<endl;
	getline (cin,operat);  //getting the operator
	if((operat=="+")||(operat=="-")||(operat=="*")||(operat=="^")) //check the operator 
	{ 
	if(operat=="^")
	   {   cout<<"Enter The Power"<<endl; 
		   cin>>power;
	if(power<0) { cout <<"ERROR"<<endl; exit(0); }
	    }
	
	
	
	
	
	//THE SECOND MATRIX
	if(operat!="^")
	{
	string m2;  //m2 is matrix 2

	cout<<"Enter The Second Matrix"<<endl;
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


//Doing +,-,* on 2 matrices
  float r[a][a];

	if(operat=="+")
	{
//sumation of two matrices	  
 for(i=0;i<count2;i++)
  {
	  
	 for(j=0;j< count1;j++)
	 {
		 if((count2==count2a)&&(count1==count1a)) //to check if we can sum the 2 matrices  
		 {
	     r[i][j]=am1[i][j]+am2[i][j];
		 }
		 else { cout <<"ERROR"<<endl; exit(0); }
	 }
  }
 if(count2==1) 
    {
 cout <<print (r,count1-1,count2)<<endl; //printing the sum. of one row matrix
    }
 else 
      {
 cout <<print (r,count1,count2)<<endl; //printing the sum. using fn print     
      } 	
	}


	else if(operat=="-")
   {
//sub. of two matrices	  
 for(i=0;i<count2;i++)
  {
	  
	 for(j=0;j< count1;j++)
	 {
		 if((count2==count2a)&&(count1==count1a)) //to check if we can sub the 2 matrices  
		 {
	     r[i][j]=am1[i][j]-am2[i][j];
		 }


		 else { cout <<"ERROR"<<endl; exit(0); }
	 }
  }
 if(count2==1) 
    {
 cout <<print (r,count1-1,count2)<<endl; //printing the sub. of one row matrix
    }
 else 
      {
 cout <<print (r,count1,count2)<<endl; //printing the sub. using fn print     
      } 	

 }

	
 else if(operat=="*")
 {
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
			   sum+=am1[i][k]*am2[k][j];
			   r[i][j]=sum; 
			  // cout<<i<<"\t"<<j<<endl;
			   // cout<<r[i][j]<<endl;
			   
			   }
			    
		  }

	   }
	   
     cout <<print(r,count1a,count2)<<endl; //printing the mult. using fn print
	           
	 }
	
	 
	 else { cout <<"ERROR"<<endl; exit(0); }
	 
 }

 

else if(operat=="^")
 {
	if(power==0){ cout<<"1"<<endl; }

	while(power>0)
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
			   sum+=am1[i][k]*am1[k][j];
			   r[i][j]=sum; 
			 // cout<<i<<"\t"<<j<<endl;
			   //cout<<r[i][j]<<endl;
			   
			   }    
		  }
	   }        
	 }

	 else { cout <<"ERROR"<<endl; exit(0); }
	power--; //To get out of while loop
	}
	 cout <<print(r,count1,count2)<<endl; //printing the mult. using fn print
 }
















 } else { cout <<"ERROR"<<endl; exit(0); } //if operator is not +,-,* 
  


  





















































	return 0;
		
}

	
	
	
	


















