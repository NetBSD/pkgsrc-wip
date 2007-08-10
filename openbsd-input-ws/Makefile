# $NetBSD: Makefile,v 1.4 2007/08/10 15:02:35 bsadewitz Exp $
#

DISTNAME=	openbsd-input-ws-1.1
PKGREVISION=	1
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

CPPFLAGS+=	-DMOTION_EVENT_HACK # XXX testing

.include "../../wip/modular-xorg-server/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
