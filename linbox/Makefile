# $NetBSD: Makefile,v 1.2 2010/08/01 14:57:09 asau Exp $
#

DISTNAME=	linbox-1.1.7rc0
PKGNAME=	linbox-1.1.7
CATEGORIES=	math
MASTER_SITES=	http://www.linalg.org/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.linalg.org/
COMMENT=	LinBox: exact computational linear algebra
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++ fortran77

CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-givaro=${BUILDLINK_PREFIX.givaro}
CONFIGURE_ARGS+=	--with-blas="-L${BUILDLINK_PREFIX.blas}/lib -lblas"

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../wip/givaro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
