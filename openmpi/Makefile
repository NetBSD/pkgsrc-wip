# $NetBSD: Makefile,v 1.31 2010/10/11 04:34:19 asau Exp $

DISTNAME=	openmpi-1.5rc8r23855
PKGNAME=	openmpi-1.4.99.23855
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/nightly/v1.5/ \
		http://www.open-mpi.org/nightly/v1.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4

CONFIGURE_ARGS+=	--disable-mpi-f90
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib"
CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??
BUILD_MAKE_FLAGS=	LIBLTDL=$(BUILDLINK_PREFIX.libltdl)/lib/libltdl.la # configure doesn't allow overriding it
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0

USE_TOOLS+=		perl:run
REPLACE_PERL=		orte/tools/wrappers/orte_wrapper_script.in

.include "options.mk"

TEST_TARGET=	check

# USE_TOOLS+=	aclocal autoconf automake bash perl
# REPLACE_BASH=	autogen.sh
# pre-configure:	replace-interpreter
# 	cd $(WRKSRC) && $(BASH) autogen.sh

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
