# $NetBSD: Makefile,v 1.73 2013/11/05 22:34:15 asau Exp $

DISTNAME=	openmpi-1.7.4a1r29587
PKGNAME=	openmpi-1.7.3.99.29587
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.7/downloads/ \
		http://www.open-mpi.org/nightly/v1.7/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

MPI_SUBPREFIX=		openmpi
MPI_PREFIX=		$(LOCALBASE)/$(MPI_SUBPREFIX)
#MPI_PREFIX=		$(LOCALBASE)

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes
.if ${OPSYS} == Darwin || ${OPSYS} == Linux
USE_LANGUAGES=		c c++ fortran
# Fix for:
# The Open MPI wrapper compiler was unable to find the specified compiler
# f77 in your PATH.
FC=			gfortran
.else
USE_LANGUAGES=		c c++ fortran77
.endif
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/extlib/otf/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/libtool \
			${WRKSRC}/ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4 \
			${WRKSRC}/opal/libltdl/m4/libtool.m4

GNU_CONFIGURE_PREFIX=	$(MPI_PREFIX)
.if ${OPSYS} != Darwin && ${OPSYS} != Linux
CONFIGURE_ARGS+=	--disable-mpi-fortran
# http://www.open-mpi.org/community/lists/users/2013/04/21752.php
# Still doesn't compile on RHEL 5, but for different reason
# CONFIGURE_ARGS+=	--disable-openib-connectx-xrc
.endif
CONFIGURE_ARGS+=	--without-sge
CONFIGURE_ARGS+=	--without-slurm
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt # in separate package
CONFIGURE_ARGS+=	--with-libltdl=external # use our libltdl
CONFIGURE_ARGS+=	--with-hwloc=$(BUILDLINK_PREFIX.hwloc:Q) #external
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L$(MPI_PREFIX)/lib $(COMPILER_RPATH_FLAG)$(MPI_PREFIX)/lib"
CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0
# Suppress regeneration:
CONFIGURE_ENV+=		ACLOCAL=: AUTOCONF=: AUTOHEADER=: AUTOMAKE=:

# Prevent detection of OpenMP support in order to make PLIST consistent:
BUILDLINK_TRANSFORM=	rm:-fopenmp

BUILDLINK_PASSTHRU_RPATHDIRS+=	${MPI_PREFIX}/lib

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

post-install:
	${MKDIR} ${DESTDIR}${MPI_PREFIX}/share/examples/openmpi
	${SED} -e "s|%%MPI_PREFIX%%|${MPI_PREFIX}|g" \
		files/shrc > ${DESTDIR}${MPI_PREFIX}/share/examples/openmpi/shrc
	${SED} -e "s|%%MPI_PREFIX%%|${MPI_PREFIX}|g" \
		files/cshrc > ${DESTDIR}${MPI_PREFIX}/share/examples/openmpi/cshrc

LIBLTDL_CONVENIENCE_SUBDIR=	opal/libltdl
.include "../../devel/libltdl/convenience.mk" # for "test" target to work
.include "../../devel/libltdl/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
# Build failed with "cannot find libxml2"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
