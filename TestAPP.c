/* *****************************************************************************
 * BEGIN: Banner
 *-----------------------------------------------------------------------------
 *                                 ETAS GmbH
 *                      D-70469 Stuttgart, Borsigstr. 14
 *-----------------------------------------------------------------------------
 *    Administrative Information (automatically filled in by ISOLAR)         
 *-----------------------------------------------------------------------------
 * Name: 
 * Description:
 * Version: 1.0
 *-----------------------------------------------------------------------------
 * END: Banner
 ******************************************************************************

 * Project : EDM2_BSW_TC377
 * Component: /TestAPP/TestAPP
 * Runnable : All Runnables in SwComponent
 *****************************************************************************
 * Tool Version: ISOLAR-A/B 9.1.2
 * Author: maa920226
 * Date : Wed Jan 12 12:00:10 2022
 ****************************************************************************/

#include "Rte_TestAPP.h"
#include "XETK_Ctrl.h"
#include "IfxCpu_regdef.h"
#include "IfxCpu_reg.h"
#include "Os.h"
#include "EcuM_Callout.h"
#include "RstMngr.h"
#include "DSPRx_MemMngr.h"
#include "ETK_SER_Page_Ctrl_Fct.h"
#include "Stubs.h"
#include "Cond_Compile.h"
/*PROTECTED REGION ID(FileHeaderUserDefinedIncludes :TestAPP_Cyclic_100ms) ENABLED START */
/* Start of user defined includes  - Do not remove this comment */
/* End of user defined includes - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedConstants :TestAPP_Cyclic_100ms) ENABLED START */
/* Start of user defined constant definitions - Do not remove this comment */
/* End of user defined constant definitions - Do not remove this comment */
/*PROTECTED REGION END */

/*PROTECTED REGION ID(FileHeaderUserDefinedVariables :TestAPP_Cyclic_100ms) ENABLED START */
/* Start of user variable defintions - Do not remove this comment  */
/* End of user variable defintions - Do not remove this comment  */
/*PROTECTED REGION END */

uint32 ASWCore0_Counter_2ms;

uint32 ASWCore0_Counter_1ms;

uint32 ASWCore0_Counter_100ms;

/*EDM2_V7_2_MCPX_400V_XXX*/

#define CALIBRATION_START_SEC
#include "Rte_MemMap.h"
#if (!EDM800V_ASample_ENABLE && MCPA_ENBL && BOARD_VARIANT_SW_DEV)
	const char SwVersion[50]={'E','D','M','2','_','V','7','_','2','_','M','C','P','A','_','4','0','0','V','_','S','W','D','E','V'};
#elif (!EDM800V_ASample_ENABLE && MCPB_ENBL && BOARD_VARIANT_SW_DEV)
	const char SwVersion[50]={'E','D','M','2','_','V','7','_','2','_','M','C','P','B','_','4','0','0','V','_','S','W','D','E','V'};
#elif (!EDM800V_ASample_ENABLE && SGCP_ENBL && BOARD_VARIANT_SW_DEV)
	const char SwVersion[50]={'E','D','M','2','_','V','7','_','2','_','S','G','C','P','_','4','0','0','V','_','S','W','D','E','V'};
#elif (!EDM800V_ASample_ENABLE && MCPA_ENBL && BOARD_VARIANT_DV)
	const char SwVersion[50]={'E','D','M','2','_','V','7','_','2','_','M','C','P','A','_','4','0','0','V','_','D','V'};
#elif (!EDM800V_ASample_ENABLE && MCPB_ENBL && BOARD_VARIANT_DV)
	const char SwVersion[50]={'E','D','M','2','_','V','7','_','2','_','M','C','P','B','_','4','0','0','V','_','D','V'};
#elif (!EDM800V_ASample_ENABLE && SGCP_ENBL && PROJ_VARIANT_GPIM)
	const char SwVersion[50]={'E','D','M','2','_','V','7','_','2','_','S','G','C','P','_','4','0','0','V','_','G','P','I','M'};
#elif (EDM800V_ASample_ENABLE && MCPA_ENBL && BOARD_VARIANT_SW_DEV)
	const char SwVersion[50]={'E','D','M','2','_','V','7','_','2','_','M','C','P','A','_','8','0','0','V'};
