# $NetBSD: Makefile,v 1.7 2009/06/07 11:24:45 thomasklausner Exp $
#

DISTNAME=	openbsd-input-ws-1.2
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://xenocara.org/src/

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xenocara.org/
COMMENT=	OpenBSD's wscons input driver for modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
