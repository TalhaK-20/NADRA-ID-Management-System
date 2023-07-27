#include<iostream>
#include<cstdlib>         // I have used this library for the rand() function 
#include<ctime> 
#define size 1313         // I have defined this size for the Linear probing 
#define SIZE 1313         // I have defined this size for the Linked list chaining
#define SIZE_BST 1313     // I have defined this size for the BST chaining and AVL chaining


using namespace std; 



class hashing{             // This class contains linear probbing           
    public:
 	int searches_attempt_linear;    	
    int total_searches_Probbing;
    int collisions_PROBBING; 
  	int index; 
    long long arr[size];
    
  
    hashing(){
         
        for(int i=0; i<size; i++){
            arr[i]=0;
        }
        collisions_PROBBING = 0;
        total_searches_Probbing = 0;
        searches_attempt_linear = 0;
    }
    
  
  
  
    void insert(long long value){
        index = value % size; 
        if(arr[index]==0){
            arr[index]=value;
        }
        else{
        	collisions_PROBBING++;
            while(arr[index]!=0){
                index++;
                if(arr[index]==0){
                    arr[index]=value;
                    break;
                }
            }
        }
    }
    
  
  
    
	
	void search(long long value){
		int count = 0;
        index = value % size;
        if(arr[index]==value){
         	count++;
        	cout<<"ID Number = "<<value<<" has been found"<<endl;
        }
   
        else{
        	index++;
         	if(arr[index]==value){
        		count++;
        		cout<<"ID Number = "<<value<<" has been found"<<endl;
			}
			else{
				cout<<"ID Number = "<<value<<" not found in the system"<<endl;
			}
        }
    }
    
    
    
    
    
	void search_ANALYSIS(long long value){
		int count = 0;
        index = value % size;
        if(arr[index]==value){
        	total_searches_Probbing++;
        	count++;
        }
   
        else{
        	index++;
        	searches_attempt_linear++;
        	if(arr[index]==value){
			}
        }
        
    }
    
    
    
	
	
	
	void delete_prob(long long value){
		int count = 0;
        index = value % size;
        if(arr[index]==value){
           arr[index] = 0;   
		   cout<<"ID Number = "<<value<<" has been removed from the system"<<endl;
		
		}
   
        else{
        	 
         	while(arr[index]!=0){
                index++;
                if(arr[index]==0){
                    arr[index]=value;
                    break;
                }
                
                else{
				    cout<<"ID Number = "<<value<<" not found in the system"<<endl;
			    }
            }
	    }
    }
    
    
    
    
    
	
	void display(){
        for(int i=0; i<size; i++){
            cout<<"arr["<<i<<"] = "<<arr[i]<<endl;   
        }
        cout<<endl;
    }
    
    
    
    
    
    
    bool prime_check(int value){
       
	    if(value <= 1){
	       return false;
        }
        
        
		for(int i=2; i<=value/2; i++){
            if(value % i == 0){
		       return false;
		    }
        }
        
        return true;
   }

    
    
};










class node{        // This class contains linked list chaining
	public:
     
	int searches_attempt_linked;	
	int total_searches_Linked;	
	int collisions_LINK;	
    int index_list; 
	long long  data;
 	node* temp;
	node* next;
	node* new_node;
 	node* arr[SIZE];
	
     
	void link_chaining_NULL(){
	    for(int i=0;i<SIZE;i++){
			arr[i]=NULL;
	    }
	    collisions_LINK = 0;
	    total_searches_Linked = 0;
	    searches_attempt_linked = 0;
	}


  	
	void link_chaining_insert(long long value){
	    new_node = new node();
		new_node->data = value;
		new_node->next = NULL;
		
		index_list = value % SIZE;
		 
		if(arr[index_list] == NULL){
			arr[index_list] = new_node; 
	    }
	    
	    
	    else{
	        collisions_LINK++;	
	        temp = arr[index_list];
	        while(temp->next != NULL){
	         	temp = temp->next;
			}
		         
			temp->next = new_node;
		}
	}
	
	
	
	
	
	

 	void link_chaining_search(long long value){
 		int count = 0;
 	
	
		index_list = value % SIZE;
		 
 		temp=arr[index_list];
 		
 		if(temp==NULL){
 		   cout<<"No such DATA is found !"<<endl;	
		}
		
		while (temp != NULL) {
		    if (temp->data == value){
            	count++;
                cout<<"ID Number = "<<temp->data<<" has been found"<<endl;
                break;
            }
            
            temp = temp->next;
        }
        if(count == 0){
		    cout<<"ID Number = "<<temp->data<<" has NOT found"<<endl; 
        }
   }
   
		  
	 
	 
	 
	 	

