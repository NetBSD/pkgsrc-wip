# $NetBSD: Makefile,v 1.4 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=	plplot-5.9.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=plplot/}
LICENSE=	gnu-lgpl-v2

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://plplot.sourceforge.net/
COMMENT=	Scientific plotting library

USE_CMAKE=	yes
USE_LANGUAGES=	c c++ # fortran77
USE_TOOLS+=	perl
CHECK_PORTABILITY_SKIP+= plplot_test/test_single_tcl.sh


CMAKE_ARGS+=	-DENABLE_f77:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_f95:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_python:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_java:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_tcl:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_itcl:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_tk:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_itk:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_ada:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_pdl:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_d:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_ocaml:BOOL=OFF
CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/${PKGMANDIR}


SUBST_CLASSES+=			builddirrefs
SUBST_STAGE.builddirrefs=	pre-configure
SUBST_MESSAGE.builddirrefs=	Removing references to work directory.
SUBST_FILES.builddirrefs=	plplot_test/test_diff.sh.in
SUBST_SED.builddirrefs=		-e 's,@TAIL_EXECUTABLE@,${TAIL},g'
SUBST_SED.builddirrefs+=	-e 's,@DIFF_EXECUTABLE@,${DIFF},g'


.include "../../devel/libltdl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
