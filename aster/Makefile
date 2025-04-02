# $NetBSD$

PKGVERSION=	14.6.0
DISTVERSION=	${PKGVERSION}-1
PKGNAME=	aster-${PKGVERSION}
DISTNAME=	aster-full-src-${DISTVERSION}.noarch
CATEGORIES=	science
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
WRKSRC=		${WRKDIR}/aster-full-src-${PKGVERSION}

MAINTAINER=	stix@stix.id.au
HOMEPAGE=	https://code-aster.org/
COMMENT=	Modelisation et Echanges de Donnees
LICENSE=	GPLv3

USE_LANGUAGES=		fortran c c++
USE_TOOLS+=		ar bison flex gmake cmake tk
NO_BUILD=		yes
NO_INSTALL=		yes
HAS_CONFIGURE=		yes
CONFIG_SHELL=		python3.11
CONFIGURE_SCRIPT=	setup.py
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--aster_root=${DESTDIR}/${PREFIX}
CONFIGURE_ARGS+=	--noprompt
CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR}
CONFIGURE_ENV+=		LD_LIBRARY_PATH=${BUILDLINK_DIR}/lib


.include "../../mk/bsd.prefs.mk"

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
