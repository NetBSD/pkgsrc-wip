# $NetBSD: Makefile,v 1.2 2009/06/07 11:24:45 thomasklausner Exp $
#

DISTNAME=	openbsd-input-usbtablet-1.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://xenocara.org/
COMMENT=	X.org USB tablet driver from OpenBSD

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/modular-xorg-server/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
