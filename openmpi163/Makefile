# $NetBSD: Makefile,v 1.8 2015/06/19 19:40:40 outpaddling Exp $

DISTNAME=	openmpi-${PKGVERSION}
PKGVERSION=	1.6.3
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/ompi/v1.6/downloads/ \
		http://www.open-mpi.org/nightly/v1.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/
COMMENT=	Open source MPI-2 implementation

MPI_SUBPREFIX=		openmpi
MPI_PREFIX=		$(LOCALBASE)/$(MPI_SUBPREFIX)

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		yes

# Be pessimistic about Fortran 90 support, which is lacking on many platforms.
# Only enable it by default on platforms where it has been tested.
.if ${OPSYS} == Darwin || ${OPSYS} == Linux
USE_LANGUAGES=		c c++ fortran
# Fix: The Open MPI wrapper compiler was unable to find the specified compiler
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
.endif
CONFIGURE_ARGS+=	--without-sge
# CONFIGURE_ARGS+=	--without-slurm
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

# A -R flag is being mysteriously inserted into the mpi wrapper flags,
# which is not supported by the Darwin linker.  This hack replaces
# it with a harmless extra -L until I can figure out how to prevent it.
# The same -R appears on Linux, but does not cause problems.
# SUBST refused to edit binary files, so do it manually.
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux"
SUBST_CLASSES+=		opal
SUBST_STAGE.opal=	post-build
SUBST_FILES.opal=	${WRKSRC}/opal/tools/wrappers/.libs/opal_wrapper
SUBST_SED.opal=		-e 's|-R|-L|g'
.endif

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
	${MKDIR} ${DESTDIR}${MPI_PREFIX}/etc/modulefiles/openmpi
	${SED} -e "s|%%MPI_PREFIX%%|${MPI_PREFIX}|g" \
		files/shrc.in > ${DESTDIR}${MPI_PREFIX}/etc/shrc
	${SED} -e "s|%%MPI_PREFIX%%|${MPI_PREFIX}|g" \
		files/cshrc.in > ${DESTDIR}${MPI_PREFIX}/etc/cshrc
	${SED} -e "s|%%MPI_PREFIX%%|${MPI_PREFIX}|g" \
		files/module.in > ${DESTDIR}${MPI_PREFIX}/etc/modulefiles/openmpi/${PKGVERSION}
	${INSTALL_DATA} ${DESTDIR}${MPI_PREFIX}/share/openmpi/examples/openmpi-default-hostfile ${DESTDIR}${MPI_PREFIX}/etc

LIBLTDL_CONVENIENCE_SUBDIR=	opal/libltdl
.include "../../devel/libltdl/convenience.mk" # for "test" target to work
.include "../../devel/libltdl/buildlink3.mk"
# .include "../../devel/libexecinfo/buildlink3.mk"
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
