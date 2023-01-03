# Clinic Management System
Welcome to the Clinic Management System! This system is designed to assist with the management and organization of a clinic. It allows for the creation and management of patient records, as well as the reservation of appointments with doctors.

## Features
The Clinic Management System offers several features to assist with the management and organization of a clinic:

- Creation and management of patient records
- Reservation of appointments with doctors
- Cancellation of reservations
- Viewing of current reservations

## Usage
To use the Clinic Management System, compile and run the C program on a compatible device. Upon running the program, you will be prompted to select your mode - either **admin** or **user**.

If you select **admin**, you will be prompted to enter a password. If the password is correct, you will be taken to the admin menu. Here, you can choose from several options:

- Add a new patient record
- Show or edit a patient record
- View current reservations

If you select **user**, you will be taken to the user menu. Here, you can choose from several options:

- Reserve a slot with a doctor
- Cancel a reservation
- View current reservations

## Functions
The Clinic Management System is written in C and consists of the following functions:

- **main()** function: This is the entry point of the program. It prompts the user to choose between administrator and user mode, and then calls the appropriate function.

- **welcomeScreen()** function: This function displays a welcome message and prompts the user to choose between administrator and user mode.

- **adminMode()** function: This function displays a menu of options for the administrator and allows the administrator to perform various tasks, such as adding new patients, showing or editing patient records, and viewing reservations.

- **userMode()** function: This function displays a menu of options for the user and allows the user to perform various tasks, such as reserving a slot with the doctor or canceling a reservation.

- **addNew()** function: This function allows the administrator to add a new patient to the system by entering the patient's information.

- **showOrEditRec()** function: This function allows the administrator or user to view or edit a patient's record.

- **reserveSlot()** function: This function allows the user to reserve a slot with the doctor by entering their ID and desired slot number.

- **cancelRes()** function: This function allows the user to cancel a reservation by entering their ID.

- **viewRes()** function: This function allows the administrator or user to view the current reservations.

## Limitations
- Only one administrator can use the system at a time.
- The system can only manage information for a limited number of patients and reservations.

## Conclusion
The Clinic Management System is a useful tool for organizing and managing patient and reservation information in a clinic. While it has some limitations, it provides a number of useful features that can help clinics to run more efficiently.

## Copyright
The Clinic Management System is copyright (C) 2019 Maged Magdy. All rights reserved.

## Contact
For any questions or issues, please contact at magedmagdy.engr@gmail.com.
