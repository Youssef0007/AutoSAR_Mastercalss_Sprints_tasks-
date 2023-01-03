/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/2/2023 05:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_InclineMotor.h"


/**
 *
 * Runnable RE_InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Opr_Move
 *
 */

void RE_InclineMotor_Move (Impl_StepMotorStepType Arg_step)
{
	Std_ReturnType status;

	/* Server Call Points */
	if(Arg_step== MOTOR_STEP_PLUS)
	{
		status = Rte_Call_rpIOSetIncline_Opr_IOSetForward();
	}
	else if (Arg_step== MOTOR_STEP_MINUS)
	{
		status = Rte_Call_rpIOSetIncline_Opr_IOSetReverse();

	}
	else 
	{
		/*do nothing */
	}
	
	
	
	
}

