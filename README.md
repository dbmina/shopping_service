"# shopping_service2"      
Objective : Implement a simple shopping service with client/admin interfaces and a database to store the product and user information.         
Description: You are a senior developer of an online shopping mall.       
Your mission is to implement an online shopping service to manage the product and user information. 
In addition, you are requested to implement a customized product recommendation functionality.       
Before you jump into the implementations, you may want to understand the overall structure of this service.          
The below figure shows the overall structure of the shopping system.         
The system mainly consists of 3 classes: AdminUI , ClientUI , and ShoppingDB (along with a few additional classes supporting these key classes.)      
● The AdminUI class provides interfaces for admins.      
● The ClientUI class provides interfaces for clients.           
● The ShoppingDB object receives the queries from the AdminUI object and ClientUI object, and returns the corresponding data.          

Objectives: Implement three methods of AdminUI to manage product data.  
Description: For the first step, implement an interface for admins to manage product data. In    
particular, implement the following methods of AdminUI . You also need to modify/add functions   
in the ShoppingDB class to store product data in the ShoppingDB object; this will be required for    
problems 1-2 and 1-3.
● Implement void AdminUI::add_product(std::string name, int price) .    
○ This function adds a product entry with the given name and price in the database.    
See the template code of the ShoppingDB class and decide on how to store the     
product information appropriately.                 
○ If the given price is positive, print “ADMIN_UI: <PRODUCT_NAME> is added to          
the database.”. (“<PRODUCT_NAME>” should be replaced with the name of the               
product; do not print “<” and “>”.)             
○ If the given price is equal to or less than zero, print "ADMIN_UI: Invalid price.".             
○ Assume that no duplicated names of products or users will be given.             
● Implement void AdminUI::edit_product(std::string name, int price) .              
○ This function modifies the price of the product of a given name in the database.                  
○ If there is a product with the given name in the database, print “ADMIN_UI:            
<PRODUCT_NAME> is modified from the database.”. Even if the price does not            
change to a new value, consider that the database is modified.          
○ If the given price is equal to or less than zero, print "ADMIN_UI: Invalid price."              
without modifying the info of the product.            
○ If there is no product with the given name in the database, print “ADMIN_UI:          
Invalid product name.”. If this is the case, do not check if the given price is valid.            
● Implement void AdminUI::list_products() .               
○ This function prints the list of entire products with the following format:                
“ADMIN_UI: Products: [(<PRODUCT_NAME1>, <PRODUCT_PRICE1>),  
(<PRODUCT_NAME2>, <PRODUCT_PRICE2>), …, (<PRODUCT_NAMEN>,  
<PRODUCT_PRICEN>)]”.   
○ Print the products in the order of the sequence the products are added to the    
database with "add_product" method.   
○ If there is no product in the database, print "ADMIN_UI: Products: []".      


Objective: Implement methods of ClientUI to support the users.       
Description: ClientUI provides an interface for clients to login, logout, search for products.           
Also, it allows a user to add products to his/her shopping cart and purchase them. There are two          
types of users, "normal user" and "premium user". Premium users get discounts off the normal            
price while normal users do not have any discount.          
As the first step, implement a sign-up, login, and logout functions of ClientUI . You also need to           
modify/add functions in the ShoppingDB class to store user data in the ShoppingDB object.          
● Implement void ClientUI::signup(std::string username, std::string password,      
bool premium) .            
○ This function creates an account with the given username and password. You          
need to store the account information in the database for the later use.         
○ Assume that no duplicated username is given.           
○ The premium parameter specifies whether the type of the user is a "premium         
user" or a "normal user".          
○ Print “CLIENT_UI: <USERNAME> is signed up.” when a user signed up.            
● Implement void ClientUI::login(std::string username, std::string password) .          
○ This allows a user to log in to the service. This means that you need to keep the          
log-in state of a user in an appropriate place.         
○ If the login is successful, print "CLIENT_UI: <USERNAME> is logged in.".        
○ If there is no user with the given name or the password does not match, print         
“CLIENT_UI: Invalid username or password.”.        
○ If there is a user currently logged-in, print "CLIENT_UI: Please logout first.". If this           
is the case, do not check if the given username and password are valid.        
● Implement void ClientUI:logout() .           
○ This allows a user to log out from the service.          
○ If there is a currently logged-in user, print "CLIENT_UI: <USERNAME> is logged        
out.". Otherwise, print "CLIENT_UI: There is no logged-in user."      
  
  Next, implement “add-to-cart” and “purchase” functions. In particular, implement the following          
