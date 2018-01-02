# $NetBSD: Makefile,v 1.2 2014/10/09 14:06:27 thomasklausner Exp $

DISTNAME=		fftw-3.3
PKGNAME=		fftw-mpich-3.3
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
GNU_CONFIGURE_PREFIX=	${PREFIX}/mpich

PKGCONFIG_OVERRIDE+=	fftw.pc.in
INFO_FILES=		yes

TEST_TARGET=		check

# for finding mpi-ch
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mpich}/mpich/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.mpich}/mpich/lib
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.mpich}/mpich/lib

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-mpi

.include "../../mk/bsd.prefs.mk"

.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_TOOLS+=		perl
TEST_MAKE_FLAGS+=	MPIRUN=$(PREFIX}/mpich/bin/mpirun
.endif

.include "../../wip/mpi-ch/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
