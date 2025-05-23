/*********************************************************************
 *   Copyright 1992, University Corporation for Atmospheric Research
 *   See netcdf/README file for copying and redistribution conditions.
 *
 *   Purpose:	implementation of classes of typed arrays for netCDF
 *
 *   $Header: /upc/share/CVS/netcdf-3/cxx/ncvalues.cpp,v 1.12 2008/03/05 16:45:32 russ Exp $
 *********************************************************************/

#include <iostream>
#include <string>
#include <cstring>

#include "ncvalues.h"

NcValues::NcValues( void ) :
	the_type(ncNoType),
	the_number(0)
{}

NcValues::NcValues( NcType type, long num ) :
	the_type(type),
	the_number(num)
{}

NcValues::~NcValues( void )
{}

long NcValues::num( void ) {
	return the_number;
}

std::ostream& operator<< (std::ostream& os, const NcValues& vals) {
	return vals.print(os);
}

implement(NcValues,ncbyte)
implement(NcValues,char)
implement(NcValues,short)
implement(NcValues,int)
implement(NcValues,nclong)
implement(NcValues,long)
implement(NcValues,float)
implement(NcValues,double)
implement(NcValues,ushort)
implement(NcValues,uint)
implement(NcValues,ncint64)
implement(NcValues,ncuint64)
implement(NcValues,ncstring)

Ncbytes_for_one_implement(ncbyte)
Ncbytes_for_one_implement(char)
Ncbytes_for_one_implement(short)
Ncbytes_for_one_implement(int)
Ncbytes_for_one_implement(nclong)
Ncbytes_for_one_implement(long)
Ncbytes_for_one_implement(float)
Ncbytes_for_one_implement(double)
Ncbytes_for_one_implement(ushort)
Ncbytes_for_one_implement(uint)
Ncbytes_for_one_implement(ncint64)
Ncbytes_for_one_implement(ncuint64)
Ncbytes_for_one_implement(ncstring)

as_ncbyte_implement(short)
as_ncbyte_implement(int)
as_ncbyte_implement(nclong)
as_ncbyte_implement(long)
as_ncbyte_implement(float)
as_ncbyte_implement(double)
as_ncbyte_implement(ushort)
as_ncbyte_implement(uint)
as_ncbyte_implement(ncint64)
as_ncbyte_implement(ncuint64)

inline ncbyte NcValues_char::as_ncbyte( long n ) const {
	return the_values[n];
}

inline ncbyte NcValues_ncbyte::as_ncbyte( long n ) const {
	return the_values[n];
}

inline ncbyte NcValues_ncstring::as_ncbyte( long n ) const {
	return the_values[n];
}

as_char_implement(short)
as_char_implement(int)
as_char_implement(nclong)
as_char_implement(long)
as_char_implement(float)
as_char_implement(double)
as_char_implement(ncint64)
as_char_implement(ncuint64)

inline char NcValues_ncbyte::as_char( long n ) const {
	return the_values[n] > CHAR_MAX ? ncBad_char : (char) the_values[n];
}

inline char NcValues_char::as_char( long n ) const {
	return the_values[n];
}

inline char NcValues_ushort::as_char( long n ) const {
	return the_values[n];
}

inline char NcValues_uint::as_char( long n ) const {
	return the_values[n];
}

inline char NcValues_ncstring::as_char( long n ) const {
	return the_values[n];
}

as_short_implement(int)
as_short_implement(nclong)
as_short_implement(long)
as_short_implement(float)
as_short_implement(double)
as_short_implement(ncint64)
as_short_implement(ncuint64)

inline short NcValues_ncbyte::as_short( long n ) const {
	return the_values[n];
}

inline short NcValues_char::as_short( long n ) const {
	return the_values[n];
}

inline short NcValues_short::as_short( long n ) const {
	return the_values[n];
}

inline short NcValues_ushort::as_short( long n ) const {
	return the_values[n];
}

inline short NcValues_uint::as_short( long n ) const {
	return the_values[n];
}

inline short NcValues_ncstring::as_short( long n ) const {
	return the_values[n];
}


as_int_implement(float)
as_int_implement(double)
as_int_implement(ncint64)
as_int_implement(ncuint64)

inline int NcValues_ncbyte::as_int( long n ) const {
	return the_values[n];
}

inline int NcValues_char::as_int( long n ) const {
	return the_values[n];
}

inline int NcValues_short::as_int( long n ) const {
	return the_values[n];
}

inline int NcValues_int::as_int( long n ) const {
	return the_values[n];
}

inline int NcValues_nclong::as_int( long n ) const {
	return the_values[n];
}

inline int NcValues_long::as_int( long n ) const {
	return the_values[n];
}

inline int NcValues_ushort::as_int( long n ) const {
	return the_values[n];
}

inline int NcValues_uint::as_int( long n ) const {
	return the_values[n];
}

inline int NcValues_ncstring::as_int( long n ) const {
	return the_values[n];
}


as_nclong_implement(float)
as_nclong_implement(double)
as_nclong_implement(ncint64)
as_nclong_implement(ncuint64)

inline nclong NcValues_ncbyte::as_nclong( long n ) const {
	return the_values[n];
}

inline nclong NcValues_char::as_nclong( long n ) const {
	return the_values[n];
}

inline nclong NcValues_short::as_nclong( long n ) const {
	return the_values[n];
}

inline nclong NcValues_int::as_nclong( long n ) const {
	return the_values[n];
}

