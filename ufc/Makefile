# $NetBSD: Makefile,v 1.7 2012/10/07 17:41:39 asau Exp $
#

DISTNAME=	ufc-2.0.5
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://launchpad.net/ufc/2.0.x/2.0.5/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://launchpad.net/ufc/2.0.x/2.0.5/+download/
COMMENT=	Unified framework for finite element assembly
LICENSE=	public-domain

FETCH_USING=	curl

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ python
USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

# Needed on OS X
# Not needed on NetBSD
CXXFLAGS+=	-I${LOCALBASE}/${PYINC}

PKGCONFIG_OVERRIDE+=	cmake/ufc-1.pc.in

# Stolen from lang/python/extension.mk
PLIST_SUBST+=   PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/swig2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
