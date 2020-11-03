#include "tariff.h"

/**
 * Calculate monthly electricity charge at domestic rate based on units consumed
 *
 * @param unitsConsumed - the number of units in kwh consumed in current month
 * @return charge - calculated charge, minimum 5.00
 */

double getMonthlyChargeDomestic(double unitsConsumed)
{
	double charge;
	if (unitsConsumed > 1300)
		charge = unitsConsumed * 0.315;
	else if (unitsConsumed > 800)
		charge = unitsConsumed * 0.31;
	else if (unitsConsumed > 700)
		charge = unitsConsumed * 0.305;
	else if (unitsConsumed > 500)
		charge = unitsConsumed * 0.3;
	else if (unitsConsumed > 400)
		charge = unitsConsumed * 0.295;
	else if (unitsConsumed > 300)
		charge = unitsConsumed * 0.27;
	else if (unitsConsumed > 200)
		charge = unitsConsumed * 0.25;
	else if (unitsConsumed > 150)
		charge = unitsConsumed * 0.22;
	else 
		charge = unitsConsumed * 0.18;
	
	if (charge < 5.00)
		charge = 5.00;

	return charge;
}


/**
 * Calculate monthly electricity charge at commercial rate based on units consumed
 *
 * @param unitsConsumed - the number of units in kwh consumed in current month
 * @return charge - calculated charge, minimum 10.00
 */
double getMonthlyChargeCommercial(double unitsConsumed)
{
	double charge;
	if (unitsConsumed > 20000)
		charge = unitsConsumed * 0.30;
	else if (unitsConsumed > 10000)
		charge = unitsConsumed * 0.31;
	else if (unitsConsumed > 3000)
		charge = unitsConsumed * 0.32;
	else if (unitsConsumed > 500)
		charge = unitsConsumed * 0.315;
	else if (unitsConsumed > 400)
		charge = unitsConsumed * 0.3;
	else if (unitsConsumed > 300)
		charge = unitsConsumed * 0.28;
	else if (unitsConsumed > 200)
		charge = unitsConsumed * 0.26;
	else if (unitsConsumed > 100)
		charge = unitsConsumed * 0.24;
	else
		charge = unitsConsumed * 0.20;

	if (charge < 10.00)
		charge = 10.00;

	return charge;
}