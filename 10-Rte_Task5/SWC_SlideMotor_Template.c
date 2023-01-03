/**
 *
 * \file SWC_SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/2/2023 05:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_SlideMotor.h"


/**
 *
 * Runnable RE_SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Opr_Move
 *
 */

void RE_SlideMotor_Move (Impl_StepMotorStepType Arg_step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(Arg_step== MOTOR_STEP_PLUS)
	{
		status = Rte_Call_rpIOSetSlide_Opr_IOSetForward();
	}
	else if (Arg_step== MOTOR_STEP_MINUS)
	{
		status = Rte_Call_rpIOSetSlide_Opr_IOSetReverse();

	}
	else 
	{
		/*do nothing */
	}
	

	
}