 	void link_chaining_search_ANALYSIS(long long value){
 		int count = 0;
 	
		 	   
 	    index_list = value % SIZE;
 		 
 		temp=arr[index_list];
 		
 		while(temp!=NULL){
 		
		    searches_attempt_linked++;
 		    
		 	if(temp->data == value){
 				count++;
 				total_searches_Linked++;
 	 		    break;
 			}
 			
 		    temp = temp->next;
 		     
 		}
	}

	 
	
	
	
	
	
	
	void link_chaining_delete(long long value){
	  
	    index_list = value % SIZE;
		temp = arr[index_list];
		node* temp_2 = temp;
	    node* previous_node;
		int count = 0;
		 
	    if(temp == NULL){
			cout<<"No such data is found in our system"<<endl;
		}
		
		else if(temp != NULL && temp->data == value){
			temp_2 = temp;
            temp = temp->next;  
            cout<<"ID Number = "<<temp_2->data<<" has been removed"<<endl;
            delete(temp_2);        
            return;
        }

       	while (temp != NULL && temp->data != value) {
            previous_node = temp;
            temp = temp->next;
        }

        if(temp == NULL){
		    return;
        }
        
		previous_node->next = temp->next;
		cout<<"ID Number = "<<temp->data<<" has been removed"<<endl;
        delete(temp);   
    }
	         	  
     
     
	
	
	
 	void link_chaining_display(){
		for(int i=0; i<SIZE; i++){
			temp = arr[i];
			cout<<"Arr["<<i<<"]"; 
			while(temp!=NULL){                     // loop for displaying linked list chaining
			    cout<<"------>"<<temp->data;
				temp = temp->next;
			    
			}	
			cout<<"------>NULL"<<endl;
		    
		}
	}
	
	


	
    bool prime_check(int value){
       
	    if(value <= 1){
	       return false;
        }
        
        
		for(int i=2; i<=value/2; i++){
            if(value % i == 0){
		       return false;
		    }
        }
        
        return true;
   }

		  
}; 






class root{      // This class contains BST chaining 
	public:
    int searches_attempt_BST;	
	int total_searches_bst;
	int collisions_BST;	
	long long data;
    long long index_BST;
    root* left;
	root* right;
	root* head;
	root* current;
	root* parent; 	
	root* new_node;
 	root* arr[SIZE_BST];
	
	 
	
	void BST_chaining_NULL(){
		for(int i=0;i<SIZE_BST;i++){
			arr[i]=NULL;
		}
	 	total_searches_bst = 0;
		collisions_BST = 0;
	    searches_attempt_BST = 0;
	}
	
   
    int hashFunction(long long number){
       return number % SIZE_BST;
    }  

		
	
	void BST_insert(root* &temp, long long value){
	    new_node = new root();
		new_node->data = value; 
	    new_node->left = NULL;
		new_node->right = NULL;
		
		index_BST = hashFunction(value);
		 
		if(arr[index_BST] == NULL){
			arr[index_BST] = new_node;
		}	
		
		else{
            collisions_BST++;			 
			temp = arr[index_BST];
			root* parent = NULL;
			root* current = temp;
		    while(current != NULL){
		    	parent = current;
			 	
				 if(value < current->data){
					current = current->left;
					if(current == NULL){
						parent->left = new_node;
						break;
					}
			   }
			   else if(value > current->data){
			   	    current = current->right; 
				    if(current == NULL){
				    	parent->right = new_node;
				    	break;
					}	      
			    }
			    else{
	 		    	break;
				}
			}
 		}
	}
 	
	 
	  
	
	

	void BST_search(root* temp, long long value){
		int count = 0;

		index_BST = hashFunction(value);
		temp = arr[index_BST];
 	    
		if(temp == NULL){
           cout<<"No DATA is present/found."<<endl; 
        }
        
		else if(temp->data == value){
		    cout<<"ID Number = "<<temp->data<<" has been found in our system"<<endl;  
        }
        
		else if (value < temp->data){
		    BST_search(temp->left, value);
        }
        
		else{
		    BST_search(temp->right, value);
        }
    }
 	
 	

 	
 	
    root* smallest_node(root* temp){
        root* current_node = temp;
 
        while(current_node != NULL && current_node->left != NULL){    // LEFTMOST NODE WHICH IS SMALLEST
            current_node = current_node->left;
        }
        return current_node;
    }
 



