# $NetBSD: Makefile,v 1.6 2013/06/23 17:36:22 outpaddling Exp $

DISTNAME=		fftw-3.3
#PKGNAME=		fftw-mpich-3.3
PKGNAME=		fftw-openmpi-3.3
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		jwbacon@tds.net
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

#INSTALLATION_PREFIX=	$(BUILDLINK_PREFIX.mpich:Q)
INSTALLATION_PREFIX=	$(BUILDLINK_PREFIX.openmpi:Q)

USE_LANGUAGES=		c fortran77
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	fftw.pc.in
INFO_FILES=		yes

TEST_TARGET=		check

CONFIGURE_ARGS+=	--enable-shared \
			--enable-mpi \
			--prefix=$(INSTALLATION_PREFIX)

.include "../../mk/bsd.prefs.mk"

.if defined(PKGSRC_RUN_TEST) && !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_TOOLS+=		perl
TEST_MAKE_FLAGS+=	MPIRUN=$(MPI_PREFIX)/bin/mpirun
#TEST_MAKE_FLAGS+=	MPIRUN=$(BUILDLINK_PREFIX.mpich:Q)/bin/mpirun
.endif

#.include "../../wip/mpi-ch/buildlink3.mk"
.include "../../wip/openmpi163/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
