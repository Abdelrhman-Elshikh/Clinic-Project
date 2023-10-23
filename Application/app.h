#ifndef APP_H_
#define APP_H_

typedef enum {
   NoUser,
   admin,
   normalUser,
}UserModes;

typedef enum{
   Exit,
   AddNewPatient,
   EditPatinetRecord,
   ReserveSlot,
   CancelReservation,
   ShowAllPetients
}AdminTasks;


#define PASSWORD 1234

void App_voidUser();
void App_voidAdmin();



#endif