#elif (EDM800V_ASample_ENABLE && MCPB_ENBL && BOARD_VARIANT_SW_DEV)
	const char SwVersion[50]={'E','D','M','2','_','V','7','_','2','_','M','C','P','B','_','8','0','0','V'};
#else
	#error "no variant selected"
#endif
/*const char SwVersion[50]={"00B_2212B0_MCPA"};*/
#define CALIBRATION_STOP_SEC
#include "Rte_MemMap.h"
uint32 csaVal_1 =0;
Ifx_CPU_DEADD_Bits csaVal_2;

 uint16 csaVal_3;
 uint32 *CSA_Ptr_1;
 uint32 csafun_1(uint32* );   
 uint8 NVM_BLOCK_Test = 0;
 uint8 NVM_BLOCK_Test_Read_36[198]={0};
uint8 NVM_BLOCK_Test_Read_37[32]={0};
uint8 NVM_BLOCK_Test_Read_38[7]={0};
uint8 NVM_BLOCK_Test_Read_39[20]={0};
uint8 NVM_BLOCK_Test_Read_40[16]={0};
uint8 NVM_BLOCK_Test_Read_41[4]={0};
uint8 NVM_BLOCK_Test_Read_42[640]={0};
uint8 NVM_BLOCK_Test_Read_35[6]={0};
uint8 NVM_BLOCK_Test_Write_35[6]={0};
uint8 NVM_BLOCK_Test_Read_0[1] = {0};
uint8 NVM_BLOCK_Test_Read_1[2] = {0};
uint8 NVM_BLOCK_Test_Write_1[2] = {0};
uint8 NVM_BLOCK_Test_Write_0[1] = {0};
 uint8 NVM_BLOCK_Test_Write_36[198]={0};
uint8 NVM_BLOCK_Test_Write_37[32]={0};
uint8 NVM_BLOCK_Test_Write_38[7]={0};
uint8 NVM_BLOCK_Test_Write_39[20]={0};
uint8 NVM_BLOCK_Test_Write_40[16]={0};
uint8 NVM_BLOCK_Test_Write_41[4]={0};
uint8 NVM_BLOCK_Test_Write_42[640]={0};     
 uint32 Rst_info_trap_trig =0;
 volatile const uint32 Rst_info_trap_trig_C=0;
 volatile const uint32 Rst_Info_Trap_Trig_Cal_En_C=0;

 Os_StackSizeType TaskMaxStackUsage [OS_NUM_CORES][6];
 Os_StackSizeType IsrMaxStackUsage [OS_NUM_ISRS];