methods of the ClientUI . You also need to modify/add functions in the ShoppingDB class to store         
user data in the ShoppingDB object.         
● For all the functions (i.e., buy , add_to_cart , list_cart_products , and buy_all_in_cart              
functions), check if a user is logged in.      
○ If there is no logged-in user, print “CLIENT_UI: Please login first.”.       
○ If a user is logged in, perform the requested task.        
● For functions buy, list_cart_products, and buy_all_in_cart, the print messages should        
reflect the current prices. Remember that the prices of the products can be modified with         
the void AdminUI::edit_product(std::string name, int price) method.         
● Implement void ClientUI::buy(std::string product_name)      
○ This function prints the price of a product with the given name (format:        
“CLIENT_UI: Purchase completed. Price: <PRICE>.”).       
○ A "premium user" gets a 10% discount ( round off to the nearest integer, round         
up if the first digit of the decimal point is 5 ). Print the discounted price for a          
premium user, and the original price for a normal user.        
○ If the given product name is invalid, print "CLIENT_UI: Invalid product name.".         
○ Note that this method has nothing to do with the products in the cart.           
● Implement void ClientUI::add_to_cart(std::string product_name) .     
○ This function adds a product to the cart of the logged-in user.        
○ The user can add the same product to the cart multiple times.      
○ Print “CLIENT_UI: <PRODUCT_NAME> is added to the cart.” after adding the         
product to the cart.       
○ If there is no product with the given name, print "CLIENT_UI: Invalid product       
name.".           
● Implement void ClientUI::list_cart_products() .         
○ This function prints all products in the cart of the logged-in user in ascending           
order of time (oldest first) that the products are added to the cart.              
○ The output format is “CLIENT_UI: Cart: [(<PRODUCT_NAME1>,          
<PRODUCT_PRICE1>), (<PRODUCT_NAME2>, <PRODUCT_PRICE2>), …]”.           
If there is no product in the cart, print "CLIENT_UI: Cart: []".        
○ You can assume that products in the database are not deleted when listing the            
product in the cart.      
○ Again, the discounted prices (i.e., 10% discount, round off to the nearest         
integer, round up if the first digit of the decimal point is 5 ) should be displayed         
for a premium user and the original prices for a normal user.          
● Implement void ClientUI::buy_all_in_cart() .          
○ Store the purchase information in the database. Question 1-3 will use the            
purchase history of users.             
○ Print the following message: “CLIENT_UI: Cart purchase completed. Total price:           
<TOTAL_PRICE>.” After that, clear the cart. If the cart is empty, print a message         
in the same format with zero total price.    
  
  Objectives: Implement void ClientUI::recommend_products() .             
Description: Now, you are asked to implement a product recommendation method based on        
the user’s purchase pattern. The recommendation for premium users will be different from that     
of normal users. In particular implement void ClientUI::recommend_products() which prints the         
recommending products for the logged-in user. The following are requirements and guidelines         
with details.         
● The printing format of void ClientUI::recommend_products() is “CLIENT_UI:            
Recommended products: [(<PRODUCT_NAME1>, <PRODUCT_PRICE1>),      
(<PRODUCT_NAME2>, <PRODUCT_PRICE2>), ...]”. If there is no product to          
recommend, print "CLIENT_UI: Recommended products: []".          
● The discounted prices (i.e., 10% discount, round off to the nearest integer, round up if       
the first digit of the decimal point is 5 ) should be displayed for a premium user and the        
original prices for a normal user.      
● If there is no logged-in user when void ClientUI::recommend_products() is called, print        
“CLIENT_UI: Please login first.” instead of printing the recommended products.         
● The print messages should reflect the current prices. Remember that the prices of the       
products can be modified with the void AdminUI::edit_product(std::string name, int         
price) method.     
● For the method recommend_product s check if a user is logged in.           
○ If there is no logged-in user, print “CLIENT_UI: Please login first.”.          
○ If a user is logged in, perform the requested task.        
The following explains more details about the recommendation policies:          
● Recommendation for a "normal user":         
○ Recommend three most recently purchased items of the logged-in user. Sort       
them in descending order of purchase time (the latest one first).       
○ The three recommended items should be unique. If there are duplicate        
purchases of the same product, consider it only once. For instance, if a user      
purchased products "a-b-c-d-c" in sequence, the recommended items should be        
"c-d-b".       
○ If the user purchased multiple products at the same time with a        
void ClientUI::buy_all_in_cart() call, assume that the product added to the      
cart later is purchased later. For example, 1) a user adds a “tissue”, and then a           
“chair” to the cart, 2) calls              
void ClientUI::buy_all_in_cart() , and 3) buys a “wallet” with           
void ClientUI::buy() , the recommendation list should be “wallet”, “chair”, and          
“tissue” in order.        

○ The number of items can be less than three if the purchase history is short.       
● Recommendation for a "premium user":     
○ Recommend recently purchased items of other users with the “similar” purchase     
history. The detailed logic is described below.       
○ First, sort all users (except for the currently logged-in user) based on purchase          
history similarities. The similarity between two users is defined as the number of       
product types purchased by both users. If a user purchased a product multiple          
times, consider this as only one product type. In case two users have the same       
similarities with the logged-in user, the user registered earlier goes first.        
○ Then, recommend the most recently purchased products of the three users with      
the highest similarities.       
○ The three recommended items should be unique. If there are duplicate items,         
consider it only once and include the most recently purchased product of the next        
similar user.         
○ If the user purchased multiple products at the same time with a          
void ClientUI::buy_all_in_cart() call, assume that the product added to the         
cart later is purchased later.        
○ For example, let's see how the recommended list can be decided for a premium         
user, Alexa. The table below shows the purchase history of 5 different users         
(including Alexa) and the purchase history similarities with Alexa.      
The most recently purchased product of a user is marked as blue.          
The most recently purchased products of the three users with the highest     
similarities is E-B-B in order. However, B is duplicated. Thus, instead of         
recommending two Bs, recommend A as the third item. So the final     
recommendation is E-B-A.      
