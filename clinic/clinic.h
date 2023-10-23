#ifndef CLINIC_H_
#define CLINIC_H_

typedef enum{
   male = 1,
   female = 2
}Genders;

typedef enum{
   none,
   F2T2_30, //from 2     to   2:30
   F2_30T3, //from 2:30  to   3
   F3T3_30, //from 3     to   3:30
   F4T4_30, //from 4     to   4:30
   F4_30T5  //from 4:30  to   5
}TimeSlots;

typedef struct 
{
   char slot[20];
   u32 id;
}Slot;



typedef struct
{
   char name[50];
   u32 ID;
   u16 age;
   u16 reserved;
   u16 gender;
}patient;


void Clinic_VoidClinicInit();
void Clinic_VoidNewPationt();
void Clinic_voidPrintAllPationts();
void Clinic_voidPrintPatientData(patient * Local_pationtPtrToPationt);
u32 Clinic_u32GetPatientByID(u32 Copy_u32PatientId);
void Clinic_voidEditByID(u32 Copy_u32PatientId);
void Clinic_voidReserveSlot(u32 copy_u32PatientId, TimeSlots copy_TimeSlotsSlot);
void Clinic_voidCancelReservation(u32 copy_u32PatientId);
void Clinic_voidPrintAvaliableSlots();
void Clinic_voidPrintPatientDataByID(u32 copy_u32PatientId);

#endif