/*********************************************************************
 *   Copyright 1992, University Corporation for Atmospheric Research
 *   See netcdf/README file for copying and redistribution conditions.
 *
 *   Purpose:    interface for classes of typed arrays for netCDF
 *
 *   $Header: /upc/share/CVS/netcdf-3/cxx/ncvalues.h,v 1.7 2006/07/26 21:12:06 russ Exp $
 *********************************************************************/

#ifndef Ncvalues_def
#define Ncvalues_def

#include <iostream>
#include <sstream>
#include <limits.h>
#include "netcdf.h"

// Documentation warned this might change and now it has, for
// consistency with C interface 
typedef signed char ncbyte;
typedef unsigned char ncubyte;
typedef char ncstring;

#define NC_UNSPECIFIED ((nc_type)0)

// C++ interface dates from before netcdf-3, still uses some netcdf-2 names
#ifdef NO_NETCDF_2
#define NC_LONG NC_INT
#define FILL_LONG NC_FILL_INT
typedef int nclong;
#define    NC_FATAL    1
#define    NC_VERBOSE    2
#endif

typedef long long ncint64;
typedef unsigned long long ncuint64;
typedef unsigned short ushort;
typedef unsigned int uint;

enum NcType 
{
  ncNoType = NC_UNSPECIFIED, 
  ncByte = NC_BYTE, 
  ncChar = NC_CHAR, 
  ncShort = NC_SHORT, 
  ncInt = NC_INT,
  ncLong = NC_LONG,        // deprecated, someday want to use for 64-bit ints
  ncFloat = NC_FLOAT, 
  ncDouble = NC_DOUBLE,
  ncUByte = NC_UBYTE,
  ncUShort = NC_USHORT,
  ncUInt = NC_UINT,
  ncInt64 = NC_INT64,
  ncUInt64 = NC_UINT64,
  ncString = NC_STRING
};

#define ncBad_ncbyte ncBad_byte
static const ncbyte ncBad_byte = NC_FILL_BYTE;
static const char ncBad_char = NC_FILL_CHAR;
static const short ncBad_short = NC_FILL_SHORT;
static const nclong ncBad_nclong = FILL_LONG;          // deprecated
static const int ncBad_int = NC_FILL_INT;
static const long ncBad_long = FILL_LONG;              // deprecated
static const float ncBad_float = NC_FILL_FLOAT;
static const double ncBad_double = NC_FILL_DOUBLE;
static const ncubyte ncBad_ubyte = NC_FILL_UBYTE;
static const ushort ncBad_ushort = NC_FILL_USHORT;
static const uint ncBad_uint = NC_FILL_UINT;
static const ncint64 ncBad_ncint64 = NC_FILL_INT64;
static const ncuint64 ncBad_ncuint64 = NC_FILL_UINT64;
static const ncstring ncBad_ncstring = NC_FILL_CHAR;

// macros to glue tokens together to form new names
#define name2(a,b) a ## b
#define declare(clas,t)        name2(clas,declare)(t)
#define implement(clas,t)      name2(clas,implement)(t)

// This is the same as the name2 macro, but we need to define our own
// version since rescanning something generated with the name2 macro
// won't necessarily cause name2 to be expanded again.
#define makename2(z, y)        makename2_x(z, y)
#define makename2_x(z, y)        z##y

#define NcVal(TYPE) makename2(NcValues_,TYPE)

#define NcValuesdeclare(TYPE)                                  \
class NcVal(TYPE) : public NcValues                            \
{                                                              \
public:                                                        \
    NcVal(TYPE)( void );                                       \
    NcVal(TYPE)(long num);                                     \
    NcVal(TYPE)(long num, const TYPE* vals);                   \
    NcVal(TYPE)(const NcVal(TYPE)&);                           \
    virtual NcVal(TYPE)& operator=(const NcVal(TYPE)&);        \
    virtual ~NcVal(TYPE)( void );                              \
    virtual void* base( void ) const;                          \
    virtual int bytes_for_one( void ) const;                   \
    virtual ncbyte as_ncbyte( long n ) const;                  \
    virtual char as_char( long n ) const;                      \
    virtual short as_short( long n ) const;                    \
    virtual int as_int( long n ) const;                        \
    virtual int as_nclong( long n ) const;                     \
    virtual long as_long( long n ) const;                      \
    virtual float as_float( long n ) const;                    \
    virtual double as_double( long n ) const;                  \
	virtual ushort as_ushort( long n ) const;                  \
	virtual uint as_uint( long n ) const;                      \
    virtual ncint64 as_ncint64( long n ) const;                \
    virtual ncuint64 as_ncuint64( long n ) const;              \
    virtual char* as_string( long n ) const;                   \
    virtual int invalid( void ) const;                         \
private:                                                       \
    TYPE* the_values;                                          \
    std::ostream& print(std::ostream&) const;                  \
};

