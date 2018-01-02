# $NetBSD$

PKGNAME=	cblas-1.0
DISTNAME=	cblas
CATEGORIES=	math
MASTER_SITES=	http://www.netlib.org/blas/blast-forum/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.netlib.org/blas/blast-forum/
COMMENT=	C bindings and headers for BLAS library
# Not sure about this.  FreeBSD port has custom blas license.
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/CBLAS
USE_LANGUAGES=	c fortran

SUBST_CLASSES+=		libblas
SUBST_STAGE.libblas=	post-patch
SUBST_SED.libblas=	-e 's|libblas.a|-L${PREFIX}/lib -lblas|g'
SUBST_SED.libblas+=	-e 's|cblas_$$(PLAT)|libcblas|g'
SUBST_SED.libblas+=	-e 's|= -O3|+=|g'
SUBST_SED.libblas+=	-e 's|CC =|CC ?=|g'
SUBST_SED.libblas+=	-e 's|FC =|FC ?=|g'
SUBST_FILES.libblas=	Makefile.in

# Can't find -lssp* on NetBSD 7.0.1
PKGSRC_USE_SSP=		no
CFLAGS+=		-fPIC
FFLAGS+=		-fPIC

INSTALLATION_DIRS=	include lib

post-extract:
	${CP} ${WRKSRC}/Makefile.LINUX ${WRKSRC}/Makefile.in

post-build:
	${MKDIR} ${WRKSRC}/shared-lib
	cd ${WRKSRC}/shared-lib && \
		${AR} x ../lib/libcblas.a && \
		${FC} -shared -o ../lib/libcblas.so *.o

do-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libcblas.* ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include

.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
