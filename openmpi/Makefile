# $NetBSD: Makefile,v 1.67 2013/03/17 18:30:57 asau Exp $

DISTNAME=	openmpi-1.7rc8r28176
PKGNAME=	openmpi-1.6.99.28176
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.7/downloads/ \
		http://www.open-mpi.org/nightly/v1.7/ \
		http://www.open-mpi.org/nightly/v1.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

MPI_SUBPREFIX=		openmpi
MPI_PREFIX=		$(LOCALBASE)/$(MPI_SUBPREFIX)
INSTALLATION_PREFIX=	$(MPI_PREFIX)

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran77
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/extlib/otf/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/libtool \
			${WRKSRC}/ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4 \
			${WRKSRC}/opal/libltdl/m4/libtool.m4

GNU_CONFIGURE_PREFIX=	$(MPI_PREFIX)
CONFIGURE_ARGS+=	--disable-mpi-fortran
CONFIGURE_ARGS+=	--without-sge
CONFIGURE_ARGS+=	--without-slurm
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt # in separate package
CONFIGURE_ARGS+=	--with-libltdl=external # use our libltdl
CONFIGURE_ARGS+=	--with-hwloc=$(BUILDLINK_PREFIX.hwloc:Q) #external
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L$(MPI_PREFIX)/lib $(LINKER_RPATH_FLAG)$(MPI_PREFIX)/lib"
CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0
# Suppress regeneration:
CONFIGURE_ENV+=		ACLOCAL=: AUTOCONF=: AUTOHEADER=: AUTOMAKE=:

# Prevent detection of OpenMP support in order to make PLIST consistent:
BUILDLINK_TRANSFORM=	rm:-fopenmp

USE_TOOLS+=		perl:run
REPLACE_PERL+=		ompi/tools/wrappers/mpijavac.pl.in

.include "options.mk"

TEST_TARGET=	check

# Debug
#BUILD_MAKE_FLAGS=	V=1

## Just in case you'll need it...
# USE_TOOLS+=	aclocal autoconf automake bash perl
# REPLACE_PERL=	autogen.sh

# pre-configure:	replace-interpreter
# 	cd $(WRKSRC) && $(PERL5) autogen.sh

LIBLTDL_CONVENIENCE_SUBDIR=	opal/libltdl
.include "../../devel/libltdl/convenience.mk" # for "test" target to work
.include "../../devel/libltdl/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
