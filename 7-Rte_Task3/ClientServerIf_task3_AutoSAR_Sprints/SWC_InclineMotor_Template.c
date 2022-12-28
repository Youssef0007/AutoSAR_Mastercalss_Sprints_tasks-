/**
 *
 * \file SWC_InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 12/28/2022 08:42 PM
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
	Dio_WriteChannel(Dio_ChannelId,Dio_LevelTypes level);
	Std_ReturnType status;

}

