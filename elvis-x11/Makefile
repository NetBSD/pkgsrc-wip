# $NetBSD: Makefile,v 1.6 2004/01/20 19:57:01 airhead Exp $
#

.include "../elvis/Makefile.common"

PKGNAME=        elvis-x11-2.2.0
COMMENT=	GUI for elvis, includes console elvis

CONFLICTS+=	elvis-[0-9]*

USE_X11=		YES
CONFIGURE_ARGS+=	--with-x=yes

.include "../../mk/bsd.pkg.mk"
