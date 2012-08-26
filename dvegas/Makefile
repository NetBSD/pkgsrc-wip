# $NetBSD: Makefile,v 1.1 2012/08/26 21:54:53 jihbed Exp $
#

DISTNAME=	dvegas-2.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/dvegas/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dvegas.hepforge.org/
COMMENT=	Parallel Adaptive Monte Carlo Integration in C++
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

GCC_REQD+=	3.0

PKGCONFIG_OVERRIDE+=	dvegas.pc.in

.include "../../math/gsl/buildlink3.mk"
.include "../../net/omniORB/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