    root* delete_node(root* temp, long long value){
    	
    	int count = 0;
     
        index_BST = hashFunction(value);
		temp = arr[index_BST];
 	    
     
        if(temp == NULL){
            cout<<"NO DATA is present ! "<<endl;
       }

       if(value < temp->data){
            temp->left = delete_node(temp->left, value);
        }
    
        else if(value > temp->data){
            temp->right = delete_node(temp->right, value);
        }

        else{
        
            if(temp->left == NULL && temp->right == NULL){          // LEAF
                cout<<"ID Number = "<<temp->data<<" has been permanently removed "<<endl;
                delete(temp);
                return NULL;
            }     
        
            else if(temp->left == NULL){        // ONE RIGHT CHILD                    
                root* temp_2 = temp;
                temp=temp->right;
                cout<<"ID Number = "<<temp_2->data<<" has been permanently removed "<<endl;
                delete(temp_2);
                return temp;
            }

            else if(temp->right == NULL){       // ONE LEFT CHILD  
                root* temp_2 = temp;
                temp=temp->left;
                cout<<"ID Number = "<<temp_2->data<<" has been permanently removed "<<endl;
                delete(temp_2);
                return temp;
            }

            else{    // 2 CHILDREN             
                root* temp_2 = smallest_node(temp->right);           
                temp->data = temp_2->data;
                temp->right = delete_node(temp->right, temp_2->data);
            }
        }    
        return temp;
   } 


 	
 	
 	
	void BST_search_ANALYSIS(root* temp, long long value){
		int count = 0;
		   
 	    index_BST = value % SIZE_BST;
 		 
 	    temp = arr[index_BST];
 		while(temp != NULL){
 			if(temp->data == value){
 				count++;
 				total_searches_bst++;
 		 	    break;
 			}
 			
			else if(value < temp->data){
				searches_attempt_BST++;
			 	temp = temp->left;
			} 
			
			else{
				searches_attempt_BST++;
			 	temp = temp->right;
			}
 		}
			   	
 		if(count == 0){
 	    }
 		
 	}
 	
 	
 	
 	
 	
 	
 	
 	

    void BST_display(root* temp){
    	
        for(int i=0; i<SIZE_BST; i++){
		    temp = arr[i];
			cout<<"Arr["<<i<<"]";
            
            while(temp!=NULL){
            	cout<<"------> "<<temp->data; 
                if(temp->left != NULL){
				    temp = temp->left; 
				}
				else{
					temp = temp->right;
				}  
            }
            cout<<"------> NULL"<<endl;
	    }
    }
 


};



