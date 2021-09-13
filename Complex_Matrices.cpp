#include <iostream>
#include <math.h>
#include <cmath>
#include<cstdlib>
#include<sstream>

using namespace std;


class complex 
{
	float real ,img;
public :
	
	complex ()
	{real=0;  img=0;  }

	complex (float a,float b)
	  { real=a;  img=b; }
	
	
	void set_real(float a)
	{ real=a; }

	void set_img(float a)
	{ img=a; }

	void set_complex(float a,float b)
	{ real=a;  img=b; }
	
/*	complex get_complex()
	{complex res;  
	res.real=real;
	res.img=img;
	return res;
	}*/

	float get_real()
	{  return real; }

	float get_img()
	{  return img; }
	
	//For multi.
	float get_mag()
	{ float mag;
	mag=sqrt(pow(real,2)+pow(img,2));
	return mag;
	}

	//For multi.
	float get_phase()
	{   
	float phase;
	phase=atan2(img,real);
	 return phase ;
	}






//Another way for sum. &sub. &multi.
	/*void  add (complex a,complex b )
	   { 
	    real=(a.get_real() + b.get_real());
		img=(a.get_img() + b.get_img());
		 
	   }


	void  sub (complex a,complex b )
	   { 
	    real=(a.get_real() - b.get_real());
		img=(a.get_img() - b.get_img());
		 
	   }*/

/*	complex mult (complex a,complex b)
	{  complex res;
	float phasea ,phaseb, maga , magb,phase_res,mag_res;
	phasea=a.get_phase();
	maga=a.get_mag();
	
	phaseb=b.get_phase();
	magb=b.get_mag();
	
	phase_res=phasea + phaseb;
	mag_res=maga * magb;
	 
	res.set_real(mag_res*cos(phase_res));
	res.set_img(mag_res*sin(phase_res));

	return res;
	}*/


};



//Fn For sum.
 complex  add (complex a,complex b )
	   { complex sum ;  
	   sum.set_real(a.get_real() + b.get_real());
	   sum.set_img(a.get_img() + b.get_img());
	   return sum;
	   }
 //Fn For sub.
	complex  sub (complex a,complex b )
	   { complex sub ;
	    sub.set_real(a.get_real() - b.get_real());
		 sub.set_img(a.get_img() - b.get_img());
		 return sub;
	   }