#define NcTypeEnum(TYPE) makename2(_nc__,TYPE)
#define _nc__ncbyte ncByte
#define _nc__char ncChar
#define _nc__short ncShort
#define _nc__int ncInt
#define _nc__nclong ncLong
#define _nc__long ncLong
#define _nc__float ncFloat
#define _nc__double ncDouble
#define _nc__ushort ncUShort
#define _nc__uint ncUInt
#define _nc__ncint64 ncInt64
#define _nc__ncuint64 ncUInt64
#define _nc__ncstring ncString

#define NcValuesimplement(TYPE)                                     \
NcVal(TYPE)::NcVal(TYPE)( void )                                    \
    : NcValues(NcTypeEnum(TYPE), 0), the_values(0)                  \
{}                                                                  \
                                                                    \
NcVal(TYPE)::NcVal(TYPE)(long num, const TYPE* vals)                \
    : NcValues(NcTypeEnum(TYPE), num)                               \
{                                                                   \
    the_values = new TYPE[num];                                     \
    for(int i = 0; i < num; i++)                                    \
      the_values[i] = vals[i];                                      \
}                                                                   \
                                                                    \
NcVal(TYPE)::NcVal(TYPE)(long num)                                  \
    : NcValues(NcTypeEnum(TYPE), num), the_values(new TYPE[num])    \
{}                                                                  \
                                                                    \
NcVal(TYPE)::NcVal(TYPE)(const NcVal(TYPE)& v) :                    \
    NcValues(v)                                                     \
{                                                                   \
    delete[] the_values;                                            \
    the_values = new TYPE[v.the_number];                            \
    for(int i = 0; i < v.the_number; i++)                           \
      the_values[i] = v.the_values[i];                              \
}                                                                   \
                                                                    \
NcVal(TYPE)& NcVal(TYPE)::operator=(const NcVal(TYPE)& v)           \
{                                                                   \
    if ( &v != this) {                                              \
      NcValues::operator=(v);                                       \
      delete[] the_values;                                          \
      the_values = new TYPE[v.the_number];                          \
      for(int i = 0; i < v.the_number; i++)                         \
        the_values[i] = v.the_values[i];                            \
    }                                                               \
    return *this;                                                   \
}                                                                   \
                                                                    \
void* NcVal(TYPE)::base( void ) const                               \
{                                                                   \
    return the_values;                                              \
}                                                                   \
                                                                    \
NcVal(TYPE)::~NcVal(TYPE)( void )                                   \
{                                                                   \
    delete[] the_values;                                            \
}                                                                   \
                                                                    \
int NcVal(TYPE)::invalid( void ) const                              \
{                                                                   \
    for(int i=0;i<the_number;i++)                                   \
    if (the_values[i] == makename2(ncBad_,TYPE)) return 1;          \
    return 0;                                                       \
}


#define Ncbytes_for_one_implement(TYPE)                             \
int NcVal(TYPE)::bytes_for_one( void ) const                        \
{                                                                   \
    return sizeof(TYPE);                                            \
}

#define as_ncbyte_implement(TYPE)                                   \
ncbyte NcVal(TYPE)::as_ncbyte( long n ) const                       \
{                                                                   \
    if (the_values[n] < 0 || the_values[n] > UCHAR_MAX)             \
      return ncBad_byte;                                            \
    return (ncbyte) the_values[n];                                  \
}

#define as_char_implement(TYPE)                                     \
char NcVal(TYPE)::as_char( long n ) const                           \
{                                                                   \
    if (the_values[n] < CHAR_MIN || the_values[n] > CHAR_MAX)       \
      return ncBad_char;                                            \
    return (char) the_values[n];                                    \
}

#define as_short_implement(TYPE)                                    \
short NcVal(TYPE)::as_short( long n ) const                         \
{                                                                   \
    if (the_values[n] < SHRT_MIN || the_values[n] > SHRT_MAX)       \
      return ncBad_short;                                           \
    return (short) the_values[n];                                   \
}

#define NCINT_MIN INT_MIN
#define NCINT_MAX INT_MAX

