# $NetBSD: Makefile,v 1.3 2008/04/16 10:56:56 asau Exp $

DISTNAME=	openmpi-1.2.6
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.2/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran

TOOLS_CREATE+=	nm
TOOLS_PATH.nm=	nm
CONFIGURE_ENV+=	NM=nm

CONFIGURE_ARGS+=	--disable-mpi-f90
CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
