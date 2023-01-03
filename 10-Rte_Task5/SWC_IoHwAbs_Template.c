/**
 *
 * \file SWC_IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SWC_IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 1/2/2023 05:18 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SWC_IoHwAbs.h"
/*For reading from position sensors */
#include "Adc.h"

/*For reading from weight sensor */
#include "Spi.h"

/*For driving motors (height ,slide ,incline )*/
#include "Dio.h"

/*Shall be replaced with inter runnable variable */
/*internal variables to read position sensors in one Adc Group */
static Adc_ValueGroupType  IoHwAb_PositionSensorsReadings [ADC_GR0_NUM_CHANNELS]=
{
	0,0,0
};


/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_Opr_IOGet
 *
 */

void RE_IoHwAbs_ECUGet_Height (Impl_IoPositionSensorReadingType* Arg_position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorsReadings);
	if (status== E_OK)
	{
		/*IoPostionSensorReadingType has to be adjusted in arxml file */
		/*as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16"*/
		Arg_position =(IoPImpl_IoPositionSensorReadingType) IoHwAb_PositionSensorsReadings[0];
	
	}
	else 
	{
		/*operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_Opr_IOGet
 *
 */

void RE_IoHwAbs_ECUGet_Incline (Impl_IoPositionSensorReadingType* Arg_position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorsReadings);
	
	if (status== E_OK)
	{
		/*IoPostionSensorReadingType has to be adjusted in arxml file */
		/*as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16"*/
		Arg_position =(IoPImpl_IoPositionSensorReadingType) IoHwAb_PositionSensorsReadings[1];
	
	}
	else 
	{
		/*operation shall be updated to return failure error code */
	}

}


/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_Opr_IOGet
 *
 */

void RE_IoHwAbs_ECUGet_Slide (Impl_IoPositionSensorReadingType* Arg_position)
{
	Std_ReturnType status;
	status = Adc_ReadGroup(AdcConf_AdcGroup_PositionsSensorsGrp,IoHwAb_PositionSensorsReadings);
	
	if (status== E_OK)
	{
		/*IoPostionSensorReadingType has to be adjusted in arxml file */
		/*as per Adc resolution "Adc_ValueGroupType can be uint8 or uint16"*/
		Arg_position =(IoPImpl_IoPositionSensorReadingType) IoHwAb_PositionSensorsReadings[2];
	
	}
	else 
	{
		/*operation shall be updated to return failure error code */
	}

}



/**
 *
 * Runnable RE_IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_Opr_IOGet
 *
 */

void RE_IoHwAbs_ECUGet_Weight (Impl_IoWeightSensorReadingType* Arg_Weight)
{
	Std_ReturnType status;
	Spi_DataType spiData ;
	status = Spi_ReadIB (SpiConf_SpiChannel_WeightSensor , &spiData);
	if (status== E_OK)
	{
		/*IoWeightSensorReadingType has to be adjusted in arxml file */
		/*as per spi_DataType "can be uint8 or uint16"*/
		Arg_Weight= (IoWeightSensorReadingType)spiData;
	
	}
	else 
	{
		/*operation shall be updated to return failure error code */
	}
	

}


/**
 *
 * Runnable RE_IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_Opr_IOSetForward
 *
 */

void RE_IoHwAbs_ECUSetForward_Height (void)
{
	/*write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh , STD_HIGH);


}


/**
 *
 * Runnable RE_IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_Opr_IOSetForward
 *
 */

void RE_IoHwAbs_ECUSetForward_Incline (void)
{
	/*write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh , STD_HIGH);


}


/**
 *
 * Runnable RE_IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_Opr_IOSetForward
 *
 */

void RE_IoHwAbs_ECUSetForward_Slide (void)
{
	/*write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh , STD_HIGH);


}


/**
 *
 * Runnable RE_IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_Opr_IOSetReverse
 *
 */

void RE_IoHwAbs_ECUSetReverse_Height (void)
{
	/*write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh , STD_LOW);

}


/**
 *
 * Runnable RE_IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_Opr_IOSetReverse
 *
 */

void RE_IoHwAbs_ECUSetReverse_Incline (void)
{
	/*write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh , STD_LOW);


}


/**
 *
 * Runnable RE_IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_Opr_IOSetReverse
 *
 */

void RE_IoHwAbs_ECUSetReverse_Slide (void)
{
	/*write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh , STD_LOW);


}

