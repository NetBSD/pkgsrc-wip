# $NetBSD: Makefile,v 1.1.1.1 2012/01/16 14:13:41 noud4 Exp $
#

LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2

LIBGDA_PROVIDER=	odbc
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-odbc=${PREFIX}

.include "options.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
