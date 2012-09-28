# $NetBSD: Makefile,v 1.2 2012/09/28 21:24:37 asau Exp $
#

DISTNAME=	dl_class_1.8
PKGNAME=	dlpoly-classic-1.8
CATEGORIES=	math parallel
MASTER_SITES=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/
COMMENT=	General purpose classical molecular dynamics
LICENSE=	original-bsd

USE_LANGUAGES=	c fortran
USE_TOOLS+=	gmake

# Force use of gfortran installation outside pkgsrc
# Toolchain wrappers handle this fine where gfortran doesn't actually exist
FC=		gfortran

BUILD_WRKSRC=	${WRKSRC}/source

AUTO_MKDIRS=	yes

do-build:
	(cd ${BUILD_WRKSRC} && \
	        ${CP} -f ${WRKSRC}/build/MakeSEQ Makefile && \
		${MAKE} ${FC})
	(cd ${BUILD_WRKSRC} && \
		${MAKE} clean && \
		${CP} -f ${WRKSRC}/build/MakePAR Makefile && \
		${MAKE} gfortran)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/execute/dlpoly-classic-mpi \
		${DESTDIR}${PREFIX}/bin

# url2pkg-marker (please do not remove this line.)

# Temporary hack to use openmpi from outside pkgsrc
# Link fails with non-pkgsrc openmpi on RHEL
# mpif77 cannot find -lmpi_f77
#.include "../../mk/bsd.prefs.mk"
#.if ${OPSYS} != "Linux"
.include "../../parallel/openmpi/buildlink3.mk"
#.endif
.include "../../mk/bsd.pkg.mk"
