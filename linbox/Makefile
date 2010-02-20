# $NetBSD: Makefile,v 1.1.1.1 2010/02/20 22:45:12 jihbed Exp $
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
USE_LANGUAGES=	c c++ fortran

CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-givaro=${BUILDLINK_PREFIX.givaro}
CONFIGURE_ARGS+=	--with-blas="-L${BUILDLINK_PREFIX.blas}/lib -lblas"

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../wip/givaro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
