# M1_General_Store_Bill

#TEST PLAN:
Table no: High level test plan
Test ID	Description	Exp I/P	Exp O/P	Actual Out	Type Of Test
H_01	Check if data is correctly entered.	Unique Account ID, name, phone, city, Account type.	Successful	Successful	Technical
H_02	Read record from file.	File pointer to file.	Successful	Successful	Technical
H_03	Display record properly.	noofAccounts pointer should be provided.	Display all Record properly.	Successful	Requirement
H_04	Search for a record.	Account ID should be provided.	Dispaly all details of particular Account ID.	Successful	Technical
H_05	Sort all records.	File storing all records.	Display all record after sorting them.	Successful	Technical
H_06	Write all records to file.	File pointer to file.	Successful	Successful	Technical
Table no: Low level test plan
Test ID	Description	Exp I/P	Exp O/P	Actual Out	Type Of Test
L_01	Check for unique ID if ID already exist do not allow insertion.	Account ID, File pointer	Successful	Successful	Technical
L_02	Read only correct data. Garbage value should not be allowed.	File pointer to file.	Successful	Successful	Technical
H_03	If there are no Account registered show no Account found.	noofAccounts pointer should be provided.	Display all registered records properly.	Successful	Requirement
H_04	If Account ID is not present display a message stating that No Account can be found.	Account ID should be provided.	Dispaly all details of particular Account ID.	Successful	Technical
H_05	If no Accounts are present then algorithm should be able to show No account registered.	File storing all records.	Display all record after sorting them.	Successful	Technical
