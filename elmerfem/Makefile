# $NetBSD$

GITHUB_PROJECT=	elmerfem
GITHUB_TAG=	refs/tags/${DISTNAME}
DISTNAME=	release-9.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/release-//1}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=ElmerCSC/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.elmerfem.org/
COMMENT=	Finite element software for multiphysical problems published
LICENSE=	gnu-gpl-v2

CMAKE_CONFIGURE_ARGS+=	-DWITH_OpenMP:BOOLEAN=TRUE
CMAKE_CONFIGURE_ARGS+=	-DWITH_MPI:BOOLEAN=TRUE
CMAKE_CONFIGURE_ARGS+=	-DWITH_ELMERGUI:BOOLEAN=TRUE
CMAKE_CONFIGURE_ARGS+=	-DWITH_PARAVIEW:BOOLEAN=TRUE
#CMAKE_CONFIGURE_ARGS+=	-DELMER_INSTALL_LIB_DIR=${PREFIX}/lib

DEPENDS+=	paraview-[0-9]*:../../wip/paraview

WRKSRC=		${WRKDIR}/elmerfem-${DISTNAME}
USE_LANGUAGES=	c c++ fortran

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	post-configure
SUBST_MESSAGE.rpath=	Add RPATH
SUBST_FILES.rpath=	${CMAKE_BUILD_DIR}/fem/src/CMakeFiles/Solver_TGT.dir/link.txt
SUBST_SED.rpath=	"s|-O|-Wl,-R${PREFIX}/lib/elmersolver -O|"

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../mk/mpi.buildlink3.mk"
.include "../../wip/qwt6-qt4/buildlink3.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
