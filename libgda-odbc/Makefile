# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:38 asau Exp $
#

LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2

LIBGDA_PROVIDER=	odbc

.include "../../databases/libgda/Makefile.common"

CONFIGURE_ARGS+=	--with-odbc=${PREFIX}

.include "options.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
