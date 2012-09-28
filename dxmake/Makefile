# $NetBSD: Makefile,v 1.6 2012/09/28 21:24:39 asau Exp $
#

DISTNAME=		dxmake-2.12
CATEGORIES=		devel
MASTER_SITES=		http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://apollo.backplane.com/FreeBSDPorts/
COMMENT=		Yet another make tool

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
