# $NetBSD: Makefile,v 1.4 2012/05/12 00:58:47 outpaddling Exp $
#

DISTNAME=	ufc-2.0.5
CATEGORIES=	math
MASTER_SITES=	http://launchpad.net/ufc/2.0.x/2.0.5/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://launchpad.net/ufc/2.0.x/2.0.5/+download/
COMMENT=	Unified framework for finite element assembly
LICENSE=	public-domain

FETCH_USING=	curl

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ python
USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../lang/python/application.mk"

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

# CXXFLAGS+=	-I${LOCALBASE}/include/python${PYVERSSUFFIX}
CXXFLAGS+=	-I${PYINC}

PKGCONFIG_OVERRIDE+=	cmake/ufc-1.pc.in

# PYDISTUTILSPKG= yes
PLIST_SUBST+=   PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/swig2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
