# $NetBSD: site.config.m4,v 1.1.1.1 2004/06/26 23:56:31 adrian_p Exp $

# pathnames specific to pkgsrc
#
define(`confEBINDIR', `${PREFIX}/libexec/sendmail')
define(`confMBINDIR', `${PREFIX}/libexec/sendmail')
define(`confSBINDIR', `${PREFIX}/sbin')
define(`confUBINDIR', `${PREFIX}/bin')
define(`confHFDIR', `${PREFIX}/share/misc')
define(`confMANROOT', `${PREFIX}/man/cat')
APPENDDEF(`confENVDEF', `-I${PREFIX}/include')
APPENDDEF(`confLIBS', `-L${PREFIX}/lib')