int main(){
	hashing b;
	
	node a;
	a.link_chaining_NULL();
	
	root obj;
	obj.BST_chaining_NULL();
	root* temp = NULL;
    
	long long x;
	int option, option_2;
    long long id;
    
    srand(time(0));
	
	do{
		cout<<endl<<endl; 
		cout<<"  **** Welcome to NADRA ID System **** "<<endl;
		cout<<"       Developed by (Talha Khalid)    "<<endl;
		cout<<"1. Perform Operations Through LINEAR PROBING"<<endl;
		cout<<"2. Perform Operations Through LINKED LIST CHAINING"<<endl;
		cout<<"3. Perform Operations Through BST CHAINING"<<endl;
		cout<<"4. Data Analysis"<<endl;
		
	    cout<<"Enter the Option / Number = ";
		cin>>option; 
		
		switch(option){
			case 1:
			
			do{
				cout<<endl<<endl; 
				cout<<" ****  LINEAR PROBING   **** "<<endl;
				cout<<"1. Insert an ID "<<endl;
			    cout<<"2. Delete an ID "<<endl;
			    cout<<"3. Search an ID "<<endl;
			    cout<<"Enter the Number (Press 0 to go to the previous screen) = ";
			    cin>>option_2;
			    
				switch(option_2){
			    	case 1:
			    	cout<<"Enter the ID you want to insert = ";
					cin>>id;
					b.insert(id);
			     	break;
					
					case 2:
			    	cout<<"Enter the ID you want to delete = ";
					cin>>id;
					b.delete_prob(id);	
			     	break;
					
					case 3:
			    	cout<<"Enter the ID you want to search = ";
					cin>>id;
					b.search(id);	
			    	break;
			    	
			   		default:
			   		cout<<"ERROR ! Invalid Option you have entered. Please enter a valid Option / Number "<<endl;
				
				}
		 	}
			
			while(option_2!=0); 		
			break;
			
			
			
			case 2:
			
			do{
				cout<<endl<<endl; 
				cout<<" ****  LINKED LIST CHAINING   **** "<<endl;
				cout<<"1. Insert an ID "<<endl;
			    cout<<"2. Delete an ID "<<endl;
			    cout<<"3. Search an ID "<<endl;
			    cout<<"Enter the Number (Press 0 to go to the previous screen) = ";
			    cin>>option_2;
			    
				switch(option_2){
			    	case 1:
			    	cout<<"Enter the ID you want to insert = ";
					cin>>id;
					a.link_chaining_insert(id);
				 	break;
					
					case 2:
			    	cout<<"Enter the ID you want to delete = ";
					cin>>id;
					a.link_chaining_delete(id);	
			     	break;
					
					case 3:
			    	cout<<"Enter the ID you want to search = ";
					cin>>id;
					a.link_chaining_search(id);	
			    	break;
			    	
			   		default:
			   		cout<<"ERROR ! Invalid Option you have entered. Please enter a valid Option / Number "<<endl;
				
				}
		 	}
			
			while(option_2!=0); 		
			break;
			
			
			
			
			
			case 3:
			
			do{
				cout<<endl<<endl;
				cout<<" ****  BST CHAINING   **** "<<endl;
				cout<<"1. Insert an ID "<<endl;
			    cout<<"2. Delete an ID "<<endl;
			    cout<<"3. Search an ID "<<endl;
			    
				cout<<"Enter the Number (Press 0 to go to the previous screen) = ";
			    cin>>option_2;
			    
				switch(option_2){
			    	case 1:
			    	cout<<"Enter the ID you want to insert = ";
					cin>>id;
					obj.BST_insert(temp, id);	
					break;
					
					case 2:
			    	cout<<"Enter the ID you want to delete = ";
					cin>>id;
					obj.delete_node(temp, id);
				 	break;
					
					case 3:
			    	cout<<"Enter the ID you want to search = ";
					cin>>id;
					obj.BST_search(temp, id);	
			    	break;
			    	
			    	default:
			    		cout<<"ERROR ! Invalid Option you have entered. Please enter a valid Option / Number "<<endl;
				}
		 	}
			
			while(option_2!=0); 		
			
			break;
			
			
			case 4:
			
			for(int i=0; i<1000; i++){
                x = (rand() % 9999999999999) + 3999999999999;
     	        
	         	b.insert(x);
        
                cout<<endl;
        
	    	    a.link_chaining_insert(x);
		   
	    	    cout<<endl;
		
	         	obj.BST_insert(temp, x);
      
	  
	            cout<<endl;
		    }   
	 
	        for(int i=0; i<100; i++){
                x = (rand() % 9999999999999) + 3999999999999;
     	        b.search_ANALYSIS(x);
      
	            a.link_chaining_search_ANALYSIS(x);
	            cout<<endl; 
	    
	     
	            obj.BST_search_ANALYSIS(temp, x);
	            cout<<endl; 
	        } 

        
    
           cout<<endl;
           cout<<" ***** DISPLAYING FOR LINEAR PROBBING *****  "<<endl;
           cout<<endl<<endl;
	       b.display();
    
    
           cout<<"  *****************************************************************************   "<<endl;
           cout<<endl<<endl;
    
	       cout<<"  ***** DISPLAYING FOR LINKED LIST CHAINING ***** "<<endl;
           cout<<endl<<endl;
	
	       a.link_chaining_display();
	       cout<<endl<<endl;
	
           cout<<"  *****************************************************************************   "<<endl;
    
           cout<<endl<<endl;
    
    	    cout<<"  ***** DISPLAYING FOR BST CHAINING ***** "<<endl;
        	cout<<endl<<endl;
    
        	obj.BST_display(temp);
	
    	    cout<<endl<<endl;
	
	
    	 	cout<<"  *****************************************************************************   "<<endl;
    
         	cout<<endl<<endl;
         	cout<<endl<<endl;
         
		    	    
		    cout<<"Total Collisions in PROBBING CHAINING =  "<<b.collisions_PROBBING<<endl;
		    cout<<"Total Collisions in LINKED LIST CHAINING =  "<<a.collisions_LINK<<endl;
	        cout<<"Total Collisions in BST CHAINING =  "<<obj.collisions_BST<<endl;
 	 	
 	        cout<<endl<<endl<<endl;
 	    
	        cout<<"Total Searches in LINEAR PROBBING CHAINING =  "<<b.total_searches_Probbing<<endl;
		    cout<<"Total Searches in LINKED LIST CHAINING =  "<<a.total_searches_Linked<<endl;
	        cout<<"Total Searches in BST CHAINING =  "<<obj.total_searches_bst<<endl;
 	    
	        cout<<endl<<endl<<endl;
	    
	        cout<<"Total Searches Attempted in LINEAR PROBBING CHAINING =  "<<b.searches_attempt_linear<<endl;
	        cout<<"Total Searches Attempted in LINKED LIST CHAINING =  "<<a.searches_attempt_linked<<endl;
	        cout<<"Total Searches Attempted in BST CHAINING =  "<<obj.searches_attempt_BST<<endl;
 	    
			cout<<endl<<endl;
          	cout<<endl<<endl;
         
		    break;	
			
	 	default:
			cout<<"ERROR ! Invalid Option you have entered. Please enter a valid Option / Number "<<endl;
		}
	} 	
	while(option!=0);
	
	cout<<"Thanks for using the SOFTWARE"<<endl;

	
}
