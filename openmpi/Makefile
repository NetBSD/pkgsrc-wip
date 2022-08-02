# $NetBSD: Makefile,v 1.50 2022/07/27 14:28:32 wiz Exp $

DISTNAME=	openmpi-4.1.4
CATEGORIES=	parallel
MASTER_SITES=	https://download.open-mpi.org/release/open-mpi/v4.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.open-mpi.org/
COMMENT=	Open source MPI-3.1 implementation
LICENSE=	modified-bsd

CONFLICTS=	mpich-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run bash:run
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${MPI_PREFIX}
CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--without-slurm
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt # in separate package
CONFIGURE_ARGS+=	--with-libltdl=${BUILDLINK_PREFIX.libltdl}
CONFIGURE_ARGS+=	--with-hwloc=${BUILDLINK_PREFIX.hwloc}
.if defined(PKGSRC_USE_MPI_SUBPREFIX)
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${MPI_PREFIX}/lib ${LINKER_RPATH_FLAG}${MPI_PREFIX}/lib"
.endif
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0
LIBTOOL_OVERRIDE=	libtool \
			ompi/contrib/vt/vt/extlib/otf/libtool \
			ompi/contrib/vt/vt/libtool \
			ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	config/libtool.m4

# Prevent detection of OpenMP support in order to make PLIST consistent
BUILDLINK_TRANSFORM=	rm:-fopenmp

.include "options.mk"

TEST_TARGET=	check

# openmpi has a large number of build options, and we must figure out
# what is going to be discovered and enabled.  First, we describe each
# PLIST var.

# Unsurprisingly, files that are only produced on GNU/Linux systems.
PLIST_VARS+=	linux
# This controls if a single library is built, apparently only on Linux and AIX.
PLIST_VARS+=	loadleveler
# True if OpenSHMEM is enabled, perhaps currently only on Linux.
PLIST_VARS+=	oshmem
# \todo Explain.  Apparently built if !Linux.
PLIST_VARS+=	pstattest
# \todo Explain.  Not used in PLIST.
PLIST_VARS+=	shm
# \todo Explain.
PLIST_VARS+=	ignoretkr
PLIST_VARS+=	noignoretkr

# \todo There are no PLIST entries with PLIST.shm

# \todo ignoretkr is not making sense

.if ${OPSYS} == "Linux"
PLIST.shm=		yes
PLIST.linux=		yes
PLIST.loadleveler=	yes
PLIST.oshmem=		yes
.elif ${OPSYS} == "AIX"
PLIST.loadleveler=	yes
.elif ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || \
    (${OPSYS} == "NetBSD" && exists(/var/shm))
PLIST.shm=		yes
.endif

.if ${OPSYS} != "Linux"
PLIST.pstattest=	yes
.endif

.if ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PLIST.ignoretkr=	yes
.else
# \todo Explain why on Darwin we don't set one of them.
.  if ${OPSYS} != "Darwin"
PLIST.noignoretkr=	yes
.  endif
.endif

REPLACE_PERL=	ompi/tools/wrappers/mpijavac.pl.in
REPLACE_PERL+=	ompi/mca/common/monitoring/*.pl

post-install:
	echo "Move files in etc to examples and fix PLIST!"

# Some people want pkgsrc to support multiple versions of MPI at once,
# but this is not the standard approach.   This logic, or perhaps extracting
# the variable from the built package, is needed in buildlink3.mk.
.if defined(PKGSRC_USE_MPI_SUBPREFIX)
MPI_SUBPREFIX=	openmpi4
MPI_PREFIX=	${PREFIX}/${MPI_SUBPREFIX}
# \todo Support this in PLIST.
.else
MPI_SUBPREFIX=
MPI_PREFIX=	${PREFIX}
.endif

#LIBLTDL_CONVENIENCE_SUBDIR=	opal/libltdl
#.include "../../devel/libltdl/convenience.mk" # for "test" target to work
.include "../../devel/libltdl/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
