# $NetBSD: Makefile,v 1.4 2005/07/27 16:31:46 thomasklausner Exp $
#

DISTNAME=		xpde-0.4.0-20030730
PKGNAME=		xpde-0.4.0
WRKSRC=			${WRKDIR}/xpde-0.4.0
CATEGORIES=		misc
MASTER_SITES=		http://www.xpde.com/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.xpde.com/
COMMENT=		"Desktop environment for X11 (Windows XP interface clone)"

LINUX_USE_X11=		yes	# this package wants linux-x11 libs
LINUX_BINPKG_FMT=	plain	# this is "plain" package, no rpm, no deb

do-install:
	cd ${WRKSRC} && ./install.sh ${PREFIX}/emul/linux/opt/xpde ../../usr/lib/

.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
