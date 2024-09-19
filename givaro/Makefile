# $NetBSD$

DISTNAME=	givaro-4.0.4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=linbox-team/}
GITHUB_RELEASE=	v4.0.4

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/linbox-team/givaro/
COMMENT=	C++ library for arithmetic and algebraic computations
LICENSE=	cecill-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	givaro.pc.in

.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
