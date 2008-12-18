# $NetBSD: Makefile,v 1.2 2008/12/18 11:11:15 cheusov Exp $
#

.include "../../wip/libdbi/Makefile_drivers"

PKGNAME=	${DISTNAME:S/libdbi-drivers/libdbi-driver-mysql/:S/-1/.1/:S/-2/.2/}

COMMENT=	MySQL driver for libdbi, a database abstraction

CONFLICTS=		libdbi-mysql-[0-9]*

INSTALLATION_DIRS+=	lib/dbd

CONFIGURE_ARGS+=	--with-mysql
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--with-dbi-incdir=${BUILDLINK_PREFIX.libdbi}/include/dbi
CONFIGURE_ARGS+=	--with-dbi-libdir=${BUILDLINK_PREFIX.libdbi}/lib
CONFIGURE_ARGS+=	--with-mysql-incdir=${BUILDLINK_PREFIX.mysql-client}/include
CONFIGURE_ARGS+=	--with-mysql-libdir=${BUILDLINK_PREFIX.mysql-client}/lib
CONFIGURE_ARGS+=	--disable-docs

.include "../../wip/libdbi/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
