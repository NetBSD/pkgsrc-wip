# $NetBSD: Makefile,v 1.3 2012/09/14 15:06:55 asau Exp $
#

DISTNAME=	plink-1.07-src
CATEGORIES=	biology science
MASTER_SITES=	http://pngu.mgh.harvard.edu/~purcell/plink/dist/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://pngu.mgh.harvard.edu/~purcell/plink/dist/
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++ fortran77
USE_TOOLS+=	gmake

CXXFLAGS+=	-Dfopen64=fopen

.include "../../mk/bsd.prefs.mk"

# Temporary hack to build on our RHEL cluster.  Make f2c a dep?
.if ${OPSYS} != "Linux"
MAKE_FLAGS+=	LIBDL=""
LIB_LAPACK=	"${LOCALBASE}/lib/liblapack.a ${LOCALBASE}/lib/libblas.a ${LOCALBASE}/lib/libf2c.a"
.else
LIB_LAPACK=	"-L${LOCALBASE}/lib -llapack -lblas -lgfortran"
.endif

MAKE_FLAGS+=	WITH_LAPACK=1 \
		LIB_LAPACK=${LIB_LAPACK}

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/plink ${DESTDIR}${PREFIX}/bin

.include "../../devel/libf2c/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
