# $NetBSD: Makefile,v 1.12 2013/03/23 15:11:55 outpaddling Exp $
#

DISTNAME=	ufc-2.1.0
# PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://launchpad.net/ufc/2.1.x/2.1.0/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/ufc
COMMENT=	Unified framework for finite element assembly
LICENSE=	public-domain

FETCH_USING=	curl

USE_TOOLS+=	pkg-config
# to do: Also depends on python
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../mk/bsd.prefs.mk"

# Cmake's FindSWIG looks first for swig2.0, then for swig
CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON

# Needed on OS X
# Not needed on NetBSD
CXXFLAGS+=	-I${PREFIX}/${PYINC}

PKGCONFIG_OVERRIDE+=	cmake/ufc-1.pc.in

# Stolen from lang/python/extension.mk
PLIST_SUBST+=   PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}

SUBST_CLASSES+=		ospath
SUBST_STAGE.ospath=	post-patch
SUBST_FILES.ospath=	src/utils/python/ufc_utils/build.py
SUBST_SED.ospath=	-e 's|os.path.join(os.path.sep, "opt", "local")|os.path.normpath("${PREFIX}")|'
SUBST_SED.ospath+=	-e 's|os.path.join(os.path.sep, "usr")|os.path.normpath("${PREFIX}")|'

.include "../../lang/python/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/swig2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
