# $NetBSD: Makefile,v 1.3 2004/03/15 10:23:25 mpasternak Exp $
# $Id: Makefile,v 1.3 2004/03/15 10:23:25 mpasternak Exp $
#

DISTNAME=		aaa_base-9.1.0-noarch-1
PKGNAME=		slackware_aaa_base-9.1.0
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://slackware.com
COMMENT=		Basic directory structure for Slackware emulation

LINUX_BASE_NODEPS=	# defined
SLACK_NO_INSTALL=	# we handle install procedure

post-install:
	cd ${EMULDIR} && ${SETENV} EMULDIR=${EMULDIR} ${SH} install/doinst.sh
	${RM} -rf ${EMULDIR}/install
	# slackware_bash won't install without this:
	${TOUCH} ${EMULDIR}/etc/shells
	# bootstrap-pkgsrc and other stuff need this:
	${ECHO} "root:*:0:0:Charlie &:/root:/bin/bash" > ${EMULDIR}/etc/passwd	
	${ECHO} "root:*:0:root" > ${EMULDIR}/etc/group
	${ECHO} "sys:*:3:root" >> ${EMULDIR}/etc/group
	
.include "../../wip/slackware_compat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
