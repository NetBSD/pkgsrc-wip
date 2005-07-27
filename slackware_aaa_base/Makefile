# $NetBSD: Makefile,v 1.4 2005/07/27 16:29:53 thomasklausner Exp $
# $Id: Makefile,v 1.4 2005/07/27 16:29:53 thomasklausner Exp $
#

DISTNAME=		aaa_base-9.1.0-noarch-1
PKGNAME=		slackware_aaa_base-9.1.0
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}

MAINTAINER=		tech-pkg@NetBSD.org
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
