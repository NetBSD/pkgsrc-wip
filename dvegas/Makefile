# $NetBSD: Makefile,v 1.2 2012/09/28 21:24:39 asau Exp $
#

DISTNAME=	dvegas-2.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/dvegas/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dvegas.hepforge.org/
COMMENT=	Parallel Adaptive Monte Carlo Integration in C++
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

GCC_REQD+=	3.0

PKGCONFIG_OVERRIDE+=	dvegas.pc.in

.include "../../math/gsl/buildlink3.mk"
.include "../../net/omniORB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
