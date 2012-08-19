# $NetBSD: Makefile,v 1.1 2012/08/19 12:28:43 noud4 Exp $
#

LIBGDA_PROVIDER=	xbase
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-xbase=${PREFIX}
CFLAGS+=		-Wno-deprecated
CFLAGS+=		-DXBASE_USED
USE_LANGUAGES+=		c c++

.include "../../wip/xbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
