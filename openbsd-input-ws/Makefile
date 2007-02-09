# $NetBSD: Makefile,v 1.1 2007/02/09 19:06:33 bsadewitz Exp $
#

DISTNAME=	openbsd-input-ws-1.0
CATEGORIES=	x11
MASTER_SITES=	http://xenocara.org/src/

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xenocara.org/
COMMENT=	OpenBSD's wscons input driver for modular X.org

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

.include "../../x11/modular-xorg-server/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
