# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:38 asau Exp $
#

LIBGDA_PROVIDER=	xbase

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-xbase=${PREFIX}
CFLAGS+=		-Wno-deprecated
CFLAGS+=		-DXBASE_USED
USE_LANGUAGES+=		c c++

.include "../../wip/xbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
