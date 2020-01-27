# $NetBSD: Makefile,v 1.39 2018/08/22 09:46:10 wiz Exp $

DISTNAME=	openmpi-4.0.0
CATEGORIES=	parallel
MASTER_SITES=	https://download.open-mpi.org/release/open-mpi/v4.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://www.open-mpi.org/
COMMENT=	Open source implementation
LICENSE=	modified-bsd

CONFLICTS=	mpich-[0-9]*

USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${MPI_PREFIX}
CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--without-slurm
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt # in separate package
CONFIGURE_ARGS+=	--with-libltdl=${BUILDLINK_PREFIX.libltdl}
CONFIGURE_ARGS+=	--with-hwloc=${BUILDLINK_PREFIX.hwloc}
CONFIGURE_ARGS+=	--with-wrapper-ldflags="-L${MPI_PREFIX}/lib ${LINKER_RPATH_FLAG}${MPI_PREFIX}/lib"
CONFIGURE_ARGS+=	OPAL_HAVE_LTDL_ADVISE=0
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/extlib/otf/libtool \
			${WRKSRC}/ompi/contrib/vt/vt/libtool \
			${WRKSRC}/ompi/mca/io/romio/romio/libtool
SHLIBTOOL_OVERRIDE=	${WRKSRC}/config/libtool.m4

# Prevent detection of OpenMP support in order to make PLIST consistent
BUILDLINK_TRANSFORM=	rm:-fopenmp

.include "options.mk"

TEST_TARGET=	check

PLIST_VARS+=	linux loadleveler oshmem pstattest shm
PLIST_VARS+=	ignoretkr noignoretkr

.if ${OPSYS} == "Linux"
PLIST.shm=		yes
PLIST.linux=		yes
PLIST.loadleveler=	yes
PLIST.oshmem=		yes
PLIST.ignoretkr=	yes
.elif ${OPSYS} == "AIX"
PLIST.loadleveler=	yes
.elif ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || \
    (${OPSYS} == "NetBSD" && exists(/var/shm))
PLIST.shm=		yes
.endif
.if ${OPSYS} != "Linux"
PLIST.pstattest=	yes
.  if ${OPSYS} != "Darwin"
PLIST.noignoretkr=	yes
.  endif
.endif

REPLACE_PERL=	ompi/tools/wrappers/mpijavac.pl.in

# In HPC, we must have multiple implementations and multiple versions of
# core tools like MPI in the same tree.  Some programs will require openmpi2,
# while others will need 3 or 4, while still others will need mpich.
MPI_SUBPREFIX=	openmpi4
MPI_PREFIX=	${PREFIX}/${MPI_SUBPREFIX}

#LIBLTDL_CONVENIENCE_SUBDIR=	opal/libltdl
#.include "../../devel/libltdl/convenience.mk" # for "test" target to work
.include "../../devel/libltdl/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
