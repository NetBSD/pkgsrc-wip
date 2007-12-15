# $NetBSD: Makefile,v 1.1 2007/12/15 23:19:45 cheusov Exp $
#

DISTNAME=	libdbi-drivers-0.8.2-1
PKGNAME=	${DISTNAME:S/libdbi-drivers/libdbi-pgsql/}
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdbi-drivers/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://libdbi-drivers.sourceforge.net/
COMMENT=	PostgreSQL driver for libdbi, a database abstraction

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	lib/dbd

CONFIGURE_ARGS+=	--with-pgsql
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--with-dbi-incdir=${BUILDLINK_PREFIX.libdbi}/include/dbi
CONFIGURE_ARGS+=	--with-dbi-libdir=${BUILDLINK_PREFIX.libdbi}/lib
CONFIGURE_ARGS+=	--with-pgsql-incdir=${BUILDLINK_PREFIX.postgresql82-client}/include
CONFIGURE_ARGS+=	--with-pgsql-libdir=${BUILDLINK_PREFIX.postgresql82-client}/lib
CONFIGURE_ARGS+=	--disable-docs

.include "../../wip/libdbi/buildlink3.mk"
.include "../../databases/postgresql82-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
