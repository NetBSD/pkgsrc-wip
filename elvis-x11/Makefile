# $NetBSD: Makefile,v 1.9 2004/01/20 21:13:03 marc Exp $
#

.include "../elvis/Makefile.common"

PKGNAME=        elvis-x11-2.2.0
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS+=	elvis-[0-9]*

USE_X11=		YES
CONFIGURE_ARGS+=	--with-x=yes
CONFIGURE_ARGS+=	--with-xft

MAKEFLAGS+=	CC="${CC} -I${LOCALBASE}/include/freetype2 ${CFLAGS}"

.include "../../fonts/Xft2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
