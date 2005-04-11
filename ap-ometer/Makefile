# $NetBSD: Makefile,v 1.10 2005/04/11 21:09:45 tvierling Exp $
#

DISTNAME=	mod_ometer-1.2.0
PKGNAME=	${DISTNAME:S/mod_/ap-/}
CATEGORIES=	www
MASTER_SITES=	http://www.umich.edu/~umweb/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.umich.edu/~umweb/software/mod_ometer.html
COMMENT=	Web counter apache module

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-freetype=${BUILDLINK_PREFIX.freetype2}
CONFIGURE_ARGS+=	--with-libpng=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-db=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_PREFIX.jpeg}

APACHE_MODULE_NAME=     ${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c

.include "../../www/apache/module.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
