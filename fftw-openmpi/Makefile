# $NetBSD: Makefile,v 1.8 2014/10/09 14:06:27 thomasklausner Exp $

DISTNAME=		fftw-3.3
PKGNAME=		fftw-openmpi-3.3
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		bacon@NetBSD.org
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c fortran77
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/openmpi

PKGCONFIG_OVERRIDE+=	fftw.pc.in
INFO_FILES=		yes

TEST_TARGET=		check

# for finding openmpi
CPPFLAGS+=		-I${BUILDLINK_PREFIX.openmpi}/openmpi/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.openmpi}/openmpi/lib
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openmpi}/openmpi/lib

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-mpi

.include "../../mk/bsd.prefs.mk"

.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_TOOLS+=		perl
TEST_MAKE_FLAGS+=	MPIRUN=$(MPI_PREFIX)/bin/mpirun
.endif

.include "../../devel/libltdl/buildlink3.mk"
.include "../../wip/openmpi163/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
