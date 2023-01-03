/**
 *
 * \file SWC_WeightSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_WeightSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/2/2023 05:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_WeightSensor.h"


/**
 *
 * Runnable RE_WeightSensor_GetWeight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppWeightSensor_Opr_GetWeight
 *
 */

void RE_WeightSensor_GetWeight (Impl_SensorWeightType* Arg_Weight)
{
	Std_ReturnType status;
	Impl_IoWeightSensorReadingType Weight;

	/* Server Call Points */
	status = Rte_Call_rpIOGetWeight_Opr_IOGet(&Arg_Weight);
	Arg_Weight =(Impl_SensorWeightType)(Weight/1000);
	
}

