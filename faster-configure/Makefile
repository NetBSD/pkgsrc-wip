# $NetBSD: Makefile,v 1.1.1.1 2004/03/14 22:09:10 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2004/03/14 22:09:10 mpasternak Exp $
#

DISTNAME=	faster-configure-1.0
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	# none
COMMENT=	Allows to run GNU configure scripts faster

NO_BUILD=	# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
.  if ${LOWER_OPSYS_VERSUFFIX} == "4"
CV_SYS_MAX_CMD_LEN=16384
.  else
CV_SYS_MAX_CMD_LEN=16384 # does 5.x have bigger number?
.  endif
.elif ${OPSYS} == "NetBSD"
CV_SYS_MAX_CMD_LEN=65535
.endif

.if defined(CV_SYS_MAX_CMD_LEN)
do-install:
	${ECHO} "lt_cv_sys_max_cmd_len=${CV_SYS_MAX_CMD_LEN}" >> ${PREFIX}/etc/config.site
.else
do-install:
	@${ECHO}
	@${ECHO} "*** ERROR: ${OPSYS} is unknown to ${PKGNAME}"
	@${ECHO} "Please add entry for your operating system to the Makefile"
	@${ECHO}
	${FALSE}
.endif

.include "../../mk/bsd.pkg.mk"
