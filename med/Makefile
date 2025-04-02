# $NetBSD$

PKGVERSION=	4.0.0
PKGNAME=	med-${PKGVERSION}
CATEGORIES=	science

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://www.salome-platform.org/user-section/about/med
COMMENT=	Modelisation et Echanges de Donnees
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		fortran c c++
USE_TOOLS+=		gmake tar
USE_LIBTOOL=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-hdf5=${PREFIX}
CONFIGURE_ARGS+=	--with-hdf5-include=${PREFIX}/include/hdf5-110
BUILDLINK_TRANSFORM+=	l:hdf5:hdf5-110
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/gcc${GFORTRAN_VERSION}/lib
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

post-extract:
	${TAR} -C ${WRKDIR} -xf ${WRKDIR}/aster-full-src-${DISTVERSION}/SRC/med-${PKGVERSION_NOREV}.tar.gz

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	.*wish
REPLACE.wish.new=	${PREFIX}/bin/wish
REPLACE_FILES.wish=	tools/mdump/xmdump2.in tools/mdump/xmdump3.in

.include "../../wip/aster/Makefile.common"

.include "../../mk/bsd.prefs.mk"

.include "../../wip/hdf5_110/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
