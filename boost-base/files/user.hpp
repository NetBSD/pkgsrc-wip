//  (C) Copyright Boost.org 2001.
//
//  Prepared by: Felix Zaslavskiy , felix@students.poly.edu
//
//  This file may be customised by the end user.
//  This file was customized specificaly for recent NetBSD system
//  but should work on most Unix systems

//	 This file defines site specific configurations
//   
//	  wstring support is turned off because its not certain
//    weather wchar_t support is present
//

//
// stdlib configuration should set these ,
// sometimes platforms don't have support so it can be manuly set
//
//  Wide character support is setup in standar library config
//#define BOOST_NO_CWCHAR
//#define BOOST_NO_CWCTYPE
//#define BOOST_NO_SWPRINTF
//#define BOOST_NO_STD_WSTREAMBUF

// to be on safe side here these are set
// comment these out if platform definaly has support
#define BOOST_NO_STD_USE_FACET
#define BOOST_NO_STD_WSTRING

// GCC3.x realy has this but it may be safe to define it
// #define BOOST_NO_INTRINSIC_WCHAR_T

//compiler needs to have threads enabled
//configuration scrips may mess this up and not define this
// we defien it manualy assuming most modern unix has thread support
#define BOOST_HAS_THREADS



