# $NetBSD: Makefile,v 1.2 2008/12/18 11:11:15 cheusov Exp $
#

.include "../../wip/libdbi/Makefile_drivers"

PKGNAME=	${DISTNAME:S/libdbi-drivers/libdbi-driver-sqlite3/:S/-1/.1/:S/-2/.2/}

COMMENT=	SQLite3 driver for libdbi, a database abstraction

CONFLICTS=		libdbi-sqlite3-[0-9]*

INSTALLATION_DIRS+=	lib/dbd

CONFIGURE_ARGS+=	--with-sqlite3
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--with-dbi-incdir=${BUILDLINK_PREFIX.libdbi}/include/dbi
CONFIGURE_ARGS+=	--with-dbi-libdir=${BUILDLINK_PREFIX.libdbi}/lib
CONFIGURE_ARGS+=	--with-sqlite3-incdir=${BUILDLINK_PREFIX.sqlite}/include
CONFIGURE_ARGS+=	--with-sqlite3-libdir=${BUILDLINK_PREFIX.sqlite}/lib
CONFIGURE_ARGS+=	--disable-docs

.include "../../wip/libdbi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
