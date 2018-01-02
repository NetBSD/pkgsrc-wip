# $NetBSD: Makefile,v 1.20 2014/06/01 12:49:35 thomasklausner Exp $
#

DISTNAME=	dolfin-${MMVERSION}.0
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/dolfin/${MMVERSION}.x/${MMVERSION}.0/+download/

MAINTAINER=	bacon@NetBSD.org
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
		-DDOLFIN_ENABLE_MPI:BOOL=OFF \
		-DLOCALBASE=${LOCALBASE}

# CHOLMOD_DIR, UMFPACK_DIR, etc. will default to .buildlink.  See CMakeCache.txt
# Installed dolfin-config.cmake contains .buildlink where it should use
# ${LOCALBASE}.  Using post-install patch for now.  Is there a better solution?
#		-DCHOLMOD_DIR:PATH=${LOCALBASE} \
#		-DCAMD_DIR:PATH=${LOCALBASE} \
#		-DCCOLAMD_DIR:PATH=${LOCALBASE} \
#		-DCOLAMD_DIR:PATH=${LOCALBASE} \
#		-DUMFPACK_DIR:PATH=${LOCALBASE} \
#		-DAMD_DIR:PATH=${LOCALBASE} \
#		-DARMADILLO_DIR:PATH=${LOCALBASE} \

.include "../../mk/bsd.prefs.mk"

CXXFLAGS+=	-fpermissive

.if ${OPSYS} == "Darwin"
CXXFLAGS+=	-I${LOCALBASE}/${PYINC}
.endif

# Fix for variadic template warnings, but causes make_pair() error
# According to FEniCS developer, warnings are caused by c++ not realizing
# that boost headers are system headers.  ( Because they're included
# from .buildlink? )
# .if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
# CXXFLAGS+=	-std=gnu++0x
# CXXFLAGS+=	-std=c++0x
# .endif

PKGCONFIG_OVERRIDE+=	cmake/templates/dolfin.pc.in


SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-configure
SUBST_FILES.bash=	dolfin-version
SUBST_SED.bash=		-e 's|/bin/bash|/usr/bin/env bash|'

SUBST_CLASSES+=		ospath
SUBST_STAGE.ospath=	post-patch
SUBST_FILES.ospath=	site-packages/dolfin/compilemodules/compilemodule.py
SUBST_SED.ospath=	-e 's|os.path.join(os.path.sep,"opt","local")|os.path.normpath("${PREFIX}")|' \
			-e 's|os.path.join(os.path.sep,"usr")|os.path.normpath("${PREFIX}")|'

# Replace .buildlink with PREFIX in installed cmake file.
# Patching files after install doesn't seem quite kosher, but it's the
# simplest solution I've found so far.  dolfin-config.cmake is regenerated
# by 'make install', so patches applied in any other phase are overwritten.
# dolfin-config.cmake may also be used during build, so maybe it should
# contain .buildlink paths until install.
DATADIR=		${DESTDIR}${PREFIX}/share/dolfin
SUBST_CLASSES+=		dolfinconf
SUBST_STAGE.dolfinconf=	post-install
SUBST_FILES.dolfinconf=	${DATADIR}/cmake/dolfin-config.cmake
SUBST_SED.dolfinconf=	-e 's|${WRKDIR}/.buildlink|${PREFIX}|g' \
			-e 's|${WRKDIR}/.wrapper|${PREFIX}|g'

# From lang/python/extension.mk
PLIST_SUBST+=   PYSITELIB=${PYSITELIB}

MMVERSION=	1.2

.include "../../lang/python/application.mk"
.include "../../wip/armadillo/buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.include "../../wip/ufc/buildlink3.mk"
.include "../../wip/py-ffc/buildlink3.mk"
.include "../../wip/py-fiat/buildlink3.mk"
.include "../../wip/py-instant/buildlink3.mk"
.include "../../wip/py-ufl/buildlink3.mk"
.include "../../wip/py-viper/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
# cgal requires qt4-libs and qt4-tools, which don't currently build on Linux or Mac
#.include "../../math/cgal/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/swig2/buildlink3.mk"
.include "../../wip/suitesparse/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
# Broken package
#.include "../../wip/petsc/buildlink3.mk"
# vtk-python module required for plotting
# Broken package
#.include "../../graphics/vtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
