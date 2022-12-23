/**
 *
 * \file SWC_HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 12/23/2022 07:56 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HMI.h"


/**
 *
 * Runnable RE_HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_RE_HMI_MainFunction_100ms
 *
 */

void RE_HMI_MainFunction (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_HeightBtnState;
	Impl_MultiStateBtnType DE_InclineBtnState;
	Impl_MultiStateBtnType DE_SlideBtnState;
	uint8 DE_Height;
	uint8 DE_Incline;
	uint8 DE_Slide;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlData_DE_Height(&DE_Height);
	if (Timeout || Not_Updated || Data ==0)
	{
		DE_HeightBtnState= MULTI_STATE_BTN_INIT;
	}
	if(Data==1)
	{
		DE_HeightBtnState= MULTI_STATE_BTN_MINUS;
	}
	if(Data==2)
	{
		DE_HeightBtnState= MULTI_STATE_BTN_PLUS;
	}
	status = Rte_Read_rpSeatCtrlData_DE_Incline(&DE_Incline);
	if (Timeout || Not_Updated || Data ==0)
	{
		DE_InclineBtnState= MULTI_STATE_BTN_INIT;
	}
	if(Data==1)
	{
		DE_InclineBtnState= MULTI_STATE_BTN_MINUS;
	}
	if(Data==2)
	{
		DE_InclineBtnState= MULTI_STATE_BTN_PLUS;
	}
	status = Rte_Read_rpSeatCtrlData_DE_Slide(&DE_Slide);
	if (Timeout || Not_Updated || Data ==0)
	{
		DE_SlideBtnState= MULTI_STATE_BTN_INIT;
	}
	if(Data==1)
	{
		DE_SlideBtnState= MULTI_STATE_BTN_MINUS;
	}
	if(Data==2)
	{
		DE_SlideBtnState= MULTI_STATE_BTN_PLUS;
	}


	
	/* Data Send Points */
	status = Rte_Write_ppSeatCtrlBtns_DE_HeightBtnState(DE_HeightBtnState);
	status = Rte_Write_ppSeatCtrlBtns_DE_InclineBtnState(DE_InclineBtnState);
	status = Rte_Write_ppSeatCtrlBtns_DE_SlideBtnState(DE_SlideBtnState);
	
	
}

