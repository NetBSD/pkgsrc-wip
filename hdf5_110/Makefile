# $NetBSD$

PKGVERSION=	1.10.11
PKGNAME=	hdf5_${PKGNAMESUFFIX}-${PKGVERSION}
DISTNAME=	hdf5-${PKGVERSION}
PKGNAMESUFFIX=	110
CATEGORIES=	devel
MASTER_SITES=	https://support.hdfgroup.org/ftp/HDF5/releases/hdf5-${PKGVERSION_NOREV:R}/hdf5-${PKGVERSION_NOREV}/src/
EXTRACT_SUFX=	.tar.bz2
COMMENT=	Hierarchical Data Format (new generation) 1.10.x

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.hdfgroup.org/HDF5/
LICENSE=	original-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pax tr
USE_LANGUAGES=		c c++ fortran
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-examplesdir=${PREFIX}/share/examples/hdf5-${PKGNAMESUFFIX}
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/hdf5-${PKGNAMESUFFIX}
CONFIGURE_ARGS+=	--program-suffix=-${PKGNAMESUFFIX}
CONFIGURE_ARGS+=	--with-default-api-version=v110
TEST_TARGET=		check

CFLAGS.SunOS+=		-std=c99 -D_XOPEN_SOURCE=600 -D__EXTENSIONS__
CONFIGURE_ENV.SunOS+=	ac_cv_func_gettimeofday=yes

#DISTINFO_FILE=	${.CURDIR}/../../devel/hdf5/distinfo
#PATCHDIR=	${.CURDIR}/../../devel/hdf5/patches

# These 2 files are not used in the build. They use [[ ... ]].
# CHECK_PORTABILITY_SKIP=	bin/snapshot hl/tools/h5watch/testh5watch.sh.in

# it appears that this file is informative only and is not actually
# used by any installed tools
# CHECK_WRKREF_SKIP=	${PREFIX}/lib/libhdf5.settings

INSTALL_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}

post-extract:
	${CP} ${WRKSRC}/config/freebsd ${WRKSRC}/config/netbsd
	${CP} ${WRKSRC}/config/freebsd ${WRKSRC}/config/netbsdelf

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/h5cc ${DESTDIR}${PREFIX}/bin/h5cc-${PKGNAMESUFFIX}
	${MV} ${DESTDIR}${PREFIX}/lib/libhdf5.settings ${DESTDIR}${PREFIX}/lib/libhdf5-${PKGNAMESUFFIX}.settings

SUBST_CLASSES+=		libname
SUBST_STAGE.libname=	pre-configure
SUBST_FILES.libname=	Makefile.in */Makefile.in */*/Makefile.in */*/*/Makefile.in \
			*/*/*/*/Makefile.in test/test_libinfo.sh.in
SUBST_SED.libname+=	-e "s|libhdf5|libhdf5-${PKGNAMESUFFIX}|g"
SUBST_SED.libname+=	-e "s|libhdf5-${PKGNAMESUFFIX}.settings|libhdf5.settings|g"

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
