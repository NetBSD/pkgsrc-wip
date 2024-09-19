# $NetBSD$

DISTNAME=	flint-2.6.3
CATEGORIES=	math
MASTER_SITES=	http://www.flintlib.org/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.flintlib.org/
COMMENT=	Fast Library for Number Theory
LICENSE=	gnu-lgpl-v2.1

HAS_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-ntl
CONFIGURE_ARGS+=	--without-blas

CONFIGURE_ARGS+=	--with-gmp=${PREFIX}
BUILDLINK_API_DEPENDS.gmp+=	gmp>=6.0
.include "../../devel/gmp/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mpfr=${PREFIX}
BUILDLINK_API_DEPENDS.mpfr+=    mpfr>=2.0.3
.include "../../math/mpfr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
