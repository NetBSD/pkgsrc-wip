# $NetBSD: Makefile,v 1.8 2004/05/07 01:57:49 xtraeme Exp $
#

DISTNAME=	mod_ometer-1.2.0
PKGNAME=	${DISTNAME:S/mod_/ap-/}
CATEGORIES=	www
MASTER_SITES=	http://www.umich.edu/~umweb/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.umich.edu/~umweb/software/mod_ometer.html
COMMENT=	Web counter apache module

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-freetype=${BUILDLINK_PREFIX.freetype2}
CONFIGURE_ARGS+=	--with-libpng=${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-db=${BUILDLINK_PREFIX.db4}
CONFIGURE_ARGS+=	--with-jpeg=${BUILDLINK_PREFIX.jpeg}

APACHE_MODULE_NAME=     ${DISTNAME:C|-.*||}.so
APACHE_MODULE_SRC=	${DISTNAME:C|-.*||}.c

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../databases/db4/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
