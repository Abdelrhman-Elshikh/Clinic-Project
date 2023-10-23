#include <stdio.h>
#include <stdlib.h>
#include "../linked_list/linkedList.h"
#include "../utilities/stdtypes.h"
#include "clinic.h"

extern Node * head;

static patient * Global_PtrToPationt = NULL;


//user Ids which reserved slots
Slot slotsArray[5] ={{"from 2 to 2:30",none},
{"from 2:30 to 3",none},
{"from 3 to 3:30",none},
{"from 4 to 4:30",none},
{"from 4:30 to 5",none}};


// int main(){

//    Clinic_VoidClinicInit();
//    Clinic_VoidNewPationt();
//    Clinic_VoidNewPationt();
//    // Clinic_VoidNewPationt();
   
//    PrintList();
   

//    // Clinic_voidPrintAllPationts();
//    // Clinic_voidReserveSlot(15,4);

//    Clinic_voidEditByID(16);
//    Clinic_voidPrintPatientData(Global_PtrToPationt);

//    printf("\n\n\n");
//    Clinic_voidPrintAllPationts();
// }

//initialize new linked list for patients
void Clinic_VoidClinicInit(void){
   ListInit();
}
//Take data about new user
void Clinic_VoidNewPationt(){
   //locate new memory to new pationt   
   patient * Local_ptrToPationt  = (patient *) malloc(sizeof(patient));
   //teke pationt name
   printf(" enter user name: ");
   scanf("%s",&Local_ptrToPationt->name);
   //if the the admin entered an exsist id 
   u32 Local_u16UniqueId=1; // 1: id exsist
   do
   {
      printf("plz Enter user unique id: ");
      scanf("%d",&(Local_ptrToPationt->ID));
      Local_u16UniqueId = Clinic_u32GetPatientByID(Local_ptrToPationt->ID);
   } while (Local_u16UniqueId == 1);
   
   
   //take pationt age
   printf("plz Enter age: ");
   scanf("%d",&Local_ptrToPationt->age);
   // make sure that user male or female
   do
   {
       printf("plz enter user gender. choose:\n 1 :male\n 2: female\n");
       scanf("%d", &Local_ptrToPationt->gender);
   } while ((Local_ptrToPationt->gender != male) && (Local_ptrToPationt->gender != female));
   //at first user have no any reservation
   Local_ptrToPationt->reserved = none;
   //pass the pointer to the data of the linked list
   AddNodeLast(Local_ptrToPationt);
}

void Clinic_voidPrintAllPationts(){
   Node *Local_NodeCurrnt = head;
   if (Local_NodeCurrnt == NULL) //if the list is  empty
   {
      printf("\nNo patients\n");
   }
   else{
      patient * Local_pationtPtrToPationt = (patient *)Local_NodeCurrnt->data;
      while (Local_NodeCurrnt != (Node *)NULL)
      {
         Local_pationtPtrToPationt = (patient *)Local_NodeCurrnt->data;
         Clinic_voidPrintPatientData(Local_pationtPtrToPationt);    
         Local_NodeCurrnt = Local_NodeCurrnt->next;
      } 
   }
}

void Clinic_voidPrintPatientData(patient * Local_pationtPtrToPationt){

   printf("\nName: %s\nAge = %d \n ID = %d\n",
   Local_pationtPtrToPationt->name,
   Local_pationtPtrToPationt->age,
   Local_pationtPtrToPationt->ID);
   if(Local_pationtPtrToPationt->gender == male){
      printf("gender = Male\n");
   }
   else if(Local_pationtPtrToPationt->gender == female){
      printf("gender = Female\n");
   }
   else;

   switch (Local_pationtPtrToPationt->reserved)
   {
   case none:
      printf("there is no any reservations\n");
      break;
   case F2T2_30:
      printf("reservation from 2 to 2:30 \n");
      break;
   case F2_30T3:
      printf("reservation from 2:30 to 3 \n");
      break;
   case F3T3_30:
      printf("reservation from 3 to 3:30 \n");
      break;
   case F4T4_30:
      printf("reservation from 4 to 4:30 \n");
      break;
   case F4_30T5:
      printf("reservation from 4:30 to 5 \n");
      break;
   default:
      break;
   }
}

