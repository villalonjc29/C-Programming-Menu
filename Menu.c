#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char user_name [20], user_pass [20];
int PRICE_LIST [] = {120, 100, 150, 125, 150, 130, 90, 120, 125, 130, 125, 110, 20, 70, 85, 85, 50, 55, 25, 20};
char MENU_LIST [20] [50] = {"Adobo               ", "Sisig               ", "Crispy Pata         ", "Chicken Inasal    ", "Kare-Kare         ", "Sinigang na Baboy", "Dinuguan at Puto", "Bagnet          ", "Bicol Express    ", "Laing               ", "Inihaw na Liempo", "Bangus          ", "Rice               ", "Leche Flan         ", "Halo-Halo         ", "Puto Bumbong    ", "Buko Pie         ", "Bibingka         ", "Iced Tea         ", "Bottled Water    "};
int QUANTITY [20] = {0};
int ITEM [20] = {0};

int main()
{
    char add_order;
    void maskPassword ();
    int login (char a [20], char b [20]);
    int option_num, order_num, order_quantity, after_order, disc_code;
    int i = 0;
    float cash_in;
    float order_total (int c, int d);
    float discounted_amount2 (float oldTotal);
    float discounted_amount3 (float oldTotal);
    float x = 0;
    void restau_menu();
    for (;;)
    {
    	printf ("----------Login Page----------------\n");
        printf ("Enter username:\n");
        scanf ("%s", user_name);
        printf ("Enter password:\n");
        maskPassword ();
        if (login (user_name, user_pass) == 1) { 
        	system ("cls");
            break;
        }
        else {
        }
    }
    restau_menu();
    for (;;) 
	{
    system("cls");
    printf ("----------OPTIONS----------\n");
    printf ("01 Back to Menu\n");
    printf ("02 Take Order\n");
    printf ("03 Exit\n");
    printf ("Enter Option Number:\n");
    scanf ("%d", &option_num);
    system ("cls");
    switch (option_num) {
    	case 01: 
    	restau_menu();
			break;

    	case 02:
    		system ("cls");
    		restau_menu();
    		for (;;) 
			{
	    		printf ("----------Take Order----------\n");
	    		printf ("Enter Order\n");
	    		scanf ("%d", &order_num);
	    		printf ("Quantity\n");
	    		scanf ("%d", &order_quantity);
	    		x += order_total (order_num, order_quantity);
	    		printf ("Total: %.2f\n",x);
	    		for (i = 0; i <= 20; i ++) {
	    			if (i == order_num) {
	    				ITEM [i - 1] = 1;
	    				QUANTITY [i - 1] += order_quantity;
					}
				}
				
				if (order_num > 20 || order_num <= 0) {
					printf ("Item does not exist!\n");
				}			
    			printf ("Additional Order? (Y/N)\n");
    			scanf ("%s", &add_order);
    			if (add_order == 'y' || add_order == 'Y') {
    			
			}
				else if (add_order == 'N' || add_order == 'n') {
				break;
			}
			
    		}
    		printf ("Enter 1 for Receipt, 2 for Options, 3 to Exit.\n");
    		scanf ("%d", &after_order);
    		switch (after_order) {
    			case 1:
    				system ("cls");
    				printf ("--------------------------------------------------------RECEIPT----------------------------------------------------\n");
    				printf ("Item\t\t\t\t\t\t    Quantity\t\t\t\t\t\tCost\n");
    				int i = 0;
    				for (i = 0; i <= 20; i ++) 
					{
						if (ITEM [i] != 0) {
						printf ("%s\t\t\t\t\t%d\t\t\t\t\t\t%d PHP\n", MENU_LIST [i], QUANTITY [i], PRICE_LIST [i] * QUANTITY [i]);
						}
					}
					
					printf ("Total: %.2f PHP\n", x);
					printf ("Discount? ([1]- None, [2]- Senior Citizen: 20%% discount, [3]-Others: 30%% discount )\n");
					scanf ("%d", &disc_code);
					switch (disc_code) {
						case 1:
							for (;;) {
							printf ("Cash:\n");
							scanf ("%f", &cash_in);
							if (cash_in>=x) {
							printf ("Change is %.2f PHP\n", cash_in - x);
							printf ("Thank you for choosing Kuya M's! Keep safe!\n");
							exit (1);
							}
							else {
								printf ("Invalid! \n");
							}

							}
							break;
							
						case 2:
							for (;;) {
							printf ("New total is %.2f PHP\n", x - (discounted_amount2 (x)));
							printf ("Cash:\n");
							scanf("%f", &cash_in);
							if (cash_in >= (x - (discounted_amount2 (x)))) {
								printf ("Change is %.2f PHP\n", cash_in - ( x - (discounted_amount2(x))));
								printf ("Thank you for choosing Kuya M's! Keep safe!\n");
								exit (1);
							}
							else {
								printf ("Invalid!\n");
							}
						}
							break;
							
						case 3:
							for (;;) {
								printf ("New total is %.2f PHP\n", x - (discounted_amount3(x)));
								printf ("Cash:\n");
								scanf("%f", &cash_in);
								if (cash_in >= (x-(discounted_amount3 (x)))) {
										printf ("Change is %.2f PHP\n", cash_in - (x-(discounted_amount3(x))));
										printf ("Thank you for choosing Kuya M's! Keep safe! \n");
										exit (1);
								}
								else {
									printf ("Invalid!\n");
								}
							}
							break;
							
						default:
							printf("Invalid\n");
							break;
					}
					break;
					
					case 2:
						break;
						
					case 3:
						printf ("Thank you! Keep safe!\n"); 
						exit (1);
			}
    		break;
    	
		case 3:
			printf ("-----------END---------\n");
    		exit (1);
    		break;
    		
    	default:
    		printf ("Error invalid input. Please try again.\n");
    		system ("cls");
    		break;
    		
			}
			
    	}
    	printf ("End\n");
    	return 0;
    }
    

    	
    	
	    

