# $NetBSD: Makefile,v 1.7 2015/09/17 13:48:05 makoto Exp $

PKGNAME=	gnuradio-doxygen-${VERSION}
COMMENT=	Doxygen documentation of GNU Radio

.include	"../../wip/gnuradio-core/Makefile.common"
.include	"../../wip/gnuradio-core/Nocore.mk"

BUILD_DEPENDS+=	doxygen>=1.8.9.1:../../devel/doxygen
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_DOXYGEN=ON
CMAKE_ARGS+=	-DENABLE_SPHINX=ON

MAKE_JOBS_SAFE=	no

.include	"../../mk/bsd.pkg.mk"
