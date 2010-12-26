# $NetBSD: Makefile,v 1.17 2010/12/26 05:01:21 davesainty Exp $
#

DISTNAME=	mod_ometer-1.3.0
PKGNAME=	${DISTNAME:S/mod_/ap-/}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.umich.edu/~umweb/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.umich.edu/~umweb/software/mod_ometer.html
COMMENT=	Web counter apache module

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-freetype=${BUILDLINK_PREFIX.freetype2}
CONFIGURE_ARGS+=	--with-libpng=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-db=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-jpeg=${JPEGBASE}
CONFIGURE_ARGS+=	--with-libpng=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-odometerdb=${VARBASE}/odometer/odometer.db

APACHE_MODULE_NAME=	${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c

BUILDLINK_TRANSFORM+=l:db:db4

.include "../../www/apache/module.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
