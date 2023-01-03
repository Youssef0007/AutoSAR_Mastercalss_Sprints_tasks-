/**
 *
 * \file SWC_HeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_HeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/2/2023 05:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_HeightSensor.h"


/**
 *
 * Runnable RE_HeightSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppHeightSensor_Opr_GetPostion
 *
 */

void RE_HeightSensor_GetPosition (Impl_SensorPostionType* Arg_position)
{
	Std_ReturnType status;
	Impl_IoPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetHeight_Opr_IOGet(&Arg_position);
	if(position==0)
	{
		Arg_position = SENSOR_POSITION_STEP_0;
	}
	else if(position>0 && position<=64)
	{
		Arg_position = SENSOR_POSITION_STEP_1;
	}
	else if(position>64 && position<=192)
	{
		Arg_position = SENSOR_POSITION_STEP_2;
	}
	else 
	{
		Arg_position = SENSOR_POSITION_STEP_3;
	}
	
	
}

