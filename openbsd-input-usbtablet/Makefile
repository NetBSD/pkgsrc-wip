# $NetBSD: Makefile,v 1.4 2012/10/03 21:32:46 asau Exp $

DISTNAME=	openbsd-input-usbtablet-1.0
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xenocara.org/
COMMENT=	X.org USB tablet driver from OpenBSD

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
