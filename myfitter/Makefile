# $NetBSD: Makefile,v 1.2 2012/10/03 15:10:01 asau Exp $
#

DISTNAME=	myfitter-0.1
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/myfitter/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://myfitter.hepforge.org/
COMMENT=	Maximum Likelihood Fits in C++
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	myFitter.pc.in

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../wip/dvegas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