int login (char a [20], char b [20]) 
{
    int x;
        if (strcmp (a, "ilovesisig321") == 0) 
        {
            if (strcmp (b, "kaintayo321") == 0) 
            {
            		system("cls");
                    printf ("Welcome!\n");
                    x = 1;
                }
                else 
                {
                	system ("cls");
                    printf ("Wrong Password.\n");
                    printf ("Please try again.\n");
                    x = 2;
                }
        }
        else if (strcmp (a, "adobolovers123")== 0)
        {
            if (strcmp (b, "tayokain123")==0)
            {
            	system ("cls");
            printf ("Welcome!\n");
            	x = 1;
            }
            else 
            {
            	system ("cls");
                printf ("Wrong Password.\n");
                printf ("Please try again.\n");
                x = 2;
            }
        }
        else if (strcmp (a, "KuyaM12") == 0)
        {
            if (strcmp (b, "kaintayo123") == 0)
            {
            	system ("cls");
                printf ("Welcome!\n");
                x = 1;
            }
            else 
            {
            	system ("cls");
                printf ("Wrong Password.\n");
                printf ("Please try again.\n");
                x = 2;
            }
        }
        else 
        {
            system ("cls");
			printf ("Username does not exist\n");
            x = 3;
        }
                
            return x;
}

void restau_menu () {
	printf ("------------------------------------------------------KUYA M'S TINDAHAN MENU-----------------------------------------------------------\n");
    printf ("01\tAdobo\t\t\t\t\t120 PHP\t\t\t11\tInihaw na Liempo\t\t\t125 PHP\n");
    printf ("02\tSisig\t\t\t\t\t100 PHP\t\t\t12\tBangus\t\t\t\t\t110 PHP\n");
    printf ("03\tCrispy Pata\t\t\t\t150 PHP\t\t\t13\tRice\t\t\t\t\t20  PHP\n");
    printf ("04\tChicken Inasal\t\t\t\t125 PHP\t\t\t14\tLeche Flan\t\t\t\t70  PHP\n");
    printf ("05\tKare-Kare\t\t\t\t150 PHP\t\t\t15\tHalo-Halo\t\t\t\t85  PHP\n");
    printf ("06\tSinigang na Baboy\t\t\t130 PHP\t\t\t16\tPuto Bumbong\t\t\t\t85  PHP\n");
    printf ("07\tDinuguan at Puto\t\t\t90  PHP\t\t\t17\tBuko Pie\t\t\t\t50  PHP\n");
    printf ("08\tBagnet\t\t\t\t\t120 PHP\t\t\t18\tBibingka\t\t\t\t55  PHP\n");
    printf ("09\tBicol Express\t\t\t\t125 PHP\t\t\t19\tIced Tea\t\t\t\t25  PHP\n");
    printf ("10\tLaing\t\t\t\t\t130 PHP\t\t\t20\tBottled Water\t\t\t\t20  PHP\n");
    printf ("Press any key to continue................\n");
    getch();
    
}

void maskPassword () {
	char m;
	int i;
	for (i = 0; i <= 20; i ++) {
		m = getch ();
		if (m == 13){
			break;
		}
		user_pass [i] = m;
		m = '*';
		printf ("%c", m);
	}

}

float order_total (int c, int d) {
	float b;
	int i = 1;
	for (i = 1; i <= 20; i ++) {
		if (i == c) {
			b = d * PRICE_LIST [i - 1];
		}
	}
	return b;		
	}
	


float discounted_amount2 (float oldTotal) {
	float result = oldTotal * 0.2;
	return result;
}

float discounted_amount3 (float oldTotal){
	float result = oldTotal * 0.3;
	return result;
}



