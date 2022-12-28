/**
 *
 * \file SWC_Seat_Manger_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_Seat_Manger
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 12/28/2022 08:42 PM
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
	Impl_StepMotorStepType Arg_step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_HeightBtnState(&DE_HeightBtnState);
	
    /*take action depending on the pressed btn*/
	if(DE_HeightBtnState==MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS)
	}
	if(DE_HeightBtnState==MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS)
	}

	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Opr_Move(Arg_step);
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
	Impl_StepMotorStepType Arg_step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_InclineBtnState(&DE_InclineBtnState);
	

	/*take action depending on the pressed btn*/
	if(DE_InclineBtnState==MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS)
	}
	if(DE_InclineBtnState==MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS)
	}

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Opr_Move(Arg_step);
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
	Impl_StepMotorStepType Arg_step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_DE_SlideBtnState(&DE_SlideBtnState);
		
	
	/*take action depending on the pressed btn*/
	if(DE_SlideBtnState==MULTI_STATE_BTN_MINUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS)
	}
	if(DE_SlideBtnState==MULTI_STATE_BTN_PLUS)
	{
		Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS)
	}
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Opr_Move(Arg_step);	
}

