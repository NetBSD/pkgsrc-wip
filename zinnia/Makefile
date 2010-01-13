# $NetBSD: Makefile,v 1.1.1.1 2010/01/13 11:12:45 obache Exp $
#

.include "Makefile.common"

COMMENT=	Online hand writing recognition system with machine learning

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	zinnia.pc.in

.include "../../mk/bsd.pkg.mk"