inline nclong NcValues_nclong::as_nclong( long n ) const {
	return the_values[n];
}

inline nclong NcValues_long::as_nclong( long n ) const {
	return the_values[n];
}

inline nclong NcValues_ushort::as_nclong( long n ) const {
	return the_values[n];
}

inline nclong NcValues_uint::as_nclong( long n ) const {
	return the_values[n];
}

inline nclong NcValues_ncstring::as_nclong( long n ) const {
	return the_values[n];
}

as_long_implement(float)
as_long_implement(double)

inline long NcValues_ncbyte::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_char::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_short::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_int::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_nclong::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_long::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_ushort::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_uint::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_ncint64::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_ncuint64::as_long( long n ) const {
	return the_values[n];
}

inline long NcValues_ncstring::as_long( long n ) const {
	return the_values[n];
}

as_ncint64_implement(ncbyte)
as_ncint64_implement(char)
as_ncint64_implement(short)
as_ncint64_implement(int)
as_ncint64_implement(nclong)
as_ncint64_implement(long)
as_ncint64_implement(float)
as_ncint64_implement(double)
as_ncint64_implement(ushort)
as_ncint64_implement(uint)
as_ncint64_implement(ncint64)
as_ncint64_implement(ncuint64)
as_ncint64_implement(ncstring)

as_ncuint64_implement(ncbyte)
as_ncuint64_implement(char)
as_ncuint64_implement(short)
as_ncuint64_implement(int)
as_ncuint64_implement(nclong)
as_ncuint64_implement(long)
as_ncuint64_implement(float)
as_ncuint64_implement(double)
as_ncuint64_implement(ushort)
as_ncuint64_implement(uint)
as_ncuint64_implement(ncint64)
as_ncuint64_implement(ncuint64)
as_ncuint64_implement(ncstring)

as_float_implement(ncbyte)
as_float_implement(char)
as_float_implement(short)
as_float_implement(int)
as_float_implement(nclong)
as_float_implement(long)
as_float_implement(float)
as_float_implement(double)
as_float_implement(ushort)
as_float_implement(uint)
as_float_implement(ncint64)
as_float_implement(ncuint64)
as_float_implement(ncstring)

as_double_implement(ncbyte)
as_double_implement(char)
as_double_implement(short)
as_double_implement(int)
as_double_implement(nclong)
as_double_implement(long)
as_double_implement(float)
as_double_implement(double)
as_double_implement(ushort)
as_double_implement(uint)
as_double_implement(ncint64)
as_double_implement(ncuint64)
as_double_implement(ncstring)

as_ushort_implement(ncbyte)
as_ushort_implement(char)
as_ushort_implement(short)
as_ushort_implement(int)
as_ushort_implement(nclong)
as_ushort_implement(long)
as_ushort_implement(float)
as_ushort_implement(double)
as_ushort_implement(ushort)
as_ushort_implement(uint)
as_ushort_implement(ncint64)
as_ushort_implement(ncuint64)
as_ushort_implement(ncstring)

as_uint_implement(ncbyte)
as_uint_implement(char)
as_uint_implement(short)
as_uint_implement(int)
as_uint_implement(nclong)
as_uint_implement(long)
as_uint_implement(float)
as_uint_implement(double)
as_uint_implement(ushort)
as_uint_implement(uint)
as_uint_implement(ncint64)
as_uint_implement(ncuint64)
as_uint_implement(ncstring)

as_string_implement(short)
as_string_implement(int)
as_string_implement(nclong)
as_string_implement(long)
as_string_implement(float)
as_string_implement(double)
as_string_implement(ushort)
as_string_implement(uint)
as_string_implement(ncint64)
as_string_implement(ncuint64)

inline char* NcValues_ncbyte::as_string( long n ) const {
	char* s = new char[the_number + 1];
	s[the_number] = '\0';
	strncpy(s, (const char*)the_values + n, (int)the_number);
	return s;
}

inline char* NcValues_char::as_string( long n ) const {
	char* s = new char[the_number + 1];
	s[the_number] = '\0';
	strncpy(s, (const char*)the_values + n, (int)the_number);
	return s;
}

inline char* NcValues_ncstring::as_string( long n ) const {
	char* s = new char[the_number + 1];
	s[the_number] = '\0';
	strncpy(s, (const char*)the_values + n, (int)the_number);
	return s;
}

std::ostream& NcValues_short::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_int::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_nclong::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_long::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_ncbyte::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_char::print(std::ostream& os) const {
	os << '"';
	long len = the_number;
	while (the_values[--len] == '\0') // don't output trailing null bytes
	;
	for(int i = 0; i <= len; i++)
	os << the_values[i] ;
	os << '"';

	return os;
}

std::ostream& NcValues_float::print(std::ostream& os) const {
	std::streamsize save=os.precision();
	os.precision(7);
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	os.precision(save);
	return os;
}

std::ostream& NcValues_double::print(std::ostream& os) const {
	std::streamsize save=os.precision();
	os.precision(15);
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1];
	os.precision(save);
	return os;
}

std::ostream& NcValues_ushort::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_uint::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_ncint64::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_ncuint64::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}

std::ostream& NcValues_ncstring::print(std::ostream& os) const {
	for(int i = 0; i < the_number - 1; i++)
		os << the_values[i] << ", ";
	if (the_number > 0)
		os << the_values[the_number-1] ;
	return os;
}


