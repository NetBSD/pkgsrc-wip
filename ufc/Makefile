# $NetBSD: Makefile,v 1.15 2014/06/01 12:49:49 thomasklausner Exp $

DISTNAME=	ufc-${MMVERSION}.0
CATEGORIES=	math
MASTER_SITES=	http://launchpad.net/ufc/${MMVERSION}.x/${MMVERSION}.0/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/ufc
COMMENT=	Unified framework for finite element assembly
LICENSE=	public-domain


USE_TOOLS+=	pkg-config
# to do: Also depends on python
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"

# Cmake's FindSWIG looks first for swig2.0, then for swig
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

# Needed on OS X
# Not needed on NetBSD
CXXFLAGS+=	-I${PREFIX}/${PYINC}

PKGCONFIG_OVERRIDE+=	cmake/ufc-1.pc.in

# Stolen from lang/python/extension.mk
PLIST_SUBST+=	PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}

MMVERSION=	2.2

.include "../../lang/python/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