void Clinic_voidEditByID(u32 Copy_u32PatientId){
   u16 Local_u16SelectField;
   if((Clinic_u32GetPatientByID(Copy_u32PatientId) ==1) && (Global_PtrToPationt != NULL)){
      printf("plz Select field:\n1:name\n2:age\n3:gender\n");
      scanf("%d",&Local_u16SelectField);
      
      switch (Local_u16SelectField)
      {
      case 1:{
         printf("enter new name:  ");
         scanf(" %s",&(Global_PtrToPationt->name));
         break;
      }
      case 2:{
         printf("enter new age:  ");
         scanf("%d",&(Global_PtrToPationt->age));
         break;
      }
      case 3:{
         printf("enter new gender:  ");
         do
            {
               printf("plz enter user gender. choose:\n 1 :male\n 2: female\n");
               scanf("%d", &(Global_PtrToPationt->gender));
            } while ((Global_PtrToPationt->gender != male) && (Global_PtrToPationt->gender != female));
         break;
      }
      default:{
         printf("\nWrong input\n");
         break;
      }
      }  
      printf("\n");
      Clinic_voidPrintPatientData(Global_PtrToPationt);
      printf("\n");
   }
   else{
      printf("\nThe id is incorrect\n");
   }
}

void Clinic_voidReserveSlot(u32 copy_u32PatientId, TimeSlots copy_TimeSlotsSlot){
   if(Clinic_u32GetPatientByID(copy_u32PatientId) == 1){

      if(slotsArray[copy_TimeSlotsSlot-1].id == none){
         if(Global_PtrToPationt ->reserved != none){
            slotsArray[(Global_PtrToPationt ->reserved)-1].id = none;
         }
         Global_PtrToPationt ->reserved = copy_TimeSlotsSlot;
         slotsArray[copy_TimeSlotsSlot-1].id = copy_u32PatientId;
      }
      else{
         printf("\nthis slot is not available\n");
      }
   }
   else{
      printf("\nThe id is incorrect\n");
   }
}

void Clinic_voidCancelReservation(u32 copy_u32PatientId){
   if(Clinic_u32GetPatientByID(copy_u32PatientId) ==1){
      if(Global_PtrToPationt->reserved != none){
         slotsArray[Global_PtrToPationt->reserved].id == none;
         Global_PtrToPationt->reserved = none;
      }
      else{
         printf("\nthis user has no reservation\n");
      }
   }
   else{
      printf("\nThe id is incorrect\n");
   }
}

void Clinic_voidPrintAvaliableSlots(){
   u32 Local_counter=0;
   printf("\nthe Avaliable Slots is:\n");
   for(Local_counter = 0 ; Local_counter < 5; Local_counter++ ){
      if(slotsArray[Local_counter].id == none){
         printf("%s\n",slotsArray[Local_counter].slot);
      }
   }
}

u32 Clinic_u32GetPatientByID(u32 Copy_u32PatientId){
   u32 Local_u16IsIdExsist = 0;
   Node * Local_NodeCurrnt = head;
   if (Local_NodeCurrnt == NULL) //if the list is  empty
   {
      Local_u16IsIdExsist = 0;
      Global_PtrToPationt = NULL; 
   }
   else{
      Global_PtrToPationt = (patient *)Local_NodeCurrnt->data;
      while(Local_NodeCurrnt != NULL)
      {
         if(Global_PtrToPationt ->ID != Copy_u32PatientId){
         Local_NodeCurrnt = Local_NodeCurrnt->next;
         }
         else{
            Local_u16IsIdExsist = 1;
            Global_PtrToPationt = ((patient *)((Local_NodeCurrnt)->data));
            break;
         }
      } 
   }
   return Local_u16IsIdExsist;
}

void Clinic_voidPrintPatientDataByID(u32 copy_u32PatientId){
   if(Clinic_u32GetPatientByID(copy_u32PatientId) == 1){
      Clinic_voidPrintPatientData(Global_PtrToPationt);
   }
   else{
      printf ("\nThis id not found\n");
   }
}