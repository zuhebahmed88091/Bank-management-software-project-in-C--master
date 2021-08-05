#include<stdio.h>
#include<stdlib.h>

int i, j;
int main_exit;
void menu();
struct date {
	int month, day, year;
};
struct {

	char name[60];
	int acc_no, age;
	char address[60];
	char citizenship[15];
	long long phone;
	float amt;
	struct date dob;
	struct date deposit;
	struct date withdraw;

}add, upd, check, rem, transaction;
void new_acc()
{
	FILE *ptr;

	ptr = fopen("record.dat", "a+");
	system("cls");
	printf("\t\t\t ADD RECORD  ");
	printf("\n\n\nEnter today's date(mm/dd/yyyy format , sample 2/5/2017):");
	scanf("%d/%d/%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
account_no:
	printf("\nEnter the account number:");
	scanf("%d", &check.acc_no);
	while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
	{
		if (check.acc_no == add.acc_no)
		{
			printf("Account no. already in use!");
			goto account_no;
		}
	}
	add.acc_no = check.acc_no;
	printf("\nEnter the name:");
	scanf("%s", add.name);
	printf("\nEnter the date of birth(mm/dd/yyyy):");
	scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
	printf("\nEnter the age:");
	scanf("%d", &add.age);
	printf("\nEnter the address:");
	scanf("%s", add.address);
	printf("\nEnter the citizenship number:");
	scanf("%s", add.citizenship);
	printf("\nEnter the phone number: ");
	scanf("%lld", &add.phone);
	printf("\nEnter the amount to deposit:$");
	scanf("%f", &add.amt);
	fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
	fclose(ptr);
	printf("\nAccount created successfully!");
add_invalid:
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\nInvalid!\a");
		goto add_invalid;
	}
}
void view_list()
{
	FILE *view;
	view = fopen("record.dat", "r");
	int test = 0;
	system("cls");
	printf("\nACC.NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

	while (fscanf(view, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
	{
		printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lld", add.acc_no, add.name, add.address, add.phone);
		test++;
	}

	fclose(view);
	if (test == 0)
	{
		system("cls");
		printf("\nNO RECORDS!!\n");
	}

invalid:
	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d", &main_exit);
	system("cls");
	if (main_exit == 1)
		menu();
	else if (main_exit == 0)
		close();
	else
	{
		printf("\nInvalid!\a");
		goto invalid;
	}
}
void edit(void)
{
	int choice, test = 0;
	FILE *old, *newrec;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");

	printf("\nEnter the account no. of the customer whose info you want to change:");
	scanf("%d", &upd.acc_no);
	while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
	{
		if (add.acc_no == upd.acc_no)
		{
			test = 1;
			printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
			scanf("%d", &choice);
			system("cls");
			if (choice == 1)
			{
				printf("Enter the new address:");
				scanf("%s", upd.address);
				fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, upd.address, add.citizenship, add.phone, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
				system("cls");
				printf("Changes saved!");
			}
			else if (choice == 2)
			{
				printf("Enter the new phone number:");
				scanf("%lld", &upd.phone);
				fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, upd.phone, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
				system("cls");
				printf("Changes saved!");
			}
		}
		else
			fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");

	if (test != 1)
	{
		system("cls");
		printf("\nRecord not found!!\a\a\a");
	invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d", &main_exit);
		system("cls");
		if (main_exit == 1)

			menu();
		else if (main_exit == 2)
			close();
		else if (main_exit == 0)
			edit();
		else
		{
			printf("\nInvalid!\a");
			goto invalid;
		}
	}
	else
	{
		printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d", &main_exit);
		system("cls");
		if (main_exit == 1)
			menu();
		else
			close();
	}
}

void transact(void)
{
	int choice, test = 0;
	FILE *old, *newrec;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	printf("Enter the account no. of the customer:");
	scanf("%d", &transaction.acc_no);
	while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
	{
		if (add.acc_no == transaction.acc_no)
		{
			test = 1;
			printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
			scanf("%d", &choice);
			if (choice == 1)
			{
				printf("Enter the amount you want to deposit:$ ");
				scanf("%f", &transaction.amt);
				add.amt += transaction.amt;
				fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
				printf("\n\nDeposited successfully!");
			}
			else
			{
				printf("Enter the amount you want to withdraw:$ ");
				scanf("%f", &transaction.amt);
				add.amt -= transaction.amt;
				fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
				printf("\n\nWithdrawn successfully!");
			}
		}
		else
		{
			fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");
	if (test != 1)
	{
		printf("\n\nRecord not found!!");
	transact_invalid:
		printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d", &main_exit);
		system("cls");
		if (main_exit == 0)
			transact();
		else if (main_exit == 1)
			menu();
		else if (main_exit == 2)
			close();
		else
		{
			printf("\nInvalid!");
			goto transact_invalid;
		}
	}
	else
	{
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d", &main_exit);
		system("cls");
		if (main_exit == 1)
			menu();
		else
			close();
	}

}
void erase(void)
{
	FILE *old, *newrec;
	int test = 0;
	old = fopen("record.dat", "r");
	newrec = fopen("new.dat", "w");
	printf("Enter the account no. of the customer you want to delete:");
	scanf("%d", &rem.acc_no);
	while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
	{
		if (add.acc_no != rem.acc_no)
			fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.amt, add.deposit.month, add.deposit.day, add.deposit.year);

		else
		{
			test++;
			printf("\nRecord deleted successfully!\n");
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat", "record.dat");
	if (test == 0)
	{
		printf("\nRecord not found!!\a\a\a");
	erase_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d", &main_exit);

		if (main_exit == 1)
			menu();
		else if (main_exit == 2)
			close();
		else if (main_exit == 0)
			erase();
		else
		{
			printf("\nInvalid!\a");
			goto erase_invalid;
		}
	}
	else
	{
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d", &main_exit);
		system("cls");
		if (main_exit == 1)
			menu();
		else
			close();
	}

}

void see(void)
{
	FILE *ptr;
	int test = 0, rate;
	int choice;
	float time;
	float intrst;
	ptr = fopen("record.dat", "r");
	printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("Enter the account number:");
		scanf("%d", &check.acc_no);

		while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
		{
			if (add.acc_no == check.acc_no)
			{
				system("cls");
				test = 1;
				printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%lld \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
					add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
			}
		}
	}
	else if (choice == 2)
	{
		printf("Enter the name:");
		scanf("%s", &check.name);
		while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lld %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF)
		{
			if (strcmpi(add.name, check.name) == 0)
			{
				system("cls");
				test = 1;
				printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%lld \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone,
					add.amt, add.deposit.month, add.deposit.day, add.deposit.year);
			}
		}
	}


	fclose(ptr);
	if (test != 1)
	{
		system("cls");
		printf("\nRecord not found!!\a\a\a");
	invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d", &main_exit);
		system("cls");
		if (main_exit == 1)
			menu();
		else if (main_exit == 2)
			close();
		else if (main_exit == 0)
			see();
		else
		{
			system("cls");
			printf("\nInvalid!\a");
			goto invalid;
		}
	}
	else
	{
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d", &main_exit);
	}
	if (main_exit == 1)
	{
		system("cls");
		menu();
	}

	else
	{

		system("cls");
		close();
	}

}


void close(void)
{
	printf("Thanks for using Made by Samir Imtiaz ");
}

void menu(void)
{
	int choice;
	system("cls");
	system("color F4");
	printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
	printf("\n\n\n\t\t\t MAIN MENU ");
	printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
	scanf("%d", &choice);

	system("cls");
	switch (choice)
	{
	case 1:new_acc();
		break;
	case 2:edit();
		break;
	case 3:transact();
		break;
	case 4:see();
		break;
	case 5:erase();
		break;
	case 6:view_list();
		break;
	case 7:close();
		break;

	}



}
int main()
{
	char pass[10], password[10] = "samir";
	printf("\n\n\t\tEnter the password to login:");
	scanf("%s", pass);

	if (strcmp(pass, password) == 0)
	{
		printf("\n\nPassword Match!\n");
		system("cls");
		menu();
	}
	else
	{
		printf("\n\nWrong password!!\a\a\a");
	login_try:
		printf("\nEnter 1 to try again and 0 to exit:");
		scanf("%d", &main_exit);
		if (main_exit == 1)
		{
			system("cls");
			main();
		}

		else if (main_exit == 0)
		{
			system("cls");
			close();
		}
		else
		{
			printf("\nInvalid!");
			system("cls");
			goto login_try;
		}
	}
	return 0;
}
