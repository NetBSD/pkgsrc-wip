# $NetBSD: Makefile,v 1.1.1.1 2004/03/12 12:42:34 mpasternak Exp $
# $Id: Makefile,v 1.1.1.1 2004/03/12 12:42:34 mpasternak Exp $
#

DISTNAME=		slackware_aaa_base-9.1.0
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}
DISTFILES=		aaa_base-9.1.0-noarch-1.tgz

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

.include "../../wip/slackware_compat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