uint16 TrigErrHook = 0;
//uint8 DSPRx_RstNVRAM_ClrCmd = 0;
#define TestAPP_START_SEC_CODE                   
#include "TestAPP_MemMap.h"
FUNC (void, TestAPP_CODE) TestAPP_Cyclic_100ms/* return value & FctID */
(
		void
)
{
	/*PROTECTED REGION ID(UserVariables :TestAPP_Cyclic_100ms) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;
    /*if(DSPRx_RstNVRAM_ClrCmd == 1)
    {
        DSPRx_MemClrSelect(DSPRx_RSTNVRAM_MEM_CLEAR);
		DSPRx_RstNVRAM_ClrCmd = 0;
    }*/

/* ajj924662 NVM Write Read Test Code*/
if(NVM_BLOCK_Test==1)
    {
        NvM_WriteBlock(0,&NVM_BLOCK_Test_Write_0);
        NVM_BLOCK_Test = 0;
	}
    if (NVM_BLOCK_Test==2)
	
    {
		NvM_ReadBlock(0,&NVM_BLOCK_Test_Read_0);
        NVM_BLOCK_Test = 0;
    }


	if(NVM_BLOCK_Test==3)
    {
        NvM_WriteBlock(1,&NVM_BLOCK_Test_Write_1);
        NVM_BLOCK_Test = 0;
    }
    if (NVM_BLOCK_Test==4)
    {
    NvM_ReadBlock(1,&NVM_BLOCK_Test_Read_1);
    NVM_BLOCK_Test = 0;
    }
	if(NVM_BLOCK_Test==71)
	{ 
		 NvM_WriteBlock(35,&NVM_BLOCK_Test_Write_35);
	     NVM_BLOCK_Test = 0;
	  }
	if(NVM_BLOCK_Test==72)
	{
		 NvM_ReadBlock(35,&NVM_BLOCK_Test_Read_35);
	    NVM_BLOCK_Test = 0;
	}
	if(NVM_BLOCK_Test==73)
	{
		NvM_WriteBlock(36,&NVM_BLOCK_Test_Write_36);
	    NVM_BLOCK_Test = 0;
	 }
	if(NVM_BLOCK_Test==74)
	{
		 NvM_ReadBlock(36,&NVM_BLOCK_Test_Read_36);
	      NVM_BLOCK_Test = 0;
	}

	if(NVM_BLOCK_Test==75) 
	{
		NvM_WriteBlock(37,&NVM_BLOCK_Test_Write_37);
	    NVM_BLOCK_Test = 0;
	  }
	if(NVM_BLOCK_Test==76)
	{
		NvM_ReadBlock(37,&NVM_BLOCK_Test_Read_37);
	    NVM_BLOCK_Test = 0;
	 }

	  if(NVM_BLOCK_Test==77) 
	{
		NvM_WriteBlock(38,&NVM_BLOCK_Test_Write_38);
	    NVM_BLOCK_Test = 0;
	 }
	 if(NVM_BLOCK_Test==78)
	 {
		NvM_ReadBlock(38,&NVM_BLOCK_Test_Read_38);
	    NVM_BLOCK_Test = 0;
	}

	if(NVM_BLOCK_Test==79) 
	{
		NvM_WriteBlock(39,&NVM_BLOCK_Test_Write_39);
        NVM_BLOCK_Test = 0;
	  }
	 if(NVM_BLOCK_Test==80)
	  {
		 NvM_ReadBlock(39,&NVM_BLOCK_Test_Read_39);
	     NVM_BLOCK_Test = 0;
	 }

	 if(NVM_BLOCK_Test==81) 
	 {
		NvM_WriteBlock(40,&NVM_BLOCK_Test_Write_40);
	    NVM_BLOCK_Test = 0;
	 }
	 if(NVM_BLOCK_Test==82)
	 {
		NvM_ReadBlock(40,&NVM_BLOCK_Test_Read_40);
	    NVM_BLOCK_Test = 0;
	 }

	 if(NVM_BLOCK_Test==83)
	 {
		NvM_WriteBlock(41,&NVM_BLOCK_Test_Write_41);
        NVM_BLOCK_Test = 0;
	 }
	 if(NVM_BLOCK_Test==84)
	 {
	 NvM_ReadBlock(41,&NVM_BLOCK_Test_Read_41);
	 NVM_BLOCK_Test = 0;
	}

	 if(NVM_BLOCK_Test==85) 
	 {
		NvM_WriteBlock(42,&NVM_BLOCK_Test_Write_42);
        NVM_BLOCK_Test = 0;
	 }
	 if(NVM_BLOCK_Test==86)
	 {
		NvM_ReadBlock(42,&NVM_BLOCK_Test_Read_42);
	    NVM_BLOCK_Test = 0;
	 }

    if(TrigErrHook == 1)
    {
        EcuM_ErrorHook(3);
	    TrigErrHook = 0;
    }
    if(Rst_Info_Trap_Trig_Cal_En_C==1)
	{
	Rst_info_trap_trig=Rst_info_trap_trig_C;	
	}
	else
	{
    //do nothing
	}
	
	if (Rst_info_trap_trig == 1 )
	{
		*CSA_Ptr_1 = (uint32*) csaVal_1;
		Rst_info_trap_trig =0;
	}
	else 
	{
		/*do nothing */
	}
    if (Rst_info_trap_trig == 12 )
    {
	  Rst_info_trap_trig=0;
      HW_SystemReset();	
    }


	if (Rst_info_trap_trig == 4 )
	{
		csaVal_2 = CPU0_DEADD.B ;
	}
	else 
	{
		/*do nothing */
	}


	if (Rst_info_trap_trig == 5 )
	{
		csaVal_1 = 4u/ 0;
        Rst_info_trap_trig =0;
	}
	else 
	{
		/*do nothing */
	}

	if (Rst_info_trap_trig == 6 )
	{
		csaVal_3 = 0xFFFF * 2;
        Rst_info_trap_trig =0;
	}
	else 
	{
		/*do nothing */
	}

   TaskMaxStackUsage[0][0] = GetTaskMaxStackUsage(OsTask1ms);
   TaskMaxStackUsage[0][1] = GetTaskMaxStackUsage(OsTask2ms);
   TaskMaxStackUsage[0][2] = GetTaskMaxStackUsage(OsTask_5ms);
   TaskMaxStackUsage[0][3] = GetTaskMaxStackUsage(OsTask10ms);
   TaskMaxStackUsage[0][4] = GetTaskMaxStackUsage(OsTask100ms);
   TaskMaxStackUsage[0][5] = GetTaskMaxStackUsage(OsTask_com);

   TaskMaxStackUsage[1][0] = GetTaskMaxStackUsage(OsTask1ms_1);
   TaskMaxStackUsage[1][1] = GetTaskMaxStackUsage(OsTask2ms_1);
   TaskMaxStackUsage[1][3] = GetTaskMaxStackUsage(OsTask10ms_1);
   TaskMaxStackUsage[1][4] = GetTaskMaxStackUsage(OsTask100ms_1);

   TaskMaxStackUsage[2][0] = GetTaskMaxStackUsage(OsTask1ms_2);
   TaskMaxStackUsage[2][1] = GetTaskMaxStackUsage(OsTask2ms_2);
   TaskMaxStackUsage[2][3] = GetTaskMaxStackUsage(OsTask10ms_2);
   TaskMaxStackUsage[2][4] = GetTaskMaxStackUsage(OsTask100ms_2);
	
//    IsrMaxStackUsage[0] = GetISRMaxStackUsage(OsIsr_AdcSr0_DmaErr0);
//    IsrMaxStackUsage[1] = GetISRMaxStackUsage(OsIsr_QSPI_DmaErr1);
//    IsrMaxStackUsage[2] = GetISRMaxStackUsage(OsIsr_Dma_DmaErr2);
//    IsrMaxStackUsage[3] = GetISRMaxStackUsage(OsIsr_QspiErr0);
//    IsrMaxStackUsage[4] = GetISRMaxStackUsage(OsIsr_QspiErr1);
//    IsrMaxStackUsage[5] = GetISRMaxStackUsage(OsIsr_QspiErr2);
//    IsrMaxStackUsage[6] = GetISRMaxStackUsage(OsIsr_QspiErr3);
//    IsrMaxStackUsage[7] = GetISRMaxStackUsage(OsIsr_QspiErr4);
//    IsrMaxStackUsage[8] = GetISRMaxStackUsage(OsIsr_ASCLIN4Err);
//    IsrMaxStackUsage[9] = GetISRMaxStackUsage(OsIsr_ASCLIN4Rx);
//    IsrMaxStackUsage[10] = GetISRMaxStackUsage(OsIsr_ASCLIN4Tx);
//    IsrMaxStackUsage[11] = GetISRMaxStackUsage(OsIsr_Can00BusOff_SRC_CAN0INT2);
//    IsrMaxStackUsage[12] = GetISRMaxStackUsage(OsIsr_Can00Rx_SRC_CAN0INT0);
//    IsrMaxStackUsage[13] = GetISRMaxStackUsage(OsIsr_Can00Tx_SRC_CAN0INT1);
//    IsrMaxStackUsage[14] = GetISRMaxStackUsage(OsIsr_Can01BusOff_SRC_CAN0INT6);
//    IsrMaxStackUsage[15] = GetISRMaxStackUsage(OsIsr_Can01Rx_SRC_CAN0INT4);
//    IsrMaxStackUsage[16] = GetISRMaxStackUsage(OsIsr_Can01Tx_SRC_CAN0INT5);
//    IsrMaxStackUsage[17] = GetISRMaxStackUsage(OsIsr_Can02BusOff_SRC_CAN0INT10);
//    IsrMaxStackUsage[18] = GetISRMaxStackUsage(OsIsr_Can02Rx_SRC_CAN0INT8);
//    IsrMaxStackUsage[19] = GetISRMaxStackUsage(OsIsr_Can02Tx_SRC_CAN0INT9);
//    IsrMaxStackUsage[20] = GetISRMaxStackUsage(OsIsr_GTMTOM10_SRC_GTMTOM10);
//    IsrMaxStackUsage[21] = GetISRMaxStackUsage(OsIsr_STM0_SRC_STM0SR0);
//    IsrMaxStackUsage[22] = GetISRMaxStackUsage(OsIsr_STM0_SRC_STM0SR0);
//    IsrMaxStackUsage[23] = GetISRMaxStackUsage(OsIsr_STM0_SRC_STM0SR0);
//    IsrMaxStackUsage[24] = GetISRMaxStackUsage(OsIsr_STM0_SRC_STM0SR0);
//    IsrMaxStackUsage[25] = GetISRMaxStackUsage(OsIsr_STM0_SRC_STM0SR0);
//    IsrMaxStackUsage[26] = GetISRMaxStackUsage(OsIsr_STM0_SRC_STM0SR0);
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */
	Cpu_Usage_Func();
	ASWCore0_Counter_100ms++;
	/** This function should invalidate the data cache (DMI) for all the cores.
    If this function is called periodically it should ensure that the calibrated parameters value will get updated inside the cpu cache.
    Note: If data cache contains data modified by the cpu, it has to be written back and invalidated by the user ! */
    dataCacheInvalidate();
	/*PROTECTED REGION ID(User Logic :TestAPP_Cyclic_100ms) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */
	/*Distab call should be kept at end of Task to maintain accurate values for variables measured under this Raster in INCA*/
	ETK_Monitor_Distab17Event_And_Process(DISPTBL_CORE0_100MS);

}
#define TestAPP_STOP_SEC_CODE  
#include "TestAPP_MemMap.h" 
#define TestAPP_START_SEC_CODE                   
#include "TestAPP_MemMap.h"
FUNC (void, TestAPP_CODE) TestAPP_Cyclic_1ms/* return value & FctID */
(
		void
)
{

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :TestAPP_Cyclic_1ms) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;

	if (Rst_info_trap_trig == 2 )
	{
		*CSA_Ptr_1 = (uint32*) csaVal_1;
		Rst_info_trap_trig =0;
	}
	else 
	{
		/*do nothing */
	}
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */
	ASWCore0_Counter_1ms++;
	/*PROTECTED REGION ID(User Logic :TestAPP_Cyclic_1ms) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */
	/*Distab call should be kept at end of Task to maintain accurate values for variables measured under this Raster in INCA*/
    ETK_Monitor_Distab17Event_And_Process(DISPTBL_CORE0_1MS);
	

}
#define TestAPP_STOP_SEC_CODE  
#include "TestAPP_MemMap.h" 
#define TestAPP_START_SEC_CODE                   
#include "TestAPP_MemMap.h"
FUNC (void, TestAPP_CODE) TestAPP_Cyclic_2ms/* return value & FctID */
(
		void
)
{

	

	/* Local Data Declaration */

	/*PROTECTED REGION ID(UserVariables :TestAPP_Cyclic_2ms) ENABLED START */
	/* Start of user variable defintions - Do not remove this comment  */
	/* End of user variable defintions - Do not remove this comment  */
	/*PROTECTED REGION END */
	Std_ReturnType retValue = RTE_E_OK;





	if (Rst_info_trap_trig == 3 )
	{
		*CSA_Ptr_1 = (uint32*) csaVal_1;
		Rst_info_trap_trig =0;
	}
	else 
	{
		/*do nothing */
	}
	/*  -------------------------------------- Data Read -----------------------------------------  */

	/*  -------------------------------------- Server Call Point  --------------------------------  */

	/*  -------------------------------------- CDATA ---------------------------------------------  */

	/*  -------------------------------------- Data Write ----------------------------------------  */

	/*  -------------------------------------- Trigger Interface ---------------------------------  */

	/*  -------------------------------------- Mode Management -----------------------------------  */

	/*  -------------------------------------- Port Handling -------------------------------------  */

	/*  -------------------------------------- Exclusive Area ------------------------------------  */

	/*  -------------------------------------- Multiple Instantiation ----------------------------  */
	ASWCore0_Counter_2ms++;
	/*PROTECTED REGION ID(User Logic :TestAPP_Cyclic_2ms) ENABLED START */
	/* Start of user code - Do not remove this comment */
	/* End of user code - Do not remove this comment */
	/*PROTECTED REGION END */
	/*Distab call should be kept at end of Task to maintain accurate values for variables measured under this Raster in INCA*/
    ETK_Monitor_Distab17Event_And_Process(DISPTBL_CORE0_2MS);


}
#define TestAPP_STOP_SEC_CODE  
#include "TestAPP_MemMap.h" 

/*PROTECTED REGION ID(FileHeaderUserDefinedFunctions :TestAPP) ENABLED START */
/* Start of user defined functions  - Do not remove this comment */
/* End of user defined functions - Do not remove this comment */
/*PROTECTED REGION END */

