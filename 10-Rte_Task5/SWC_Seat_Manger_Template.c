/**
 *
 * \file SWC_Seat_Manger_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_Seat_Manger
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/3/2023 05:39 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_Seat_Manger.h"

/* the logic needed to auto adjust the driver seat in task 4 part1*/
static bool IsMotorAdjNeeded (Impl_SensorPostionType position, Impl_SensorWeightType Weight, Impl_StepMotorStepType* Step)
{
	bool adjMotor =FALSE;

	switch(position)
	{
		case SENSOR_POSITION_STEP_0:
		 if(weight > 60)
		 {
			Step = MOTOR_STEP_PLUS;
			adjMotor = TRUE;
		 }
		 break;

		case SENSOR_POSITION_STEP_1:
		 if(weight > 80)
		 {
			Step = MOTOR_STEP_PLUS;
			adjMotor = TRUE;
		 }
		 else if(weight<=80 && weight>=60)
		 {
			/*position OK*/
		 }
		 else
		 {
			Step = MOTOR_STEP_MINUS;
			adjMotor = TRUE;
		 }
		 break;
		
		case SENSOR_POSITION_STEP_2:
		 if(Weight>100)
		 {
			Step = MOTOR_STEP_PLUS;
			adjMotor = TRUE ;
		 }
		 else if (Weight <= 100 && Weight >= 80)
		 {
			/*Position OK*/
		 }
		 else
		 {
			Step = MOTOR_STEP_MINUS;
			adjMotor = TRUE;
		 }
		 break;

		case SENSOR_POSITION_STEP_3:
		 if(Weight < 100)
		 {
			Step = MOTOR_STEP_MINUS;
			adjMotor = TRUE;	
		 }
		 break;

		default:
		 break;

	}
	return adjMotor;
}


/**
 *
 * Runnable RE_SeatManger_AutoHeight
 *
 * Triggered By:
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *  - TimingEventImpl.TE_RE_SeatManger_AutoHeight_200ms
 *
 */

void RE_SeatManger_AutoHeight (void)
{
	Std_ReturnType status;
	Impl_StepMotorStepType Arg_step;
	Impl_SensorPostionType Arg_position;
	Impl_SensorWeightType Arg_Weight;

	bool adjMotor;
	/* Server Call Points */
	
	status = Rte_Call_rpHeightSensor_Opr_GetPostion(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
	adjMotor = IsMotorAdjNeeded(Arg_position,Arg_Weight,&Arg_step);
	if(adjMotor)
	{
		status = Rte_Call_rpHeightMotor_Opr_Move(Arg_step);
	}
}

/**
 *
 * Runnable RE_SeatManger_AutoIncline
 *
 * Triggered By:
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *  - TimingEventImpl.TE_RE_SeatManger_AutoIncline_200ms
 *
 */

void RE_SeatManger_AutoIncline (void)
{
	Std_ReturnType status;
	Impl_StepMotorStepType Arg_step;
	Impl_SensorPostionType Arg_position;
	Impl_SensorWeightType Arg_Weight;

	bool adjMotor;
	/* Server Call Points */
	
	status = Rte_Call_rpInclineSensor_Opr_GetPostion(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
	adjMotor = IsMotorAdjNeeded(Arg_position,Arg_Weight,&Arg_step);
	if(adjMotor)
	{
		status = Rte_Call_rpInclineMotor_Opr_Move(Arg_step);
	}
}


/**
 *
 * Runnable RE_SeatManger_AutoSlide
 *
 * Triggered By:
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_AUTO_ON_ENTRY
 *  - TimingEventImpl.TE_RE_SeatManger_AutoSlide_200ms
 *
 */

void RE_SeatManger_AutoSlide (void)
{
	Std_ReturnType status;
	Impl_StepMotorStepType Arg_step;
	Impl_SensorPostionType Arg_position;
	Impl_SensorWeightType Arg_Weight;

	bool adjMotor;
	/* Server Call Points */
	
	status = Rte_Call_rpSlideSensor_Opr_GetPostion(&Arg_position);
	status = Rte_Call_rpWeightSensor_Opr_GetWeight(&Arg_Weight);
	
	adjMotor = IsMotorAdjNeeded(Arg_position,Arg_Weight,&Arg_step);
	if(adjMotor)
	{
		status = Rte_Call_rpSlideMotor_Opr_Move(Arg_step);
	}
}


/**
 *
 * Runnable RE_SeatManger_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_DE_HeightBtnState
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
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
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
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
 *  - SwcModeSwitchEventImpl.MSE_rpSeatCtrlMode_MANUAL_ON_ENTRY
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

