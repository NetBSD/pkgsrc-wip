# $NetBSD: Makefile,v 1.1.1.1 2004/10/17 17:29:17 imilh Exp $
#

DISTNAME=	nos-tun
CATEGORIES=	net
MASTER_SITES=	http://imil.net/NetBSD/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/NetBSD/
COMMENT=	The nos-tun utility is used to establish an nos style tunnel

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=      FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

WRKSRC=		${WRKDIR}/nos-tun
USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	sbin man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nos-tun ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/nos-tun.8 ${PREFIX}/man/man8/nos-tun.8

.include "../../mk/bsd.pkg.mk"
