# $NetBSD: Makefile,v 1.1 2008/12/18 10:39:54 cheusov Exp $
#

DISTNAME=	libdbi-drivers-0.8.3-1
PKGNAME=	${DISTNAME:S/libdbi-drivers/libdbi-driver-mysql/:S/-1/.1/:S/-2/.2/}
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdbi-drivers/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://libdbi-drivers.sourceforge.net/
COMMENT=	MySQL driver for libdbi, a database abstraction

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS=		libdbi-mysql-[0-9]*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

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
