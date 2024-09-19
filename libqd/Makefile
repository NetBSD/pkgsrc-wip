# $NetBSD$

DISTNAME=	qd-2.3.22
PKGNAME=	lib${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://www.davidhbailey.com/dhbsoftware/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.davidhbailey.com/dhbsoftware/
COMMENT=	Double-double and quad-double package for Fortran and C++
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

PKGCONFIG_OVERRIDE+=	qd.pc.in

.include "../../mk/bsd.pkg.mk"
