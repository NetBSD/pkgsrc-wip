# $NetBSD: Makefile,v 1.2 2013/03/05 19:37:15 asau Exp $

PKGVERSION=	1.6.3
DISTNAME=	openmpi-${PKGVERSION}
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.6/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

# Allow multiple MPI installations to coexist.  This is mandatory on most
# HPC clusters.
MPI_PREFIX=	${PREFIX:Q}/openmpi

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${MPI_PREFIX}
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/extlib/otf/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/libtool \
			${WRKSRC}/ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4 \
			${WRKSRC}/opal/libltdl/m4/libtool.m4

# CONFIGURE_ARGS+=	--disable-mpi-f90
CONFIGURE_ARGS+=	--without-sge
CONFIGURE_ARGS+=	--without-slurm
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt # in separate package
CONFIGURE_ARGS+=	--with-libltdl=external # use our libltdl
CONFIGURE_ARGS+=	--with-hwloc=$(BUILDLINK_PREFIX.hwloc:Q) #external
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${PREFIX}/lib ${LINKER_RPATH_FLAG}${PREFIX}/lib"

# f2c limitation?
# CONFIGURE_ENV+=		ompi_cv_f77_have_INTEGERp8=no	# no "INTEGER*8"??
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0

.include "../../mk/bsd.prefs.mk"

# Override use of g95
#.if ${OPSYS} != "NetBSD"
FC=		gfortran
#.endif

# pkgsrc doesn't get LINKER_RPATH_FLAG right on all platforms, so we
# may need to override.  Even with this, pkgsrc inserts a -R${MPI_PREFIX}/lib
# in opal_wrapper.  See post-build  below.

.if ${OPSYS} == "Darwin"
LINKER_RPATH_FLAG=	-rpath,
.elif ${OPSYS} == "Linux"
LINKER_RPATH_FLAG=	-rpath=
.endif

LDFLAGS+=	-Wl,${LINKER_RPATH_FLAG}${MPI_PREFIX}/lib

CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${MPI_PREFIX}/lib -Wl,${LINKER_RPATH_FLAG}${MPI_PREFIX}/lib"

# Prevent detection of OpenMP support in order to make PLIST consistent:
BUILDLINK_TRANSFORM=	rm:-fopenmp

USE_TOOLS+=		perl:run

.include "options.mk"
TEST_TARGET=	check

## Just in case you'll need it...
# USE_TOOLS+=	aclocal autoconf automake bash perl
# REPLACE_BASH=	autogen.sh

# pre-configure:	replace-interpreter
# 	cd $(WRKSRC) && $(BASH) autogen.sh

# A -R flag is being mysteriously inserted into the mpi wrapper flags,
# which is not supported by the Darwin linker.  This hack replaces
# it with a harmless extra -L until I can figure out how to prevent it.
# The same -R appears on Linux, but does not cause problems.
# SUBST refused to edit binary files, so do it manually.
.if ${OPSYS} == "Darwin"
post-build:
	sed -i '' -e 's|-R|-L|g' ${WRKSRC}/opal/tools/wrappers/.libs/opal_wrapper
.endif

# Remove files that would conflict on case-insensitive filesystems, so we
# have a consistent PLIST and user interface across all platforms.  This
# will reduce the number of MPI-dependent packages that fail on other platforms.
# Is there a check for case-insensitive filesystems vs. using OPSYS?

post-install:
.if ${OPSYS} != "Darwin" && ${OPSYS} != "Interix"
	${RM} -f ${DESTDIR}${MPI_PREFIX}/bin/mpiCC \
		${DESTDIR}${MPI_PREFIX}/bin/orteCC \
		${DESTDIR}${MPI_PREFIX}/man/man1/mpiCC.1 \
		${DESTDIR}${MPI_PREFIX}/man/man1/orteCC.1 \
		${DESTDIR}${MPI_PREFIX}/share/openmpi/mpiCC-wrapper-data.txt \
		${DESTDIR}${MPI_PREFIX}/share/openmpi/orteCC-wrapper-data.txt
.endif
	${MKDIR} ${DESTDIR}${MPI_PREFIX}/etc
	${SED} -e "s|%%MPI_PREFIX%%|${MPI_PREFIX}|g" \
		files/shrc > ${DESTDIR}${MPI_PREFIX}/etc/shrc
	${SED} -e "s|%%MPI_PREFIX%%|${MPI_PREFIX}|g" \
		files/cshrc > ${DESTDIR}${MPI_PREFIX}/etc/cshrc

LIBLTDL_CONVENIENCE_SUBDIR=	opal/libltdl
.include "../../devel/libltdl/convenience.mk" # for "test" target to work
.include "../../devel/libltdl/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
