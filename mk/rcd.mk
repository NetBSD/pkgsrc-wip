# $Id: rcd.mk,v 1.2 2004/08/27 07:53:09 bubuchka Exp $
# from "Id: oshavercd.mk,v 1.4 2003/11/19 21:28:47 bubuchka Exp"
#
# This makefile intended to determine is system have rc.d framework,
# or not. If there is no such one, it will be installed by dependency.
#
# The following system variables must be defined before:
#	RCD_DIR				'rc.d' directory of rc.d scripts
#	RCD_ORDER			'rcorder' executable to run on rc.d/*
#	RCD_SUBR			'rc.subr' set of rc.d subroutines
#
# The following variables will be defined:
#	MAJOR_OS_VERSION		two very first numbers of used OS
#	OS_HAVE_RCD			YES, if OS have rc.d, or NO elsewhere

.ifndef OSHAVERCD_MK
OSHAVERCD_MK=		# defined

.include "../../mk/bsd.prefs.mk"

#
# The following MUST be definded in defs.<opsys>.mk
#

RCD_DIR?=		/etc/rc.d
RCD_ORDER?=		/sbin/rcorder
RCD_SUBR?=		/etc/rc.subr

FILES_SUBST+=		RCD_DIR=${RCD_DIR}				\
			RCD_ORDER=${RCD_ORDER}				\
			RCD_SUBR=${RCD_SUBR}

#
# The rest should be defined in bsd.pkg.install.mk
#

MAJOR_OS_VERSION=	${OS_VERSION:S/${OS_VERSION:C/^[0-9]*\.[0-9]*//}//}

.if ${OPSYS} == "NetBSD" && ${MAJOR_OS_VERSION} >= 1.5
OS_HAVE_RCD=		YES
.elif ${OPSYS} == "FreeBSD" && ${MAJOR_OS_VERSION} >= 5.0
OS_HAVE_RCD=		YES
.elif exists(${RCD_DIR}) && exists(${RCD_ORDER}) && exists(${RCD_SUBR})
OS_HAVE_RCD=		YES
.endif

OS_HAVE_RCD?=		NO

.if ${OS_HAVE_RCD} == "NO"
DEPENDS+=		rc.subr-[0-9]*:../../pkgtools/rc.subr
DEPENDS+=		rcorder-[0-9]*:../../pkgtools/rcorder
.endif

.endif	# OSHAVERCD_MK
