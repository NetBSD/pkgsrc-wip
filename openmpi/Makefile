# $NetBSD: Makefile,v 1.13 2009/12/03 10:18:00 asau Exp $

DISTNAME=	openmpi-1.3.4
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.3/downloads/ \
		http://www.open-mpi.org/nightly/v1.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

MAKE_JOBS_SAFE=	no	# temporary

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4

#CONFIGURE_ARGS=		LIBLTDL_SUBDIR=	# use our libltdl

CONFIGURE_ARGS+=	--enable-debug
CONFIGURE_ARGS+=	--disable-mpi-f90
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib"
CONFIGURE_ENV+=		NM=/usr/bin/nm
CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??
CONFIGUGE_ENV+=		LIBLTDL=libltdl.la # LTDLINCL=-I/usr/pkg/include
BUILD_MAKE_FLAGS=	LIBLTDL=$(BUILDLINK_PREFIX.libltdl)/lib/libltdl.la # configure doesn't allow overriding it
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
CONFIGURE_ENV+=		NM=/usr/bin/nm	# configure doesn't detect it
.endif

TEST_TARGET=	check

# opal/util/if.c

#USE_TOOLS+=	aclocal autoconf automake
#USE_TOOLS+=	bash
# pre-configure:
# 	cd ${WRKSRC} && bash autogen.sh && aclocal && autoconf && automake

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
