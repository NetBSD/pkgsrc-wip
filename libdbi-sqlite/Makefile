# $NetBSD: Makefile,v 1.1 2008/01/10 21:09:36 cheusov Exp $
#

DISTNAME=	libdbi-drivers-0.8.2-1
PKGNAME=	${DISTNAME:S/libdbi-drivers/libdbi-sqlite/}
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdbi-drivers/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://libdbi-drivers.sourceforge.net/
COMMENT=	sqlite driver for libdbi, a database abstraction

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	lib/dbd

CONFIGURE_ARGS+=	--with-sqlite
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--with-dbi-incdir=${BUILDLINK_PREFIX.libdbi}/include/dbi
CONFIGURE_ARGS+=	--with-dbi-libdir=${BUILDLINK_PREFIX.libdbi}/lib
CONFIGURE_ARGS+=	--with-sqlite-incdir=${BUILDLINK_PREFIX.sqlite}/include
CONFIGURE_ARGS+=	--with-sqlite-libdir=${BUILDLINK_PREFIX.sqlite}/lib
CONFIGURE_ARGS+=	--disable-docs

.include "../../wip/libdbi/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
