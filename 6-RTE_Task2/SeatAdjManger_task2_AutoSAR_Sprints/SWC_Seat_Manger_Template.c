/**
 * 
 * \file SWC_Seat_Manger_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_Seat_Manger
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 12/23/2022 07:56 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_Seat_Manger.h"


/**
 *
 * Runnable RE_SeatManger_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_HeightBtnState
 *
 */

void RE_SeatManger_SetHeight (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_HeightBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);
	if(DE_HeightBtnState==MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS)
	}
	if(DE_HeightBtnState==MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS)
	}

	
}


/**
 *
 * Runnable RE_SeatManger_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_InclineBtnState
 *
 */

void RE_SeatManger_SetIncline (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_InclineBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);
	if(DE_InclineBtnState==MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS)
	}
	if(DE_InclineBtnState==MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS)
	}
	
}


/**
 *
 * Runnable RE_SeatManger_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_SlideBtnState
 *
 */

void RE_SeatManger_SetSlide (void)
{
	Std_ReturnType status;
	Impl_MultiStateBtnType DE_SlideBtnState;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
	if(DE_SlideBtnState==MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS)
	}
	if(DE_SlideBtnState==MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS)
	}
	
}

