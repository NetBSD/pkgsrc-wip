# $NetBSD: Makefile,v 1.3 2005/07/27 16:29:57 thomasklausner Exp $
# $Id: Makefile,v 1.3 2005/07/27 16:29:57 thomasklausner Exp $
#

DISTNAME=		bash-2.05b-i486-3
PKGNAME=		slackware_bash-2.05b
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://slackware.com
COMMENT=		Glibc and other important shared libraries for slackware emulation

LINUX_BASE_NODEPS=	# defined
SLACK_NO_INSTALL=	# we handle install procedure

DEPENDS=		slackware_glibc_solibs>=2.3.2:../../wip/slackware_glibc_solibs
DEPENDS+=		slackware_aaa_elflibs>=9.1.0:../../wip/slackware_aaa_elflibs
DEPENDS+=		slackware_aaa_base>=9.1.0:../../wip/slackware_aaa_base

post-install:
	cd ${EMULDIR} && ${SH} install/doinst.sh
	${RM} -rf ${EMULDIR}/install

.include "../../wip/slackware_compat/Makefile.common"
.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
