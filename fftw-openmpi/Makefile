# $NetBSD: Makefile,v 1.4 2013/03/08 06:27:35 asau Exp $

DISTNAME=		fftw-3.3
PKGNAME=		fftw-openmpi-3.3
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.fftw.org/pub/fftw/ \
			http://www.fftw.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fftw.org/
COMMENT=		Collection of fast C routines to compute DFTs
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

INSTALLATION_PREFIX=	$(BUILDLINK_PREFIX.mpich:Q)
#INSTALLATION_PREFIX=	$(BUILDLINK_PREFIX.openmpi:Q)

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
.endif

.include "../../wip/mpi-ch/buildlink3.mk"
#.include "../../wip/openmpi/buildlink3.mk"
#.include "../../wip/openmpi-prefixed/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
