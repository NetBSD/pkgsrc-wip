# $NetBSD: Makefile,v 1.5 2008/02/25 18:52:23 tnn2 Exp $
#

DISTNAME=		dxmake-2.12
CATEGORIES=		devel
MASTER_SITES=		http://apollo.backplane.com/FreeBSDPorts/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://apollo.backplane.com/FreeBSDPorts/
COMMENT=		Yet another make tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		groff nroff

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/cat1
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
