# $NetBSD: Makefile,v 1.7 2013/01/27 22:12:38 outpaddling Exp $
#

PKGNAME=	fvcom-2.7.1
DISTNAME=	sourcecode1
CATEGORIES=	science
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/password_required/t2/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://fvcom.smast.umassd.edu/FVCOM/password_required/t2/
COMMENT=	Prognostic coastal ocean circulation model
#LICENSE=	fvcom-license

WRKSRC=		${WRKDIR}/FVCOM2.7.1/FVCOM_source

USE_TOOLS+=	make
# Code is actually Fortran77, even though the build system generates .f90 files
USE_LANGUAGES=	c fortran77

# Use bundled metis
# DEPENDS+=	metis>=4.0:../../math/metis

AUTO_MKDIRS=	yes

FETCH_MESSAGE=  "Please download the files"
FETCH_MESSAGE+= "    "${DISTFILES:Q}
FETCH_MESSAGE+= "manually from "${MASTER_SITES:Q}"."

SUBST_CLASSES+=		log2
SUBST_FILES.log2=	METIS_source/coarsen.c \
			METIS_source/kmetis.c \
			METIS_source/kvmetis.c \
			METIS_source/metis_source.c \
			METIS_source/mkmetis.c \
			METIS_source/proto.h \
			METIS_source/rename.h \
			METIS_source/util.c
SUBST_STAGE.log2=	post-patch
SUBST_MESSAGE.log2=	Fixing log2 conflict
SUBST_SED.log2=		-e 's|log2|metis_log2|g'

pre-patch:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile
	${MV} ${WRKDIR}/FVCOM2.7.1/METIS_source ${WRKSRC}

pre-build:
	(cd ${WRKSRC}/METIS_source && make)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom ${DESTDIR}${PREFIX}/bin

# Current netcdf package missing mod file
# No netcdf support until this is resolved
#.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
