# $NetBSD: Makefile,v 1.3 2005/07/27 16:30:12 thomasklausner Exp $
# $Id: Makefile,v 1.3 2005/07/27 16:30:12 thomasklausner Exp $
#

DISTNAME=		coreutils-5.2.0-i486-2
PKGNAME=		slackware_coreutils-2.3.2
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://slackware.com
COMMENT=		Core utilities for Slackware emulation

LINUX_BASE_NODEPS=	# defined
SLACK_NO_INSTALL=	# we handle install procedure

DEPENDS=		slackware_aaa_base>=9.1.0:../../wip/slackware_aaa_base

post-install:
	cd ${EMULDIR} && ${SH} install/doinst.sh
	${RM} -rf ${EMULDIR}/install

.include "../../wip/slackware_compat/Makefile.common"
.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