#define as_int_implement(TYPE)                                      \
int NcVal(TYPE)::as_int( long n ) const                             \
{                                                                   \
    if (the_values[n] < NCINT_MIN || the_values[n] > NCINT_MAX)     \
      return ncBad_int;                                             \
    return (int) the_values[n];                                     \
}

#define NCLONG_MIN INT_MIN
#define NCLONG_MAX INT_MAX

#define as_nclong_implement(TYPE)                                   \
nclong NcVal(TYPE)::as_nclong( long n ) const                       \
{                                                                   \
    if (the_values[n] < NCLONG_MIN || the_values[n] > NCLONG_MAX)   \
      return ncBad_nclong;                                          \
    return (nclong) the_values[n];                                  \
}

#define as_long_implement(TYPE)                                     \
long NcVal(TYPE)::as_long( long n ) const                           \
{                                                                   \
    if (the_values[n] < LONG_MIN || the_values[n] > LONG_MAX)       \
      return ncBad_long;                                            \
    return (long) the_values[n];                                    \
}

#define as_float_implement(TYPE)                                    \
inline float NcVal(TYPE)::as_float( long n ) const                  \
{                                                                   \
    return (float) the_values[n];                                   \
}

#define as_double_implement(TYPE)                                   \
inline double NcVal(TYPE)::as_double( long n ) const                \
{                                                                   \
    return (double) the_values[n];                                  \
}

#define as_ushort_implement(TYPE)                                   \
inline ushort NcVal(TYPE)::as_ushort( long n ) const                \
{                                                                   \
    return (ushort) the_values[n];                                  \
}

#define as_uint_implement(TYPE)                                     \
inline uint NcVal(TYPE)::as_uint( long n ) const                    \
{                                                                   \
    return (uint) the_values[n];                                    \
}

#define as_ncint64_implement(TYPE)                                  \
inline ncint64 NcVal(TYPE)::as_ncint64( long n ) const              \
{                                                                   \
    return (ncint64) the_values[n];                                 \
}

#define as_ncuint64_implement(TYPE)                                 \
inline ncuint64 NcVal(TYPE)::as_ncuint64( long n ) const            \
{                                                                   \
    return (ncuint64) the_values[n];                                \
}

#define as_string_implement(TYPE)                                   \
char* NcVal(TYPE)::as_string( long n ) const                        \
{                                                                   \
    char* s = new char[64];                                         \
    std::ostringstream ostr;                                        \
    ostr << the_values[n];                                          \
    ostr.str().copy(s, std::string::npos);                          \
    s[ostr.str().length()] = 0;                                     \
    return s;                                                       \
}

///	<summary>
///		ABC for value blocks.
///	</summary>
class NcValues {
public:
	NcValues( void );
	NcValues(NcType, long);
	virtual ~NcValues( void );
	virtual long num( void );
	virtual std::ostream& print(std::ostream&) const = 0;
	virtual void* base( void ) const = 0;
	virtual int bytes_for_one( void ) const = 0;

	// The following member functions provide conversions from the value
	// type to a desired basic type.  If the value is out of range, the
	// default "fill-value" for the appropriate type is returned.
	virtual ncbyte as_ncbyte( long n ) const = 0;     // nth value as a byte
	virtual char as_char( long n ) const = 0;         // nth value as char
	virtual short as_short( long n ) const = 0;       // nth value as short
	virtual int as_int( long n ) const = 0;           // nth value as int
	virtual int as_nclong( long n ) const = 0;        // nth value as nclong
	virtual long as_long( long n ) const = 0;         // nth value as long
	virtual float as_float( long n ) const = 0;       // nth value as floating-point
	virtual double as_double( long n ) const = 0;     // nth value as double
	virtual ushort as_ushort( long n ) const = 0;     // nth value as unsigned short
	virtual uint as_uint( long n ) const = 0;         // nth value as unsigned int
	virtual ncint64 as_ncint64( long n ) const = 0;   // nth value as ncint64
	virtual ncuint64 as_ncuint64( long n ) const = 0; // nth value as ncuint64
	virtual char* as_string( long n ) const = 0;      // nth value as string

protected:
	NcType the_type;
	long the_number;
	friend std::ostream& operator<< (std::ostream&, const NcValues&);
};

declare(NcValues,ncbyte)
declare(NcValues,char)
declare(NcValues,short)
declare(NcValues,int)
declare(NcValues,nclong)
declare(NcValues,long)
declare(NcValues,float)
declare(NcValues,double)
declare(NcValues,ushort)
declare(NcValues,uint)
declare(NcValues,ncint64)
declare(NcValues,ncuint64)
declare(NcValues,ncstring)

#endif
