# $NetBSD: Makefile,v 1.13 2012/11/14 01:25:01 outpaddling Exp $
#

DISTNAME=	dolfin-1.0.0
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/dolfin/1.0.x/1.0.0/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	https://launchpad.net/dolfin
COMMENT=	C++/Python interface of FEniCS
LICENSE=	gnu-lgpl-v3

# Don't add gsed yet: Causes ../../mk/tools/replace.mk to override the
# gsed command and use sed
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ python
USE_CMAKE=	yes

REPLACE_PYTHON+=	scripts/dolfin-plot/dolfin-plot
REPLACE_PYTHON+=	scripts/dolfin-order/dolfin-order
REPLACE_PYTHON+=	scripts/dolfin-convert/dolfin-convert

CMAKE_ARGS+=	-DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
		-DDOLFIN_ENABLE_MPI:BOOL=OFF

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CXXFLAGS+=	-I${LOCALBASE}/${PYINC}
.endif

# Fix for variadic template warnings, but causes make_pair() error
.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
#CXXFLAGS+=	-std=gnu++0x
#CXXFLAGS+=	-std=c++0x
.endif

# MAKE_ENV+=	ARMADILLO_DIR=${PREFIX}

# Work around compile errors.  ( Doesn't work right now: see pre-build )
# MAKE_ENV+=	BOOST_NO_0X_HDR_INITIALIZER_LIST=1

PKGCONFIG_OVERRIDE+=	cmake/templates/dolfin.pc.in

FETCH_USING=	curl

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-configure
SUBST_FILES.bash=	dolfin-version
SUBST_SED.bash=		-e 's|/bin/bash|/usr/bin/env bash|'

# Stolen from lang/python/extension.mk
PLIST_SUBST+=   PYSITELIB=${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../wip/armadillo/buildlink3.mk"
.include "../../wip/metis/buildlink3.mk"
.include "../../wip/ufc/buildlink3.mk"
.include "../../wip/py-ffc/buildlink3.mk"
.include "../../wip/py-fiat/buildlink3.mk"
.include "../../wip/py-instant/buildlink3.mk"
.include "../../wip/py-ufl/buildlink3.mk"
.include "../../wip/py-viper/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
# cgal requires qt4-libs and qt4-tools, which don't build on Linux or Mac
#.include "../../math/cgal/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../wip/swig2/buildlink3.mk"
.include "../../wip/suitesparse/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
# Broken package
#.include "../../wip/petsc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