//Fn For multi.
	complex mult (complex a,complex b)
	{  complex res;
	float phasea ,phaseb, maga , magb,phase_res,mag_res;
	phasea=a.get_phase();
	maga=a.get_mag();
	
	phaseb=b.get_phase();
	magb=b.get_mag();
	
	//phase_res=phasea + phaseb;
	//mag_res=maga * magb;
	
	if((a.get_real()==0&&b.get_img()==0)||(b.get_real()==0&&a.get_img()==0))
	{
	res.set_img(maga * magb*sin(phasea + phaseb));
	
	return res;
	}
	
	if((a.get_real()==0&&b.get_real()==0)||(b.get_img()==0&&a.get_img()==0))
	{
	res.set_real(maga * magb*cos(phasea + phaseb));
	
	return res;
	}


	else
    {res.set_real(maga * magb*cos(phasea + phaseb));
	res.set_img(maga * magb*sin(phasea + phaseb)); 
	}



	return res;
	
	}







	complex change_to_no(string s1) //changing string to no.
	{int n,n1=0,n2=0;
	complex res;
	if(s1.length()==1)  //if the no. is i
	{ if(s1[0]=='i') { res.set_img(1); } 
	else
	{ res.set_real( atof(s1.substr().c_str())); }
	}

	if(s1.length()==2)  //if the no. is -i
	{ if(s1[0]=='-'&&s1[1]=='i')  { res.set_img(-1); }
	
	else if(s1[s1.length()-1]=='i')  {string s2=s1.substr(0,s1.length()-1);  res.set_img(atof(s2.substr().c_str())); }
	else { res.set_real( atof(s1.substr().c_str())); }
	return res;}
	


	for(n=s1.length()-1;n>0;n--)  
			 {
			if(s1[n]=='i')  //finding i and erase it
			{  s1=s1.erase(s1.length()-1);
			for(n=s1.length()-1;n>0;n--)
			 {
				 if(s1[n]=='+')  //incase of +ve img
				 {n1=1;
				 
				 res.set_img( atof(s1.substr(n).c_str())); 
				 s1=s1.erase(n);  
				 res.set_real( atof(s1.substr(0,(n)).c_str()));
				      
				 }
				 else if(s1[n]=='-')  //incase of -ve img
				 {n2=1;

				 res.set_img( atof(s1.substr(n).c_str())); //n-1
				 s1=s1.erase(n); 
  				 res.set_real( atof(s1.substr().c_str()));//(0,n)
				 }
				
			
			
			}
			
			}
	        }
				 
  return res;
	}



	#define a1 100 //to chande the size of the matrix


	string print (complex am[a1][a1],int count1,int count2) //am is any matrix
	{int i,j;
	//Printing the matrix
	string str;
	ostringstream s;
    s<<"[";
	for(i=0;i<count2;i++)
	{
		for(j=0;j<count1;j++)
			{
				if(am[i][j].get_img()==1&&am[i][j].get_real()==0)
			      {s <<"i"; }
				else if(am[i][j].get_img()==-1&&am[i][j].get_real()==0)
			      {s <<"-i"; }
				else if(am[i][j].get_img()==0)
			      {s <<am[i][j].get_real();}
			
				else if(am[i][j].get_real()==0)
			      {s<<am[i][j].get_img()<<"i";}
                
				else if(am[i][j].get_img()==1)
			      {s<<am[i][j].get_real()<<"+"<<"i";}
			
			    else if(am[i][j].get_img()==-1)
		          {s<<am[i][j].get_real()<<"-i";}

				else if(am[i][j].get_img()>0)
			     {s<<am[i][j].get_real()<<"+"<<am[i][j].get_img()<<"i";}
			
			    else if(am[i][j].get_img()<0)
		          {s<<am[i][j].get_real()<<am[i][j].get_img()<<"i";}
		       



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








int main()
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

	
    complex am1[a1][a1];  //am1 is the array of matrix 1
	complex am2[a1][a1];  //am2 is the array of matrix 2


	string s1;
	
	int n=0,i,j,k,h=0,count1=1,count2=1,count11=0; //count11 to see if the input can be a matrix or not
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
		  /* convert from string to float and put it into array of matrix 1 */
	
             if(m123.length()>0) 
			  { if(i==0){ count1++;} //to take no. of column one time without adding 1 on it in the new row
			 
			 s1=m123.substr(0,(k));
			 am1[i][j]=change_to_no(s1);
		     m123=m123.erase(0,k+1);
	
			  }
		  }

		  if(v==1)
		  {
		  if(m123.length()>0) 
		      {   count2++;
		
		  s1=m123.substr(0,(k));
		  am1[i][j]=change_to_no(s1);
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
/*	for(i=0;i<count2;i++)
	{
	for(j=0;j<count1-1;j++){
	cout<<am1[i][j].get_real()<<" "<<am1[i][j].get_img()<<"\t";
	
	}
	cout<<am1[i][j].get_real()<<" "<<am1[i][j].get_img()<<endl;
	
	}*/





	

	
	string operat; //operat is the operator
	//cout<<"Enter operator"<<endl;
	getline (cin,operat);  //getting the operator
	if((operat=="+")||(operat=="-")||(operat=="*")) //check the operator 
	{ 
	
	 
	    
	
	//THE SECOND MATRIX
	string m2;  //m2 is matrix 2

	//cout<<"Enter The SECOND Matrix"<<endl;
	getline (cin,m2);  //take matrix 2 from user into a string

	
	
	if(m2[0]!=ch1){ cout <<"ERROR1"<<endl; exit(0);} //matrices must start and end with []
	if(m2[m2.length()-1]!=ch2){ cout <<"ERROR"<<endl;  exit(0);}
	
	
	string m21=m2.erase(0,1);         
	string m22=m2.erase(m2.length()-1,1); //m21 ,m22 are matrix 2 without []

	/*cout<<m21<<endl<<m22<<endl<<"without []"<<endl;*/

	
	string s2;
	
	string m223=m22; // m223 to erase no. till space to put the new one in the array
	
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
		  /* convert from string to float and put it into array of matrix 2 */
	
             if(m223.length()>0) 
			  { if(i==0){ count1a++;} //to take no. of column one time without adding 1 on it in the new row
		   
		   s2=m223.substr(0,(k));
	   	   am2[i][j]=change_to_no(s2);
		   m223=m223.erase(0,k+1);
			 
		//	  cout<<am2[i][j]<<"\t"<<"1"<<m223<<endl;
			  }
		  }

		  if(v==1)
		  {
		  if(m223.length()>0) 
		      {   count2a++;
		
		    s2=m223.substr(0,(k));
			am2[i][j]=change_to_no(s2);
		    m223=m223.erase(0,k+1);
	//	    cout<<am2[i][j]<<"\t"<<"1"<<m223<<endl;
		  break;		      }
		 
		  }
	  }
	if(i!=0)
	{
	if(count1a!=(count11a+1)){cout <<"ERROR"<<endl; exit(0); } //printing ERROR for wrong matrix
	}
	}
	//cout<<print(am2,count1a,count2a)<<endl; //to print the result
	// if one row mat. printed value will be like in =,-
	/*for(i=0;i<count2a;i++)
	{
	for(j=0;j<count1a-1;j++){
	cout<<am2[i][j].get_real()<<" "<<am2[i][j].get_img()<<"\t";
	
	}
	cout<<am2[i][j].get_real()<<" "<<am2[i][j].get_img()<<endl;
	
	}*/

	

	//Doing +,-,* on 2 matrices
  complex r[a1][a1];

	if(operat=="+")
	{
//sumation of two matrices	  
 for(i=0;i<count2;i++)
  {
	  
	 for(j=0;j< count1;j++)
	 {
		 if((count2==count2a)&&(count1==count1a)) //to check if we can sum the 2 matrices  
		 {
	     r[i][j]=add(am1[i][j],am2[i][j]);
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
	     r[i][j]=sub(am1[i][j],am2[i][j]);
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
	       { complex sum(0,0); //to start from 0 each time
			   for(k=0;k<count1;k++) //count1==count2a  
			   {
			   sum=add(sum,mult(am1[i][k],am2[k][j]));
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

 





	} else { cout <<"ERROR"<<endl; exit(0); } //if operator is not +,-,*



	

	

return 0;
}

	//[1 i 1+i;-2 -2-5i 0;1 i 1+i;-2 -2-5i 0]







































/*complex x(9,0),y(10,11),sum;
float a;
sum=mult(x,y);
//a=x.get_mag();
cout<<x.get_real()<<endl<<x.get_img()<<endl;
cout<<y.get_real()<<endl<<y.get_img()<<endl;
cout<<sum.get_real()<<endl<<sum.get_img()<<endl;
//cout<<a<<endl;
*/

















