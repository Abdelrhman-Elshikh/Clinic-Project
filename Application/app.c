#include <stdio.h>
#include <stdlib.h>
#include "../utilities/stdtypes.h"
#include "../clinic/clinic.h"
#include "app.h"

UserModes mode = NoUser ;

int main(){
   Clinic_VoidClinicInit();
   while (1)
   {   
      while (mode == NoUser)
      {
         do
         {
            printf("\nenter user mode\n");
            printf("choose\n1:admin\n2:normal user\n");
            scanf("%d",&mode);
         }while ((mode != admin) && (mode != normalUser));
      }
      
      if(mode == admin){
         App_voidAdmin();
      }
      else if (mode == normalUser){
         App_voidUser();
      }
   }
   return 0;
}

void App_voidUser(){
   u32 Local_u32UserId;  
   printf("\nEnter your id: ");
   scanf("%d",&Local_u32UserId);
   Clinic_voidPrintPatientDataByID(Local_u32UserId);

   mode = NoUser;
}

void App_voidAdmin(){
   u32 Local_u32PasswordWrongCounter=0;
   u32 Local_u32Password;
   u32 Local_u32ChooseOperation;
   u32 Local_u32patientId;
   TimeSlots slot;

   for(Local_u32PasswordWrongCounter =0; Local_u32PasswordWrongCounter < 3 ;Local_u32PasswordWrongCounter++){
      printf("\nEnter password: ");
      scanf("%d",&Local_u32Password);
      if(Local_u32Password != PASSWORD)
      {
         printf("\nWrong password\n");         
      }
      else{
         break;
      }
   }
   if (Local_u32PasswordWrongCounter >=3)
   {
      printf("\nWrong password entered to many times\n");
      mode = none;
   }
   

   while (mode == admin)
   {
      printf("\nchoose what you want to do\n");
      printf("0:change Mode\n1:Add new patient\n2:Edit patient record\n\
3:Reserve a slot with doctor\n4:Cancel reservation\n5:Show all patients: \n");
      scanf("%d",&Local_u32ChooseOperation);
      switch (Local_u32ChooseOperation)
      {
      case Exit:
         mode = NoUser;
         break;
      case AddNewPatient:
         Clinic_VoidNewPationt();
         break;
      case EditPatinetRecord:
         printf("enter patient id");
         scanf("%d",&Local_u32patientId);
         Clinic_voidEditByID(Local_u32patientId);
         break;
      case ReserveSlot:
         Clinic_voidPrintAvaliableSlots();
         printf("\nenter patient id: ");
         scanf("%d",&Local_u32patientId);
         printf("\nenter time slot: ");
         scanf("%d",&slot);
         Clinic_voidReserveSlot(Local_u32patientId,slot);
         break;
      case CancelReservation:
         printf("\nenter patient id: ");
         scanf("%d",&Local_u32patientId);
         Clinic_voidCancelReservation(Local_u32patientId);
         break;
      case ShowAllPetients:
         Clinic_voidPrintAllPationts();
         break;
      default:
         break;
      }
   }
      
}