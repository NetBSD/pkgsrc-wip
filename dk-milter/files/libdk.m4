# $NetBSD: libdk.m4,v 1.1.1.1 2005/02/24 13:05:46 adrian_p Exp $

include(confBUILDTOOLSDIR`/M4/switch.m4')


define(`confREQUIRE_LIBSM', `true')

dnl Enable these lines to make use of the provided asynchronous resolver:
dnl bldPUSH_SMLIB(`ar')
dnl APPENDDEF(`confENVDEF', `-DUSE_ARLIB ')
dnl APPENDDEF(`confINCDIRS', `-I../libar/ ')

dnl Enable and edit this as appropriate for your system:
APPENDDEF(`confINCDIRS', `-I@SSLBASE@/include ')


define(`confMT', `true')

bldPRODUCT_START(`library', `libdk')
define(`bldSOURCES', `dk.c rfc2822.c util.c ')
bldPRODUCT_END

bldFINISH
