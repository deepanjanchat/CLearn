/*
 * BookInv.h
 *
 *  Created on: 03-Aug-2020
 *      Author: dc
 */

#ifndef BOOKINV_H_
#define BOOKINV_H_
struct bookInv {      //common coding practice is to save structure definitions in a separate header file.
	char title[30];
	char author[30];
	int pages;
	float price;
};
#endif /* BOOKINV_H_ */
