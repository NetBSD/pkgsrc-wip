# $NetBSD: dk-filter.m4,v 1.1.1.1 2005/02/24 13:05:46 adrian_p Exp $

include(confBUILDTOOLSDIR`/M4/switch.m4')


define(`confMT', `TRUE')
define(`confREQUIRE_LIBSM', `true')

APPENDDEF(`confLIBS', `-lssl -lcrypto -lpthread')
APPENDDEF(`confINCDIRS', `-I@SSLBASE@/include ')
APPENDDEF(`confLIBDIRS', `-L@SSLBASE@/lib ')
APPENDDEF(`confLIBDIRS', `-L@PTHREAD@/lib ')

dnl To use the asynchronous resolver library provided, enable this line:
dnl bldPUSH_SMLIB(`ar')

bldPUSH_SMLIB(`dk')
APPENDDEF(`confINCDIRS', `-I../libdk/ ')

bldPUSH_SMLIB(`sm')

APPENDDEF(`confINCDIRS', `-I@LMBASE@/include')
APPENDDEF(`confLIBDIRS', `-L@LMBASE@/lib')

dnl Enable for IPv6 support:
@DNL@APPENDDEF(`confENVDEF', `-DNETINET6 ')

dnl Compile time options, especially FFRs:
dnl APPENDDEF(`confENVDEF', `-D_FFR_AUTH_RESULTS ')
dnl APPENDDEF(`confENVDEF', `-D_FFR_EXTERNAL_IGNORE_LIST ')
dnl APPENDDEF(`confENVDEF', `-D_FFR_FLUSH_HEADERS ')
dnl APPENDDEF(`confENVDEF', `-D_FFR_MACRO_LIST ')
dnl APPENDDEF(`confENVDEF', `-D_FFR_MULTIPLE_KEYS ')
dnl APPENDDEF(`confENVDEF', `-D_FFR_POPAUTH ')
dnl APPENDDEF(`confENVDEF', `-D_FFR_REPORTINFO ')
dnl APPENDDEF(`confENVDEF', `-D_FFR_REQUIRED_HEADERS ')
dnl APPENDDEF(`confENVDEF', `-D_FFR_SELECT_CANONICALIZATION ')

bldPRODUCT_START(`executable', `dk-filter')
define(`bldSOURCES', `dk-filter.c util.c ')
PREPENDDEF(`confLIBS', `-lmilter ')
bldPRODUCT_END

bldPRODUCT_START(`manpage', `dk-filter')
define(`bldSOURCES', `dk-filter.8')
bldPRODUCT_END

bldFINISH
