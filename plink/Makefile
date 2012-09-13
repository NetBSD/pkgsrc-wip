# $NetBSD: Makefile,v 1.1 2012/09/13 01:15:34 outpaddling Exp $
#

DISTNAME=	plink-1.07-src
CATEGORIES=	science
MASTER_SITES=	http://pngu.mgh.harvard.edu/~purcell/plink/dist/
EXTRACT_SUFX=	.zip

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://pngu.mgh.harvard.edu/~purcell/plink/dist/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++ fortran77
# USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CXXFLAGS+=	-Dfopen64=fopen

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
MAKE_FLAGS+=	LIBDL=""
# Temporary hack.  Make f2c a dep?
LIB_LAPACK=	"${LOCALBASE}/lib/liblapack.a ${LOCALBASE}/lib/libblas.a ${LOCALBASE}/lib/libf2c.a"
.else
LIB_LAPACK=	"-L${LOCALBASE}/lib -llapack -lblas -lgfortran"
.endif

MAKE_FLAGS+=	WITH_LAPACK=1 \
		LIB_LAPACK=${LIB_LAPACK}

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/plink ${DESTDIR}${PREFIX}/bin

.include "../../math/lapack/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
