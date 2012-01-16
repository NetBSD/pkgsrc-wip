# $NetBSD: Makefile,v 1.1.1.1 2012/01/16 14:44:01 noud4 Exp $
#

LICENSE=		gnu-gpl-v2 AND gnu-lgpl-v2

CONFLICTS=		libgda-[0-9]*	# till PR pkg/45845 applied.

LIBGDA_PROVIDER=	sqlite
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../databases/libgda/Makefile.common"
PKGNAME=		${DISTNAME:S/libgda-/libgda-${LIBGDA_PROVIDER}3-/}

CONFIGURE_ARGS+=	--with-sqlite=${PREFIX}

INSTALLATION_DIRS+=	share/gtk-doc/html/libgda-3.0

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/C/html/limitations_sqlite.html ${DESTDIR}${PREFIX}/share/gtk-doc/html/libgda-3.0

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
