# $NetBSD: Makefile,v 1.3 2013/03/22 00:38:01 outpaddling Exp $

DISTNAME=	dl_class_1.8
PKGNAME=	dlpoly-classic-1.8
CATEGORIES=	science
MASTER_SITES=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://ccpforge.cse.rl.ac.uk/gf/download/frsrelease/238/2028/
COMMENT=	General purpose classical molecular dynamics
LICENSE=	original-bsd

USE_LANGUAGES=	c fortran
USE_TOOLS+=	gmake

# Use gfortran if it's installed as a base compiler outside pkgsrc
# rather than install f2c or g95 unnecessarily
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

# Temporary hack to use openmpi from outside pkgsrc
# Link fails with non-pkgsrc openmpi on RHEL
# mpif77 cannot find -lmpi_f77
#.include "../../mk/bsd.prefs.mk"
#.if ${OPSYS} != "Linux"
.include "../../parallel/openmpi/buildlink3.mk"
#.endif
.include "../../mk/bsd.pkg.mk"
