# $NetBSD: Makefile,v 1.5 2013/06/22 15:54:28 outpaddling Exp $

DISTNAME=	openmx3.7
PKGNAME=	openmx-openmpi-3.7
CATEGORIES=	science
MASTER_SITES=	http://www.openmx-square.org/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.openmx-square.org/
COMMENT=	Nano-scale material simulations based on DFT
LICENSE=	gnu-gpl-v1

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAKE_FILE=	makefile
# check_lead and MAIN_TRAN_Display targets fail to build
BUILD_TARGET=	All \
		DosMain \
		jx \
		analysis_example \
		esp \
		OpticalConductivityMain \
		polB \
		test_mpi \
		TranMain \
		TranMain_NC
USE_TOOLS+=	gmake

# FIXME: CentOS installation didn't notice that fortran was missing from
# USE_LANGUAGES, but RHEL 5 did.
USE_LANGUAGES=	c fortran

SUBST_CLASSES+=		compile
SUBST_FILES.compile=	${WRKSRC}/makefile
SUBST_STAGE.compile=	post-patch
SUBST_SED.compile=	-e "s|-openmp -O3 -I/usr/local/include|-fopenmp ${CFLAGS}|g"
SUBST_SED.compile+=	-e "s|-lg2c -static||g"
# SUBST_SED.compile+=	-e "s|-L/usr/local/lib|-L${MPI_PREFIX}/lib -Wl,-rpath,${MPI_PREFIX}/lib -L${PREFIX}/lib -Wl,-rpath,${PREFIX}/lib|g"
SUBST_SED.compile+=	-e "s|-L/usr/local/lib|-L${MPI_PREFIX}/lib ${COMPILER_RPATH_FLAG}${MPI_PREFIX}/lib -L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib|g"
SUBST_SED.compile+=	-e 's|$$(CC) $$(OBJS)|$$(FC) $$(OBJS)|g'

# Some build targets "install" binaries into ${WRKDIR}/${DISTNAME}/work, so we
# remove them before installing the work dir to share/openmx
do-install:
	${MKDIR} ${DESTDIR}${MPI_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/openmx ${DESTDIR}${MPI_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/TranMain ${DESTDIR}${MPI_PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/TranMain_NC ${DESTDIR}${MPI_PREFIX}/bin
	${MKDIR} ${DESTDIR}${MPI_PREFIX}/share/openmx
	${CP} -R ${WRKDIR}/${DISTNAME}/work ${DESTDIR}${MPI_PREFIX}/share/openmx
.for f in DosMain jx analysis_example esp OpticalConductivityMain polB test_mpi
	${CP} ${WRKDIR}/${DISTNAME}/work/${f} ${DESTDIR}${MPI_PREFIX}/bin
	${RM} ${DESTDIR}${MPI_PREFIX}/share/openmx/work/${f}
.endfor

.include "../../wip/openmpi163/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
# Investigate: Any advantage to using fftw-openmpi?
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
